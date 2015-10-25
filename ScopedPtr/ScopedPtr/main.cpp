//
//  main.cpp
//  ScopedPtr
//
//  https://stepic.org/lesson/Умные-указатели-4650/step/3?course=Программирование-на-языке-C  &unit=1055
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


struct ScopedPtr
{
    // реализуйте следующие методы:
    //
    explicit ScopedPtr(Expression *ptr = 0) {
        ptr_ = ptr;
    }
    ~ScopedPtr() {
        if (ptr_ != 0) delete ptr_;
    }
    
    // возвращает указатель, сохраненный внутри ScopedPtr (например, чтобы передать его в какую-то функцию);
    Expression* get() const {
        return ptr_;
    }
    
    // забирает указатель у ScopedPtr и возвращает значение этого указателя, после вызова release ScopedPtr не должен освобождать память (например, чтобы вернуть этот указатель из функции);
    Expression* release() {
        Expression *e = get();
        ptr_ = 0;
        return e;
    }
    
    // метод заставляет ScopedPtr освободить старый указатель, а вместо него захватить новый (например, чтобы переиспользовать ScopedPtr, так как оператор присваивания запрещен)
    void reset(Expression *ptr = 0) {
        if (ptr_ != 0) delete ptr_;
        ptr_ = ptr;
    }
    
    Expression& operator*() const {
        return *ptr_;
    }
    Expression* operator->() const {
        return ptr_;
    }
    
    
private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);
    
    Expression *ptr_;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

/*
 Помните иерархию Expression, которую мы разрабатывали на четвёртой неделе? Реализуйте ScopedPtr, который будет работать с указателями на базовый класс Expression. В этом задании вам требуется реализовать методы get, release и reset, операторы * и -> так, как это было описано в предыдущем степе. А также реализуйте конструктор ScopedPtr от указателя на Expression.
 
 Подсказка: в качестве признака того, что ScopedPtr не хранит никакого указателя (после вызова release), используйте нулевой указатель, при этом вы можете явно проверить указатель в деструкторе, но делать это не обязательно, так как delete от нулевого указателя ничего не делает.
 
 Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
*/
