//
//  main.cpp
//  Inheritance
//
//  https://stepic.org/lesson/Особенности-наследования-в-C  -557/step/7?course=Программирование-на-языке-C  &unit=880
//  Copyright (c) 2015 Informatik-007. All rights reserved.
//

#include <iostream>

struct A {
    int a() {
        return a_;
    }
    
    virtual char plus () const { return '+' ; }

private:
    int a_;
    
    virtual char name () const { return 'A' ; }
};

struct B : private A {
    int b() {
        b_ = this->a();
        return b_;
    }
    
    char name () const { return 'B' ; } // TRUE: Если в базовом классе виртуальная функция определена как private, то в производном классе её можно переопределить как public.
    // FALSE: Производные классы не могут переопределять private-виртуальные методы базового класса, если они унаследованы от базового класса с модификатором private.
    
private:
    int b_;
    
    char plus () const { return '+' ; } // TRUE: Если в базовом классе виртуальная функция определена как public, то в производном классе её можно переопределить как private.

protected:
    void boo() { std::cout << "boo"; }
};

struct C : B {
    int c() {
        // c_ = this->a(); // TRUE: Производные классы не видят private-предков своего базового класса.
        return c_;
    }
private:
    int c_;
};

struct D : private C {
    int d_;
    int d() {
        return d_;
    }
    void doAction() {
        this->boo(); // FALSE: Производные классы не видят protected-предков своего (непосредственного) базового класса, если они унаследованы от базового класса с модификатором private.
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
