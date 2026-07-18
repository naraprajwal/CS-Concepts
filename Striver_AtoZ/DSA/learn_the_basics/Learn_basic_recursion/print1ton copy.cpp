#include <iostream>
using namespace std;

int sum_n(int n){
    if(n>1) return n+sum_n(n-1);
    else return 1;
}
int main (){
    int n;
    cin>>n;
    sum_n(n);
    return 0;
}