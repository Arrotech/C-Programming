#include <iostream>
#include <memory>

struct AllcoationMetrics
{

    //initialize allocated memory
    uint32_t TotalAllocatedMemory = 0;

    //initialize freed memory
    uint32_t TotalFreedMemory = 0;

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
    free(memory);
}

struct Object
{
    int x, y, z;
    std::string name;
};

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
    ShowUsage();
    Object* obj = new Object;
    ShowUsage();
    {
        //unique pointer
        std::unique_ptr<Object> obj = std::make_unique<Object>();
        ShowUsage();
    }
    ShowUsage();
}