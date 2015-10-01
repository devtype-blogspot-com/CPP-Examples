/*
 https://stepic.org/lesson/Многомерные-массивы-543/step/9?course=Программирование-на-языке-C  &unit=866
 
 Напишите функцию, которая принимает на вход целочисленную матрицу M (другими словами, просто двумерный целочисленный массив) размера rows×cols, и возвращает транспонированную матрицу MT (тоже двумерный целочисленный массив) размера cols×rows. Если в M на пересечении i-ой строки и j-ого столбца стояло число x, то на пересечении  j-ой строки и i-ого столбца в матрице MT тоже будет стоять число x, или другими словами MT[j][i]=M[i][j].
 
 Обратите внимание, что вам неизвестно, каким именно способом выделялась память для массива M. Выделять память под массив MT можете любым удобным вам способом. Изменять исходную матрицу нельзя.
 
 Требования к реализации: при выполнении этого задания вы можете определять любые вспомогательные функции. Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.
 */

#include <iostream>

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

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** mT = create_array2d(cols, rows);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            mT[j][i] = m[i][j];
        }
    }
    return mT;
}

int main(int argc, const char * argv[]) {
    const int sz = 2;
    int ** m = create_array2d(sz, sz);
    m[0][0]=1; m[0][1]=0;
    m[1][0]=2; m[1][1]=4;
    int ** mT = transpose(m, sz, sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            std::cout << mT[i][j] << " ";
        }
        std::cout << "\n";
    }
    free_array2d(mT, sz, sz);
    return 0;
}
