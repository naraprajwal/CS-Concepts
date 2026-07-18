#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int floorsqrt(int m,int n){
    //cout<<i<<endl;
    int low = 1;
    int high = m;
    //cout<<low<<" "<<high<<endl;
    while (low<=high){
        int mid = (low+high)/2;
        //cout<<mid<<endl;
        int temp=pow(mid,n);
        if (temp==m)return mid;

        else if (temp>m){
            high=mid-1;
            if (pow(high,n)<=m)return high;
        }
        else {
            low=mid+1;
            if (pow(low,n)>m)return mid;
        }
    }
    return -1;
}



int main(){
    int n, m;

    cout << "Enter n (root): ";
    cin >> n;

    cout << "Enter m (number): ";
    cin >> m;

    cout << "Nth root: " << floorsqrt(m, n) << endl;

    return 0;
}