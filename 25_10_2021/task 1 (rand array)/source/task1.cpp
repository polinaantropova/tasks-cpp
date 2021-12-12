﻿// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void frequency(int* a, int size) {
    //sort array
    for (int k = 0; k < size - 1; ++k) {
        int minl = k;
        for (int l = k + 1; l < size; ++l) {
            if (a[l] <= a[minl]) {
                minl = l;
            }
        }
        std::swap(a[k], a[minl]);
    }
    //search frequency element
    int cur = 0;
    int maxFrEl = 0;
    int maxFr_cy = 1;
    int curFr_cy = 1;
    for (int i = 1; i < size; ++i) {
        if (a[i] == cur) {
            curFr_cy++;
            if (curFr_cy > maxFr_cy) {
                maxFr_cy = curFr_cy;
                maxFrEl = i;
            }
        }
        else {
            cur = a[i];
            curFr_cy = 1;
        }
    }
    std::cout << "the most frequent element: " << a[maxFrEl] <<", number of repetitions: " << maxFr_cy << "\n";
}


int main()
{
    int a[10];
    int i, min, sum=0, k=-1;
    double average;
    min = 1000;

    srand(time(0)); 
    

   //случайный массив из 10 элементов от 1 до 900
    for (i = 0; i < 10; ++i) {
        a[i] = 1 + rand() % 900;
        if (a[i] < min)
        {
            min = a[i];
            k = i+1; // запоминаем номер минимального элемента
        }
        sum += a[i];
    }
    average = (double)sum / 10;
    for (i = 0; i < 10; ++i)
        std::cout << a[i] << " ";


    // расположение элементов массива в обратном порядке
    int n = 10, h = 0;
    for (i = 0; i < n / 2; ++i)

    {
        h = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = h;


    }
    // сортировка массива по среднему значению
    int tmp = 0, lesscounter = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < average)
            lesscounter += 1;
    }
    //std::cout << "lesscounter = " << lesscounter << std::endl;
    int j = 0;
    for (int i = 0; i < lesscounter; ++i) {
        while (a[i] > average) {
            tmp = a[i];
            a[i] = a[n - 1 - j];
            a[n - 1 - j] = tmp;
            j += 1;
        }

    }
    

    std::cout << "\n" << "min = " << min << " and his number = " << k << "\n";
    std::cout <<  "average = " << average << " and sum = " << sum<<"\n";
    std::cout << "after swap by average " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "number of comparisons = " << j << std::endl << std::endl;
    /*std::cout << "\n" << "return array : " << "\n";

    for (i = 0; i < 10; ++i)
        std::cout << a[i] << " ";*/
    frequency(a, 10);
    
    int b[10] = { 1,2,4,5,6,2,2,2,3,4 };
    for (i = 0; i < 10; ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;
    frequency(b, 10);
}


