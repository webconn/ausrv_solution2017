#pragma once

#include "task.h"

// Returns nullptr if tasklist is schedulable
// or pointer to task which breaks everything
Task* checkSchedulability(TaskList tasks);
