#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reverseInParentheses.h"


int main(int argc, char const *argv[])
{
    char * test = malloc(strlen("foo(bar(baz))blim") + 8);
    strcpy(test, "foo(bar(baz))blim");
    reverseInParentheses(test);
    return 0;
}
