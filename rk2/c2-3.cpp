/*Точные суммы
Умеете ли вы быстро искать нужное? На вход программы подаётся массив V размером 10⩽N⩽100000 целых чисел, каждое из которых лежит в диапазоне от -109 до 109 и 1⩽M⩽100000 образцов. 
Для каждого образца требуется определить, существует ли такая пара чисел, принадлежащих массиву, которая даёт в сумме ровно значение образца.
Input format
N M
V1
V2
...
VN
P1
P2
...
PM
Output format
Требуется вывести ровно M строк. Если не существует такой пары чисел в массиве, сумма которых равна Pi, то нужно вывести строку Not found. 
Если же такая пара существует, нужно её вывести в порядке неубывания. Если таких пар несколько, вывести ту из возможных пар, первый элемент которой наименьший из всех возможных.*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    unsigned N, M;
    scanf("%u%u", &N, &M);
    int elem;
    vector <int> V;
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &elem);
        V.push_back(elem);
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < M; ++i)
    {
        scanf("%d", &elem);
        vector<int>::iterator left = V.begin();
        vector<int>::iterator right = V.end() - 1;
        bool f = false;
        while (left != right && !f)
        {
            int sum = *left + *right;
            if (sum > elem) right--;
            else if (sum < elem) left++;
            else
            {
                f = 1;
                printf("%d %d\n", *left, *right);
            }
        }
        if (!f) printf("Not found\n");
    }
    return 0;
}