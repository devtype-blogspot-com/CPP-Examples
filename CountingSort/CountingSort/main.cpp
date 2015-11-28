//
//  main.cpp
//  CountingSort
//
//  https://stepic.org/lesson/Сортировки-основанные-не-на-сравнениях-13252/step/3?unit=3437
//  https://ru.wikipedia.org/wiki/Сортировка_подсчётом
//

#include <iostream>
#include "assert.h"

void counting_sort(int* vec, int len, int min, int max)
{
    assert(len > 0);
    assert(min <= max);
    assert(vec != NULL);
    
    int cnt[max-min+1];
    
    for (int i = min; i <= max; ++i) {
        cnt[i - min] = 0;
    }
    
    for (int i = 0; i < len; ++i) {
        ++cnt[vec[i] - min];
    }
    
    for (int i = min; i <= max; ++i) {
        for(int j = cnt[i - min]; j--;) {
            *vec++ = i;
        }
    }
}

int main(int argc, const char * argv[]) {
    int len;
    std::cin >> len;
    int *vec = new int[len];
    for (size_t i = 0; i < len; i++) std::cin >> vec[i];
    counting_sort(vec, len, 0, 10);
    for (size_t i = 0; i < len; i++) std::cout << vec[i] << " ";
    delete [] vec;
    return 0;
}

/*
 Первая строка содержит число 1≤n≤10^4, вторая — n натуральных чисел, не превышающих 10. Выведите упорядоченную по неубыванию последовательность этих чисел.
 
 Sample Input:
 5
 2 3 9 2 9
 
 Sample Output:
 2 2 3 9 9

*/