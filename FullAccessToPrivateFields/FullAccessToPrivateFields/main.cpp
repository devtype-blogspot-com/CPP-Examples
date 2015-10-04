//
//  main.cpp
//  FullAccessToPrivateFields
//
//  https://stepic.org/lesson/Модификаторы-доступа-548/step/7?course=Программирование-на-языке-C  &unit=871

#include <iostream>

struct Cls {
    Cls(char c, double d, int i)
    {
        this->c = c;
        this->d = d;
        this->i = i;
    }
private:
    char c;
    double d;
    int i;
};

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    char *c = (char *)&cls;
    return *c;
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    char *c = (char *)&cls;
    double *d = (double *)(c + sizeof(char) + 7);
    return *d;
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
    char *c = (char *)&cls;
    double *d = (double *)(c + sizeof(char) + 7);
    int *i = (int *)((char *)d + sizeof(double));
    return *i;
}

int main(int argc, const char * argv[]) {
    Cls cls('a', 3.14, 1990);
    
    char &c = get_c(cls);
    printf("%c ", get_c(cls));
    c = 'b';
    printf("%c ", get_c(cls));
    
    printf("\n");
    
    double &d = get_d(cls);
    printf("%f ", get_d(cls));
    d = 2.4;
    printf("%f ", get_d(cls));

    printf("\n");

    int &i = get_i(cls);
    printf("%d ", get_i(cls));
    i = 30;
    printf("%d ", get_i(cls));

    return 0;
}
