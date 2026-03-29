#include <iostream>
#include <windows.h>
using namespace std;

   


class Test {
    int id;
public:
    Test(int n=0) : id(n) {
        cout << "created " << id << "\n";
    }
    ~Test() {
        cout << "destroyed " << id << "\n";
    }
};

void myFunction1() {
    cout << "Вход в функцию\n";
    Test obj;  // создаётся здесь
    cout << "Выход из функции\n";
}  // 👈 здесь obj уничтожается (выход из области видимости)

void myFunction2() {
    cout << "Вход в функцию\n";
    Test* ptr = new Test();  // создаётся здесь
    cout << "Выход из функции\n";
    delete ptr;
}  // 👈 здесь obj уничтожается (выход из области видимости)

void myFunction3() {
    cout << "Вход в функцию\n";
    Test t1(1);  // создаётся здесь
    Test t2(2);
    cout << "Выход из функции\n";
}  // 👈 здесь obj уничтожается (выход из области видимости)

void myFunction4() {
    static Test obj;  // создаётся только один раз
    cout << "Вызов функции\n";
}

int main() {
    SetConsoleOutputCP(1251);
    cout << "Начало main\n";
    //myFunction1();
    //myFunction2();
    //myFunction3();
    myFunction4();
    cout << "Конец main\n";
    return 0;
}