#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    int last = n - 1;

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < last; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        --last;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << endl << "Prepared by 23ce114 Pranjal Patil" << endl;
    return 0;
}
