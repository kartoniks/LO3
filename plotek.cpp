#include<iostream>
using namespace std;
string cipher(string m, int k)
{
    string c=m;
    int n=0;
    for(int i=0; i<k; i++)
        for(int j=i; j<m.size(); j+=k)
        c[n++]=m[j];
    return c;
}

string de(string c, int k)
{
    string m=c;
    int n=0;
    for(int i=0; i<k; i++)
    {
        for(int j=i; j<c.size(); j+=k)
            m[j]=c[n++];
    }
    return m;
}
int main()
{
    string text;
    int key;
    cin >> text >> key;
    cout << cipher(text, key)<<"\n";
    string code=cipher(text, key);
    cout << de(code,key);
    return 0;
}
