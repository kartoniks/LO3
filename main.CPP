#include<iostream>
#include<cstdlib>
#include<fstream>
#include<windows.h>
using namespace std;
void dodaj()
{
    fstream plik;
    plik.open( "key.txt", ios::out | ios::app );
    cout<<"Podaj slowo:\n";
    string w;
    cin >> w;
    plik << w<<" ";
    cout<<"Podaj definicje:\n";
    cin >> w;
    plik << w<<"\n";
    plik.close();
}
int main()
{
    int z;
    while(true)
    {
        system("cls");
        cout<<"1.Dodaj nowe slowo\n2.Zamknij\n";
        z=getchar();
        z-=48;
        switch(z)
        {
        case 1:
            dodaj();
            break;
        case 2:
            return 0;
        }
    }



    return 0;
}
