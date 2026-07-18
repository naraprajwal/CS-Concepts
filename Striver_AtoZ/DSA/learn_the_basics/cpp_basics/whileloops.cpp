#include<iostream>
using namespace std;

int main (){
    int d;
    std::cout << "enter the value of d - "  << std::endl;
    std::cin >> d;
    int i=0;
    int temp=d;
    int sum=0;
    while(i<50){
        sum += temp;
        temp += 10;
        i++;
        //std::cout << i << std::endl;
    }
    std::cout << sum << std::endl;
    return 0;
}