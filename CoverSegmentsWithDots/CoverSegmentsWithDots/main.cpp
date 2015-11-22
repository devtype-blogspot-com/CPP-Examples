//
//  main.cpp
//  https://stepic.org/lesson/%D0%92%D0%B2%D0%B5%D0%B4%D0%B5%D0%BD%D0%B8%D0%B5-13238/step/9?unit=3424
//

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using Segment = std::pair<int, int>;

std::vector <int> get_covering_set(std::vector <Segment> segments) {
    std::vector <int> result;
    
    std::sort(segments.begin(), segments.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    });

    // fix this function
    for (auto s : segments) {
        bool skip = false;
        for (auto p : result) {
            if (p >= s.first && p <= s.second) {
                skip = true;
            }
        }
        if (skip) {
            continue;
        }
        result.push_back(s.second);
    }
    
    return result;
}

int main(void) {
    int segments_count;
    std::cin >> segments_count;
    std::vector <Segment> segments(segments_count);
    for (auto &s:segments) {
        std::cin >> s.first >> s.second;
    }
    
    auto points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point:points) {
        std::cout << point << " ";
    }
    std::cout << std::endl;
}

/*
 Задача на программирование: покрыть отрезки точками
 
 По данным n отрезкам необходимо найти множество точек минимального размера, 
 для которого каждый из отрезков содержит хотя бы одну из точек.
 
 В первой строке дано число 1≤n≤100 отрезков. 
 Каждая из последующих n строк содержит по два числа 0≤l≤r≤10^9, задающих начало и конец отрезка.
 Выведите оптимальное число m точек и сами m точек. 
 Если таких множеств точек несколько, выведите любое из них.
*/




/*
http://e-maxx.ru/algo/covering_segments
 
 Заметим сначала, что можно рассматривать только те решения, в которых каждая из точек находится на правом конце какого-либо отрезка. Действительно, нетрудно понять, что любое решение, если оно не удовлетворяет этому свойству, можно привести к нему, сдвигая его точки вправо настолько, насколько это возможно.
 
 Попытаемся теперь построить решение, удовлетворяющее указанному свойству. Возьмём точки-правые концы отрезков, отсортируем их, и будем двигаться по ним слева направо. Если текущая точка является правым концом уже покрытого отрезка, то мы пропускаем её. Пусть теперь текущая точка является правым концом текущего отрезка, который ещё не был покрыт до этого. Тогда мы должны добавить в ответ текущую точку, и отметить все отрезки, которым принадлежит эта точка, как покрытые. Действительно, если бы мы пропустили текущую точку и не стали бы добавлять её в ответ, то, так как она является правым концом текущего отрезка, то мы уже не смогли бы покрыть текущий отрезок.
 
*/