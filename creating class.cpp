#include<iostream>
using namespace std;
class car
{
    private:
    string company;
    string model;
    int year;

    public:
    void setdata()
    {
        cout<<"Enter comp name:"<<endl;
        cin>>company;
        cout<<"Enter mod name:"<<endl;
        cin>>model;
        cout<<"Enter year:"<<endl;
        cin>>year;

    }
    void getdata()
    {
        cout<<"The name of the company:"<<company<<endl;
        cout<<"The name of the model:"<<model<<endl;
        cout<<"The year is:"<<year<<endl;
    }

};

int main()
{
    car c;
    c.setdata();
    c.getdata();
    return 0;

}
