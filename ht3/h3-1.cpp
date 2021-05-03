/*Подсчёт частот
На вход подаётся строка, состоящая из букв A-Z. Необходимо вывести все буквы, которые встречаются в строке в порядке убывания частот вместе с частотой. 
В случае равенства частот первой должна идти буква, которая встречается в алфавите раньше.
Input format
Строка из букв A-Z
Output format
L1 C1
...
Lk Ck
где Li — буква, входящая с строку, Ci — число вхожданий буквы в строку.*/

#include <stdio.h>
#include <map>
#include <set>
#include <iostream>

using namespace std;

int main()
{
    map <char, int> freq;
    int c;
    while ((c = getchar()) != '\n')
    {
        freq[c] += 1;
    }
    auto val_comp = [](const pair<char, int>& p1, const pair<char, int>& p2) {return p1.second > p2.second;};
    std::multiset < pair<char, int>, decltype(val_comp) > m_set {freq.begin(), freq.end(), val_comp};
    for (const auto& p: m_set) cout << p.first << ' ' << p.second << endl;
    return 0;
}