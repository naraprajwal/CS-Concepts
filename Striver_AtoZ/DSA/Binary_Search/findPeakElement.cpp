#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& arr){
    int low = 0;
    int high = arr.size() - 1;

    while(low < high){
        int mid = low + (high - low) / 2;

        if(arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Peak element index: " << findPeakElement(arr) << endl;

    return 0;
}
