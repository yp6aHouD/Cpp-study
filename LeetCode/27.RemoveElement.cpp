#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int removeElement(vector<int>& nums, int val)
        {
            int index = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] != val)
                {
                    nums[index] = nums[i];
                    index++;
                }
            }
            return index;
        }
};

int main()
{
    int val = 3;

    vector<int> vec = {3, 2, 2, 3}; 
    cout << "numbers not like val (" << val << ") = " 
        << Solution().removeElement(vec, val) << endl;
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}