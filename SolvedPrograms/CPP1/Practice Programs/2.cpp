#include<iostream>

using namespace std;

int main(){
	int n1, n2, n3;
	int max;
	cout<<"Enter 3 numbers: ";
	cin>>n1>>n2>>n3;
	
	if(n1 > n2){
		max = n1;
	}
	else{
		max = n2;
	}
	
	if(max < n3){
		max = n3;
	}
	else{
		//eat 5 star and do nothing;
	}
	
	cout<<"Maximum no. is: "<<max<<endl;
	
	cout<<"\n--CODED BY GAURANG DALAL--\n";
		
	return 0;
}