#ifndef __WORKSPACE_KALMANFILTER_INC_DEFINE_BASIC_TYPE_H_
#define __WORKSPACE_KALMANFILTER_INC_DEFINE_BASIC_TYPE_H_
typedef unsigned char uint8_t; // 无符号8位数

typedef signed char int8_t; // 有符号8位数

typedef unsigned int uint16_t; // 无符号16位数

typedef signed int int16_t; // 有符号16位数

typedef unsigned long uint32_t; // 无符号32位数

typedef signed long int32_t; // 有符号32位数

typedef float float32_t; // 单精度浮点数

typedef double float64_t; // 双精度浮点数

enum return_code
{
    RETURN_OK = 0,
    RETURN_ERROR = 1
};

#endif // __WORKSPACE_KALMANFILTER_INC_DEFINE_BASIC_TYPE_H_