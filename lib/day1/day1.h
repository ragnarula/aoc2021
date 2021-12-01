
namespace day1
{
    int CountIncreases(const std::vector<int>& input)
    {
        int increases = 0;

        for(int i = 0; i < input.size(); ++i)
        {
            if(i > 0)
            {
                if(input[i] > input[i - 1])
                {
                    ++increases;
                }
            }
        }

        return increases;
    }
}