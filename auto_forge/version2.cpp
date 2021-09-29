#include <iostream>
using namespace std;

struct _t
{
    int x;
};

float *foo()
{
    _t t;
    t.x = 2;
    float *ptr = (float *)&t.x;
    return ptr;
}

int main()

{

    float *t = foo();
    // std::cout << t << "\t: ";
    // std::cout << "Hello World";
    // printf("%d\t: ", *t);

    return 0;
}