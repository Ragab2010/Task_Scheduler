#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono> // Include the chrono library for time-related functionality

class Task {
public:
    // Constructor to initialize the task with its name, execution time, and interval
    Task(const std::string& name, const std::chrono::system_clock::time_point& executionTime, const std::chrono::seconds& interval);

    // Getter functions for retrieving task attributes
    std::string GetName() const;
    std::chrono::system_clock::time_point GetExecutionTime() const;
    std::chrono::seconds GetInterval() const;

private:
    std::string name; // Name of the task
    std::chrono::system_clock::time_point executionTime; // Time when the task is scheduled to execute
    std::chrono::seconds interval; // Interval for recurring tasks (if applicable)
};

#endif // TASK_H
