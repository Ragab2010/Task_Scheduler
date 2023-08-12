#include "Task.h"

// Constructor implementation
Task::Task(const std::string& name, const std::chrono::system_clock::time_point& executionTime, const std::chrono::seconds& interval)
    : name(name), executionTime(executionTime), interval(interval) {}

// Getter function implementations
std::string Task::GetName() const {
    return name;
}

std::chrono::system_clock::time_point Task::GetExecutionTime() const {
    return executionTime;
}

std::chrono::seconds Task::GetInterval() const {
    return interval;
}
