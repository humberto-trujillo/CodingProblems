#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

void printlist(int n)
{
    if(n>0)
    {
        printlist(n-1);
        printf("%d\n",n);
    }
}

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code!"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    printlist(5);

}