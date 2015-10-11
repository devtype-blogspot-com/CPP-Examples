//
//  main.cpp
//  ConvertSequence
//
//  Copyright (c) 2015 Informatik-007. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    unsigned int n, len;
    int avg = 0;
    std::cin >> n;
    int *x;
    len = n / 2;
    x = new int[len];
    int a = 1;
    for (int i = 0; i < n; i++) {
        if (i < len) {
            std::cin >> x[i];
        } else {
            int t;
            std::cin >> t;
            
            if ( (n % 2 != 0) && (i == ((n + 1) / 2) - 1) ) {
                avg = t;
                a = 0;
                continue;
            }

            int idx = len - (i - len) - a;
            x[idx] += t;
        }
    }
    for (int i = 0; i < len; i++) {
        std::cout << x[i] << " ";
    }
    
    if (n % 2 != 0) {
        std::cout << avg;
    }
        
    delete [] x;
    return 0;
}

/*
 Напишите программу, которая превращает последовательность целых чисел x[1],x[2],…,x[n] в последовательность (x[1]+x[n]),(x[2]+x[n−1]),(x[3]+x[n−2]),… длины ⌈n/2⌉.
 
 Формат входа: на вход подаётся целое положительное число n<106, а за ним разделённые пробелами идут n целых чисел, соответствующих x[1],…,x[n].
 
 Формат вывода: на вывод через пробел нужно вывести ⌈n/2⌉ целых чисел, соответствующих последовательности (x[1]+x[n]),(x[2]+x[n−1]),(x[3]+x[n−2]),…. В том случае, если число n — нечётное, то в качестве последнего члена последовательности нужно вывести x[(n+1)/2] (т.е. среднее число массива).
 
 Sample Input:
 10 30 32 43 65 -32 54 34 -23 11 9
 Sample Output:
 39 43 20 99 22

*/