//
//  main.cpp
//  Expression
//
//  https://stepic.org/lesson/Виртуальные-методы-554/step/8?course=Программирование-на-языке-C  &unit=877
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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

/*
 В этом задании вам предлагается разработать иерархию классов Expression для представления арифметических выражений. Конкретнее, вам нужно определить три класса: Expression — базовый класс иерархии, Number — для представления чисел и BinaryOperation — класс описывающий бинарную операцию (+, ­-, * или /).
 
 В данном задании вам нужно расставить ключевое слово virtual там, где это необходимо, определить метод evaluate там, где его не хватает, а также реализовать деструкторы, там где они нужны.
 
 При выполнении этого задания учтите, что при уничтожении объекта BinaryOperation он отвечает за уничтожение левого и правого операндов (гарантируется, что они выделены в динамической памяти).
 
 Требования к реализации: при выполнении этого задания не нужно вводить или выводить что-либо. Вы можете заводить любые вспомогательные функции, методы или классы, но не нужно реализовывать функцию main.
*/