#include <bits/stdc++.h>
using namespace std;

int binsearch(int a[], int l, int h, int key)
{
    int mid;
    if(l <= h)
    {
        mid = (l + h) / 2;
        if (key == a[mid])
        return mid;
        else if(key < a[mid])
        return (binsearch(a, l, mid - 1, key));
        else
        return binsearch(a, mid + 1, h, key);
    }
    return 0;
}

int main()
{
    int a[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    if(binsearch(a, 0, 9, 23))
    cout << "number is present" << endl;
    else
    cout << "number is not present" << endl;
    return 0;
}
