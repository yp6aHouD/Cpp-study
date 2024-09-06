#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix)
        {
            vector<int> answer;

            int top = 0, left = 0;
            int bottom = matrix.size() - 1;
            int right = matrix[0].size() - 1;

            while (true)
            {
                if (top > bottom) break;
                for(int i = left; i <= right; i++)
                {
                    answer.push_back(matrix[top][i]);
                }
                top++;

                if (right < left) break;
                for (int i = top; i <= bottom; i++)
                {
                    answer.push_back(matrix[i][right]);
                }
                right--;

                if (bottom < top) break;
                for (int i = right; i >= left; i--)
                {
                    answer.push_back(matrix[bottom][i]);
                }
                bottom--;  

                if (left > right) break;
                for (int i = bottom; i >= top; i--)
                {
                    answer.push_back(matrix[i][left]);
                }
                left++;
            }
            return answer;
        }
};

int main()
{
    int matrix[6][4] = {{1,2,3,4}, 
                        {5,6,7,8}, 
                        {9,10,11,12}, 
                        {13,14,15,16}, 
                        {17,18,19,20}, 
                        {21,22,23,24}};
    vector<vector<int>> vecMatrix(6, vector<int>(4));

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            vecMatrix[i][j] = matrix[i][j];
        }
    }

    int matrix2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> vecMatrix2(3, vector<int>(3));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            vecMatrix2[i][j] = matrix2[i][j];
        }
    }

    Solution classObj;
    vector<int> result = classObj.spiralOrder(vecMatrix);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result2 = classObj.spiralOrder(vecMatrix2);

    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}