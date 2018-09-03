#if defined IS_TEST_NET && defined DPAY_ENABLE_SDC
#include <boost/test/unit_test.hpp>

#include <dpay/chain/account_object.hpp>
#include <dpay/chain/comment_object.hpp>
#include <dpay/protocol/dpay_operations.hpp>

#include <dpay/plugins/market_history/market_history_plugin.hpp>

#include "../db_fixture/database_fixture.hpp"

using namespace dpay::chain;
using namespace dpay::protocol;

BOOST_FIXTURE_TEST_SUITE( sdc_market_history, sdc_database_fixture_for_plugin )

BOOST_AUTO_TEST_CASE( sdc_mh_test )
{
   using namespace dpay::plugins::market_history;

   try
   {
      int argc = boost::unit_test::framework::master_test_suite().argc;
      char** argv = boost::unit_test::framework::master_test_suite().argv;
      for( int i=1; i<argc; i++ )
      {
         const std::string arg = argv[i];
         if( arg == "--record-assert-trip" )
            fc::enable_record_assert_trip = true;
         if( arg == "--show-test-names" )
            std::cout << "running test " << boost::unit_test::framework::current_test_case().p_name << std::endl;
      }

      appbase::app().register_plugin< market_history_plugin >();
      db_plugin = &appbase::app().register_plugin< dpay::plugins::debug_node::debug_node_plugin >();
      init_account_pub_key = init_account_priv_key.get_public_key();

      db_plugin->logging = false;
      appbase::app().initialize<
         dpay::plugins::market_history::market_history_plugin,
         dpay::plugins::debug_node::debug_node_plugin
      >( argc, argv );

      db = &appbase::app().get_plugin< dpay::plugins::chain::chain_plugin >().db();
      BOOST_REQUIRE( db );

      open_database();

      generate_block();
      db->set_hardfork( DPAY_NUM_HARDFORKS );
      generate_block();

      vest( "initminer", 10000 );

      // Fill up the rest of the required miners
      for( int i = DPAY_NUM_INIT_MINERS; i < DPAY_MAX_WITNESSES; i++ )
      {
         account_create( DPAY_INIT_MINER_NAME + fc::to_string( i ), init_account_pub_key );
         fund( DPAY_INIT_MINER_NAME + fc::to_string( i ), DPAY_MIN_PRODUCER_REWARD.amount.value );
         witness_create( DPAY_INIT_MINER_NAME + fc::to_string( i ), init_account_priv_key, "foo.bar", init_account_pub_key, DPAY_MIN_PRODUCER_REWARD.amount );
      }

      validate_database();

      ACTORS( (alice)(bob)(sam)(sdccreator) );

      signed_transaction tx;
      asset_symbol_type any_sdc_symbol = create_sdc( "sdccreator", sdccreator_private_key, 3);

      fund( "alice", ASSET( "1000.000 TESTS" ) );
      fund( "bob", ASSET( "1000.000 TESTS" ) );
      fund( "sam", ASSET( "1000.000 TESTS" ) );
      fund( "alice", asset( 1000000, any_sdc_symbol ) );

      tx.operations.clear();
      tx.signatures.clear();

      const auto& bucket_idx = db->get_index< bucket_index >().indices().get< by_bucket >();
      const auto& order_hist_idx = db->get_index< order_history_index >().indices().get< by_id >();

      BOOST_REQUIRE( bucket_idx.begin() == bucket_idx.end() );
      BOOST_REQUIRE( order_hist_idx.begin() == order_hist_idx.end() );
      validate_database();

      auto fill_order_a_time = db->head_block_time();
      auto time_a = fc::time_point_sec( ( fill_order_a_time.sec_since_epoch() / 15 ) * 15 );

      limit_order_create_operation op;
      op.owner = "alice";
      op.amount_to_sell = asset( 1000, any_sdc_symbol );
      op.min_to_receive = ASSET( "2.000 TESTS" );
      op.expiration = db->head_block_time() + fc::seconds( DPAY_MAX_LIMIT_ORDER_EXPIRATION );
      tx.operations.push_back( op );
      tx.set_expiration( db->head_block_time() + DPAY_MAX_TIME_UNTIL_EXPIRATION );
      sign( tx, alice_private_key );
      db->push_transaction( tx, 0 );

      tx.operations.clear();
      tx.signatures.clear();

      op.owner = "bob";
      op.amount_to_sell = ASSET( "1.500 TESTS" );
      op.min_to_receive = asset( 750, any_sdc_symbol );
      tx.operations.push_back( op );
      sign( tx, bob_private_key );
      db->push_transaction( tx, 0 );

      generate_blocks( db->head_block_time() + ( 60 * 90 ) );

      auto fill_order_b_time = db->head_block_time();

      tx.operations.clear();
      tx.signatures.clear();

      op.owner = "sam";
      op.amount_to_sell = ASSET( "1.000 TESTS" );
      op.min_to_receive = asset( 500, any_sdc_symbol );
      tx.operations.push_back( op );
      tx.set_expiration( db->head_block_time() + DPAY_MAX_TIME_UNTIL_EXPIRATION );
      sign( tx, sam_private_key );
      db->push_transaction( tx, 0 );

      generate_blocks( db->head_block_time() + 60 );

      auto fill_order_c_time = db->head_block_time();

      tx.operations.clear();
      tx.signatures.clear();

      op.owner = "alice";
      op.amount_to_sell = asset( 500, any_sdc_symbol );
      op.min_to_receive = ASSET( "0.900 TESTS" );
      tx.operations.push_back( op );
      tx.set_expiration( db->head_block_time() + DPAY_MAX_TIME_UNTIL_EXPIRATION );
      sign( tx, alice_private_key );
      db->push_transaction( tx, 0 );

      tx.operations.clear();
      tx.signatures.clear();

      op.owner = "bob";
      op.amount_to_sell = ASSET( "0.450 TESTS" );
      op.min_to_receive = asset( 250, any_sdc_symbol );
      tx.operations.push_back( op );
      tx.set_expiration( db->head_block_time() + DPAY_MAX_TIME_UNTIL_EXPIRATION );
      sign( tx, bob_private_key );
      db->push_transaction( tx, 0 );
      validate_database();

      auto bucket = bucket_idx.begin();

      BOOST_REQUIRE( bucket->seconds == 15 );
      BOOST_REQUIRE( bucket->open == time_a );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "1.500 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "1.500 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 750, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket->seconds == 15 );
      BOOST_REQUIRE( bucket->open == time_a + ( 60 * 90 ) );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "0.500 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "0.500 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 250, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket->seconds == 15 );
      BOOST_REQUIRE( bucket->open == time_a + ( 60 * 90 ) + 60 );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "0.450 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "0.450 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "0.950 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 500, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket->seconds == 60 );
      BOOST_REQUIRE( bucket->open == time_a );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "1.500 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "1.500 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 750, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket->seconds == 60 );
      BOOST_REQUIRE( bucket->open == time_a + ( 60 * 90 ) );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "0.500 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "0.500 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 250, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket->seconds == 60 );
      BOOST_REQUIRE( bucket->open == time_a + ( 60 * 90 ) + 60 );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "0.450 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "0.450 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "0.950 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 500, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket->seconds == 300 );
      BOOST_REQUIRE( bucket->open == time_a );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "1.500 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "1.500 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 750, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket->seconds == 300 );
      BOOST_REQUIRE( bucket->open == time_a + ( 60 * 90 ) );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "0.450 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "0.450 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "1.450 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 750, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket->seconds == 3600 );
      BOOST_REQUIRE( bucket->open == time_a );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "1.500 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "1.500 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 750, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket->seconds == 3600 );
      BOOST_REQUIRE( bucket->open == time_a + ( 60 * 60 ) );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "0.450 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "0.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "0.450 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "1.450 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 750, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket->seconds == 86400 );
      BOOST_REQUIRE( bucket->open == DPAY_GENESIS_TIME );
      BOOST_REQUIRE( bucket->dpay.high == ASSET( "0.450 TESTS " ).amount );
      BOOST_REQUIRE( bucket->non_dpay.high == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.low == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.low == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.open == ASSET( "1.500 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.open == asset( 750, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.close == ASSET( "0.450 TESTS").amount );
      BOOST_REQUIRE( bucket->non_dpay.close == asset( 250, any_sdc_symbol ).amount );
      BOOST_REQUIRE( bucket->dpay.volume == ASSET( "2.950 TESTS" ).amount );
      BOOST_REQUIRE( bucket->non_dpay.volume == asset( 1500, any_sdc_symbol ).amount );
      bucket++;

      BOOST_REQUIRE( bucket == bucket_idx.end() );

      auto order = order_hist_idx.begin();

      BOOST_REQUIRE( order->time == fill_order_a_time );
      BOOST_REQUIRE( order->op.current_owner == "bob" );
      BOOST_REQUIRE( order->op.current_orderid == 0 );
      BOOST_REQUIRE( order->op.current_pays == ASSET( "1.500 TESTS" ) );
      BOOST_REQUIRE( order->op.open_owner == "alice" );
      BOOST_REQUIRE( order->op.open_orderid == 0 );
      BOOST_REQUIRE( order->op.open_pays == asset( 750, any_sdc_symbol ) );
      order++;

      BOOST_REQUIRE( order->time == fill_order_b_time );
      BOOST_REQUIRE( order->op.current_owner == "sam" );
      BOOST_REQUIRE( order->op.current_orderid == 0 );
      BOOST_REQUIRE( order->op.current_pays == ASSET( "0.500 TESTS" ) );
      BOOST_REQUIRE( order->op.open_owner == "alice" );
      BOOST_REQUIRE( order->op.open_orderid == 0 );
      BOOST_REQUIRE( order->op.open_pays == asset( 250, any_sdc_symbol ) );
      order++;

      BOOST_REQUIRE( order->time == fill_order_c_time );
      BOOST_REQUIRE( order->op.current_owner == "alice" );
      BOOST_REQUIRE( order->op.current_orderid == 0 );
      BOOST_REQUIRE( order->op.current_pays == asset( 250, any_sdc_symbol ) );
      BOOST_REQUIRE( order->op.open_owner == "sam" );
      BOOST_REQUIRE( order->op.open_orderid == 0 );
      BOOST_REQUIRE( order->op.open_pays == ASSET( "0.500 TESTS" ) );
      order++;

      BOOST_REQUIRE( order->time == fill_order_c_time );
      BOOST_REQUIRE( order->op.current_owner == "bob" );
      BOOST_REQUIRE( order->op.current_orderid == 0 );
      BOOST_REQUIRE( order->op.current_pays == ASSET( "0.450 TESTS" ) );
      BOOST_REQUIRE( order->op.open_owner == "alice" );
      BOOST_REQUIRE( order->op.open_orderid == 0 );
      BOOST_REQUIRE( order->op.open_pays == asset( 250, any_sdc_symbol ) );
      order++;

      BOOST_REQUIRE( order == order_hist_idx.end() );

      validate_database();
   }
   FC_LOG_AND_RETHROW()
}

BOOST_AUTO_TEST_SUITE_END()
#endif