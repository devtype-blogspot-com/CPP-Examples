//
//  main.cpp
//  Shape
//
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>
#include <cmath>
// Воспользуйтесь константой для пи - M_PI

// базовый класс для фигур
struct Shape
{
    // метод area вычисляющий площадь фигуры
    virtual double area() const = 0;
    
    virtual ~Shape () {}
};

// класс для круга
struct Circle : Shape
{
    // конструктор от радиуса
    Circle(double r) : r_(r) {
    }
    
    ~Circle() {}
    
    // реализация метода area
    double area() const {
        return M_PI * r_ * r_;
    }
    
    double r_;
};

// класс прямоугольника
struct Rectangle : Shape
{
    // конструктор от ширины и высоты
    Rectangle(double a, double b) : a_(a), b_(b) {
    }
    
    ~Rectangle() {}
    
    // реализация метода area
    double area() const {
        return a_ * b_;
    }
    
    double a_, b_;
};


int main(int argc, const char * argv[]) {
    double r, w, h;
    
    r = 5;
    Shape * s1 = new Circle(r);
    
    w = 4; h = 2;
    Shape * s2 = new Rectangle(w, h);
    
    return 0;
}

/*
 Вам нужно реализовать базовый класс для геометрических фигур — Shape и два его наследника — Circle и Rectangle. 
 
 У базового класса Shape нужно определить общий метод area(), который возвращает площадь геометрической фигуры,
 а в наследниках — реализовать этот метод. 
 
 В комментариях к коду указано, какие параметры должны принимать конструкторы классов-наследников.
 
 Требования к реализации: При реализации не нужно вводить или выводить что-либо. Реализовывать main не нужно.
*/