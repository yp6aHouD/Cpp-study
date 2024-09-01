#include <iostream>
#include <cctype>

using namespace std;

class Solution
{
    public:
        bool isPalindrome(string s)
        {
            if (s.length() == 0) return true;
            char *ptr1 = &s[0], *ptr2 = &s[s.length() - 1];

            while (ptr1 < ptr2)
            {
                while (ptr1 < ptr2 && !isalnum(*ptr1)) ptr1++;
                while (ptr1 < ptr2 && !isalnum(*ptr2)) ptr2--;

                if (tolower(*ptr1) == tolower(*ptr2))
                {
                    ptr1++; ptr2--;
                }

                else return false;
            }

            return true;
        }
};

int main()
{
    string str1 = "A man, a plan, a canal: Panama";
    cout << "Is string \"" << str1 << "\" a palindrome? Answer = " << Solution().isPalindrome(str1) << endl;

    string str2 = "race a car";
    cout << "Is string \"" << str2 << "\" a palindrome? Answer = " << Solution().isPalindrome(str2) << endl;

    return 0;
}

