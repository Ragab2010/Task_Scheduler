#include "TaskScheduler.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

void TaskScheduler::Run() {
    while (true) {
        std::cout << "Task Scheduler" << std::endl;
        std::cout << "1. Schedule a task" << std::endl;
        std::cout << "2. Show task list" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 3) {
            break;
        }

        switch (choice) {
            case 1:
                GetUserScheduledTask();
                break;
            case 2:
                ShowTaskList();
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }
}

void TaskScheduler::ExecuteTask(const Task& task) {
    // Convert the task execution time to a time_t value for formatting
    std::time_t executionTime = std::chrono::system_clock::to_time_t(task.GetExecutionTime());
    // Display task execution details
    std::cout << "Executing task: " << task.GetName() << " at " << std::put_time(std::localtime(&executionTime), "%F %T") << std::endl;
}

void TaskScheduler::GetUserScheduledTask() {
    std::string taskName;
    std::cout << "Enter task name:";
    std::getline(std::cin, taskName);
        // Clear the newline character from the buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int choice;
    std::cout << "1. Schedule at a specific time" << std::endl;
    std::cout << "2. Schedule with an interval" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
        std::time_t scheduledTime;
        std::cout << "Enter scheduled time (UNIX timestamp): ";
        std::cin >> scheduledTime;
        tasks.emplace_back(taskName, std::chrono::system_clock::from_time_t(scheduledTime), std::chrono::seconds(0));
    } else if (choice == 2) {
        int intervalSeconds;
        std::cout << "Enter interval in seconds: ";
        std::cin >> intervalSeconds;
        tasks.emplace_back(taskName, std::chrono::system_clock::now() + std::chrono::seconds(intervalSeconds), std::chrono::seconds(intervalSeconds));
    }
}

void TaskScheduler::ShowTaskList() {
    std::cout << "Scheduled Tasks:" << std::endl;

    if (tasks.empty()) {
        std::cout << "No tasks scheduled." << std::endl;
        return;
    }

    int index = 1;
    for (const auto& task : tasks) {
        // Convert the task execution time to a time_t value for formatting
        std::time_t executionTime = std::chrono::system_clock::to_time_t(task.GetExecutionTime());
        // Display task details with formatted execution time
        std::cout << "[" << index << "] " << task.GetName() << " - Execution Time: " << std::put_time(std::localtime(&executionTime), "%F %T") << std::endl;
        ++index;
    }
}
