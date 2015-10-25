//
//  main.cpp
//  SharedPtr
//
//  https://stepic.org/lesson/Умные-указатели-4650/step/5?course=Программирование-на-языке-C  &unit=1055
//  Copyright (c) 2015 Informatik-007. All rights reserved.
//

#include <iostream>

struct Expression
{
    // Во всех классах должен быть метод evaluate, который возвращает значение типа double — значение соответствующего арифметического выражения,
    virtual double evaluate() const = 0;
    
    virtual ~Expression () {}
};

struct Number : Expression
{
    Number(double value)
    : value(value)
    {}
    
    // например, значение экземпляра типа Number — это число, которое он хранит,
    double evaluate() const {
        return value;
    }
    
private:
    double value; // Класс Number должен хранить значение типа double.
};

struct BinaryOperation : Expression
{
    /*
     Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
     которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
    : left(left), op(op), right(right)
    { }
    
    // а если у вас есть объект BinaryOperation с операцией +, то нужно вычислить значения левого и правого операнда и вернуть их сумму.
    double evaluate() const {
        double result = 0;
        switch(op){
            case '+': result = left->evaluate() + right->evaluate(); break;
            case '-': result = left->evaluate() - right->evaluate(); break;
            case '*': result = left->evaluate() * right->evaluate(); break;
            case '/': result = left->evaluate() / right->evaluate(); break;
        }
        return result;
    }
    
    ~BinaryOperation () {
        delete left;
        delete right;
    }
    
private:
    // Класс BinaryOperation должен хранить указатель на левый и правый операнды, которые сами являются арифметическими выражениями,
    Expression const * left;
    Expression const * right;
    char op; // а также тип операции (+, ­-, * или /), которую нужно над ними произвести.
};

struct Counter {
    Counter (size_t cnt) { cnt_ = cnt; }
    void dec() { if (cnt_ > 0) cnt_--; }
    void inc() { cnt_++; }
    size_t val() { return cnt_; }
    size_t cnt_;
};

// SharedPtr отличается от ScopedPtr тем, что кроме хранения указателя на объект, он хранит еще и счетчик ссылок (количество объектов SharedPtr, которые хранят один и тот же указатель).
// Имея такой счетчик, мы можем определить момент, когда на объект, выделенный в куче, не останется больше ссылок (когда счетчик ссылок станет равным 0), и освободить память.
struct SharedPtr
{
    // реализуйте следующие методы
    //
    explicit SharedPtr(Expression *ptr = 0) {
        // в конструкторе SharedPtr от ненулевого указателя мы инициализируем счетчик ссылок в 1 (конструктор создает первый SharedPtr, который хранит указатель)
        ptr_ = ptr;
        counter_ = 0;
        if (ptr_ != 0) counter_ = new Counter(1);
    }
    
    ~SharedPtr() {
        // в деструкторе мы уменьшаем значение счетчика на 1, если в объекте SharedPtr хранится ненулевой указатель (мы удаляем один SharedPtr, который указывает на объект в куче)
        if (ptr_ != 0) {
            counter_->dec();
            if (counter_->val() == 0) {
                delete ptr_;
                delete counter_;
            }
        }
    }
    
    SharedPtr(const SharedPtr & other) {
        // в конструкторе копирования мы увеличиваем счетчик ссылок на 1, если копируемый SharedPtr содержит ненулевой указатель (конструктор копирования создает еще один SharedPtr с указателем на тот же самый объект)
        
        ptr_ = other.get();
        counter_ = other.counter_;
        if (ptr_ != 0)  counter_->inc();
    }
    
    // оператор присваивания
    SharedPtr& operator=(const SharedPtr & right) {
        if (this == &right) return *this;
        
        // уменьшает счетчик ссылок левого операнда на 1, если внутри левого SharedPtr хранится ненулевой указатель
        if (this->ptr_ != 0) {
            this->counter_->dec();
            if (this->counter_->val() == 0) {
                delete ptr_;
                delete counter_;
            }
        }
        
        // увеличивает счетчик правого SharedPtr на 1, если в правом SharedPtr хранится ненулевой указатель (обычное дело для оператора присваивания — сначала освобождаем старые ресурсы, потом выделяем новые, но при этом нужно быть особенно внимательным с присваиванием самому себе)
        if (right.ptr_ != 0) right.counter_->inc();
        
        counter_ = right.counter_;
        ptr_ = right.ptr_;
        return *this;
    }
    
    Expression* get() const {
        // метод get, как и в случае со ScopedPtr
        return ptr_;
    }
    
    void reset(Expression *ptr = 0) {
        // метод reset — аналогичен reset у ScopedPtr, но освобождает память, только если счетчик ссылок после декремента равен 0
        
        if (ptr_ != 0) {
            counter_->dec();
            if (counter_->val() == 0) {
                delete ptr_;
                delete counter_;
            }
        }
        
        ptr_ = ptr;
        counter_ = 0;
        if (ptr_ != 0) counter_ = new Counter(1);

    }
    
    Expression& operator*() const {
        return *ptr_;
    }
    
    Expression* operator->() const {
        return ptr_;
    }
    
    Counter *counter_;
    Expression *ptr_;

};

void test1() {
    SharedPtr a(new Number(2));
    SharedPtr b(new Number(2));
//    BinaryOperation bop(a.get(), '+', b.get());
    
//    Expression const * expr = &bop;
}

void test2() {
    SharedPtr a(0);
    SharedPtr b = a;

}

int main(int argc, const char * argv[]) {
    test2();
    
    return 0;
}

/*
 Задание повышенной сложности.
 
 Реализуйте класс SharedPtr как описано ранее. Задание немного сложнее, чем кажется на первый взгляд. Уделите особое внимание "граничным случаям" — нулевой указатель, присваивание самому себе, вызов reset на нулевом SharedPtr и прочее.
 
 Подсказка: возможно, вам понадобится завести вспомогательную структуру.
 
 Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.

 */
