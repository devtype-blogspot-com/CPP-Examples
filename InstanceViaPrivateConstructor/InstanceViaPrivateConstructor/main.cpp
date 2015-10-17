//
//  main.cpp
//  https://stepic.org/lesson/Наследование-552/step/9?course=Программирование-на-языке-C  &unit=875
//
//  Copyright (c) 2015 Informatik-007. All rights reserved.
//

#include <iostream>

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const char *msg) : msg(msg) { }
private:
    const char *msg;
};

void foo_says(const Foo& foo) { foo.say(); }

struct Bar : Foo {
    Bar(const char *msg) : Foo(msg) {
    }
};

Bar get_foo(const char *msg) {
    return Bar(msg);
}

int main(int argc, const char * argv[]) {
    
    foo_says(get_foo("Hello!"));
    return 0;
}
