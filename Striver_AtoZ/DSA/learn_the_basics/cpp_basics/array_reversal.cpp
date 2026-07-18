#include <iostream>
using namespace std;

void arrayReversal(int arr[], int brr[], int n) {
    for(int i = 0; i < n; i++) {
        brr[i] = arr[n - 1 - i];
    }
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    int brr[n];

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    arrayReversal(arr, brr, n);

    cout << "Reversed array:\n";

    for(int i = 0; i < n; i++) {
        cout << brr[i] << " ";
    }

    cout << endl;

    return 0;
}