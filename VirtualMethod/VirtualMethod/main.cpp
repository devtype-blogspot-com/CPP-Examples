//
//  main.cpp
//  VirtualMethod
//
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>
#include <iomanip>

struct Person {
    Person(std::string name) {
        name_ = name;
    }
    
    virtual std::string name() const {
        return name_;
    }
    
private:
    virtual std::string occupation() const = 0;
    
    std::string name_;
};

struct Professor : Person {
    Professor(std::string name) : Person(name) {
    }
    
    std::string name() const {
        return "Prof. " + Person::name();
    }
    
private:
    std::string occupation() const { // Виртуальный метод может быть private.
        return "professor";
    }
};

int main(int argc, const char * argv[]) {
    Professor pr("Stroustrup");
    std::cout << pr.name() << std::endl; // Prof. Stroustrup
    
    Person * p = &pr;
    std::cout << p->name() << std::endl; // Prof. Stroustrup
    return 0;
}
