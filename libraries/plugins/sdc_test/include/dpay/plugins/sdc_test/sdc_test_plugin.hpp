#pragma once
#include <appbase/application.hpp>

#include <dpay/plugins/chain/chain_plugin.hpp>

namespace dpay { namespace plugins { namespace sdc_test {

using namespace appbase;

#define DPAY_SDC_TEST_PLUGIN_NAME "sdc_test"

class sdc_test_plugin : public appbase::plugin< sdc_test_plugin >
{
   public:
      sdc_test_plugin();
      virtual ~sdc_test_plugin();

      APPBASE_PLUGIN_REQUIRES( (dpay::plugins::chain::chain_plugin) )

      static const std::string& name() { static std::string name = DPAY_SDC_TEST_PLUGIN_NAME; return name; }

      virtual void set_program_options( options_description& cli, options_description& cfg ) override;
      void plugin_initialize( const variables_map& options ) override;
      void plugin_startup() override;
      void plugin_shutdown() override;

   private:
      std::unique_ptr< class sdc_test_plugin_impl > my;
};

} } } // dpay::plugins::sdc_test