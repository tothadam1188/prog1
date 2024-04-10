#include <iostream>
#include <windows.h>
#include <unistd.h>

using namespace std;
struct Coordinates
{
    int x;
    int y;
};

void ClearScreen()
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Movement(Coordinates &pos, Coordinates &dir)
{
    const int XBORDER_MIN = 0;
    const int XBORDER_MAX = 30;
    const int YBORDER_MIN = 0;
    const int YBORDER_MAX = 17;
    if(pos.x == XBORDER_MIN && dir.x == -1 )
    {
        dir.x=1;
    }
    if(pos.x == XBORDER_MAX && dir.x == 1 )
    {
        dir.x=-1;
    }
    if(pos.y == YBORDER_MIN && dir.y == -1 )
    {
        dir.y=1;
    }
    if(pos.y == YBORDER_MAX && dir.y == 1 )
    {
        dir.y=-1;
    }
    pos.x=pos.x+dir.x;
    pos.y=pos.y+dir.y;
};

void ScreenPrint(const Coordinates pos)
{
    cout<<"\t ";
    for(int i=0; i<31; i++) cout<<"_";
    cout<<endl;
    for(int i=0; i<18; i++)
    {
        cout<<"\t|";
        for(int j=0; j<31; j++)
        {

            if(i==-pos.y+17 && j==pos.x) cout<<'o';
            else cout<<' ';
        }
        cout<<"|"<<endl;
    }
    cout<<"\t ";
    for(int i=0; i<31; i++) cout<<"-";
    cout<<endl;
};

int main()
{
    string directionString;
    Coordinates location;
    location.x=15;
    location.y=8;
    Coordinates movement;
    cout << "Please input the ball's movement direction (N - E - S - W and combinations)"<<endl;
    cin >> directionString;
    if(directionString.find('N')!=string::npos || directionString.find('n')!=string::npos) movement.y = 1;
    if(directionString.find('S')!=string::npos || directionString.find('s')!=string::npos) movement.y = -1;
    if(directionString.find('E')!=string::npos || directionString.find('e')!=string::npos) movement.x = 1;
    if(directionString.find('W')!=string::npos || directionString.find('w')!=string::npos) movement.x = -1;
    system("CLS");
    while(true)
    {
        ScreenPrint(location);
        Movement(location,movement);
        usleep(30000);
        ClearScreen();
    }
    return 0;
}
