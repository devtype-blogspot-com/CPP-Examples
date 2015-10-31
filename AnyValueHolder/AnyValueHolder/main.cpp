//
//  main.cpp
//  AnyValueHolder
//
//  https://stepic.org/lesson/Шаблоны-функций-564/step/11?unit=887
//  https://ru.wikipedia.org/wiki/Dynamic_cast
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <typeinfo> // Для std::bad_cast

// Эти классы реализовывать заново не нужно
struct ICloneable
{
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() { }
};

// Поле data_ типа T в классе ValueHolder
// открыто, к нему можно обращаться
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

// Это класс, который вам нужно реализовать
class Any
{
public:
    // В классе Any должен быть конструктор,
    // который можно вызвать без параметров,
    // чтобы работал следующий код:
    //    Any empty; // empty ничего не хранит
    Any() {
        value_ = 0;
    }

    // В классе Any должен быть шаблонный
    // конструктор от одного параметра, чтобы
    // можно было создавать объекты типа Any,
    // например, следующим образом:
    //    Any i(10); // i хранит значение 10
    template <typename T>
    Any(const T& value) : value_(new ValueHolder<T>(value)) {
    }

    // Не забудьте про деструктор. Все выделенные
    // ресурсы нужно освободить.
    ~Any() {
        delete value_;
    }

    // В классе Any также должен быть конструктор
    // копирования (вам поможет метод clone
    // интерфейса ICloneable)
    Any (const Any &other) {
        this->value_ = (other.value_ != 0) ? other.value_->clone() : 0;
    }

    // В классе должен быть оператор присваивания и/или
    // шаблонный оператор присваивания, чтобы работал
    // следующий код:
    //    Any copy(i); // copy хранит 10, как и i
    //    empty = copy; // empty хранит 10, как и copy
    //    empty = 0; // а теперь empty хранит 0
    Any& operator=(const Any &other) {
        if (this != &other) {
            delete value_;
            this->value_ = (other.value_ != 0) ? other.value_->clone() : 0;
        }
        return *this;
    }

    // Ну и наконец, мы хотим уметь получать хранимое
    // значение, для этого определите в классе Any
    // шаблонный метод cast, который возвращает
    // указатель на хранимое значение, или нулевой
    // указатель в случае несоответствия типов или
    // если объект Any ничего не хранит:
    //    int *iptr = i.cast<int>(); // *iptr == 10
    //    char *cptr = i.cast<char>(); // cptr == 0,
    //        // потому что i хранит int, а не char
    //    Any empty2;
    //    int *p = empty2.cast<int>(); // p == 0
    // При реализации используйте dynamic_cast,
    // который мы уже обсуждали ранее.
    template <typename T>
    T* cast() {
        if (value_ != 0) {
            try {
                ValueHolder<T> &value = dynamic_cast<ValueHolder<T>&>(*value_);
                return &(value.data_);
            } catch (const std::bad_cast& e){}
        }
        return 0;
    }
private:
    ICloneable *value_;
};

int main(int argc, const char * argv[]) {
    Any empty; // empty ничего не хранит
    
    Any i(10); // i хранит значение 10
    
    Any copy(i); // copy хранит 10, как и i
    empty = copy; // empty хранит 10, как и copy
    empty = 0; // а теперь empty хранит 0

    int *iptr = i.cast<int>(); // *iptr == 10
    assert(*iptr == 10);
    
    char *cptr = i.cast<char>(); // cptr == 0,
        // потому что i хранит int, а не char
    assert(cptr == 0);

    Any empty2;
    int *p = empty2.cast<int>(); // p == 0
    assert(p == 0);

    return 0;
}

/*
 В первом уроке вы реализовали простой шаблон ValueHolder, в этом задании мы используем его чтобы написать класс Any (интересно, что не шаблонный), который позволяет хранить значения любого типа! Например, вы сможете  создать массив объектов типа Any, и сохранять в них int-ы, double-ы или даже объекты Array. Подробности в шаблоне кода. Hint: в нешаблонном классе Any могут быть шаблонные методы, например, шаблонный конструктор.
*/