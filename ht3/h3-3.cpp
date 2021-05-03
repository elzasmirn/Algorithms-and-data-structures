/*Инверсии
Известно, что сложность сортировки может определяться числом инверсий — пар элементов последовательности, расположенных не в надлежащем порядке.
Например, в последовательности {4,5,1,2}, которую нужно упорядочить по неубыванию, имеются следующие пары, образующие инверсии: (4,1), (4,2), (5,1), (5,2).
Требуется установить, а сколько же инверсий в заданной последовательности длины N, которую нужно упорядочить по неубыванию. 
Имеется не более 10000000 целых чисел, каждое из которых лежит в диапазоне от -1000000000 до 1000000000.
Input format
N
A1
A2
...
AN
Output format
Количество инверсий в последовательности*/

#include <iostream>

using namespace std;

void merge_sort(int* array, int array_size, unsigned long long* num_of_inv)
{
    if (array_size <= 1) return;
    
    int middle = array_size / 2;
    int left_size = middle;
    int right_size = array_size - middle;
    int* left = array;
    int* right = array + left_size;

    merge_sort(left, left_size, num_of_inv);
    merge_sort(right, right_size, num_of_inv);
    
    int left_index = 0;
    int right_index = 0;
    int index = 0; 
    int* temp_array = new int[array_size];
    while (left_index < left_size && right_index < right_size)
    {
        if (left[left_index] <= right[right_index])
            temp_array[index++] = left[left_index++];
        else 
        {
            temp_array[index++] = right[right_index++];
            *num_of_inv += left_size - left_index;
        }
    }
    
    while (left_index < left_size)
        temp_array[index++] = left[left_index++];
    while (right_index < right_size)
        temp_array[index++] = right[right_index++];
        
    for (int i = 0; i < array_size; i++)
        array[i] = temp_array[i];
    delete[] temp_array;
}

int main()
{
    int n, tmp;
    unsigned long long num_of_inv = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        arr[i] = tmp;
    }

    merge_sort(arr, n, &num_of_inv);

    cout << num_of_inv << endl;
    delete [] arr;
    return 0;
}