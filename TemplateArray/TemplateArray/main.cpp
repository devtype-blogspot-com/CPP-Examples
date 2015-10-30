//
//  main.cpp
//  TemplateArray
//
//  https://stepic.org/lesson/Шаблоны-классов-563/step/7?unit=886
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>
#include <cstddef>

template <typename T>
class Array
{
public:
    // Список операций:
    //
    explicit Array(size_t size = 0, const T& value = T()) : data_(new T[size]), size_(size) {
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
        for (int i = 0; i != size_; ++i) {
            data_[i] = value;
        }
    }
    Array(const Array &other) : size_(other.size()), data_(new T[other.size()]) {
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
        for (int i = 0; i != size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    ~Array() {
    //   деструктор, если он вам необходим.
        delete [] data_;
    }
    Array& operator=(const Array &other) {
    //   оператор присваивания.
        if (this != &other) {
            delete [] data_;
            size_ = other.size_;
            data_ = new T[size_];
            for (int i = 0; i != size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }
    size_t size() const {
    //   возвращает размер массива (количество
    //                              элементов).
        return size_;
    }
    //   две версии оператора доступа по индексу.
    T& operator[](size_t i) {
        return data_[i];
    }
    const T& operator[](size_t i) const {
        return data_[i];
    }
private:
    T * data_;
    size_t size_;
};

int main(int argc, const char * argv[]) {
    Array<int> ai(10, 0);
    Array<int> af(ai);

    return 0;
}
