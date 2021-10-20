#ifndef KEYS_H
#define KEYS_H


namespace lab3
{
    enum class keys_form
    {
        VERSION,
        HELP,
        LIST,
        RECURSIVE,
        SORTED,
        DIRECTORY,
        INODE,
        FILE
    };


    const std::unordered_map<char, keys_form> short_keys =
    {
        {'v', keys_form::VERSION},
        {'h', keys_form::HELP},
        {'l', keys_form::LIST},
        {'r', keys_form::RECURSIVE},
        {'s', keys_form::SORTED},
        {'d', keys_form::DIRECTORY},
        {'i', keys_form::INODE},
        {'f', keys_form::FILE},
    };


    const std::unordered_map<std::string, keys_form> long_keys =
    {
        {"version",   keys_form::VERSION},
        {"help",      keys_form::HELP},
        {"list",      keys_form::LIST},
        {"recursive", keys_form::RECURSIVE},
        {"sorted",    keys_form::SORTED},
        {"directory", keys_form::DIRECTORY},
        {"inode",     keys_form::INODE},
        {"file",      keys_form::FILE},
    };
}

#endif //KEYS_H
