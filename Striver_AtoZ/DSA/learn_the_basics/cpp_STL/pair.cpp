#include<iostream>
using namespace std;

int main (){
    pair<int,int> p1 = {2,3};
    cout << p1.first << " " << p1.second<<endl;
    pair<int,pair<int,int>> p2 = {2,{1,2}};
    cout << p2.first <<" "<< p2.second.first<<" "<<p2.second.second;
    return 0;
}
