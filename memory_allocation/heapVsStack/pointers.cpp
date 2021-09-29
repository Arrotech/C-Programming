#include <iostream>

int main(){
    //pointer is integer that holds the address of an object where you can read and write from memory
    // allocate data on the stack
    int x = 10;
    int* ptr = &x;
    *ptr = x;

    std::cout << "Address " << ptr;
    std::cout << "\nValue " << *ptr;
    std::cout << "\nNew Value " << x;

    //allocate data on the heap
    char* buffer = new char[8];
    memset(buffer, 0, 8);

    char** ptr2 = &buffer;

    delete[] buffer;
}

