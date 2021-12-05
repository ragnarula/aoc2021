#include "day4/day4.h"
#include "stringhelpers.h"
#include <optional>
#include <algorithm>

namespace day4
{
    std::vector<Board> GetBoards(const std::vector<std::string>& input) 
    {
        std::vector<Board> boards;
        Board board;
        for(int i = 2; i < input.size(); ++i)
        {
            const auto line = input[i];
            if(line == "")
            {
                boards.push_back(std::move(board));
                board = Board();
                continue;
            }
            const auto row = aoc::Tokenize(line, " ");
            board.push_back(std::move(row));
        }

        boards.push_back(board);
        return boards;
    }
    
    std::vector<int> GetNumbers(const std::vector<std::string>& input) 
    {
        return {};
    }
    
    void Mark(Board& board, std::string number) 
    {
        for(auto& row : board)
        {
            for(auto& item : row)
            {
                if(item == number)
                {
                    item = "X";
                }
            }
        }
    }
    
    Line GetRow(const Board& board, int row) 
    {
        return board[row];
    }
    
    Line GetCol(const Board& board, int col) 
    {
        Line line;
        for(auto& row : board)
        {
            line.push_back(row[col]);
        }

        return line;
    }
    
    bool IsWinner(const Board& board) 
    {
        for(auto& row : board)
        {
            if(std::count_if(row.begin(), row.end(), [](const auto& elem){ return elem == "X";}) == row.size())
            {
                return true;
            }
        }

        const auto cols = board[0].size();
        for(int i = 0; i < cols; ++i)
        {
            auto col = GetCol(board, i);
            if(std::count_if(col.begin(), col.end(), [](const auto& elem){ return elem == "X";}) == col.size())
            {
                return true;
            }
        }

        return false;
    }
    
    int Score(const Board& board) 
    {
        int sum = 0;
        for(auto& row : board)
        {
            for(auto& item : row)
            {
                if(item != "X")
                {
                    sum += std::stoi(item);
                }
            }
        }
        return sum;
    }

    std::string Solution::GetFirst(const std::vector<std::string>& input) 
    {
        if(input.size() == 0)
        {
            return "";
        }

        const auto numbers = aoc::Tokenize(input[0], ",");
        
        auto boards = GetBoards(input);

        for(auto& number : numbers)
        {
            for(auto& board : boards)
            {
                Mark(board, number);
                if(IsWinner(board))
                {
                    int sum = Score(board);
                    int score = sum * std::stoi(number);
                    return std::to_string(score);
                }
            }
        }

        return "";
    }
    
    std::string Solution::GetSecond(const std::vector<std::string>& input) 
    {
        if(input.size() == 0)
        {
            return "";
        }

        const auto numbers = aoc::Tokenize(input[0], ",");
        
        auto boards = GetBoards(input);

        int lastWinner = -1;
        for(auto& number : numbers)
        {
            for(int i = 0; i < boards.size(); ++i)
            {
                auto& board = boards[i];
                const bool wasWinner = IsWinner(board);
                Mark(board, number);
                const bool isWinner = IsWinner(board);
                if(wasWinner == false && isWinner)
                {
                    lastWinner = i;
                }
            }
        }

        boards = GetBoards(input);
        for(auto& number : numbers)
        {
            for(int i = 0; i < boards.size(); ++i)
            {
                auto& board = boards[i];
                Mark(board, number);
                if(i == lastWinner && IsWinner(board))
                {
                    int sum = Score(board);
                    int score = sum * std::stoi(number);
                    return std::to_string(score);
                }
            }
        }

        return "";
    }
}