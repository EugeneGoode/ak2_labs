#include <iostream>
#include <vector>

#include "KeyProcessor.h"



int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv+1, argv + argc);

    lab3::KeyProcessor kp(args);

    std::cout << kp.getUniqueAmount() << '\n';

    for (const auto& i: kp.getUniqueKeys())
    {
        std::cout << i << '\n';
    }


    return 0;
}
