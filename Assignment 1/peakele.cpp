#include <bits/stdc++.h>
using namespace std;
int peakele(int a[], int l, int h)
{
    int m;
    if (l <= h)
    {
        m = l + ((h-1) / 2);
        if (m > 0 && (a[m] < a[m - 1]))
        return peakele(a, l, m-1);
        else if ((m < (h-1)) && (a[m] < a[m+1]))
        return peakele(a, m+1, h);
        else
        return m;
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,1};
    int ans = peakele(a, 0, 4);
    cout << ans;
    return 0;
}
