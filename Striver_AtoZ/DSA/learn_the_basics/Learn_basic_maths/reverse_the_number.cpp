#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n,n_new=0;
    cout << "Enter an integer - ";
    cin >> n;
    int temp1=n;
    int digits = (int)log10(abs(n))+1;
    for (int i=0;i<digits;i++){
        int temp2 = temp1%(int)pow(10,1);
        n_new += temp2*(int)pow(10,digits-1-i);
        temp1 = (int)temp1/10; 
    }
    cout << n_new;
    return 0;
}