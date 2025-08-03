#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
 
    if(n <= 0){
        cout<<"Not possible";
        return -1;
    }

    for(int i = 1; i <= 10; i++){
        cout<<n<<" * "<<i<<" = "<<n*i<<endl;
    }

    cout<<"\n--CODED BY GAURANG DALAL--\n";

    return 0;
}