#ifndef __MODULE_BASE_H
#define __MODULE_BASE_H

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus

class Module {
public:
    /* 构造函数 */
    Module();
    
    /* 析构函数 */
    virtual ~Module();
    
    /* 初始化函数 - 纯虚函数，子类必须实现 */
    virtual bool Init() = 0;
    
    /* 模块任务函数 - 纯虚函数，子类必须实现 */
    virtual void ModuleTask() = 0;
    
    /* 启动模块任务 */
    bool StartModuleTask(const char* task_name, uint32_t stack_size = 256, osPriority_t priority = osPriorityNormal);
    
    /* 停止模块任务 */
    void StopModuleTask(void);
    
    /* 获取模块状态 */
    bool IsInitialized(void) const { return initialized_; }
    bool IsTaskRunning(void) const { return task_running_; }
    
protected:
    /* 任务句柄 */
    osThreadId_t task_handle_;
    
    /* 状态标志 */
    bool initialized_;
    bool task_running_;
    
private:
    /* 任务入口函数 - 静态函数，适配FreeRTOS */
    static void TaskEntry(void* argument);
};

#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif

#endif /* __MODULE_BASE_H */