//
//  main.cpp
//  Rational
//
//  https://stepic.org/lesson/Правила-переопределения-операторов-559/step/3?course=Программирование-на-языке-C  &unit=882
//  https://stepic.org/lesson/Правила-переопределения-операторов-559/step/4?course=Программирование-на-языке-C  &unit=882
//  https://stepic.org/lesson/Правила-переопределения-операторов-559/step/6?course=Программирование-на-языке-C  &unit=882
//  https://stepic.org/lesson/Правила-переопределения-операторов-559/step/8?course=Программирование-на-языке-C  &unit=882
//
//  Copyright (c) 2015 Informatik-007. All rights reserved.
//

#include <iostream>


struct Rational
{
    Rational(int numerator = 0, int denominator = 1);
    
    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);
    
    void neg();
    void inv();
    double to_double() const {
        return (double)numerator_ / (double)denominator_;
    }
    
    Rational & operator +=( int i ) {
        (*this) += Rational(i);
        return * this ;
    }
    Rational& operator+=(Rational rational) {
        this->add(rational);
        return * this ;
    }

    Rational & operator -=( int i ) {
        (*this) -= Rational(i);
        return * this ;
    }
    Rational& operator-=(Rational rational) {
        this->sub(rational);
        return * this ;
    }

    Rational & operator *=( int i ) {
        (*this) *= Rational(i);
        return * this ;
    }
    Rational& operator*=(Rational rational) {
        this->mul(rational);
        return * this ;
    }

    Rational & operator /=( int i ) {
        (*this) /= Rational(i);
        return * this ;
    }
    Rational& operator/=(Rational rational) {
        this->div(rational);
        return * this ;
    }
    
    Rational operator-() const {
        Rational r(numerator_, denominator_);
        r.neg();
        return r;
    }
    Rational operator+() const {
        Rational r(numerator_, denominator_);
        return r;
    }
    
    
    operator double () const {
        return to_double();
    }

    
private:
    int numerator_;
    unsigned denominator_;
};


Rational operator +( Rational r1 , Rational const & r2 ) {
    return r1 += r2 ;
}
Rational operator -( Rational r1 , Rational const & r2 ) {
    return r1 -= r2 ;
}
Rational operator *( Rational r1 , Rational const & r2 ) {
    return r1 *= r2 ;
}
Rational operator /( Rational r1 , Rational const & r2 ) {
    return r1 /= r2 ;
}


bool operator <( Rational const & a , Rational const & b ) {
    return a.to_double() < b.to_double();
}
bool operator ==( Rational const & a , Rational const & b ) {
    return !(a < b) && !(b < a);
}
bool operator !=( Rational const & a , Rational const & b ) {
    return !( a == b );
}
bool operator >( Rational const & a , Rational const & b ) {
    return b < a ;
}
bool operator <=( Rational const & a , Rational const & b ) {
    return !( b < a );
}
bool operator >=( Rational const & a , Rational const & b ) {
    return !( a < b );
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


/*
 Вам дан класс Rational, который описывает рациональное число. В нем определены методы add, sub, mul и div, которые прибавляют к нему число, отнимают число, умножают на число и делят на число соответственно. Кроме того в нем определен метод neg, который меняет знак на противоположный.
 
 Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, чтобы они могли принимать в качестве аргументов и объекты типа Rational и целые числа. Кроме того вам необходимо определить операторы унарного минуса и плюса для класса Rational.
 
 Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
*/


/*
 Определите для класса Rational операторы сложения, вычитания, умножения и деления, так чтобы объекты типа Rational можно было складывать (вычитать, умножать и делить) не только друг с другом но и с целыми числами.
 
 Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
*/


/*
 Еще одна важная группа операторов, которые полезно реализовать для класса рациональных чисел — это операторы сравнения. Реализуйте операторы <, <=, >, >=, ==, != для класса Rational так, чтобы можно было сравнивать объекты класса Rational не только друг с другом, но и с целыми числами.
 
 При решении задания не используйте метод to_double, он введен в класс, в первую очередь, для удобства тестирования. Вы можете определять любые вспомогательные методы или функции если необходимо.
 
 Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
*/


/*
 Добавьте в класс Rational оператор приведения к double. Все операторы из предыдущих заданий отсутствуют и реализовывать их не нужно. Метод to_double можно использовать в этом задании.
 
 Важное замечание: добавлять оператор преобразования к double в класс Rational не самая удачная идея, например, потому, что при таком преобразовании может происходить потеря точности. Эта задача дана исключительно с целью ознакомления с правильным порядком перегрузки таких операторов.
 
 Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно.
*/