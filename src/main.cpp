#include <iostream>

#include "reader.h"

int main(int argc, char *argv[])
{
        if (argc < 2) {
                std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
                return -1;
        }

        auto lst = readTasks(argv[1]);

        for (auto task : lst) {
                std::cout << task << std::endl;
        }

        return 0;
}
