/*
Write a function that reverses characters in (possibly nested) parentheses in the input string.

Input strings will always be well-formed with matching ()s.

Example

For inputString = "(bar)", the output should be
reverseInParentheses(inputString) = "rab";
For inputString = "foo(bar)baz", the output should be
reverseInParentheses(inputString) = "foorabbaz";
For inputString = "foo(bar)baz(blim)", the output should be
reverseInParentheses(inputString) = "foorabbazmilb";
For inputString = "foo(bar(baz))blim", the output should be
reverseInParentheses(inputString) = "foobazrabblim".
Because "foo(bar(baz))blim" becomes "foo(barzab)blim" and then "foobazrabblim".
Input/Output

[execution time limit] 0.5 seconds (c)

[input] string inputString

A string consisting of lowercase English letters and the characters ( and ). It is guaranteed that all parentheses in inputString form a regular bracket sequence.

Guaranteed constraints:
0 ≤ inputString.length ≤ 50.

[output] string

Return inputString, with all the characters that were in parentheses reversed.
*/

#include "reverseInParentheses.h"
#include <stdio.h>
#include <string.h>

char * reverseAt(char * inputString, int a, int b)
{
    while(a<b)
    {
        char temp = inputString[a];
        inputString[a++] = inputString[b];
        inputString[b--] = temp;
    }
    return inputString;
}

char * removeParenthesesAt(char * inputString, int a, int b)
{
    char result[50];
    int pos = 0;
    for(int i = 0; i < strlen(inputString); i++)
    {
        if(i != a && i !=b)
        {
            result[pos++] = inputString[i];
        }
    }
    result[pos] = '\0';
    strcpy(inputString, result);
    return inputString;
}

char * reverseInParentheses(char * inputString)
{
    int pos[50];
    int index = 0;
    for(int i=0; i<strlen(inputString); i++)
    {
        if(inputString[i] == '(')
        {
            pos[index++] = i+1;
        }
        else if(inputString[i] == ')')
        {
            int start = pos[--index];
            reverseAt(inputString, start, i-1);
            removeParenthesesAt(inputString, start-1, i);
            i-=2;
        }
    }
    return inputString;
}
