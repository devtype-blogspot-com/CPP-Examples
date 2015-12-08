//
//  main.cpp
//  LongestCommonSubsequence2
//
//  https://stepic.org/lesson/Наибольшая-возрастающая-подпоследовательность-13257/step/6?unit=3442
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> d(n), p(n);
    
    for (int i=0; i<n; ++i) {
        d[i] = 1;
        p[i] = -1;
        for (int j=0; j<i; ++j)
            if (a[j] >= a[i])
                if (1 + d[j] > d[i]) {
                    d[i] = 1 + d[j];
                    p[i] = j;
                }
    }
    
    int ans = d[0],  pos = 0;
    for (int i=0; i<n; ++i)
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    cout << ans << endl;
    
    vector<int> path;
    while (pos != -1) {
        path.push_back (pos);
        pos = p[pos];
    }
    reverse (path.begin(), path.end());
    for (int i=0; i<(int)path.size(); ++i)
        cout << path[i] + 1 << ' ';

    
    return 0;
}

/*

 Задача на программирование повышенной сложности: наибольшая невозрастающая подпоследовательность
 
 
 Дано целое число 1≤n≤10^5 и массив A[1…n], содержащий неотрицательные целые числа, не превосходящие 10^9. Найдите наибольшую невозрастающую подпоследовательность в A. В первой строке выведите её длину k, во второй — её индексы 1≤i[1]<i[2]<…<i[k]≤n (таким образом, A[ i[1] ]≥A[ i[2] ]≥…≥A[ i[n] ]).
 
 Sample Input:
 5
 5 3 4 4 2
 
 Sample Output:
 4
 1 3 4 5

*/