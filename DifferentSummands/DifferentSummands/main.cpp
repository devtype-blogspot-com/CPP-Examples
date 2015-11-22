//
//  main.cpp
//  https://stepic.org/lesson/%D0%92%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5-13238/step/11?unit=3424
//
//  По данному числу 1≤n≤10^9 найдите максимальное число k,
//  для которого n можно представить как сумму k различных натуральных слагаемых.
//  Выведите в первой строке число k, во второй — k слагаемых.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int k = 0;
    
    vector<int>summands;
    
    int cnt = 1;
    while (n != 0) {
        if (n - cnt <= cnt && n - cnt != 0) {
            cnt++;
            continue;
        } else {
            summands.push_back(cnt);
            n -= cnt;
            k++;
            cnt++;
        }
    }
    
    cout << k << endl;
    for (auto summand : summands) cout << summand << " ";
    
    return 0;
}
