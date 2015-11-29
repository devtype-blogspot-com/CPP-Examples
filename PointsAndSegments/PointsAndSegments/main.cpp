//
//  main.cpp
//  PointsAndSegments
//
//  Задача на программирование: точки и отрезки
//  https://stepic.org/lesson/Быстрая-сортировка-13249/step/6?unit=3434
//

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include "assert.h"


using namespace std;

int min (int x, int y){
    if (x<y) return x;
    return y;
}

int max (int x, int y){
    if (x>y) return x;
    return y;
}

void naive(int N, int M, int *a, int *b) {
    int p,k=0,j=0,i=0;

    for (i=0; i<M; i++){
        std::cin >> p;
        for (j=0; j<N; j++){
            if ((p>=min(a[j],b[j]))&&(p<=max(a[j],b[j]))){
                k++;
            }
        }
        std::cout << k << " ";
        k=0;
    }
}

int bar(const vector< int> &numbers, int key) {
    int left = 0, right = numbers.size() - 1, mid;
    
    while (left <= right) {
        mid = (int) ((left + right) / 2);
        if (key == numbers[mid]) {
            break;
        }
        else if (key > numbers[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return mid;
}

void foo(int n, int m, int a[], int b[]) {
    std::vector<int> left_points(a, a + n);
    std::sort(left_points.begin(), left_points.end());
    
    std::vector<int> rigth_points(b, b + n);
    std::sort(rigth_points.begin(), rigth_points.end());

    int point;
    std::vector<int>::iterator low,up;
    for (int i = 0; i < m; i++){
        std::cin >> point;
        
        int less = bar(left_points, point);
        while ( !(left_points[less] <= point) ) {
            less--;
            if (less == -1) break;
        }
        if (less == -1) { // среди отрезков нет ни одного чей левый край был бы меньше или равен точке
        } else {
            assert(left_points[less] <= point);
            while (less + 1 < n && left_points[less + 1] <= point) less++;
        }
        
        int less_or_eq = bar(rigth_points, point);
        while ( !(rigth_points[less_or_eq] < point) ) {
            less_or_eq--;
            if (less_or_eq == -1) break;
        }
        if (less_or_eq == -1) { // среди отрезков нет ни одного чей левый край был бы меньше точки
        } else {
            assert(rigth_points[less_or_eq] < point);
            while (less_or_eq + 1 < n && rigth_points[less_or_eq + 1] < point) less_or_eq++;
        }
        
        cout << labs(less - less_or_eq) << " ";
    }
}

void test1()
{
    int a[] = {1, 3, 2};
    int b[] = {4, 6, 5};
    foo(3, 1, a, b);
}

void test2()
{
    int a[] = {0, 7};
    int b[] = {5, 10};
    foo(2, 1, a, b);
}

int main() {
    int N, M; // количество отрезков и точек на прямой
    int *a, *b;
    std::cin >> N >> M;
    a = new int[N];
    b = new int[N];
    for (int i = 0; i < N; i++){
        std::cin >> a[i] >> b[i];
    }
    
//    naive(N, M, a, b);
    foo(N, M, a, b);
//    test2();

    return 0;
}

/*
 
 В первой строке задано два целых числа 1≤n≤50000 и 1≤m≤50000 — количество отрезков и точек на прямой, соответственно. Следующие n строк содержат по два целых числа a[i] и b[i] (a[i]≤b[i]) — координаты концов отрезков. Последняя строка содержит m целых чисел — координаты точек. Все координаты не превышают 10^8 по модулю. Точка считается принадлежащей отрезку, если она находится внутри него или на границе. Для каждой точки в порядке появления во вводе выведите, скольким отрезкам она принадлежит.
 
 Sample Input:
 2 3
 0 5
 7 10
 1 6 11
 
 Sample Output:
 1 0 0
 
*/

/*
 http://linuxconfig.org/example-of-c-binary-search-algorithm
 http://www.cplusplus.com/reference/algorithm/sort/
 http://www.cyberforum.ru/cpp-beginners/thread24910.html
 http://forum.algolist.ru/task/1676-trebuetsia-pomosh-ili-zdravaia-mysl.html
 http://codeforces.com/blog/entry/7932
*/