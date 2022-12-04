#include "Interface/Kalmer.h"
#include "Interface/KalmImpl.h"
#include "Interface/KalmImplGaGa/KalmanImplKf.h"
#include "Interface/KalmImplGaGa/KalmanImplUkf.h"

RC Kalmer::init(cf_ic && _init_config)
{
   if (_init_config.kal_type_ == kalman_types::NORMAL_KF_)
   {
       sp_kalman_impl_ = std::make_shared<KalmImplKf>();
       return RC::RETURN_OK;
   }
   if (_init_config.kal_type_ == kalman_types::UNSCENTED_KF_)
   {
       sp_kalman_impl_ = std::make_shared<KalmImplUkf>();
       return RC::RETURN_OK;
   }
   
   printf("%s unknown error\n", __FUNCTION__);
   return RC::RETURN_ERROR;
}

RC Kalmer::predict()
{
   return sp_kalman_impl_->predict();
}

RC Kalmer::update()
{
   return sp_kalman_impl_->update();
}
