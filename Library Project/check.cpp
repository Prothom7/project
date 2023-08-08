#include<iostream>

using namespace std;


int main()
{
    int test;
    cin>>test;

    for(int i=0;i<test;i++)
    {
        int n;
        cin>>n;
        int array[n];
        int sum1;
        int sum2=0;

        for(int j=0;j<n;j++)
        {
            cin>>array[j];
        }


        for(int j=1;j<n;j++)
        {
            sum2+=array[j];

        }

        
if(array[0]!=1&&array[0]!=0)
{
         if(array[0]%2==0&&sum2%2!=0)
        cout<<"NO\n";

        else if(array[0]%2!=0&&sum2%2==0)
        cout<<"NO\n";

        else
        cout<<"YES\n";

}

       else
       {

        if(array[0]==1)
        {
        if(sum2%2!=0)
        cout<<"YES\n";

        else
        cout<<"NO\n";
        }

        else
        {
            if(sum2%2==0)
        cout<<"YES\n";

        else
        cout<<"NO\n";
        }

       } 
        
    }
}