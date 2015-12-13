//
//  main.cpp
//  MaximumSumSublist
//
//  https://stepic.org/lesson/Обзор-13262/step/4?unit=3447
//

#include <iostream>
#include <climits>
#include <algorithm>

#define SZ 100

using namespace std;

int n, a[SZ + 1];

int foo(int step, int sum) {
    
    int s1, s2;
    
    if (step == n)
        s1 = s2 = sum;
    else
        s1 = s2 = -INT_MAX;
    
    if (step + 1 <= n)
        s1 = foo(step + 1, sum + a[step + 1]);
    
    if (step + 2 <= n)
        s2 = foo(step + 2, sum + a[step + 2]);
    
    return max(s1, s2);
}

int bar() {
    int s[SZ + 1];
    for (int i = 1; i <= n; i++) {
        switch (i) {
            case 1: s[i] = a[i];
                break;
            case 2: s[i] = max(s[i - 1] + a[i], a[i]);
                break;
            default: s[i] = max(s[i - 1] + a[i], s[i - 2] + a[i]);
                break;
        }
    }
    return s[n];
}

int main(int argc, const char * argv[]) {

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
//    cout << foo(0, 0);
    cout << bar();
    
    return 0;
}

/*
 
 Задача на программирование: лестница
 
 Даны число 1≤n≤10^2 ступенек лестницы и целые числа −10^4≤a[1],…,a[n]≤10^4, которыми помечены ступеньки.
 Найдите максимальную сумму, которую можно получить, идя по лестнице снизу вверх (от нулевой до n-й ступеньки), 
 каждый раз поднимаясь на одну или две ступеньки.
 
 
 Sample Input 1:
 2
 1 2
 Sample Output 1:
 3
 
 
 Sample Input 2:
 2
 2 -1
 Sample Output 2:
 1
 
 
 Sample Input 3:
 3
 -1 2 1
 Sample Output 3:
 3

*/