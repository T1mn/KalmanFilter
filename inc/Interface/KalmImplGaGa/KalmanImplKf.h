#ifndef __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPLGAGA_KALMANIMPLKF_H_
#define __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPLGAGA_KALMANIMPLKF_H_
#include "../KalmImpl.h"

class KalmImplKf : public KalmImpl
{
    KalmImplKf(cf_ic &&_init_config) : KalmImpl(std::move(_init_config)) {}
    virtual RC predict()
    {
        auto s = sp_state_;
        s->v_state_ = s->m_F_ * s->v_state_;
        s->m_P_ = s->m_F_ * s->v_state_ * s->m_F_.transpose() + s->m_Q_;
    }
    virtual RC update()
    {
        auto s = sp_state_;
        s->m_K_ = s->m_P_ * s->m_H_.transpose() * ((s->m_H_ * s->m_P_ * s->m_H_.transpose() + s->m_R_).inverse());
        s->v_state_ = s->v_state_ + s->m_K_ * (s->v_measu_ - s->m_H_ * s->v_state_);
        s->m_P_ = s->m_P_ - s->m_K_ * s->m_H_ * s->m_P_;
    }
    virtual ~KalmImplKf() override{}
};
#endif // __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPLGAGA_KALMANIMPLKF_H_