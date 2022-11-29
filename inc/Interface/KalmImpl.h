#ifndef __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPL_H_
#define __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPL_H_
#include "Interface/Kalmer.h"

class KalmImpl
{
private:
    /* data */
public:
    KalmImpl(cf_ic &&_init_config){
        e_state_ = Eigen::VectorXf(_init_config.stt_size_);
        e_measu_ = Eigen::VectorXf(_init_config.msu_size_);
        m_F_ = Eigen::MatrixXf();//TODO
        m_H_ = Eigen::MatrixXf();//TODO
        m_P_ = Eigen::MatrixXf(_init_config.stt_size_, _init_config.stt_size_);
        m_Q_ = Eigen::MatrixXf(_init_config.stt_size_, _init_config.stt_size_);
        m_R_ = Eigen::MatrixXf(_init_config.msu_size_, _init_config.msu_size_);
    };
    virtual ~KalmImpl() = default;
    virtual RC predict() = 0;
    virtual RC update() = 0;
protected:
    Eigen::VectorXf e_state_;
    Eigen::VectorXf e_measu_;
    Eigen::MatrixXf m_F_;
    Eigen::MatrixXf m_H_;
    Eigen::MatrixXf m_P_;
    Eigen::MatrixXf m_Q_;
    Eigen::MatrixXf m_R_;
};

#endif // __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPL_H_