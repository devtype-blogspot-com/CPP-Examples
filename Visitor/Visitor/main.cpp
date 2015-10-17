//
//  main.cpp
//  Visitor
//
//  https://stepic.org/lesson/Объектно-ориентированное-программирование-556/step/10?course=Программирование-на-языке-C  &unit=879
//  Copyright (c) 2015 Informatik-007. All rights reserved.
//

#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    // Во всех классах должен быть метод evaluate, который возвращает значение типа double — значение соответствующего арифметического выражения,
    virtual double evaluate() const = 0;
    
    virtual ~Expression () {}
    
    virtual void visit(Visitor * vistitor) const = 0;
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
    
    double get_value() const { return value; }
    
    void visit(Visitor * visitor) const { visitor->visitNumber(this); }
    
    ~Number () {}
    
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
    
    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }
    
    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

    
private:
    // Класс BinaryOperation должен хранить указатель на левый и правый операнды, которые сами являются арифметическими выражениями,
    Expression const * left;
    Expression const * right;
    char op; // а также тип операции (+, ­-, * или /), которую нужно над ними произвести.
};

/* Этот класс вам нужно реализовать */
struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout << number->get_value();
    }
    
    void visitBinaryOperation(BinaryOperation const * bop)
    {
        std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << bop->get_op();
        bop->get_right()->visit(this);
        std::cout << ")";
    }
};

int main(int argc, const char * argv[]) {
    Number *a = new Number(2);
    Number *b = new Number(2);
    BinaryOperation bop(a, '+', b);

    Expression const * expr = &bop;
    PrintVisitor visitor;
    expr->visit(&visitor);
    return 0;
}
