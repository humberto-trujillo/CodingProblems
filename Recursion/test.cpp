#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

/*
It's called tail recursion when no other instructions follow
after the call of the recursive function.
*/
void tail_recursion(int n)
{
    if(n>0)
    {
        printf("%d\n",n);
        tail_recursion(n-1);
    }
}

/*
It's called head recursion when no other instructions occur
before the call of the recursive function.
*/
void head_recursion(int n)
{
    if(n>0)
    {
        head_recursion(n-1);
        printf("%d\n",n);
    }
}

/*
Declaring a variable or fucntion as static means that such variable will only
be accesible in the source file it was declared in.
Static variables are stored in the code section of memory and they act as global varibles.
When declaring a static variable inside a function, the scope is limited to the function only.
Useful when we need to preserve the value of a variable between function calls.
*/
int static_recursion(int n)
{
    static int x = 0;
    if (n>0)
    {
        x++;
        return static_recursion(n-1) + n;
    }
    return 0;
}

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code!"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    printf("Head recursion.\n");
    head_recursion(5);
    printf("Tail recursion.\n");
    tail_recursion(5);
    printf("Recursion with static variable. %d\n", static_recursion(5));
}