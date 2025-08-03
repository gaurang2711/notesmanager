#include<iostream>

using namespace std;
int main(){
    int n;
    int a = 0, b = 1, i;
    int next = a + b;

    cout<<"Enter n: ";
    cin>>n;

    if(n == 0){
        cout<<"Not possible";
        return -1;
    }

    if(n == 1){
        cout<<a;
        return 0;
    }

    cout<<a<<" "<<b<<" ";

    for(i = 1; i < n - 1; i++){
        cout<<next<<" ";
        a = b;
        b = next;
        next = a + b;
    }

    cout<<"\n--CODED BY GAURANG DALAL--\n";

    return 0;
} 