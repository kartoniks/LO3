#include<iostream>
#include<queue>
using namespace std;
queue<char> rle(string a)
{
    int q=1;
    queue<char>code;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i+1]==a[i])
        {
            q++;
        }
        if(a[i+1]!=a[i])
        {
            if(q>1)
            {
                code.push(q+48);
                code.push(a[i]);
            }
            else
                code.push(a[i]);
            q=1;
        }
    }
    return code;
}
int main()
{
    string a;
    cin>>a;
    queue <char> stefan;
    stefan=rle(a);
    cout<<"cr wynosi:"<<double(stefan.size())/double(a.length())<<endl;
    while(stefan.empty()==false)
    {
        cout<<stefan.front();
        stefan.pop();
    }
/*    int q=1;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i+1]==a[i])
        {
            q++;
        }
        if(a[i+1]!=a[i])
        {
            if(q>1)
                cout<<q<<a[i];
            else
                cout<<a[i];
            q=1;
        }
    }*/

    return 0;
}
