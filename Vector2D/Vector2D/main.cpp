//
//  main.cpp
//  Vector2D
//
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>


// шаблонный класс Vector2D
template <typename T>
struct Vector2D
{
    // конструктор по-умолчанию, инициализирует координаты нулями
    Vector2D() : x(0), y(0) {}
    
    // конструктор от x и y
    Vector2D(const T& x, const T& y) : x(x), y(y) {}
    
    // конструктор от Vector2D с другим шаблонным параметром
    template <typename V>
    Vector2D(Vector2D<V> const& v) : x(v.x), y(v.y) {}
    
    void add(Vector2D vector) {
        x+=vector.x;
        y+=vector.y;
    }
    void sub(Vector2D vector) {
        x-=vector.x;
        y-=vector.y;
    }
    void mul(T number) {
        x*=number;
        y*=number;
    }
    
    Vector2D& operator+=(Vector2D vector) {
        this->add(vector);
        return * this ;
    }
    Vector2D& operator-=(Vector2D vector) {
        this->sub(vector);
        return * this ;
    }
    Vector2D& operator*=(T n) {
        this->mul(n);
        return * this ;
    }

    // поля
    T x;
    T y;
};

// оператор +
template <typename T>
Vector2D<T> operator+(Vector2D<T> a, Vector2D<T> b) { return a+=b; }

// оператор -
template <typename T>
Vector2D<T> operator-(Vector2D<T> a, Vector2D<T> b) { return a-=b; }

// оператор умножения на число слева
template <typename T>
Vector2D<T> operator*(T k, Vector2D<T> a) { return a*=k; }

// оператор умножения на число справа
template <typename T>
Vector2D<T> operator*(Vector2D<T> a, T k) { return a*=k; }


int main(int argc, const char * argv[]) {
    Vector2D<int> v(1,2);
    Vector2D<double> w(v);
    
    Vector2D<double> a(w);
    Vector2D<double> b(w);
    Vector2D<double> c = a + b;
    std::cout << c.x << " " << c.y << std::endl;

    return 0;
}

/*
 Реализуйте шаблонный класс Vector2D описывающий вектор на плоскости. Вектор задаётся двумя координатами и хранит их в открытых полях x и y. Шаблонный параметр — это тип координат вектора.
 
 Для этого класса вам нужно реализовать сложение, вычитание, умножение на число (слева и справа) и сравнение на равенство/неравенство. Все операторы должны быть реализованы как внешние функции. Короткие версии операторов реализовывать не нужно.
 
 Кроме того нужно реализовать констуруктор от Vector2D с другим шаблонным параметром. Т.е. должен корректно работать следующий код:
 
 Vector2D<int> v(1,2);
 
 Vector2D<double> w(v);
 Требования к реализации: При реализации не нужно вводить или выводить что-либо. Реализовывать main не нужно.
*/