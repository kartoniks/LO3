#include<iostream>
using namespace std;
int rekur(int a, int b)
{
    if(b==0)
        return a;
    else
        return rekur(b, a%b);

}
int iter(int a, int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int a,b;
    cin >> a >> b;
    cout<<iter(a,b)<<"\n"<<rekur(a,b);


    return 0;
}
