//
//  main.cpp
//  StringAnalog
//

#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
    String (const String &other) {
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
        if (this != &other)
            String(other).swap(*this);
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

int main(int argc, const char * argv[]) {
    String s1("test test");
    
    String s2(3, 'X');
    s2.append(s1);
    
    String s3 = s2;
    
    return 0;
}
