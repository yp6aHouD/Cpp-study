#include <iostream>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // if (magazine.size() < ransomNote.size()) return false;
        int j = 0, i = 0;
        int size1 = ransomNote.size(), size2 = magazine.size();;
        while (i < size1)
        {
            while(j < size2)
            {
                if (ransomNote[i] == magazine[j]) 
                {
                    magazine.erase(j,1);
                    j = 0;
                    break;
                }

                j++;
                if (j == size2) return false;
            }
            i++;
        }
        return true;
    }
};

int main()
{
    string ransomNote = "ba", magazine = "b";
    Solution s;

    cout << s.canConstruct(ransomNote, magazine);

    
    return 0;
}
