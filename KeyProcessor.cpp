#include "KeyProcessor.h"



namespace lab3
{
    KeyProcessor::KeyProcessor(const args_t& args)
            : args_(args)
    {
        if (!args.empty())
        {
            process();
        }
    }


    void KeyProcessor::setArgs(const args_t& args)
    {
        args_ = args;
        process();
    }


    void KeyProcessor::process()
    {
        for (const auto& token: args_)
        {
            if(token.substr(0, 2) == "--")
            {
                const std::string& long_key = token.substr(2);
                if (long_keys.find(long_key) != long_keys.cend())
                {
                    unique_keys_.emplace(long_keys.at(long_key));
                }
                else
                {
                    std::cout << "Unknown key: " << long_key << '\n';
                }
            }
            else
            {
                for (const auto& short_key: token.substr(1))
                {
                    if (short_keys.find(short_key) != short_keys.cend())
                    {
                        unique_keys_.emplace(short_keys.at(short_key));
                    }
                    else
                    {
                        std::cout << "Unknown key: " << short_key << '\n';
                    }
                }
            }
        }
    }


    size_t KeyProcessor::getUniqueAmount() const
    {
        return unique_keys_.size();
    }


    args_t KeyProcessor::getUniqueKeys() const
    {
        args_t unique_keys;

        for (auto unique_key: unique_keys_)
        {
            for (const auto& [key, value]: long_keys)
            {
                if (unique_key == value)
                {
                    unique_keys.push_back(key);
                }
            }
        }

        return unique_keys;
    }
}
