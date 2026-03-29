#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    int* p = new int(5);
    std::cout << *p << "\n";
    delete p;

    int* arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        *(arr+i) = i;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << *(arr+i) << "\n";
    }

    delete [] arr;
}


