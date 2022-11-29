#ifndef __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPLGAGA_KALMANIMPLKF_H_
#define __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPLGAGA_KALMANIMPLKF_H_
#include "../KalmImpl.h"

class KalmImplKf : public KalmImpl
{
    KalmImplKf(cf_ic &&_init_config):KalmImpl(std::move(_init_config)){}
    virtual RC predict(){
        
    }
    virtual ~KalmImplKf() override{}
    
};
#endif // __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPLGAGA_KALMANIMPLKF_H_