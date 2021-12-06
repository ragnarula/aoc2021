#pragma once
#include <tuple>
#include <string>
#include <vector>
#include <functional>

#define REGISTER(_DAY, _CLASS) aoc::Register(#_DAY, [](){ return std::make_unique<_CLASS>(); });

namespace aoc
{
    std::unique_ptr<class ISolution> GetSolution(const std::string& day);

    enum class EPart {First, Second};
    std::vector<std::string> GetInputForDay(const std::string& day, EPart part = EPart::First);

    std::tuple<std::string, std::string> GetSolutionForDay(const std::string& day);

    class ISolution
    {
    public:
        virtual ~ISolution() {}
        virtual std::string GetFirst(const std::vector<std::string>& input) = 0;
        virtual std::string GetSecond(const std::vector<std::string>& input) = 0;
    };

    using SolutionSource = std::function<std::unique_ptr<ISolution>(void)>;
    void Register(const std::string& day, SolutionSource source);
}