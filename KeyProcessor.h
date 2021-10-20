#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

#include "Keys.h"


namespace lab3
{
    using args_t = std::vector<std::string>;

    class KeyProcessor
    {
    public:
        explicit KeyProcessor(const args_t& args = args_t());

        void setArgs(const args_t& args);
        [[nodiscard]] size_t getUniqueAmount() const;
        [[nodiscard]] args_t getUniqueKeys() const;

    private:
        args_t args_;
        std::set<keys_form> unique_keys_;

        void process();
    };
}


#endif //PROCESSOR_H
