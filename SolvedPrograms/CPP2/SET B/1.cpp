#include<iostream>

using namespace std;

class cube{
    public:
        float len;
        float wid;
        float dep;

        void getData(){
            cout<<"Enter length: ";
            cin>>len;
            cout<<"Enter width: ";
            cin>>wid;
            cout<<"Enter depth: ";
            cin>>dep;
        }

        void volume(){
            float vol = len * wid * dep;
            cout<<"Volume of the cube is: "<<vol<<endl;
        }
};

int main(){
    cube c;
    c.getData();
    c.volume();
    return 0;
}