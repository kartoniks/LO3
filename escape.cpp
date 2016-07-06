#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<queue>
using namespace std;
char board[20][20];

void display()
{
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++)
            cout<<board[i][j];
        cout<<"\n";
    }
}
int playerx=10;
int playery=10;

int enemyx=2;
int enemyy=2;
void prepare(){
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
        board[i][j]='.';
}
void setobstacle(){
    for(int i=0; i<5; i++)
        {
            board[3][i+3]='O';
            board[17][i+12]='O';
            board[i+3][3]='O';
            board[i+13][17]='O';
        }
}
bool checkenemy(){
    if(playerx==enemyx && playery==enemyy)
        return true;
    else
        return false;
}

int bfs(int x, int y)
{
    if(board[x][y]=='O')
        return 9999;
    int see[20][20];
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            see[i][j]=9999;
    see[x][y]=0;
    queue<int> qx;
    queue<int> qy;
    qx.push(x);
    qy.push(y);
    int fir;
    int sec;
    while(true)
    {
        fir=qx.front();
        sec=qy.front();
        qx.pop();
        qy.pop();
        char direc;
        if(fir>0 && board[fir-1][sec]!='O' && see[fir-1][sec]==9999){
            qx.push(fir-1);
            qy.push(sec);
        }
        if(fir<19 && board[fir+1][sec]!='O' && see[fir+1][sec]==9999){
            qx.push(fir+1);
            qy.push(sec);
        }
        if(sec>0 && board[fir][sec-1]!='O' && see[fir][sec-1]==9999){
            qx.push(fir);
            qy.push(sec-1);
        }
        if(sec<19 && board[fir][sec+1]!='O' && see[fir][sec+1]==9999){
            qx.push(fir);
            qy.push(sec+1);
        }
        if(see[fir][sec]>see[fir-1][sec])
            see[fir][sec]=see[fir-1][sec]+1;
        if(see[fir][sec]>see[fir+1][sec])
            see[fir][sec]=see[fir+1][sec]+1;
        if(see[fir][sec]>see[fir][sec-1])
            see[fir][sec]=see[fir][sec-1]+1;
        if(see[fir][sec]>see[fir][sec+1])
            see[fir][sec]=see[fir][sec+1]+1;
        if(board[fir][sec]=='X')
            return see[fir][sec];
    }

}
void movenemy(int x, int y, int (*f)(int,int)){
    int u=bfs(x+1,y);
    int d=bfs(x-1,y);
    int l=bfs(x,y-1);
    int r=bfs(x,y+1);
    board[enemyx][enemyy]='.';
    if(min(min(d,u),min(l,r))==u)
        enemyx++;
    else if(min(min(d,u),min(l,r))==d)
        enemyx--;
    else if(min(min(d,u),min(l,r))==l)
        enemyy--;
    else if(min(min(d,u),min(l,r))==r)
        enemyy++;
}

int main()
{
    prepare();
    setobstacle();
    int time=1;
    while(time++)
    {
        board[playerx][playery]='.';
        if(GetAsyncKeyState(VK_UP) && board[playerx-1][playery]!='O' && playerx>0)
            playerx--;
        else if(GetAsyncKeyState(VK_DOWN)&& board[playerx+1][playery]!='O' && playerx<19)
            playerx++;
        else if(GetAsyncKeyState(VK_LEFT)&& board[playerx][playery-1]!='O' && playery>0)
            playery--;
        else if(GetAsyncKeyState(VK_RIGHT)&& board[playerx][playery+1]!='O' && playery<19)
            playery++;
        board[playerx][playery]='X';
        if(time%2==0)
            movenemy(enemyx, enemyy, &bfs);
        board[enemyx][enemyy]='E';
        if(checkenemy())
        {
            cout<<"KONIEC GRY";
            int a;
            cin>>a;
            break;
        };
        display();
        Sleep(200);
        system("cls");
    }


    return 0;
}
