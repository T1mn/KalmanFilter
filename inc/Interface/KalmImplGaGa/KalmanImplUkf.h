#ifndef __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPLGAGA_KALMANIMPLUKF_H_
#define __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPLGAGA_KALMANIMPLUKF_H_
#include "../KalmImpl.h"

class KalmImplUkf : public KalmImpl
{
public:
    KalmImplUkf(cf_ic &&_init_config) : KalmImpl(std::move(_init_config)) {}
    virtual RC predict() override
    {
    }
    virtual RC update() override
    {
    }
    virtual ~KalmImplUkf() override {}
};
#endif // __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPLGAGA_KALMANIMPLUKF_H_