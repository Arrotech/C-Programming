#include <iostream>
#include <memory>

struct AllcoationMetrics
{

    //initialize allocated memory
    uint64_t TotalAllocatedMemory = 0;

    //initialize freed memory
    uint64_t TotalFreedMemory = 0;

    //calculate memory usage
    uint32_t Usage()
    {
        return TotalAllocatedMemory - TotalFreedMemory;
    }
};

static AllcoationMetrics s_AllcoationMetrics;

//override the new operator
//do not use the new operator that is in standard library
//its good to allocate memory here, thats the point of this
//purpose of this method is to return a void pointer/memory address
void *operator new(size_t size)
{

    s_AllcoationMetrics.TotalAllocatedMemory += size;

    // std::cout << "Allocating " << size << " bytes\n";
    //allocate appropriate amount of memory and return a pointer to that memory
    return malloc(size);
}

// delete memory
void operator delete(void *memory, size_t size)
{
    s_AllcoationMetrics.TotalFreedMemory += size;
    // std::cout << "Freeing " << size << " bytes\n";
    return free(memory);
}

struct _t
{
    int x;
};

_t *foo()
{
    _t t;
    t.x = 100;
    _t *ptr = (_t *)&t.x;
    return ptr;
}

static void ShowUsage()
{
    std::cout << "Memory usage " << s_AllcoationMetrics.Usage() << " bytes\n";
}

int main()
{

    //stack allocation
    // Object obj;

    //heap allocation
    //new keyword will run through the void function
    ShowUsage(); // 0 bytes
    _t *obj = new _t;
    ShowUsage(); // 4 bytes (int)
    // {
    //     //unique pointer
    //     std::unique_ptr<_t> obj = std::make_unique<_t>();
    //     ShowUsage();
    // }
    _t *t = foo();
    ShowUsage();
    printf("\n%d\t: ", t->x);
    printf("Hello World\n");
    // std::cout << t << std::endl;
    ShowUsage();
    delete t;
    ShowUsage();

    return 0;
}