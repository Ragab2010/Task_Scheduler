#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include "Task.h"
#include <vector>
#include <ctime> // Include the ctime library for time-related operations

class TaskScheduler {
public:
    // Function to start the task scheduler
    void Run();

private:
    // Helper functions for task execution, user interaction, and task list display
    void ExecuteTask(const Task& task);
    void GetUserScheduledTask();
    void ShowTaskList();

    std::vector<Task> tasks; // Store a list of scheduled tasks
};

#endif // TASK_SCHEDULER_H
