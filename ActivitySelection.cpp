#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mycomp(pair<int,int> a,pair<int,int> b)
{
    return (a.second < b.second);
}

int maxActivity(pair<int,int> arr[],int n)
{
    sort(arr,arr+n,mycomp);
    int prev = 0;
    int res = 0;

    for(int curr = 0; curr < n; curr++)
    {
        if(arr[curr].first >= arr[prev].second)
        {
            prev = curr;
            res++;
        }
    }

    return res;
}

int main()
{
   pair<int,int> arr[] = {{4, 7}, {1, 3}, {6, 10}, {2, 5}, {8, 9}};

   cout << "maximum number activities can be : "<< maxActivity(arr,6) << endl;

    return 0;
}
