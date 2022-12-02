#ifndef __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPL_H_
#define __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPL_H_
#include "Interface/Kalmer.h"

class KalmImpl
{
private:
    /* data */
public:
    KalmImpl(cf_ic &&_init_config) : sp_state_(std::make_shared<kalman_matrix_state_t>(_init_config)),
                                     sp_confg_(std::make_shared<matrix_size_config__t>(_init_config)){};
    virtual ~KalmImpl() = default;
    virtual RC predict() = 0;
    virtual RC update() = 0;
    RC set_measu(Eigen::VectorXf &&_measu) { 
        // TODO: check size
        if(_measu.size() != sp_confg_->msu_size_)
        {
            printf("KalmImpl::set_measu check error\n");
            return RC::RETURN_ERROR;
        }
        sp_state_->v_measu_ = _measu;
        return RC::RETURN_OK;
    };
    RC set_P(Eigen::MatrixXf &&_P){
        sp_state_->m_P_ = _P;
    }
    RC set_Q(Eigen::MatrixXf &&_Q)
    {
        sp_state_->m_Q_ = _Q;
    }
    RC set_R(Eigen::MatrixXf &&_R)
    {
        sp_state_->m_R_ = _R;
    }
    RC set_F(Eigen::MatrixXf &&_F)
    {
        sp_state_->m_F_ = _F;
    }

protected:
    using kalman_matrix_state_t = km_s;
    using matrix_size_config__t = cf_ic;
    std::shared_ptr<kalman_matrix_state_t> sp_state_;
    std::shared_ptr<matrix_size_config__t> sp_confg_;
};

#endif // __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPL_H_