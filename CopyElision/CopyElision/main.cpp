//
//  main.cpp
//  CopyElision
//  https://stepic.org/lesson/Конструктор-копирования-и-оператор-присваивания-550/step/9?course=Программирование-на-языке-C  &unit=873

#include <iostream>

struct String {
    String (const String &other) {
        std::cout << "Вызов конструктора копирования" << std::endl;
        
        size = other.size;
        str = new char[size + 1];
        str[size] = '\0';
        
        const char * i = other.str;
        while (i != other.str + other.size) {
            str[i - other.str] = *i;
            i++;
        };
    }
    
    String(const char *str = "") {
        size = 0;
        this->str = 0;
        size = lengthOfStr(str);
        this->str = (size > 0) ? cpStr(str, size) : 0;
    }
    
    String(size_t n, char c) {
        size = n;
        str = new char[size + 1];
        str[size] = '\0';
        char * i = str;
        while (i - str < size) {
            *i = c;
            i++;
        };
    }
    
    ~String() {
        if (str != 0)
            delete [] str;
        str = 0;
        size = 0;
    }
    
    String &operator=(const String &other)
    {
        if (this != &other) {
            // 1 вариант
            // String(other).swap(*this);
            
            // 2 вариант
            delete [] str;
            size = other.size;
            str = new char[size];
            for (size_t i = 0; i != size; i++) {
                str[i] = other.str[i];
            }
        }
        return *this;
    }
    
    void swap(String & a) {
        std::swap(size, a.size);
        std::swap(str, a.str);
    }
    
    void append(String &other) {
        size_t newSz = size + other.size;
        char *newStr = new char[newSz + 1];
        newStr[newSz] = '\0';
        
        const char * i = str;
        while (i != str + size) {
            newStr[i - str] = *i;
            i++;
        };
        
        i = other.str;
        while (i != other.str + other.size) {
            newStr[size + i - other.str] = *i;
            i++;
        };
        
        delete [] str;
        size = newSz;
        str = newStr;
    }
    
    size_t lengthOfStr(const char * const str) {
        const char * i = str;
        while (*i != '\0') {
            i++;
        };
        return i - str;
    }
    
    char* cpStr(const char * const str, size_t strSz) {
        char *newStr = new char[strSz + 1];
        newStr[strSz] = '\0';
        
        const char * i = str;
        while (i != str + strSz) {
            newStr[i - str] = *i;
            i++;
        };
        
        return newStr;
    }
    
    size_t size;
    char *str;
};


// Test 1
String spaces(size_t n) {
    const String s(n, ' ');
    return s;
}
int test1() {
    std::cout << spaces(10).str << "\n";
    return 0;
}

// Test 2
/*
 Давайте рассмотрим наш второй тест.
 Из приведенной ситуации вызывается оператор присваивания.
 А уже потом вызывается только конструктор копирования.
 Значит, из ситуации 2 не вызывается конструктор копирования.
 
 Компилятор оптимизирует вызовы конструктора копирования.
 А из нашего примера конструктор копирования может быть не вызван.
 Для g++ и clang++ можно использовать флаг -fno-elide-constructors, чтобы отключить эту оптимизацию.

 */
int test2() {
    String ten_spaces;
    ten_spaces = String(10, ' ');
    std::cout << ten_spaces.str << "\n";
    return 0;
}

// Test 3
void foo(String str) {
    std::cout << str.str << "\n";
}
int test3() {
    foo(String(10, ' '));
    return 0;
}

// Test 4
/*
 Если рассмотреть 4 пример, то там объект создается, то есть вызывается конструктор с одним параметром, 
 и потом передается по константной ссылке.
 При этом конструктор копирования нигде не вызывается.
 */
void bar(const String &str) {
    std::cout << str.str << "\n";
}
int test4() {
    bar("          "); // ten spaces;
    return 0;
}

// Main
int main(int argc, const char * argv[]) {
    std::cout << "test 1:\n"; test1();
    std::cout << "test 2:\n"; test2();
    std::cout << "test 3:\n"; test3();
    std::cout << "test 4:\n"; test4();
    return 0;
}
