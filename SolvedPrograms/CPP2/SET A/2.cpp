#include<iostream>
#include<string>

using namespace std;

class prod{
    private:
        int p_id;
        string p_name;
        double p_price;
    
    public:
        void getDetails(){
            cout<<"Product ID: ";
            cin>>p_id;
            cout<<"Product Name: ";
            cin.ignore();
            getline(cin, p_name);
            cout<<"Product Price: ";
            cin>>p_price;
        }

        void displayDetails(){
            cout<<"\nProduct ID: "<<p_id<<endl;
            cout<<"Product Name: "<<p_name<<endl;
            cout<<"Product Price: "<<p_price<<endl;
        }
};

int main(){
    prod p1, p2;
    cout<<"Enter details for Product 1:"<<endl;
    p1.getDetails();
    cout<<"Enter details for Product 2:"<<endl;
    p2.getDetails();

    cout<<"\n--PRODUCT DETAILS--\n";
    p1.displayDetails();
    p2.displayDetails();
    return 0;
}