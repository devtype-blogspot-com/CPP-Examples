/*
 https://stepic.org/lesson/Многомерные-массивы-543/step/10?course=Программирование-на-языке-C  &unit=866
 
 Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом массиве строку, содержащую наименьшее среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива.
 
 Подумайте, как обменять строки массива, не обменивая элементы строк по-отдельности.
 
 Требования к реализации: при выполнении этого задания вы можете определять любые вспомогательные функции. Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.
 */

#include <iostream>

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    unsigned min[2] = {0, 0};
    for (unsigned i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] < m[min[0]][min[1]]) {
                min[0] = i;
                min[1] = j;
            }
        }
    }
    int *t = m[0];
    m[0] = m[min[0]];
    m[min[0]] = t;
}

int ** create_array2d(size_t a, size_t b)
{
    int ** m = new int *[a];
    m[0] = new int[a * b];
    for (size_t i = 1; i != a; ++i)
        m[i] = m[i - 1] + b;
    return m;
}

void free_array2d(int ** m, size_t a, size_t b)
{
    delete [] m[0];
    delete [] m;
}

void test1()
{
    const int sz = 3;
    int ** m = create_array2d(sz, sz);
    m[0][0]=1; m[0][1]=0; m[0][2]=2;
    m[1][0]=2; m[1][1]=4; m[1][2]=3;
    m[2][0]=4; m[2][1]=5; m[2][2]=-1;
    swap_min(m, sz, sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
    free_array2d(m, sz, sz);
}

/**
 produce bug
 */
void test2()
{
    const int sz = 3;
    int ** m = new int*[sz];
    for (int i = 0; i < sz; i++)
        m[i] = new int[sz];
    m[0][0]=1; m[0][1]=0; m[0][2]=2;
    m[1][0]=2; m[1][1]=4; m[1][2]=3;
    m[2][0]=4; m[2][1]=5; m[2][2]=-1;
    swap_min(m, sz, sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
    for (int i = 0; i < sz; i++)
        delete[] m[i];
    delete[] m;
}

int main(int argc, const char * argv[]) {
    test2();
    return 0;
}
