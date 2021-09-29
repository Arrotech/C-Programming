#include <iostream>

struct Alloc
{
    uint32_t allocate_memory = 0;
    uint32_t freed_memory = 0;
    uint32_t Usage()
    {
        return allocate_memory - freed_memory;
    };
};

static Alloc s_Alloc;

void *operator new(size_t size)
{
    s_Alloc.allocate_memory += size;
    return malloc(size);
};

// void operator delete(void *memory, size_t size)
// {
//     s_Alloc.freed_memory += size;
//     free(memory);
// };

static void ShowMemoryUsage()
{
    std::cout << "Memory usage: " << s_Alloc.Usage() << " bytes\n";
};

struct _t
{
    int x;
};

int *foo()
{
    _t t;
    t.x = 100;
    int *ptr = &t.x;
    *ptr = t.x;
    std::cout << "\nAddress " << t.x << "\n";
    return ptr;
};

int main()
{

    ShowMemoryUsage();
    int *y;
    ShowMemoryUsage();
    y = foo();
    ShowMemoryUsage();
    std::cout << "\nAddress " << y << "\n";
    // ShowMemoryUsage();
    std::cout << "\nValue " << *y << "\n";
    // ShowMemoryUsage();
};
