#include <iostream>
using namespace std;

int main() {
    int a = 5;          // где хранится? stack
    int* p = new int(10); // где хранится? heap

    cout << &a << endl;
    cout << a << endl;
    cout << p << endl;
    cout << *p << endl;

    delete p;
}