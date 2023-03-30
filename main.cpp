/*
Nama 		: Devina Lusiana
NIM 		: 211511011
Tanggal 	: 18 Mei 2022
Mata Kuliah : Struktur Data & Algoritma
*/

#include <iostream>
#include <limits>
#include "heap.h"
#include "list.h"
using namespace std;

int main()
{
    List L;
    address P;

    CreateList(&L);

    int i = 1;
    int data;

    menuHeapSort();
    for (;;)
    {
        cout << "Masukkan angka ke " << i << ": ";
        while (!(cin >> data))
        {
            cout << "Input salah, silahkan masukkan angka (bilangan bulat) : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
        }
        if (data == 00)
        {
            break;
        }
        InsVLast(&L, data);
        i++;
    }
    cout << endl << "Data yang anda masukkan: ";
    PrintInfo(L);
    cout << endl;

    HeapSort(L);

    return 0;
}
