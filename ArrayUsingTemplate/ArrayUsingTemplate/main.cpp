//
//  main.cpp
//  ArrayUsingTemplate
//
//  https://stepic.org/lesson/Шаблоны-классов-563/step/8?unit=886
//  https://ru.wikipedia.org/wiki/New_(C++)#Placement_new
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
    Array(size_t size, const T& value = T()) : data_((T*) new char[size*sizeof(T)]), size_(size) {
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
        for (int i = 0; i != size_; ++i) {
            new (data_ + i) T(value);
        }
    }
    Array() {
    //   конструктор класса, который можно вызвать
    //   без параметров. Должен создавать пустой
    //   Array.
        size_ = 0;
        data_ = (T*) new char[size_*sizeof(T)];
    }
    Array(const Array &other) : size_(other.size()), data_((T*) new char[other.size()*sizeof(T)]) {
    //   конструктор копирования, который создает
    //   копию параметра. Для типа T оператор
    //   присвивания не определен.
        for (int i = 0; i != size_; ++i) {
            new (data_ + i) T(other.data_[i]);
        }
    }
    ~Array() {
    //   деструктор, если он вам необходим.
        for (int i = 0; i != size_; ++i) {
            data_[i].~T();
        }
        delete [] (char*) data_;
    }
    Array& operator=(const Array &other) {
    //   оператор присваивания.
        if (this != &other) {
            
            for (int i = 0; i != size_; ++i) {
                data_[i].~T();
            }
            delete [] (char*) data_;

            size_ = other.size_;
            data_ = (T*) new char[size_*sizeof(T)];
            for (int i = 0; i != size_; ++i) {
                new (data_ + i) T(other.data_[i]);
            }
        }
        return *this;
    }
    size_t size() const {
    //   возвращает размер массива (количество
    //                              элемнтов).
        return size_;
    }
    T& operator[](size_t i) {
        return data_[i];
    }
    const T& operator[](size_t i) const {
        return data_[i];
    }
    //   две версии оператора доступа по индексу.
private:
    T * data_;
    size_t size_;
};

int main(int argc, const char * argv[]) {
    Array<std::string> * a = new Array<std::string>(10, "qqq");
    Array<std::string> b(100, "www");
    *a = b;
    delete a;
    
    return 0;
}
