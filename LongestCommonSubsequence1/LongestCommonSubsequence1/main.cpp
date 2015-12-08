//
//  main.cpp
//  LongestCommonSubsequence1
//
//  https://stepic.org/lesson/Наибольшая-возрастающая-подпоследовательность-13257/step/5?unit=3442
//  http://e-maxx.ru/algo/longest_increasing_subseq_log
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    vector<int> d(n);
    
    for (int i=0; i<n; ++i) {
        d[i] = 1;
        for (int j=0; j<i; ++j)
            if (A[i] % A[j] == 0)
                d[i] = max (d[i], 1 + d[j]);
    }
    
    int ans = d[0];
    for (int i=0; i<n; ++i)
        ans = max (ans, d[i]);
    cout << ans << endl;
    
    return 0;
}

/*
 
 Задача на программирование: наибольшая последовательнократная подпоследовательность
 Дано целое число 1≤n≤10^3 и массив A[1…n] натуральных чисел, не превосходящих 2⋅10^9. Выведите максимальное 1≤k≤n, для которого найдётся подпоследовательность 1≤i[1]<i[2]<…<i[k]≤n длины k, в которой каждый элемент делится на предыдущий (формально: для  всех 1≤j<k, A[ i[j] ] | A[ i[j+1] ]).
 
 
 
 Sample Input:
 4
 3 6 7 12
 
 Sample Output:
 3
 
*/