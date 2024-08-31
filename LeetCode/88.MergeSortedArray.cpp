#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // if there's nothing in second vector
        if (0 == n) return;

        // if there's nothing in first vector
        else if (0 == m)
        {
            nums1 = nums2;
            return;
        }

        else
        {
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;

            while (i >= 0 && j >= 0)
            {
                nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
            }

            while (j >= 0)
            {
                nums1[k--] = nums2[j--]; 
            }
        }
    }
};

int main()
{
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};
    
    Solution().merge(nums1, 1, nums2, 1);
    for (int num : nums1)
    {
        cout << num << " ";
    }

    cout << endl;

    vector<int> nums3 = {2, 2, 2, 0, 0, 0, 0};
    vector<int> nums4 = {2, 2, 2, 2};
    
    Solution().merge(nums3, 3, nums4, 4);
    for (int num : nums3)
    {
        cout << num << " ";
    }

    cout << endl;

    vector<int> nums5 = {1, 4, 8};
    vector<int> nums6 = {};
    
    Solution().merge(nums5, 3, nums6, 0);
    for (int num : nums5)
    {
        cout << num << " ";
    }

    cout << endl;

    vector<int> nums7 = {1, 2, 3, 0, 0, 0};
    vector<int> nums8 = {2, 5, 6};
    
    Solution().merge(nums7, 3, nums8, 3);
    for (int num : nums5)
    {
        cout << num << " ";
    }
    return 0;
}