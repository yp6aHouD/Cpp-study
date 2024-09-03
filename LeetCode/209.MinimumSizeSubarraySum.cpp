#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int minSubArrayLen(int target, vector<int>& nums)
        {
            if (nums.size() == 0 || target == 0) return 0;    

            int left = 0, right = 0, sum = 0;
            int answer = 0;

            while (right != nums.size())
            {
                sum += nums[right];
                if (sum < target)
                {
                    right++;
                    continue;
                }
                else if (sum >= target)
                {
                    if (right - left == 0) return 1;
                    if (answer == 0)
                    {
                        answer = right - left + 1;
                    }
                    else answer = answer < right - left + 1 ?
                        answer : right - left + 1;

                    sum -= nums[left] + nums[right];
                    left++;
                }
            }

            return answer;
        }
};

int main()
{
    int target = 15, answer;
    vector<int> nums = {1,2,3,4,5};

    answer = Solution().minSubArrayLen(target, nums);

    cout << "Minimal length of a subarray which sum is equal or greater than "
        << target << " is " << answer << endl;
        
    return 0;
}