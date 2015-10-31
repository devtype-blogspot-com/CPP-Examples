//
//  main.cpp
//  ArraySize
//
//  https://stepic.org/lesson/Ещё-о-шаблонах-567/step/3?unit=890
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <cstddef> // size_t

// реализуйте шаблонную функцию array_size,
// которая возвращает значение типа size_t.

template<typename T, size_t N>
size_t array_size(const T (&arr)[N]) {
    return N;
}

int main(int argc, const char * argv[]) {
    int ints[] = {1, 2, 3, 4};
    int *iptr = ints;
    double doubles[] = {3.14};
    assert(array_size(ints)==4); // вернет 4
    assert(array_size(doubles)==1); // вернет 1
    
    // array_size(iptr); // тут должна произойти ошибка компиляции
    
    return 0;
}
