#include<iostream>
using namespace std ;

int main (){
    int n,n_amstrong=0;
    cout << "enter a number - ";
    cin>>n;
    int temp1=n;
    int digits = (int)log10(abs(n))+1;
    for (int i=0;i<digits;i++){
        int temp2 = temp1%(int)pow(10,1);
        n_amstrong += (int)pow(temp2,digits);
        temp1 = (int)temp1/10; 
    }
    if (n==n_amstrong)cout <<"The number is Amstrong NUmber";
    else cout <<"The number is not Anstrong NUmber";

    return 0;

}