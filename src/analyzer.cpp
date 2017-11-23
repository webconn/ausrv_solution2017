#include "analyzer.h"

#include <map>
#include <string>

using namespace std;

// Performs inteer division with ceiling
int idiv_ceil(int num, int denom)
{
        return num / denom + (((num < 0) ^ (denom > 0)) && (num % denom));
}

// Checks schedulability of given tasks list
// Returns nullptr if list is schedulable
// or pointer to the highest priority task which breaks everything

Task* checkSchedulability(TaskList tasks)
{
        // Return value is a non-schedulable task with the highest priority
        Task *ret = nullptr;

        for (auto &task : tasks) {
                int responce_time = task.duration;
                int prev_responce_time = 0;

                // Calculate responce time
                while (responce_time > prev_responce_time && responce_time < task.period) {
                        prev_responce_time = responce_time;

                        // calculate substep
                        responce_time = task.duration;
                        for (auto &o_task : tasks) {
                                if (o_task.priority > task.priority) {
                                        responce_time += idiv_ceil(prev_responce_time, o_task.period) * o_task.duration;
                                }
                        }
                }

                // Check responce time
                if (responce_time > task.deadline) {
                        // check if this task has higher priority than a previous one
                        if (!ret || ret->priority < task.priority) {
                                ret = &task;
                        }
                }
        }

        return ret;
}
