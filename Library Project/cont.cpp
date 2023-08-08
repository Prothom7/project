#include<iostream>

using namespace std;

class member
{
    public:
    int x;

    void getx()
    {
        x=7;
        cout<<x;
    }
};

int main()
{
    member Y;
    Y.x=0;

    cout<<Y.x;

    Y.getx();

}