#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mycomp(pair<int,int> a,pair<int,int> b)
{
    double r1 = (double)a.first/a.second;
    double r2 = (double)b.first/b.second;

    return r1 > r2;
}

double fknapsack(int w,pair<int,int> arr[],int n)
{
    sort(arr,arr + n,mycomp);

    double res = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i].second <= w)
        {
            res += arr[i].first;
            w = w - arr[i].second;
        }
        else{
            res += arr[i].first*((double)w/arr[i].second);
            break;
        }
    }

    return res;
}

int main()
{
    pair<int, int> arr[] = {{60, 10}, {100, 20}, {120, 30}};
    cout << "maxm profit : " << fknapsack(50,arr,3);
    return 0;
}
