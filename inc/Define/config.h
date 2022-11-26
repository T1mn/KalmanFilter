#ifndef __WORKSPACE_KALMANFILTER_INC_DEFINE_CONFIG_H_
#define __WORKSPACE_KALMANFILTER_INC_DEFINE_CONFIG_H_
#include "Define/basic_type.h"

using state_size_t = int32_t;
using measu_size_t = int32_t;

typedef enum kalman_types
{
    NORMAL_KF_ = 0,
    UNSCENTED_KF_ = 1,
} cf_kts;

typedef struct init_config_st{
    kalman_types kal_type_;
    state_size_t stt_size_;
    measu_size_t msu_size_;
    init_config_st() : kal_type_(kalman_types::NORMAL_KF_), stt_size_(0), msu_size_(0) {}

} cf_ic;

#endif // __WORKSPACE_KALMANFILTER_INC_DEFINE_CONFIG_H_