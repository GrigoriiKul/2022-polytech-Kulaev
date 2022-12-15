#include <random>
#include <iostream>
#include <chrono>
#include <Windows.h>



using namespace std;


void fill_array_random(int arr[], int n, int a, int b)
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(a, b);

    for (int i = 0; i < n; ++i)
    {
        arr[i] = dist(rng);
    }
}


void swap(int arr[], int idx_a, int idx_b)
{
    int temp = arr[idx_a];
    arr[idx_a] = arr[idx_b];
    arr[idx_b] = temp;
}


void selection_sort(int arr[], int n)
{
    int count, key;
    for (int i = 0; i < n - 1; i++)
    {
        count = arr[i];
        key = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[key]) key = j;
        }
        if (key != i)
        {
            arr[i] = arr[key];
            arr[key] = count;
        }
    }
}


int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr, pivotIndex, start);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr, i, j);
            i++;
            j--;
        }
    }

    return pivotIndex;
}


void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int p = partition(arr, start, end);
    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
}


void main()
{
    while (true)
    {
        int size = 0;
        char skip;
        setlocale(LC_ALL, "rus");
        cout << "Ââåäèòå ðàçìåð ìàññèâà" << endl;
        cin >> size;
        system("cls");
        int* arr = new int[size];
        fill_array_random(arr, size, 0, 100);
        auto begin = chrono::steady_clock::now();
        quick_sort(arr, 0, size - 1);
        auto end = chrono::steady_clock::now();
        auto elapsed_ms = chrono::duration_cast <chrono::nanoseconds> (end - begin);
        fill_array_random(arr, size, 0, 100);
        begin = chrono::steady_clock::now();
        selection_sort(arr, size);
        end = chrono::steady_clock::now();
        auto elapsed_ms2 = chrono::duration_cast <chrono::nanoseconds> (end - begin);
        cout << "Ðàçìåð ìàññèâà: " << size << endl << elapsed_ms2.count() * 0.000000001 << " (ss), "
            << elapsed_ms.count() * 0.000000001 << " (qs)" << endl;
        cout << "Ââåäèòå ëþáîé ñèìâîë, åñëè âû õîòèòå âûáðàòü ñëåäóþùèé ðàçìåð ìàññèâà" << endl
            << "Åñëè âû õîòèòå çàêðûòü ïðîãðàììó, ââåäèòå q" << endl;
        cin >> skip;
        if (skip == 'q')
        {
            break;
        }
        system("cls");
        delete[] arr;
    }
}