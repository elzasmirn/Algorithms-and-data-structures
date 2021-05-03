/*Башня
В Бурляндск приехал цирк. Одним из привлекающих внимание горожан номеров всегда было построение как можно более высокой башни из группы циркачей.
В построенной башне один циркач стоит на земле, второй - на его плечах, третий - на плечах второго, и так далее. 
У циркача под номером i вес равен wi, а сила — fi. Сила — способность удерживать на себе заданный вес. 
Точно известно, что более тяжёлый циркач является и более сильным. Впрочем, циркачи с одинаковым весом могут иметь различную силу.
Input format
Первая строка ввода содержит 4⩽N⩽3000 — количество человек в команде, которые хотят построить башню.
Каждая их последующих строк содержит по два числа — вес и силу участника команды. Все числа — положительные целые, меньшие 100000.
Output format
Максимальная высота башни, которую может построить эта команда.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Circusman
{
public:
    int w;
    int f;
};

int main()
{
    int N;
    std::cin >> N;
    std::vector<Circusman> circus;
    int w, f;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> w >> f;
        Circusman tmp{w, f};
        circus.push_back(tmp);
    }
    sort(circus.begin(), circus.end(), [](Circusman x, Circusman y) { return x.w + x.f < y.w + y.f; });
    int M = 0;
    auto comparator = [](Circusman x, Circusman y) { return x.w > y.w; };
    std::multiset <Circusman, decltype(comparator)> tower(comparator);
    for (auto c: circus)
    {
        if (c.f >= M)
        {
            M += c.w;
            tower.insert(c);
        }
        else
        {
            int max_weight = tower.begin()->w;
            if (c.f >= M - max_weight && c.w < max_weight)
            {
                M -= max_weight;
                tower.erase(tower.begin());
                M += c.w;
                tower.insert(c);
            }
        }
    }
    std::cout << tower.size() << std::endl;
    return 0;
}