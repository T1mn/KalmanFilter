#ifndef __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMER_H_
#define __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMER_H_
#include "Eigen/Core"
#include "Define/basic_type.h"
#include "Define/config.h"
#include <memory>

class KalmImpl;

class KalmImplKf;

class KalmImplUkf;

class Kalmer
{
private:
    /* data */
public:
    Kalmer(/* args */);
    ~Kalmer();
    RC init(cf_ic &&);
    RC predict();
    RC update();
private:
    std::shared_ptr<KalmImpl> sp_kalman_impl_;
};

Kalmer::Kalmer(/* args */)
{
}

Kalmer::~Kalmer()
{
}

#endif // __WORKSPACE_KALMANFILTER_INC_INTERFACE_KALMER_H_