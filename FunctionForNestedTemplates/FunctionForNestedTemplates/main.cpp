//
//  main.cpp
//  FunctionForNestedTemplates
//
//  https://stepic.org/lesson/Шаблоны-функций-564/step/9?unit=887
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


// Весь вывод должен осущствляться в поток out,
// переданный в качестве параметра.
//
// Можно заводить любые вспомогаетльные функции,
// структуры или даже изменять сигнатуру flatten,
// но при этом все примеры вызова из задания должны
// компилироваться и работать.

template <typename T>
void flatten(const T& array, std::ostream& out)
{
    out << array << " ";
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out)
{
    for (size_t i = 0; i != array.size(); i++) {
        flatten(array[i], out);
    }
}


int main(int argc, const char * argv[]) {
    Array<int> ints(2, 0);
    ints[0] = 10;
    ints[1] = 20;
    flatten(ints, std::cout); // выводит на экран строку "10 20"
    std::cout << "\n";
    
    Array< Array<int> > array_of_ints(2, ints);
    flatten(array_of_ints, std::cout); // выводит на экран строку "10 20 10 20"
    std::cout << "\n";

    Array<double> doubles(10, 0.0);
    flatten(doubles, std::cout); // работать должно не только для типа int
    std::cout << "\n";

    return 0;
}

/*
 Шаблонный класс Array может хранить объекты любого типа, для которого определён конструктор копирования, в том числе и другой Array, например, Array< Array<int> >. Глубина вложенности может быть произвольной. Напишите шаблонную функцию (или несколько) flatten, которая принимает на вход такой "многомерный" Array неизвестной заранее глубины вложенности и выводит в поток out через пробел все элементы, хранящиеся на самом нижнем уровне. Примеры работы функции flatten:
 
 
 Note: лидирующие и завершающие пробельные символы будут игнорироваться проверяющей системой, т. е. там где ожидается "10 20" будет так же принят, например, вариант "   10 20   ", но не вывод "1020".
 
 Hint: шаблонные функции тоже можно перегружать, из нескольких шаблонных функций будет выбрана наиболее специфичная.
 
*/