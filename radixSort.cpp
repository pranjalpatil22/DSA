#include <iostream>

using namespace std;

int digits(int arr[], int n)
{
    int digit = 0;
    int maxm = -1;
    for(int i = 0; i < n; i++)
    {
        if(maxm < arr[i])
            maxm = arr[i];
    }

    while(maxm > 0)
    {
        maxm = maxm/10;
        digit++;
    }
    return digit;
}
void radixSort(int arr[], int n)
{
    int div = 1;
    int num = digits(arr,n);

    int bucket[10][n];

    for(int i = 0; i < num; i++)
    {
        int k = 0;
        int buck[10] = {0};
        for(int j = 0; j < n; j++)
        {
            int l = (arr[j]/div)%10;
            bucket[l][buck[l]++] = arr[j];

        }

        for(int l=0; l<10; l++)
        {
            for(int m=0; m<buck[l]; m++)
            {
                arr[k++]=bucket[l][m];
            }
        }

        div = div*10;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {76,54,43,21,1};
    radixSort(arr,5);
    return 0;
}
