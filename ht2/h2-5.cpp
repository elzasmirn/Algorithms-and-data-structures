/*Количество подстрок
Назовём подстрокой любой набор подряд идущих символов строки. Например, в строке aba можно найти три подстроки длины один: a, b, a, две подстроки длины два: ab и ba, а также одну подстроку длины 3: aba.
Две подстроки здесь совпадают, поэтому различных подстрок здесь 5.
Нужно для заданной строки, состоящей из строчных букв латинского алфавита, определить, сколько в ней можно найти различных подстрок.
Input format
Строка, длиной от 5 до 10000 символов.
Output format
Количество различных подстрок в данной строке.*/

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    char buff[10001];
    scanf("%10000s", buff);
    std::string s(buff);
    int n = (int)s.size();
    std::vector<int> prefix(n + 1);
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        prefix[1] = 0;
        int len = 0;
        int max = 0;
        for (int i = 1; i < n; i++)
        {
            while (true)
            {
                if (s[i] == s[len])
                {
                    len++;
                    break;
                }
                if (!len)
                {
                    break;
                }
                len = prefix[len];
            }
            prefix[i + 1] = len;
            max = std::max(len, max);
        }
        sum += (int)s.size() - max;
        s.erase(s.begin());
    }
    printf("%d", sum);
}