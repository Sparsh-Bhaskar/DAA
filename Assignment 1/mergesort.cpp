#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int mid, int h)
{
    int i, j, k;
    int b[h+1];
    i = l;
    j = mid + 1;
    k = l;
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
        b[k++] = a[i++];
        else 
        b[k++] = a[j++];
    }
    for(; i <= mid; i++)
    b[k++] = a[i];
    for(; j <= h; j++)
    b[k++] = a[j];
    for(i = l; i <= h; i++)
    a[i] = b[i];
    
}

void mergesort(int a[], int l, int h)
{
    int mid;
    if ( l <  h)
    {
        mid = (l + h) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {12, 11, 13, 5, 6, 7};
    cout << "input array is: " << endl;
    for(int i = 0; i <= 5; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    mergesort(a, 0, 5);
    cout << "sorted array is: " << endl;
    for(int i = 0; i <= 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
