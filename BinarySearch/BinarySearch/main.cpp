//
//  main.cpp
//  BinarySearch
//
//  https://stepic.org/lesson/Двоичный-поиск-13246/step/4?unit=3431
//  http://mathbits.com/MathBits/CompSci/Arrays/Binary.htm

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

//int get_pos(const std::vector<int> &numbers, int number) {
//    // TODO optimize this function
//    auto it = std::find(numbers.begin(), numbers.end(), number);
//    if (it == numbers.end()) {
//        return -1;
//    }
//    return static_cast<int>(it - numbers.begin()) + 1;
//}

int get_pos(const std::vector<int> &numbers, int number, int lowerbound, int upperbound) {
    int position;
    position = (lowerbound + upperbound) / 2;
    
    while((numbers[position] != number) && (lowerbound <= upperbound)) {
        if (numbers[position] > number) {
            upperbound = position - 1;
        } else {
            lowerbound = position + 1;
        }
        position = (lowerbound + upperbound) / 2;
    }
    if (lowerbound <= upperbound) {
        return position + 1;
    } else
        return -1;
}

int main(void) {
    size_t number_count;
    std::cin >> number_count;
    std::vector<int> numbers(number_count);
    for (auto &number:numbers) {
        std::cin >> number;
    }
    assert(std::is_sorted(numbers.begin(), numbers.end()));
    
    size_t query_count;
    std::cin >> query_count;
    while (query_count-- > 0) {
        int number;
        std::cin >> number;
        std::cout << get_pos(numbers, number, 0, number_count - 1) << " ";
    }
    std::cout << std::endl;
}

/*
 Задача на программирование: двоичный поиск
 
 В первой строке даны целое число 1≤n≤10^5 и массив A[1…n] из n различных натуральных чисел, не превышающих 10^9, в порядке возрастания, во второй — целое число 1≤k≤10^5 и k натуральных чисел b[1],…,b[k], не превышающих 10^9. Для каждого i от 1 до k необходимо вывести индекс 1≤j≤n, для которого A[j]=b[i], или −1, если такого j нет.

 Sample Input:
 5 1 5 8 12 13
 5 8 1 23 1 11
 
 Sample Output:
 3 1 -1 1 -1
 
*/