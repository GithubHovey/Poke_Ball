#ifndef INDICATOR_H
#define INDICATOR_H

#include "module.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus

/* LED资源类型枚举 */
typedef enum {
    LED_TYPE_IO,    /* IO控制类型 */
    LED_TYPE_PWM    /* PWM控制类型 */
} LedResourceType;

/* LED资源结构体 */
typedef struct {
    uint8_t id;                 /* LED ID号 */
    LedResourceType type;       /* LED资源类型 */
} LedResource;

/* 指示器状态结构体 */
typedef struct {
    uint8_t id;         /* 指示器ID */
    bool state;         /* 开关状态 */
    uint8_t brightness; /* 亮度 (0-100) */
} IndicatorState;

class Indicator : public Module {
public:
    /* 构造函数 */
    Indicator();
    
    /* 析构函数 */
    ~Indicator();
    
    /* 初始化函数 - 重写基类 */
    bool Init() override;
    
    /* 模块任务函数 - 重写基类 */
    void ModuleTask() override;
    
    /* 设置灯光状态（开关和亮度合并） */
    void SetLight(uint8_t indicator_id, bool state, uint8_t brightness = 100);
    
    /* LED注册 */
    bool RegisterLed(const LedResource* led_resource);
    
private:
    /* 最大指示器数量 */
    static const uint8_t MAX_INDICATORS = 8;
    
    /* LED注册队列最大数量 */
    static const uint8_t MAX_LED_REGISTRATIONS = 10;
    
    /* 指示器状态数组 */
    IndicatorState indicators_[MAX_INDICATORS];
    
    /* LED注册队列 */
    LedResource led_resources_[MAX_LED_REGISTRATIONS];
    
    /* 已注册的LED数量 */
    uint8_t registered_led_count_;
    
};

#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif

#endif /* INDICATOR_H */