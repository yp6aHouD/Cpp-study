#include <iostream>
#include <list>

using namespace std;

struct phoneBook
{
    char Name[20];
    char Tel[12];
    char Addr[50];
};

int main()
{
    phoneBook myContact; // создание собственной структуры

    list<string> myList;
    myList.push_back("one");
    myList.push_back("two");
    myList.push_back("three");
    
    for (string value : myList)
    {
        cout << value << " ";
    }
    return 0;
}