#include <dpay/protocol/get_config.hpp>
#include <dpay/protocol/config.hpp>
#include <dpay/protocol/asset.hpp>
#include <dpay/protocol/types.hpp>
#include <dpay/protocol/version.hpp>

namespace dpay { namespace protocol {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

#ifdef IS_TEST_NET
   result[ "IS_TEST_NET" ] = true;
   result["TESTNET_BLOCK_LIMIT"] = TESTNET_BLOCK_LIMIT;
#else
   result[ "IS_TEST_NET" ] = false;
#endif
#ifdef DPAY_ENABLE_SMT
   result[ "DPAY_ENABLE_SMT" ] = true;
   result["SMT_VESTING_WITHDRAW_INTERVAL_SECONDS"] = SMT_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["SMT_UPVOTE_LOCKOUT"] = SMT_UPVOTE_LOCKOUT;
   result["SMT_MAX_VOTABLE_ASSETS"] = SMT_MAX_VOTABLE_ASSETS;
#else
   result[ "DPAY_ENABLE_SMT" ] = false;
#endif

   result["BBD_SYMBOL"] = BBD_SYMBOL;
   result["DPAY_INITIAL_VOTE_POWER_RATE"] = DPAY_INITIAL_VOTE_POWER_RATE;
   result["DPAY_REDUCED_VOTE_POWER_RATE"] = DPAY_REDUCED_VOTE_POWER_RATE;
   result["DPAY_100_PERCENT"] = DPAY_100_PERCENT;
   result["DPAY_1_PERCENT"] = DPAY_1_PERCENT;
   result["DPAY_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD"] = DPAY_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD;
   result["DPAY_ACTIVE_CHALLENGE_COOLDOWN"] = DPAY_ACTIVE_CHALLENGE_COOLDOWN;
   result["DPAY_ACTIVE_CHALLENGE_FEE"] = DPAY_ACTIVE_CHALLENGE_FEE;
   result["DPAY_ADDRESS_PREFIX"] = DPAY_ADDRESS_PREFIX;
   result["DPAY_APR_PERCENT_MULTIPLY_PER_BLOCK"] = DPAY_APR_PERCENT_MULTIPLY_PER_BLOCK;
   result["DPAY_APR_PERCENT_MULTIPLY_PER_HOUR"] = DPAY_APR_PERCENT_MULTIPLY_PER_HOUR;
   result["DPAY_APR_PERCENT_MULTIPLY_PER_ROUND"] = DPAY_APR_PERCENT_MULTIPLY_PER_ROUND;
   result["DPAY_APR_PERCENT_SHIFT_PER_BLOCK"] = DPAY_APR_PERCENT_SHIFT_PER_BLOCK;
   result["DPAY_APR_PERCENT_SHIFT_PER_HOUR"] = DPAY_APR_PERCENT_SHIFT_PER_HOUR;
   result["DPAY_APR_PERCENT_SHIFT_PER_ROUND"] = DPAY_APR_PERCENT_SHIFT_PER_ROUND;
   result["DPAY_BANDWIDTH_AVERAGE_WINDOW_SECONDS"] = DPAY_BANDWIDTH_AVERAGE_WINDOW_SECONDS;
   result["DPAY_BANDWIDTH_PRECISION"] = DPAY_BANDWIDTH_PRECISION;
   result["DPAY_BLOCKCHAIN_PRECISION"] = DPAY_BLOCKCHAIN_PRECISION;
   result["DPAY_BLOCKCHAIN_PRECISION_DIGITS"] = DPAY_BLOCKCHAIN_PRECISION_DIGITS;
   result["DPAY_BLOCKCHAIN_HARDFORK_VERSION"] = DPAY_BLOCKCHAIN_HARDFORK_VERSION;
   result["DPAY_BLOCKCHAIN_VERSION"] = DPAY_BLOCKCHAIN_VERSION;
   result["DPAY_BLOCK_INTERVAL"] = DPAY_BLOCK_INTERVAL;
   result["DPAY_BLOCKS_PER_DAY"] = DPAY_BLOCKS_PER_DAY;
   result["DPAY_BLOCKS_PER_HOUR"] = DPAY_BLOCKS_PER_HOUR;
   result["DPAY_BLOCKS_PER_YEAR"] = DPAY_BLOCKS_PER_YEAR;
   result["DPAY_CASHOUT_WINDOW_SECONDS"] = DPAY_CASHOUT_WINDOW_SECONDS;
   result["DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF12"] = DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF12;
   result["DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF17"] = DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF17;
   result["DPAY_CHAIN_ID"] = DPAY_CHAIN_ID;
   result["DPAY_COMMENT_REWARD_FUND_NAME"] = DPAY_COMMENT_REWARD_FUND_NAME;
   result["DPAY_CONTENT_APR_PERCENT"] = DPAY_CONTENT_APR_PERCENT;
   result["DPAY_CONTENT_CONSTANT_HF0"] = DPAY_CONTENT_CONSTANT_HF0;
   result["DPAY_CONTENT_REWARD_PERCENT"] = DPAY_CONTENT_REWARD_PERCENT;
   result["DPAY_CONVERSION_DELAY"] = DPAY_CONVERSION_DELAY;
   result["DPAY_CONVERSION_DELAY_PRE_HF_16"] = DPAY_CONVERSION_DELAY_PRE_HF_16;
   result["DPAY_CREATE_ACCOUNT_DELEGATION_RATIO"] = DPAY_CREATE_ACCOUNT_DELEGATION_RATIO;
   result["DPAY_CREATE_ACCOUNT_DELEGATION_TIME"] = DPAY_CREATE_ACCOUNT_DELEGATION_TIME;
   result["DPAY_CREATE_ACCOUNT_WITH_DPAY_MODIFIER"] = DPAY_CREATE_ACCOUNT_WITH_DPAY_MODIFIER;
   result["DPAY_CURATE_APR_PERCENT"] = DPAY_CURATE_APR_PERCENT;
   result["DPAY_DEFAULT_BBD_INTEREST_RATE"] = DPAY_DEFAULT_BBD_INTEREST_RATE;
   result["DPAY_EQUIHASH_K"] = DPAY_EQUIHASH_K;
   result["DPAY_EQUIHASH_N"] = DPAY_EQUIHASH_N;
   result["DPAY_FEED_HISTORY_WINDOW"] = DPAY_FEED_HISTORY_WINDOW;
   result["DPAY_FEED_HISTORY_WINDOW_PRE_HF_16"] = DPAY_FEED_HISTORY_WINDOW_PRE_HF_16;
   result["DPAY_FEED_INTERVAL_BLOCKS"] = DPAY_FEED_INTERVAL_BLOCKS;
   result["DPAY_GENESIS_TIME"] = DPAY_GENESIS_TIME;
   result["DPAY_HARDFORK_REQUIRED_WITNESSES"] = DPAY_HARDFORK_REQUIRED_WITNESSES;
   result["DPAY_INFLATION_NARROWING_PERIOD"] = DPAY_INFLATION_NARROWING_PERIOD;
   result["DPAY_INFLATION_RATE_START_PERCENT"] = DPAY_INFLATION_RATE_START_PERCENT;
   result["DPAY_INFLATION_RATE_STOP_PERCENT"] = DPAY_INFLATION_RATE_STOP_PERCENT;
   result["DPAY_INIT_MINER_NAME"] = DPAY_INIT_MINER_NAME;
   result["DPAY_INIT_PUBLIC_KEY_STR"] = DPAY_INIT_PUBLIC_KEY_STR;
#if 0
   // do not expose private key, period.
   // we need this line present but inactivated so CI check for all constants in config.hpp doesn't complain.
   result["DPAY_INIT_PRIVATE_KEY"] = DPAY_INIT_PRIVATE_KEY;
#endif
   result["DPAY_INIT_SUPPLY"] = DPAY_INIT_SUPPLY;
   result["DPAY_INIT_TIME"] = DPAY_INIT_TIME;
   result["DPAY_IRREVERSIBLE_THRESHOLD"] = DPAY_IRREVERSIBLE_THRESHOLD;
   result["DPAY_LIQUIDITY_APR_PERCENT"] = DPAY_LIQUIDITY_APR_PERCENT;
   result["DPAY_LIQUIDITY_REWARD_BLOCKS"] = DPAY_LIQUIDITY_REWARD_BLOCKS;
   result["DPAY_LIQUIDITY_REWARD_PERIOD_SEC"] = DPAY_LIQUIDITY_REWARD_PERIOD_SEC;
   result["DPAY_LIQUIDITY_TIMEOUT_SEC"] = DPAY_LIQUIDITY_TIMEOUT_SEC;
   result["DPAY_MAX_ACCOUNT_CREATION_FEE"] = DPAY_MAX_ACCOUNT_CREATION_FEE;
   result["DPAY_MAX_ACCOUNT_NAME_LENGTH"] = DPAY_MAX_ACCOUNT_NAME_LENGTH;
   result["DPAY_MAX_ACCOUNT_WITNESS_VOTES"] = DPAY_MAX_ACCOUNT_WITNESS_VOTES;
   result["DPAY_MAX_ASSET_WHITELIST_AUTHORITIES"] = DPAY_MAX_ASSET_WHITELIST_AUTHORITIES;
   result["DPAY_MAX_AUTHORITY_MEMBERSHIP"] = DPAY_MAX_AUTHORITY_MEMBERSHIP;
   result["DPAY_MAX_BLOCK_SIZE"] = DPAY_MAX_BLOCK_SIZE;
   result["DPAY_SOFT_MAX_BLOCK_SIZE"] = DPAY_SOFT_MAX_BLOCK_SIZE;
   result["DPAY_MAX_CASHOUT_WINDOW_SECONDS"] = DPAY_MAX_CASHOUT_WINDOW_SECONDS;
   result["DPAY_MAX_COMMENT_DEPTH"] = DPAY_MAX_COMMENT_DEPTH;
   result["DPAY_MAX_COMMENT_DEPTH_PRE_HF17"] = DPAY_MAX_COMMENT_DEPTH_PRE_HF17;
   result["DPAY_MAX_FEED_AGE_SECONDS"] = DPAY_MAX_FEED_AGE_SECONDS;
   result["DPAY_MAX_INSTANCE_ID"] = DPAY_MAX_INSTANCE_ID;
   result["DPAY_MAX_MEMO_SIZE"] = DPAY_MAX_MEMO_SIZE;
   result["DPAY_MAX_WITNESSES"] = DPAY_MAX_WITNESSES;
   result["DPAY_MAX_MINER_WITNESSES_HF0"] = DPAY_MAX_MINER_WITNESSES_HF0;
   result["DPAY_MAX_MINER_WITNESSES_HF17"] = DPAY_MAX_MINER_WITNESSES_HF17;
   result["DPAY_MAX_PERMLINK_LENGTH"] = DPAY_MAX_PERMLINK_LENGTH;
   result["DPAY_MAX_PROXY_RECURSION_DEPTH"] = DPAY_MAX_PROXY_RECURSION_DEPTH;
   result["DPAY_MAX_RATION_DECAY_RATE"] = DPAY_MAX_RATION_DECAY_RATE;
   result["DPAY_MAX_RESERVE_RATIO"] = DPAY_MAX_RESERVE_RATIO;
   result["DPAY_MAX_RUNNER_WITNESSES_HF0"] = DPAY_MAX_RUNNER_WITNESSES_HF0;
   result["DPAY_MAX_RUNNER_WITNESSES_HF17"] = DPAY_MAX_RUNNER_WITNESSES_HF17;
   result["DPAY_MAX_SATOSHIS"] = DPAY_MAX_SATOSHIS;
   result["DPAY_MAX_SHARE_SUPPLY"] = DPAY_MAX_SHARE_SUPPLY;
   result["DPAY_MAX_SIG_CHECK_DEPTH"] = DPAY_MAX_SIG_CHECK_DEPTH;
   result["DPAY_MAX_SIG_CHECK_ACCOUNTS"] = DPAY_MAX_SIG_CHECK_ACCOUNTS;
   result["DPAY_MAX_TIME_UNTIL_EXPIRATION"] = DPAY_MAX_TIME_UNTIL_EXPIRATION;
   result["DPAY_MAX_TRANSACTION_SIZE"] = DPAY_MAX_TRANSACTION_SIZE;
   result["DPAY_MAX_UNDO_HISTORY"] = DPAY_MAX_UNDO_HISTORY;
   result["DPAY_MAX_URL_LENGTH"] = DPAY_MAX_URL_LENGTH;
   result["DPAY_MAX_VOTE_CHANGES"] = DPAY_MAX_VOTE_CHANGES;
   result["DPAY_MAX_VOTED_WITNESSES_HF0"] = DPAY_MAX_VOTED_WITNESSES_HF0;
   result["DPAY_MAX_VOTED_WITNESSES_HF17"] = DPAY_MAX_VOTED_WITNESSES_HF17;
   result["DPAY_MAX_WITHDRAW_ROUTES"] = DPAY_MAX_WITHDRAW_ROUTES;
   result["DPAY_MAX_WITNESS_URL_LENGTH"] = DPAY_MAX_WITNESS_URL_LENGTH;
   result["DPAY_MIN_ACCOUNT_CREATION_FEE"] = DPAY_MIN_ACCOUNT_CREATION_FEE;
   result["DPAY_MIN_ACCOUNT_NAME_LENGTH"] = DPAY_MIN_ACCOUNT_NAME_LENGTH;
   result["DPAY_MIN_BLOCK_SIZE_LIMIT"] = DPAY_MIN_BLOCK_SIZE_LIMIT;
   result["DPAY_MIN_BLOCK_SIZE"] = DPAY_MIN_BLOCK_SIZE;
   result["DPAY_MIN_CONTENT_REWARD"] = DPAY_MIN_CONTENT_REWARD;
   result["DPAY_MIN_CURATE_REWARD"] = DPAY_MIN_CURATE_REWARD;
   result["DPAY_MIN_PERMLINK_LENGTH"] = DPAY_MIN_PERMLINK_LENGTH;
   result["DPAY_MIN_REPLY_INTERVAL"] = DPAY_MIN_REPLY_INTERVAL;
   result["DPAY_MIN_REPLY_INTERVAL_HF20"] = DPAY_MIN_REPLY_INTERVAL_HF20;
   result["DPAY_MIN_ROOT_COMMENT_INTERVAL"] = DPAY_MIN_ROOT_COMMENT_INTERVAL;
   result["DPAY_MIN_VOTE_INTERVAL_SEC"] = DPAY_MIN_VOTE_INTERVAL_SEC;
   result["DPAY_MINER_ACCOUNT"] = DPAY_MINER_ACCOUNT;
   result["DPAY_MINER_PAY_PERCENT"] = DPAY_MINER_PAY_PERCENT;
   result["DPAY_MIN_FEEDS"] = DPAY_MIN_FEEDS;
   result["DPAY_MINING_REWARD"] = DPAY_MINING_REWARD;
   result["DPAY_MINING_TIME"] = DPAY_MINING_TIME;
   result["DPAY_MIN_LIQUIDITY_REWARD"] = DPAY_MIN_LIQUIDITY_REWARD;
   result["DPAY_MIN_LIQUIDITY_REWARD_PERIOD_SEC"] = DPAY_MIN_LIQUIDITY_REWARD_PERIOD_SEC;
   result["DPAY_MIN_PAYOUT_BBD"] = DPAY_MIN_PAYOUT_BBD;
   result["DPAY_MIN_POW_REWARD"] = DPAY_MIN_POW_REWARD;
   result["DPAY_MIN_PRODUCER_REWARD"] = DPAY_MIN_PRODUCER_REWARD;
   result["DPAY_MIN_TRANSACTION_EXPIRATION_LIMIT"] = DPAY_MIN_TRANSACTION_EXPIRATION_LIMIT;
   result["DPAY_MIN_TRANSACTION_SIZE_LIMIT"] = DPAY_MIN_TRANSACTION_SIZE_LIMIT;
   result["DPAY_MIN_UNDO_HISTORY"] = DPAY_MIN_UNDO_HISTORY;
   result["DPAY_NULL_ACCOUNT"] = DPAY_NULL_ACCOUNT;
   result["DPAY_NUM_INIT_MINERS"] = DPAY_NUM_INIT_MINERS;
   result["DPAY_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM"] = DPAY_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM;
   result["DPAY_OWNER_AUTH_RECOVERY_PERIOD"] = DPAY_OWNER_AUTH_RECOVERY_PERIOD;
   result["DPAY_OWNER_CHALLENGE_COOLDOWN"] = DPAY_OWNER_CHALLENGE_COOLDOWN;
   result["DPAY_OWNER_CHALLENGE_FEE"] = DPAY_OWNER_CHALLENGE_FEE;
   result["DPAY_OWNER_UPDATE_LIMIT"] = DPAY_OWNER_UPDATE_LIMIT;
   result["DPAY_POST_AVERAGE_WINDOW"] = DPAY_POST_AVERAGE_WINDOW;
   result["DPAY_POST_REWARD_FUND_NAME"] = DPAY_POST_REWARD_FUND_NAME;
   result["DPAY_POST_WEIGHT_CONSTANT"] = DPAY_POST_WEIGHT_CONSTANT;
   result["DPAY_POW_APR_PERCENT"] = DPAY_POW_APR_PERCENT;
   result["DPAY_PRODUCER_APR_PERCENT"] = DPAY_PRODUCER_APR_PERCENT;
   result["DPAY_PROXY_TO_SELF_ACCOUNT"] = DPAY_PROXY_TO_SELF_ACCOUNT;
   result["DPAY_BBD_INTEREST_COMPOUND_INTERVAL_SEC"] = DPAY_BBD_INTEREST_COMPOUND_INTERVAL_SEC;
   result["DPAY_SECONDS_PER_YEAR"] = DPAY_SECONDS_PER_YEAR;
   result["DPAY_RECENT_RSHARES_DECAY_TIME_HF19"] = DPAY_RECENT_RSHARES_DECAY_TIME_HF19;
   result["DPAY_RECENT_RSHARES_DECAY_TIME_HF17"] = DPAY_RECENT_RSHARES_DECAY_TIME_HF17;
   result["DPAY_REVERSE_AUCTION_WINDOW_SECONDS_HF6"] = DPAY_REVERSE_AUCTION_WINDOW_SECONDS_HF6;
   result["DPAY_REVERSE_AUCTION_WINDOW_SECONDS_HF20"] = DPAY_REVERSE_AUCTION_WINDOW_SECONDS_HF20;
   result["DPAY_ROOT_POST_PARENT"] = DPAY_ROOT_POST_PARENT;
   result["DPAY_SAVINGS_WITHDRAW_REQUEST_LIMIT"] = DPAY_SAVINGS_WITHDRAW_REQUEST_LIMIT;
   result["DPAY_SAVINGS_WITHDRAW_TIME"] = DPAY_SAVINGS_WITHDRAW_TIME;
   result["DPAY_BBD_START_PERCENT_HF14"] = DPAY_BBD_START_PERCENT_HF14;
   result["DPAY_BBD_START_PERCENT_HF20"] = DPAY_BBD_START_PERCENT_HF20;
   result["DPAY_BBD_STOP_PERCENT_HF14"] = DPAY_BBD_STOP_PERCENT_HF14;
   result["DPAY_BBD_STOP_PERCENT_HF20"] = DPAY_BBD_STOP_PERCENT_HF20;
   result["DPAY_SECOND_CASHOUT_WINDOW"] = DPAY_SECOND_CASHOUT_WINDOW;
   result["DPAY_SOFT_MAX_COMMENT_DEPTH"] = DPAY_SOFT_MAX_COMMENT_DEPTH;
   result["DPAY_START_MINER_VOTING_BLOCK"] = DPAY_START_MINER_VOTING_BLOCK;
   result["DPAY_START_VESTING_BLOCK"] = DPAY_START_VESTING_BLOCK;
   result["DPAY_TEMP_ACCOUNT"] = DPAY_TEMP_ACCOUNT;
   result["DPAY_UPVOTE_LOCKOUT_HF7"] = DPAY_UPVOTE_LOCKOUT_HF7;
   result["DPAY_UPVOTE_LOCKOUT_HF17"] = DPAY_UPVOTE_LOCKOUT_HF17;
   result["DPAY_UPVOTE_LOCKOUT_SECONDS"] = DPAY_UPVOTE_LOCKOUT_SECONDS;
   result["DPAY_VESTING_FUND_PERCENT"] = DPAY_VESTING_FUND_PERCENT;
   result["DPAY_VESTING_WITHDRAW_INTERVALS"] = DPAY_VESTING_WITHDRAW_INTERVALS;
   result["DPAY_VESTING_WITHDRAW_INTERVALS_PRE_HF_16"] = DPAY_VESTING_WITHDRAW_INTERVALS_PRE_HF_16;
   result["DPAY_VESTING_WITHDRAW_INTERVAL_SECONDS"] = DPAY_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["DPAY_VOTE_DUST_THRESHOLD"] = DPAY_VOTE_DUST_THRESHOLD;
   result["DPAY_VOTING_MANA_REGENERATION_SECONDS"] = DPAY_VOTING_MANA_REGENERATION_SECONDS;
   result["BEX_SYMBOL"] = BEX_SYMBOL;
   result["VESTS_SYMBOL"] = VESTS_SYMBOL;
   result["DPAY_VIRTUAL_SCHEDULE_LAP_LENGTH"] = DPAY_VIRTUAL_SCHEDULE_LAP_LENGTH;
   result["DPAY_VIRTUAL_SCHEDULE_LAP_LENGTH2"] = DPAY_VIRTUAL_SCHEDULE_LAP_LENGTH2;
   result["DPAY_MAX_LIMIT_ORDER_EXPIRATION"] = DPAY_MAX_LIMIT_ORDER_EXPIRATION;
   result["DPAY_DELEGATION_RETURN_PERIOD_HF0"] = DPAY_DELEGATION_RETURN_PERIOD_HF0;
   result["DPAY_DELEGATION_RETURN_PERIOD_HF20"] = DPAY_DELEGATION_RETURN_PERIOD_HF20;
   result["DPAY_RD_MIN_DECAY_BITS"] = DPAY_RD_MIN_DECAY_BITS;
   result["DPAY_RD_MAX_DECAY_BITS"] = DPAY_RD_MAX_DECAY_BITS;
   result["DPAY_RD_DECAY_DENOM_SHIFT"] = DPAY_RD_DECAY_DENOM_SHIFT;
   result["DPAY_RD_MAX_POOL_BITS"] = DPAY_RD_MAX_POOL_BITS;
   result["DPAY_RD_MAX_BUDGET_1"] = DPAY_RD_MAX_BUDGET_1;
   result["DPAY_RD_MAX_BUDGET_2"] = DPAY_RD_MAX_BUDGET_2;
   result["DPAY_RD_MAX_BUDGET_3"] = DPAY_RD_MAX_BUDGET_3;
   result["DPAY_RD_MAX_BUDGET"] = DPAY_RD_MAX_BUDGET;
   result["DPAY_RD_MIN_DECAY"] = DPAY_RD_MIN_DECAY;
   result["DPAY_RD_MIN_BUDGET"] = DPAY_RD_MIN_BUDGET;
   result["DPAY_RD_MAX_DECAY"] = DPAY_RD_MAX_DECAY;
   result["DPAY_ACCOUNT_SUBSIDY_PRECISION"] = DPAY_ACCOUNT_SUBSIDY_PRECISION;
   result["DPAY_WITNESS_SUBSIDY_BUDGET_PERCENT"] = DPAY_WITNESS_SUBSIDY_BUDGET_PERCENT;
   result["DPAY_WITNESS_SUBSIDY_DECAY_PERCENT"] = DPAY_WITNESS_SUBSIDY_DECAY_PERCENT;
   result["DPAY_DEFAULT_ACCOUNT_SUBSIDY_DECAY"] = DPAY_DEFAULT_ACCOUNT_SUBSIDY_DECAY;
   result["DPAY_DEFAULT_ACCOUNT_SUBSIDY_BUDGET"] = DPAY_DEFAULT_ACCOUNT_SUBSIDY_BUDGET;
   result["DPAY_DECAY_BACKSTOP_PERCENT"] = DPAY_DECAY_BACKSTOP_PERCENT;

   return result;
}

} } // dpay::protocol
