//
//  main.cpp
//  Stack
//
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>

using namespace std;

// стека для целых чисел
struct IntStack {
    // конструкторы
    IntStack() {
        size_ = 0;
        capacity_ = 2;
        data_ = new int[capacity_];
    }
    
    IntStack(IntStack const& s) {
        size_ = s.size_;
        capacity_ = s.capacity_;
        data_ = new int[capacity_];
        for (size_t i = 0; i != capacity_; i++) {
            data_[i] = (i < size_) ? s.data_[i] : 0;
        }
    }
    
    // деструктор
    ~IntStack() {
        delete [] data_;
    }
    
    // оператор присваивания
    IntStack & operator=(IntStack const &s) {
        if (this != &s)
            IntStack(s).swap(*this);
        return *this;
    }
    void swap(IntStack & a) {
        size_t const t1 = size_;
        size_ = a.size_;
        a.size_ = t1;
        
        size_t const t2 = capacity_;
        capacity_ = a.capacity_;
        a.capacity_ = t2;
        
        int * const t3 = data_;
        data_ = a.data_;
        a.data_ = t3;
    }

    // размер стека
    size_t size() const { return size_; }
    
    // операции
    
    // добавить элемент
    void push(int i) {
        if (size_ == capacity_) {
            size_t newCapacity = capacity_ * 2;
            int * newData = new int[newCapacity];
            for (size_t i = 0; i != newCapacity; i++) {
                newData[i] = (i < size_) ? data_[i] : 0;
            }
            delete [] data_;
            data_ = newData;
            capacity_ = newCapacity;
        }
        data_[size_++] = i;
    }
    
    // удалить элемент
    void pop() {
        if (size_ > 0) {
            size_--;
        }
    }
    
    // получить элемент на вершине стека
    int top() const {
        return (size_ > 0) ? data_[size_ - 1] : 0;
    }
    
    // поля данных
    // не менять!
private:
    int * data_;      // массив
    size_t size_;     // количество элементов в массиве
    size_t capacity_; // размер массива
};

int main(int argc, const char * argv[]) {
    IntStack s;
    for (int i = 1; i != 10; ++i)
        s.push(i); // добавляем числа от одного до 10
    
    while (s.size() > 0) {
        std::cout << s.top() << ' '; // печатаем верхних элемент стека
        s.pop(); // удаляем верхний элемент стека
    }
    // на cout будет выведено "9 8 7 6 5 4 3 2 1 "
    
    return 0;
}

/*
 Струтура данных стек позволяет хранить элементы в порядке, обратном порядку их добавления 
 (т.е. последний добавленный элемент будет вытащен из стека раньше всех). 
 Обычно для стека выделяют две главные операции: push и pop. 
 Операция push добавляет элемент в стек, а pop — удаляет из стека последний добавленный элемент.
 
 В данном задании вам предлагается реализовать структуру данных стек для хранения целых чисел, 
 назовём эту структуру IntStack. Следующий код показывает пример работы с этой структурой.
 
 
 IntStack s;
 for (int i = 1; i != 10; ++i)
     s.push(i); // добавляем числа от одного до 10
 
 while (s.size() > 0) {
     std::cout << s.top() << ' '; // печатаем верхних элемент стека
     s.pop(); // удаляем верхний элемент стека
 }
 // на cout будет выведено "9 8 7 6 5 4 3 2 1 "
 
 
 Можно реализовывать стек разными способами. В данном задании вам нужно реализовать стек на массиве: 
 элеметы стека хранятся в динамическом массиве, если массива недостаточно, 
 то выделяется новый массив в два раза большего размера.
 
 Структура стека и его методы уже описаны в шаблоне, вам нужно только правильно реализовать их.
 
 Требования к реализации: в данном задании запрещено использовать строки или контейнеры STL 
 (даже, если вы с ними уже знакомы). 
 Вам разрешено заводить вспомогательные методы, если они вам нужны, но запрещего добавлять поля.  
 При реализации не нужно вводить или выводить что-либо. 
 Реализовывать main не нужно.
 Не используйте функции из cstdlib (malloc, calloc, realloc и free).
*/