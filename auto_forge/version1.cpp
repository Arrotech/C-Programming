#include <iostream>
using namespace std;

struct _t
{
    int x;
};

int *foo(int *sum)
{
    _t t;
    t.x = 2;
    *sum = t.x;
    return sum;
}

int main()

{

    int *t = new int;
    t = foo(t);

    printf("%d\t: ", t);
    printf("Hello World");

    return 0;
}