#include<iostream>

using namespace std;

class rectangle{
    public:
        float len;
        float bre;
    
    void getData(){
        cout<<"Enter length: ";
        cin>>len;
        cout<<"Enter breadth: ";
        cin>>bre;
    }
    void showData(){
        float area = len * bre;
        float peri = 2 * (len + bre);
        cout<<"Area of rectangle: "<<area<<endl;
        cout<<"Perimeter of rectangle: "<<peri<<endl;
    }
};

int main(){
    rectangle r;
    r.getData();
    r.showData();
    return 0;
}
