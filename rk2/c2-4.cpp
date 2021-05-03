/*Анаграммы
Как известно, анаграммами называются слова, которые могут получиться друг из друга путём перестановки букв, например LOOP, POOL, POLO. 
Будем называть все слова такого рода комплектом.
Требуется определить число комплектов во входном множестве.
Input format
На вход программы подаётся число слов 1⩽N⩽100000. 
В каждой из очередных N строк присутствует одно слово, состоящее из заглавных букв латинского алфавита. 
Все слова имеют одинаковую длину 3⩽L⩽10000.
Output format
NumberOfComplects*/

#include <stdio.h>
#include <string>
#include <set>
#include <vector>

int main()
{
    unsigned N, cnt = 0;
    scanf("%u", &N);
    char s[10001];
    std::set < std::vector <unsigned> > classes;
    while (N--)
    {
        scanf("%s", s);
        std::string str(s);
        std::vector <unsigned> freq(26);
        for (auto elem: str)
        {
            freq[elem - 'A'] += 1;
        }
        if (classes.find(freq) == classes.end())
        {
            classes.insert(freq);
            cnt++;
        }
    }
    printf("%u\n", cnt);
    return 0;
}