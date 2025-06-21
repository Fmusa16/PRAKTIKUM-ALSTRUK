#include <iostream>
using namespace std;

bool isSortedAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {11, 12,25 ,34,64 };
    int arr2[] = {11, 12, 34, 25, 64};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSortedAscending(arr, n)) {
        cout << " Array terurut." << endl;
    } else {
        cout << "Array tidak urut." << endl;
    }

    if (isSortedAscending(arr2, n)) {
        cout << " Array terurut." << endl;
    } else {
        cout << "Array tidak urut." << endl;
    }
    
    return 0;
    return 1;
}