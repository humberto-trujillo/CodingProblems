mkdir -p build
gcc -g --std=c99 -Wall -Isrc/ src/reverseInParentheses.c test/test_reverseInParentheses.c -o build/reverseInParentheses.out