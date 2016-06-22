#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>

using namespace std;

char tab[5][50];
int zle[50];
int a=2, b=0, score=0, level;

void narysuj(){
    for(int i=0;i<5;i++){
        for(int x=0;x<50;x++){
            cout << tab[i][x];
        }
        cout << endl;
    }
}

bool kont(int x, int y){
    if(zle[y]==x){
        return 0;
    }
    return 1;
}

void ruch(char x){
    if(x=='s'){
        a++;
    }
    if(x=='w'){
        a--;
        tab[a][b+1]=='.';
    }
}

void gra(){
    Sleep(1000);
    while(b<49){
        char z='g';
        tab[a][b]='.';
        if(kbhit())
            z=getch();
        ruch(z);
        system("cls");
        b++;
        if(tab[a][b]=='*'){
            score+=10;
        }
        if(kont(a, b)){
        tab[a][b]='x';
        narysuj();
        Sleep(800-level);
        }
        else
            break;
    }
}

int main(){
    srand(time(NULL));
    cout << "Witaj w Torze z Przeszkodami!" << endl << "Postaraj sie dojsc do konca toru nie trafiajac w przeszkode (# to przeszkoda, * to punkty)"<< endl << "Sterowanie: w - gora, s- dol" << endl;
    system("PAUSE");
    for(int i=0;i<5;i++){
        for(int x=0;x<50;x++){
            tab[i][x]='.';
        }
    }
    cout << "Wybierz poziom trudnoci: 1 - 5";
    cin >> level;
    level*=100;
    tab[a][b]='x';
    for(int i=1;i<50;i++){
        int a=rand()%5;
        tab[a][i]='#';
        int b=rand()%5;
        while(b==a){
            b=rand()%5;
        }
        zle[i]=a;
        tab[b][i]='*';
    }
    while(tab[a][b+1]=='#'){
        tab[a][b+1]=='.';
        tab[rand()%5][b+1]='#';
    }
    system("cls");
    narysuj();
    gra();
    system("cls");
    if(b==49){
        cout << "Wygrales!!!" << endl << "Zdobyles " << score << " punktow!" << endl;
    }
    else
        cout << "Przegrana!" << endl;
    system("PAUSE");
    return 0;
}
