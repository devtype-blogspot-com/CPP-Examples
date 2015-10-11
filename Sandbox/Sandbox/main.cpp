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


int main(int argc, const char * argv[]) {
    std::cout << a;
    return 0;
}
