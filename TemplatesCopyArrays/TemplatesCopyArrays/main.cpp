//
//  main.cpp
//  TemplatesCopyArrays
//
//  https://stepic.org/lesson/Шаблоны-функций-564/step/5?unit=887
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>

template <typename T, typename U>
void copy_n(T *dest, U *src, size_t cnt) {
    for (size_t i = 0; i != cnt; i++) {
        dest[i] = src[i];
    }
}

int main(int argc, const char * argv[]) {
    
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};
    copy_n(doubles, ints, 4); // теперь в массиве doubles содержатся элементы 1.0, 2.0, 3.0 и 4.0
    
    for (size_t i = 0; i != 4; i++) {
        std::cout << doubles[i] << "\n";
    }
    
    return 0;
}
