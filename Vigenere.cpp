#include<iostream>
using namespace std;

string szyfruj(string wejscie, string klucz)
{
    string szyfr;
    string dlugiklucz;
    dlugiklucz.resize(wejscie.length());
    szyfr.resize(wejscie.length());
    //cout << wejscie <<" "<< klucz;
    int z;
    for(int i=0; i<wejscie.length(); i++)
    {
        dlugiklucz[i]=klucz[i%klucz.length()];
    }
    for(int i=0; i<wejscie.length(); i++)
    {
        z=(wejscie[i]-97+dlugiklucz[i]-97)%26+97;
        szyfr[i]=z;
    }
    return szyfr;
}

string odszyfruj(string wejscie, string klucz)
{
    int z;
    for(int i=0; i<klucz.length(); i++)
    {
        z=(26-(klucz[i]-97))%26+97;
        klucz[i]=z;
    }
    return szyfruj(wejscie,klucz);
}

int main()
{
    string wejscie, klucz;
    cin >> wejscie >> klucz;
    string szyfr=szyfruj(wejscie, klucz);
    cout << szyfr <<"\n";
    string nowy=odszyfruj(szyfr,klucz);
    cout << nowy <<"\n";
    return 0;
}
