#pragma once

#include <string>
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

std::ostream& operator<<(std::ostream& o, const Task& t);
