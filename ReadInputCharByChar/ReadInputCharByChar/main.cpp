/*
 https://stepic.org/lesson/Динамическая-память-542/step/10?course=Программирование-на-языке-C  &unit=865
 
 Реализуйте функцию getline, которая считывает поток ввода посимвольно, пока не достигнет конца потока или не встретит символ переноса строки ('\n'), и возвращает C-style строку с прочитанными символами.
 
 Обратите внимание, что так как размер ввода заранее неизвестен, то вам нужно будет перевыделять память в процессе чтения, если в потоке ввода оказалось больше символов, чем вы ожидали.
 
 Память, возвращенная из функции будет освобождена оператором delete[]. Символ переноса строки ('\n') добавлять в строку не нужно, но не забудьте, что в конце C-style строки должен быть завершающий нулевой символ.
 
 Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции, если они вам нужны. Определять функцию main не нужно.
 */

#include <iostream>

#define SZ 65536

char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *newStr = new char[new_size];
    unsigned i;
    for (i = 0; i < size && i < new_size; i++) {
        newStr[i] = str[i];
    }
    delete[] str;
    for (; i < new_size; i++) {
        newStr[i] = 0;
    }
    return newStr;
}

char *getline()
{
    char *line = new char[SZ];
    unsigned size = SZ, i = 0;
    char c;
    while (std::cin.get(c)) {
        if (c == '\n') break;
        if (i >= size) {
            line = resize(line, size, size + SZ);
            size += SZ;
        }
        line[i++] = c;
    };
    
    if (i >= size) {
        line = resize(line, size, size + SZ);
    }
    line[i] = '\0';

    return line;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Enter input:\n");
    char *line = getline();
    printf("%s", line);
    delete[] line;
    return 0;
}
