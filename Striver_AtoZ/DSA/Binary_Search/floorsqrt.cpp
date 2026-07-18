#include<iostream>
#include<vector>
using namespace std;

int floorsqrt(int n){
    int i=1;
    while (i*i<n){
        if (i*i==n)return i;
        i*=2;
    }
    //cout<<i<<endl;
    int low = i/2;
    int high = i;
    //cout<<low<<" "<<high<<endl;
    while (low<=high){
        int mid = (low+high)/2;
        //cout<<mid<<endl;
        int temp=mid*mid;
        if (temp==n)return mid;

        else if (temp>n){
            high=mid-1;
            if (high*high<=n)return high;
        }
        else {
            low=mid+1;
            if (low*low>n)return mid;
        }
    }
    return -1;
}



int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Floor square root: " << floorsqrt(n) << endl;

    return 0;
}