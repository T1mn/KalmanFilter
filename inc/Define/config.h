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

typedef struct kalm_state_st{
    Eigen::VectorXf v_state_;
    Eigen::VectorXf v_measu_;
    Eigen::MatrixXf m_F_;
    Eigen::MatrixXf m_H_;
    Eigen::MatrixXf m_P_;
    Eigen::MatrixXf m_Q_;
    Eigen::MatrixXf m_R_;
    Eigen::MatrixXf m_K_;
    kalm_state_st(cf_ic &&_ic) : v_state_(_ic.stt_size_), v_measu_(_ic.msu_size_),
                                 m_H_(_ic.msu_size_, _ic.stt_size_), m_P_(_ic.stt_size_, _ic.stt_size_),
                                 m_Q_(_ic.stt_size_, _ic.stt_size_), m_R_(_ic.msu_size_, _ic.msu_size_),
                                 m_K_(_ic.stt_size_, _ic.msu_size_) {}
} km_s;

#endif // __WORKSPACE_KALMANFILTER_INC_DEFINE_CONFIG_H_