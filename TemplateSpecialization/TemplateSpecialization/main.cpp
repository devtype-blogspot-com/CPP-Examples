//
//  main.cpp
//  TemplateSpecialization
//
//  https://stepic.org/lesson/Специализация-шаблонов-566/step/7?unit=889
//  http://stackoverflow.com/a/13071396/2289640
//  Copyright © 2015 Informatik-007. All rights reserved.
//

#include <iostream>


struct Dummy { };
typedef int type;


// Определите шаблон SameType с двумя типовыми
// параметрами. В шаблоне должна быть определена
// одна статическая константа типа bool с именем
// value


template<class T, class U>
struct SameType {
    static const bool value = false;
};

template<class T>
struct SameType<T, T> {
    static const bool value = true;
};


//template <typename A, typename B> struct SameType { static const bool value = false; };
//template <> struct SameType<int, int> { static const bool value = true; };
//template <> struct SameType<int, int&> { static const bool value = false; };
//template <> struct SameType<Dummy, Dummy> { static const bool value = true; };
//template <> struct SameType<int, const int> { static const bool value = false; };


int main(int argc, const char * argv[]) {
    std::cout << SameType<int, int>::value << std::endl; // выведет 1, т. е. true
    std::cout << SameType<int, type>::value << std::endl; // 1, type == int
    std::cout << SameType<int, int&>::value << std::endl; // 0, int и ссылка на int - различные типы
    std::cout << SameType<Dummy, Dummy>::value << std::endl; // 1
    std::cout << SameType<int, const int>::value << std::endl; // 0, const - часть типа
    
    return 0;
}

/*
 В качестве упражнения на частичную специализацию шаблонов классов вам предлагается реализовать простой шаблон SameType. Этот шаблон не содержит никаких методов, а только одно статическое константное поле типа bool, с именем value. Шаблон принимает два типовых параметра, и если два типовых параметра шаблона являются одним и тем же типом, то статическое поле value должно хранить значение true, в противном случае значение false. Примеры:
 
 struct Dummy { };
 typedef int type;
 
 std::cout << SameType<int, int>::value << std::endl; // выведет 1, т. е. true
 std::cout << SameType<int, type>::value << std::endl; // 1, type == int
 std::cout << SameType<int, int&>::value << std::endl; // 0, int и ссылка на int - различные типы
 std::cout << SameType<Dummy, Dummy>::value << std::endl; // 1
 std::cout << SameType<int, const int>::value << std::endl; // 0, const - часть типа
 
 Hint: задание простое, решение занимает порядка десяти строк кода.
 
*/