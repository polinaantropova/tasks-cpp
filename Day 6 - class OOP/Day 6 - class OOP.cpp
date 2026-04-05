 //Упражнение 1
     /*+Создайте класс Integer с одной приватной переменной типа int.
+Определите конструктор класса, который выводит сообщение при создании объекта.
++Определите функции для получения и установки переменной и вывода ее значения.
В функции main создайте объект класса Integer и вызовите у него функции класса, 
получая, устанавливая и выводя значение переменной каждого объекта.


#include <iostream>

class Integer {
    int number;

public:
    Integer(int a);
    int getNumber();
    void setNumber(int new_value);
};

Integer::Integer(int p_num) {
    number = p_num;
    std::cout << "Create class object " << number << std::endl;
}

int Integer::getNumber() {
    std::cout << "Number is " << number << std::endl;
    return number;
}

void Integer::setNumber(int new_value) {
    number = new_value;
    std::cout << "Update class object " << number << std::endl;
}


int main()
{
    std::cout << "Hello World!\n";
    Integer f1(100);
    f1.getNumber();
    f1.setNumber(200);
    f1.getNumber();
}
*/
//Упражнение 2
/*Добавьте в класс функцию, которая сравнивает текущий объект с другим объектом Integer, 
переданным в качестве аргумента. 
Функция должна возвращать 
число больше нуля, если текущий объект больше аргумента; 
меньше нуля, если текущий объект меньше аргумента, 
и 0, если объекты равны.
В функции main создайте несколько объектов Integer и сравните их.
Сделайте функцию compare, которая определена в предыдущем задании в классе Integer, дружественной.*/

#include <iostream>

class Integer
{
friend int compare(const Integer& num1, const Integer& num2);
public:
    Integer(int number)
    {
        value = number;
    }
    void print() const
    {
        std::cout << "Value: " << value << std::endl;
    }    
private:
    int value;
};

int compare(const Integer& num1, const Integer& num2)
{
    return num1.value - num2.value;
}

int main() {
    Integer f1(5);
    Integer f2(5);
    Integer f3(7);
    Integer f4(1);

    std::cout << compare(f1, f2) << std::endl;
    std::cout << compare(f1, f3) << std::endl;
    std::cout << compare(f1, f4) << std::endl;
}