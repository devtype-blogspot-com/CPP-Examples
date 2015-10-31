//
//  main.cpp
//  MinimumSearchFunctionUsingTempates
//
//  https://stepic.org/lesson/Шаблоны-функций-564/step/8?unit=887
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>

#include <cstddef>

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T());
    Array(const Array& other);
    ~Array();
    Array& operator=(Array other);
    void swap(Array &other);
    size_t size() const;
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;
    
private:
    size_t size_;
    T *data_;
};

template<typename T, class Comp>
T minimum(Array<T> q, Comp less) {
    T min = q[0];
    for (size_t i = 1; i != q.size(); i++) {
        if (less(q[i], min)) {
            min = q[i];
        }
    }
    return min;
}

bool less(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };

int main(int argc, const char * argv[]) {
    
    Array<int> ints(3);
    ints[0] = 10;
    ints[1] = 2;
    ints[2] = 15;
    int min = minimum(ints, less); // в min должно попасть число 2
    std::cout << "min = " << min << "\n";
    int max = minimum(ints, Greater()); // в max должно попасть число 15
    std::cout << "max = " << max << "\n";

    return 0;
}

/*
 
 Реализуйте шаблонную функцию minimum, которая находит минимальный элемент, который хранится в экземпляре шаблонного класса Array, при этом типовой параметр шаблона Array может быть произвольным. Чтобы сравнивать объекты произвольного типа, на вход функции также будет передаваться компаратор, в качестве компаратора может выступать функция или объект класса с перегруженным оператором "()". Примеры вызова функции minimum:
*/