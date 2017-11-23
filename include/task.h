#pragma once

#include <string>
#include <list>
#include <ostream>

// \brief Task description structure
class Task {
public:
        std::string name;
        int period;
        int priority;
        int deadline;
        int duration;
};

typedef std::list<Task> TaskList;

std::ostream& operator<<(std::ostream& o, const Task& t);
