//
//  main.cpp
//  ValueHolder
//
//  https://stepic.org/lesson/Шаблоны-классов-563/step/9?unit=886
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>


struct ICloneable
{
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() { }
};

// Шаблон ValueHolder с типовым параметром T,
// должен содержать одно открытое поле data_
// типа T.
//
// В шаблоне ValueHolder должен быть определен
// конструктор от одного параметра типа T,
// который инициализирует поле data_.
//
// Шаблон ValueHolder должен реализовывать
// интерфейс ICloneable, и возвращать указатель
// на копию объекта, созданную в куче, из метода
// clone.

template <typename T>
struct ValueHolder : ICloneable // дальше самостоятельно
{
    ValueHolder(const T& value) : data_(value) {
    }
    
    ICloneable* clone() const {
        ICloneable* c = new ValueHolder<T>(data_);
        return c;
    }
    
    ~ValueHolder() {
    }
    
    T data_;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

/*
 Шаблонные классы можно наследовать. 
 Реализуйте шаблонную структуру ValueHolder с одним типовым параметром T, унаследованную от интерфейса ICloneable.
 Интерфейс ICloneable содержит всего один виртуальный метод ICloneable* clone() const, который должен вернуть указатель на копию объекта, на котором он был вызван (объект должен быть создан в куче). 
 Шаблон ValueHolder, как говорит его название, хранит всего одно значение (назовите его data_) типа T (для типа T определен конструктор копирования). 
 Не делайте поле data_ закрытым (поэтому в данном случае мы явно пишем, что ValueHolder должна быть структурой).
*/