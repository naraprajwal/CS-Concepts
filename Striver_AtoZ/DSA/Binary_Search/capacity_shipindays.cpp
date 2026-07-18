

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int daysRequired(const vector<int>& weights, int capacity){
    int days = 1;
    int currentWeight = 0;

    for(int weight : weights){
        if(currentWeight + weight <= capacity){
            currentWeight += weight;
        }
        else{
            days++;
            currentWeight = weight;
        }
    }

    return days;
}

int shipWithinDays(vector<int>& weights, int days){
    int low = *max_element(weights.begin(), weights.end());
    int high = 0;
    for(int weight : weights)
        high += weight;

    int ans = high;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(daysRequired(weights, mid) <= days){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter the number of packages: ";
    cin >> n;

    vector<int> weights(n);
    cout << "Enter the package weights: ";
    for(int i = 0; i < n; i++)
        cin >> weights[i];

    int days;
    cout << "Enter the number of days: ";
    cin >> days;

    cout << "Minimum ship capacity: " << shipWithinDays(weights, days) << endl;

    return 0;
}