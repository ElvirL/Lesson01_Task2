/*
Задание 2. Сортировка

Что нужно сделать:
Пользователь вводит в консоль 15 дробных чисел. Необходимо прочитать их и вывести в консоль в порядке от большего к меньшему. 
По возможности используйте минимум дополнительной памяти и проходов по массиву.

Пример:

Ввод: 1.2 2.3 1.11 3.4 5.5 5.4 5.3 5.1 1.5 1.25 5.41 5.31 5.11 1.51 1.251
Вывод: 5.5 5.41 5.4 5.31 5.3 5.11 5.1 3.4 2.3 1.51 1.5 1.251 1.25 1.2 1.11

*/

#include <iostream>

using namespace std;

void merge(float list[], int start, int end, int mid){
    float mergedList[15];
    int i,j,k;
    i = start;
    k = start;
    j = mid + 1;

    while (i <= mid && j <= end){
        if (list[i] > list[j]){
            mergedList[k] = list[i];
            ++k;
            ++i;
        }
        else {
            mergedList[k] = list[j];
            ++k;
            ++j;
        }
    }

    while (i <= mid){
        mergedList[k] = list[i];
        ++k;
        ++i;
    }

    while (j<=end){
        mergedList[k] = list[j];
        ++k;
        ++j;
    }

    for (i = start; i<k; ++i){
        list[i] = mergedList[i];
    }
}

void mergeSort(float list[], int start, int end){
    int mid;
    if (start < end){
        mid = (start+end)/2;
        mergeSort(list,start,mid);
        mergeSort(list,mid+1,end);
        merge(list,start,end,mid);
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    float numbers[15];
    cout << "Ввод: ";
    for (int i=0; i<15; ++i){
        cin >> numbers[i];
    }


    mergeSort(numbers, 0, 14);

    cout << "Вывод: ";
    for (int i=0; i<15; ++i){
        cout << numbers[i] << " ";
    }


}