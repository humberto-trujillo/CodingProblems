mkdir -p build
gcc -g --std=c99 -Wall -Isrc/ src/boxBlur.c test/test_boxBlur.c -o build/boxBlur.out