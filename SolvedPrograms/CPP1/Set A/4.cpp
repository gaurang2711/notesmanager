#include<iostream>

using namespace std;

int main(){
    int n, ogN, revN = 0;
    cout<<"Enter num: ";
    cin>>n;

    ogN = n;

    while(n > 0){
        int dig = n % 10;
        revN = (revN * 10) + dig;
        n = n / 10;
    }

    if(ogN == n){
        cout<<n<<" is Palindrome"<<endl;
    }
    else{
        cout<<n<<" is not Palindrome"<<endl;
    }

    cout<<"\n--CODED BY GAURANG DALAL--\n";

    return 0;
}
