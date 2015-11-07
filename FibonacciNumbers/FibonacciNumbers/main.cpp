//
//  main.cpp
//  FibonacciNumbers
//
//  https://stepic.org/lesson/Числа-Фибоначчи-13228/step/6?unit=3414
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>

// Вариант 1

int f1(int n) {
    if (n <= 1) return n;
    else return f1(n-1) + f1(n-2);
}

// Вариант 2

#define FIB_TABLE_SZ 40

long fib_table[FIB_TABLE_SZ + 1];

void initFibTable() // сначала инициализируйте таблицу
{
    fib_table[0] = 0;
    fib_table[1] = 1;
    for (size_t i = 2; i <= FIB_TABLE_SZ; i++) fib_table[i] = fib_table[i-1] + fib_table[i-2];
}

long f2(int n) {
    if (n <= 1) return n;
    else if (n <= FIB_TABLE_SZ) return fib_table[n];
    else return f2(n-1) + f2(n-2);
}

// Последняя цифра

#define DIG_TBL_SZ 10000000

char dig_table[DIG_TBL_SZ];

void init_dig_tbl() {
    dig_table[0] = 0;
    dig_table[1] = 1;
    for (size_t i = 2; i <= DIG_TBL_SZ; i++) dig_table[i] = (dig_table[i-1] + dig_table[i-2]) % 10;
}

char lastDig(int n) {
    if (n <= 1) return n;
    else if (n <= DIG_TBL_SZ) return dig_table[n];
    else return (lastDig(n-1) + lastDig(n-2)) % 10;
}

// Главная функция

int main(int argc, const char * argv[]) {
    init_dig_tbl();
    
    int n;
    std::cin >> n;
    std::cout << (int)lastDig(n);
    return 0;
}
