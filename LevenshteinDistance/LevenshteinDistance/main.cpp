//
//  main.cpp
//  LevenshteinDistance
//
//  https://stepic.org/lesson/Расстояние-редактирования-13258/step/8?path=null
//  https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C.2B.2B
//

#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

size_t levenshtein_distance(const std::string &s1, const std::string &s2)
{
    size_t s1len = s1.size();
    size_t s2len = s2.size();
    
    auto column_start = (decltype(s1len))1;
    
    auto column = new decltype(s1len)[s1len + 1];
    std::iota(column + column_start, column + s1len + 1, column_start);
    
    for (auto x = column_start; x <= s2len; x++) {
        column[0] = x;
        auto last_diagonal = x - column_start;
        for (auto y = column_start; y <= s1len; y++) {
            auto old_diagonal = column[y];
            auto possibilities = {
                column[y] + 1,
                column[y - 1] + 1,
                last_diagonal + (s1[y - 1] == s2[x - 1]? 0 : 1)
            };
            column[y] = std::min(possibilities);
            last_diagonal = old_diagonal;
        }
    }
    auto result = column[s1len];
    delete[] column;
    return result;
}

int main(int argc, const char * argv[]) {
    string s1, s2;
    cin >> s1 >> s2;
    cout << levenshtein_distance(s1, s2);
    return 0;
}

/*
 
 Задача на программирование: расстояние редактирования
 
 
 Вычислите расстояние редактирования двух данных непустых строк длины не более 102, содержащих строчные буквы латинского алфавита.
 
 
 Sample Input 1:
 ab
 ab
 
 Sample Output 1:
 0
 
 
 Sample Input 2:
 short
 ports
 
 Sample Output 2:
 3
 
*/