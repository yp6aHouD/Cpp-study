#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty() || (s.empty() && t.empty())) return true;
        if (t.empty()) return false;
        
        char *ptr1 = &s[0], *ptr2 = &t[0];

        while (*ptr1 != '\0' && *ptr2 != '\0')
        {
            if (*ptr1 == *ptr2) {ptr1++; ptr2++;}
            else ptr2++;
        }
        if (*ptr1 == '\0') return true;
        else return false;
    }
};


int main()
{
    string str1 = "axc";
    string str2 = "ahbgdc";

    cout << "is \"" << str1 << "\" a subsequence of \"" << str2 
        << "\"? Answer: " << Solution().isSubsequence(str1, str2) << endl;

    string str3 = "abc";
    string str4 = "ahbgdc";

    cout << "is \"" << str3 << "\" a subsequence of \"" << str4 
        << "\"? Answer: " << Solution().isSubsequence(str3, str4) << endl;
    return 0;
}