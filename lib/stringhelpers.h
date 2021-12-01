#include <vector>
#include <string>

namespace aoc
{
std::vector<std::string> Tokenize(std::string input, std::string delim)
{
    size_t last = 0;
    size_t next = 0;

    std::vector<std::string> results;
    while((next = input.find(delim, last)) != std::string::npos)
    {
        auto len = next - last;
        if(len > 0)
        {
            results.push_back(input.substr(last, next - last));
        }
        last = next + 1;
    }

    if(last != 0 && last < input.size())
    {
        results.push_back(input.substr(last, input.size() - last));
    }
    
    return results;
}
}
