#include "indicator.h"
#include <string.h>

#ifdef __cplusplus

Indicator::Indicator() {
    /* 初始化所有指示器为关闭状态 */
    for (uint8_t i = 0; i < MAX_INDICATORS; i++) {
        indicators_[i] = {i, false, 0};
    }
    
    /* 初始化LED注册队列 */
    registered_led_count_ = 0;
    for (uint8_t i = 0; i < MAX_LED_REGISTRATIONS; i++) {
        led_resources_[i] = {0, LED_TYPE_IO};
    }
}

Indicator::~Indicator() {
    /* 析构函数 */
}

bool Indicator::Init() {
    /* 初始化指示器模块 */
    /* 这里可以添加硬件初始化代码 */
    return true;
}

void Indicator::ModuleTask() {
    /* 指示器模块任务 */
}

void Indicator::SetLight(uint8_t indicator_id, bool state, uint8_t brightness) {
    /* 检查ID有效性 */
    if (indicator_id >= MAX_INDICATORS) {
        return;
    }
    
    /* 限制亮度范围 */
    if (brightness > 100) {
        brightness = 100;
    }
    
    /* 更新状态 */
    indicators_[indicator_id].state = state;
    indicators_[indicator_id].brightness = brightness;
    
    /* 更新硬件 */
    UpdateHardware(indicator_id);
}

bool Indicator::RegisterLed(const LedResource* led_resource) {
    /* 检查参数有效性 */
    if (led_resource == nullptr) {
        return false;
    }
    
    /* 检查是否已达到注册上限 */
    if (registered_led_count_ >= MAX_LED_REGISTRATIONS) {
        return false;
    }
    
    /* 检查指示器ID是否有效 */
    if (led_resource->id >= MAX_INDICATORS) {
        return false;
    }
    
    /* 检查是否已经注册过该ID */
    for (uint8_t i = 0; i < registered_led_count_; i++) {
        if (led_resources_[i].id == led_resource->id) {
            return false;  /* ID已存在 */
        }
    }
    
    /* 注册新的LED资源 */
    led_resources_[registered_led_count_] = *led_resource;
    registered_led_count_++;
    
    return true;
}

#endif /* __cplusplus */