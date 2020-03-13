mkdir -p build
gcc -g --std=c99 -Wall -Isrc/ src/avoidObstacles.c test/test_avoidObstacles.c -o build/avoidObstacles.out