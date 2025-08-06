#include<iostream>

using namespace std;

class student{
    public:
        int rollno;
        float percentage;
        void getDetials(){
            cout<<"Roll no: ";
            cin>>rollno;
            cout<<"Percetages: ";
            cin>>percentage;
        }
        void displayDetails(){
            cout<<"Roll no: "<<rollno<<endl;
            cout<<"Percentage: "<<percentage<<endl;
        }
};

int main(){
    student s1, s2;
    cout<<"Enter details for student 1: "<<endl;
    s1.getDetials();
    cout<<"Enter details for student 2: "<<endl;
    s2.getDetials();

    cout<<"STUDENT WITH HIGHER PERCENTAGES\n";
    if (s1.percentage > s2.percentage)
    {
        s1.displayDetails();
    }
    else{
        s2.displayDetails();
    }
    
}