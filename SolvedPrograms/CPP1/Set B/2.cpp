#include<iostream>

using namespace std;

int main() {
    int n;
    long long TSS = 0, CTS = 0;

    cout << "Enter n: ";
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j >=i; ++j){
            CTS = CTS + j;
        }
        TSS = TSS + CTS;
    }

    cout<<"Total is: "<<TSS<<endl;

    cout<<"\n--CODED BY GAURANG DALAL--\n";

    return 0;
}