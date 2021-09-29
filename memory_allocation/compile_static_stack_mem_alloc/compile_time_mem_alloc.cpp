#include <iostream>

// occupies memory at compile tile
// global scope allocation
int x;

void foo()
{

    // ocuupies memory at compile time
    // static allocation
    static int y = 10;

    y = y + 1;
    printf("%d\n", y);
}

int main()
{
    // occupies memory at compile time
    // automatic allocation/stack allocation
    int z;

    z = 5;

    printf("%d\n", z);

    foo();

    return 0;
}