#include <iostream>

#include "reader.h"
#include "analyzer.h"

int main(int argc, char *argv[])
{
        if (argc < 2) {
                std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
                return -1;
        }

        auto lst = readTasks(argv[1]);

        // debugging output
        /* for (auto task : lst) { */
                /* std::cout << task << std::endl; */
        /* } */

        // check schedulability
        auto badTask = checkSchedulability(lst);
        if (!badTask) {
                std::cout << "YES" << std::endl;
                return 0;
        } else {
                std::cout << "NO" << std::endl << badTask->name << std::endl;
                return 1;
        }

        return 0;
}
