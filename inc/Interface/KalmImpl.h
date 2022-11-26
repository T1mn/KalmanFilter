#ifndef __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPL_H_
#define __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPL_H_
#include "Interface/Kalmer.h"

class KalmImpl
{
private:
    /* data */
public:
    KalmImpl(/* args */);
    ~KalmImpl();
    RC init();
    RC predict(cf_ic &&);
    RC update();

};

KalmImpl::KalmImpl(/* args */)
{
}

KalmImpl::~KalmImpl()
{
}


#endif // __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMIMPL_H_