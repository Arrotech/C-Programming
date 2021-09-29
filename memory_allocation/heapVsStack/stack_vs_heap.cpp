#include <iostream>
#include <string>

stuct Object()
{
    float x, y, z;
    Object()
        : x(5), y(6), z(7) {}
};

int main()
{

    // stack memory allocation
    //with stack, once the scope ends all the memory gets freed/poped off
    int s_x = 5;
    int s_array[5];
    Object s_obj;

    // heap memory allocation
    // with new operator you have to manually free memory ourseleves
    // allocate with heap if you need the lifetime of the scope to be longer (out of scope)
    // also allcate when you need store more data
    int *h_x = new int;
    *h_x = 10;
    int *h_array = new int[5];
    Object *h_obj = new Object;

    // with new operator you have to manually free memory ourseleves
    delete hx;
    delete h_array;
    delete h_obj;

    // with smart pointers you do no need to delete memory yourself
}