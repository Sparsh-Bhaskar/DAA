#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do 
    {
        do { i++; } while (a[i] <= pivot);
        do { j--; } while (a[j] > pivot);
        if ( i < j) swap( &a[i], &a[j] );
    }
    while ( i < j );
    swap( &a[l], &a[j]);
    return j;
}

void quicksort(int a[], int l, int h)
{
    int j;
    if ( l < h)
    {
        j = partition(a, l, h);
        quicksort(a, l, j);
        quicksort(a, j+1, h);
    }
}

int main()
{
    int a[] = {4, 2, 6, 9, 2};
    cout << "input array is: " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    quicksort(a, 0, 5);

    cout << "sorted array is: " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
