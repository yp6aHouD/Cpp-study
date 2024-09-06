#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        if (board.size() == 0) return false;

        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> rowSet;
            unordered_set<char> colSet;
            unordered_set<char> squareSet;

            for (int j = 0; j < 9; j++)
            {
                // row
                if (board[i][j] != '.')
                {
                    if (rowSet.find(board[i][j]) != rowSet.end()) return false;
                    rowSet.insert(board[i][j]);
                }

                // column
                if (board[j][i] != '.')
                {
                    if (colSet.find(board[j][i]) != colSet.end()) return false;
                    colSet.insert(board[j][i]);
                }

                // square 3x3
                int rowNumber = 3 * (i / 3) + (j / 3);
                int colNumber = 3 * (i % 3) + (j % 3);
                if (board[rowNumber][colNumber] != '.')
                    {
                        if (squareSet.find(board[rowNumber][colNumber]) != squareSet.end())
                            return false;
                        squareSet.insert(board[rowNumber][colNumber]);
                    }
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<char>> board = 
        {
         {'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}
        };

    Solution solution;
    bool answer = solution.isValidSudoku(board);

    cout << "Is this sudoku is valid? Answer: " << answer << endl;
}