//
//  main.cpp
//  NumberOfPositiveNumbers
//
//  Copyright (c) 2015 Informatik-007. All rights reserved.
//

#include <iostream>

unsigned int sumOfDigits(unsigned int num)
{
    unsigned int sum = 0;
    while ( num > 0 ) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main () {
    unsigned int N;
    std::cin >> N;
    unsigned int answer = 0;
    for (unsigned int i = 1; i < N; i++) {
        unsigned int sum = sumOfDigits(i);
        if (sum == sumOfDigits(N)) {
            answer++;
        }
    }
    std::cout << answer;
    return 0;
}

/*
 Напишите программу, которая по целому положительному числу N вычисляет количество положительных целых чисел меньших N таких, что их сумма цифр (в десятичной записи) равна сумме цифр в числе N.
 
 Формат входа: целое положительное число N<10^7.
 
 Формат вывода: количество таких целых положительных чисел меньших N, у которых сумма цифр равняется сумме цифр числа N.
 
 Sample Input:
 123
 Sample Output:
 9
*/