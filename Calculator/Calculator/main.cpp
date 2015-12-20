//
//  main.cpp
//  Calculator
//
//  https://stepic.org/lesson/Обзор-13262/step/5?unit=3447
//

#include <iostream>
#include <vector>
#include <climits>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> steps(N + 1, INT_MAX);
    steps[N] = 0;
    std::vector<int> next_num(N + 1, -1);
    
    for (int i = N; i > 1; --i) {
        int s = steps[i] + 1;
        // 3 * x
        if (!(i % 3) && steps[i / 3] > s) {
            steps[i / 3] = s;
            next_num[i / 3] = i;
        }
        // 2 * x
        if (!(i % 2) && steps[i / 2] > s) {
            steps[i / 2] = s;
            next_num[i / 2] = i;
        }
        // x + 1
        if (steps[i - 1] > s) {
            steps[i - 1] = s;
            next_num[i - 1] = i;
        }
    }
    
    std::cout << steps[1] << std::endl;
    for (int i = 1; i != -1; i = next_num[i])
        std::cout << i << ' ';
    std::cout << std::endl;
}

/*
 
 Задача на программирование: калькулятор
 
 
 У вас есть примитивный калькулятор, который умеет выполнять всего три операции с текущим числом x: заменить x на 2x, 3x или x+1. По данному целому числу 1≤n≤10^5 определите минимальное число операций k, необходимое, чтобы получить n из 1. Выведите k и последовательность промежуточных чисел.
 
 
 Sample Input 1:
 1
 Sample Output 1:
 0
 1
 
 
 Sample Input 2:
 5
 Sample Output 2:
 3
 1 2 4 5
 
 
 Sample Input 3:
 96234
 Sample Output 3:
 14
 1 3 9 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234
 
*/