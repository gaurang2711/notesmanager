#include<iostream>

using namespace std;

int main(){
	int n;
	int temp;
	int res = 0;
	cout<<"Enter number: ";
	cin>>n;
	temp = n;
	while(temp != 0){
		int rem = temp % 10;
		res = res + (rem * rem * rem);
		temp = temp / 10;
	}
	if(n == res){
		cout<<n<<" is an Armstrong number"<<endl;
	}
	else{
		cout<<n<<" is not an Armstrong number"<<endl;
	}

	return 0;
}