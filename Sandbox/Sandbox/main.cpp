//
//  main.cpp
//  Sandbox
//
//  Copyright (c) 2015 Informatik-007. All rights reserved.
//

#include <iostream>


#define square(x) (x * x)
int b = square(2.5);
int a = square(2 + b);
void test1() {
    std::cout << a;
}


void foo(char) { std::cout << "char" << std::endl; }
void foo(signed char) { std::cout << "signed char" << std::endl; }
void foo(unsigned char) { std::cout << "unsigned char" << std::endl; }
void test2()
{
    foo('a'); // в результате вызова foo('a') будет выведено char
    // foo(97); // вызов foo(97) приведет к ошибке компиляции
}


// программа не скомпилируется, потому что такая перегрузка функции square не допустима
float  square2(float value) { return value * value; }
// double square2(float value) { return (double)value * value; }
double test3()
{
    double sq = square2(2.0);
    return sq;
}


void promotion(char &) { std::cout << "char" << std::endl; }
void promotion(int  &) { std::cout << "int"  << std::endl; }
void promotion(long &) { std::cout << "long" << std::endl; }
void test4() {
    short sh = 10;
    // promotion(sh); // вызов promotion(sh) не скомпилируется, так как нет ни одной подходящей функции для вызова
}


int main(int argc, const char * argv[]) {
    test4();
    return 0;
}
