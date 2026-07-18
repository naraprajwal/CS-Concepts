#include<iostream>
using namespace std;
int main (){
    int n;
    cout<<"Enter a number - ";
    cin>>n;
    int Divisors_count=1;
    for (int i=1;i<n;i++){
        if (n%i==0)Divisors_count++;
        else continue;
    }
    if(Divisors_count==2)cout << "the numner is prime";
    else cout << "the number is not prime";
    return 0;
}