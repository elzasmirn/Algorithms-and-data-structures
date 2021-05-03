/*Чуждые элементы
Последовательность из 2⩽N⩽1000000 элементов содержит натуральные числа от 1 до 1018. Назовём пару соседних чисел, которая имеет общие множители, большие единицы, родственниками. 
В исходную последовательность вставляют натуральные числа (чуждые элементы) таким образом, что в итоговой последовательности не остаётся родственников. Требуется определить минимально возможную сумму чуждых элементов. 
Пример: в исходную последовательность
4 8 9 10
можно вставить чуждый элемент 5 после 4:
4 5 8 9 10
после чего последовательность не содержит родственников.
Input format
N
X1
X2
...
XN
Output format
Sum*/

#include <stdio.h>

unsigned int gcd(unsigned int u, unsigned int v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}

int main()
{
    unsigned n;
    scanf("%u", &n);
    unsigned long long prev;
    scanf("%llu", &prev);
    unsigned long long cur;
    unsigned long long res = 0;
    while(--n)
    {
        scanf("%llu", &cur);
        res += (gcd(prev, cur) > 1);
        prev = cur;
    }
    printf("%llu\n", res);
    return 0;
}