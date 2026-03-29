#include <iostream>

class IntArray {
private:
    int* data = nullptr;
    int size = 0;

public:
    IntArray(int size) {
        this->size = size;
        data = new int[size];
    };
    ~IntArray() {
        delete [] data;
    };

    // запрет копирования (пока)
    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            return; 
        }
        *(data + index) = value;
    };
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        return *(data + index);
    };
    void print() {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << "\t";
        }
    };
    void resize(int new_size) {
        int* tmp = new int[new_size];
        int min_size = (new_size < size) ? new_size : size;
        for (int i = 0; i < min_size; ++i) {
            tmp[i] = data[i];
        }
        for (int i = min_size; i < new_size; ++i) {
            tmp[i] = 0;
        }
        delete[] data;
        data = tmp;
        size = new_size;
    };
};

int main()
{
    std::cout << "Hello World!\n";
    IntArray a1(2);
    a1.set(0, 1);
    a1.set(1, 2);
    std::cout << a1.get(0) << "\n";
    std::cout << a1.get(1) << "\n";
    std::cout << "First output:" << std::endl;
    a1.print();
    std::cout << std::endl;
    a1.resize(3);
    a1.set(2, 3);
    std::cout << "Second output (after resize):" << std::endl;
    a1.print();
}

