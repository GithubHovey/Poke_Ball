#include "module.h"

#ifdef __cplusplus

Module::Module() : 
    task_handle_(nullptr),
    initialized_(false),
    task_running_(false) {
}

Module::~Module() {
    StopModuleTask();
}

bool Module::StartModuleTask(const char* task_name, uint32_t stack_size, osPriority_t priority) {
    if (task_running_) {
        return true;  // 任务已经在运行
    }
    
    if (!initialized_) {
        return false;  // 模块未初始化
    }
    
    /* 创建任务 */
    osThreadAttr_t task_attributes = {0};
    task_attributes.name = task_name;
    task_attributes.stack_size = stack_size;
    task_attributes.priority = priority;
    
    task_handle_ = osThreadNew(TaskEntry, this, &task_attributes);
    
    if (task_handle_ != nullptr) {
        task_running_ = true;
        return true;
    }
    
    return false;
}

void Module::StopModuleTask(void) {
    if (task_running_ && task_handle_ != nullptr) {
        osThreadTerminate(task_handle_);
        task_handle_ = nullptr;
        task_running_ = false;
    }
}

void Module::TaskEntry(void* argument) {
    Module* module = static_cast<Module*>(argument);
    
    if (module != nullptr) {
        /* 循环执行任务 */
        while (true) {
            module->ModuleTask();
            osDelay(1);  /* 1ms延时，避免任务占用过多CPU */
        }
    }
    
    /* 任务结束 */
    osThreadExit();
}

#endif /* __cplusplus */