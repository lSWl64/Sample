#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
#define MAX_X 13
#define MAX_Y 6

void gotoxy(int x, int y);
int Tic_Tac_Toe(char arr[7][14]);

int main() {
 bool playerCheck = true;
 int X = (MAX_X / 2) ;
 int Y = (MAX_Y / 2) ;

 char icon_P1 = 'O';
 char icon_P2 = 'X';
 char board[7][14] =
 {
   {"#############"},
   {"#   #   #   #"},
   {"#############"},
   {"#   #   #   #"},
   {"#############"},
   {"#   #   #   #"},
   {"#############"},
 };
 for(int i=0; i<7; i++)
 {
   for(int j=0; j<14; j++)
   {
     cout << board[i][j];
   }
   cout << endl;
 }

 gotoxy(0, MAX_Y + 1);
 cout << endl << "<Tic-Tac-Toe Game>" << endl << "Player1 : O" << endl << "Player2 : X" << endl
 << "Select position by input NumberPad(7,8,9,4,5,6,1,2,3) and make a move by Enter key!" ;
 int keyin = 0;
 while (1) {
   gotoxy(0,0);
   for(int i=0; i<7; i++)
   {
     for(int j=0; j<14; j++)
     {
       cout << board[i][j];
     }
     cout << endl;
   }

   switch(Tic_Tac_Toe(board))
   {
     case 1:
      gotoxy(MAX_X*2,MAX_Y/2);
      if(playerCheck==true)
      {
        cout << "Player2 Win!";
        gotoxy(MAX_X,MAX_Y+6);
        return 0;
      }
      else
      {
        cout << "Player1 Win!";
        gotoxy(MAX_X,MAX_Y+6);
        return 0;
      }

     case 2:
      gotoxy(MAX_X*2,MAX_Y/2);
      cout << "DRAW!";
      gotoxy(MAX_X,MAX_Y+6);
      return 0;
   };

   gotoxy(X, Y);
   if(playerCheck==true)
    cout << icon_P1;
   else
    cout << icon_P2;

   keyin = getch();
   cout << "\b ";
   switch (keyin)
   {
    case '7':
     if (board[1][2] == ' ')
     {
      X=2; Y=1;
     }
     break;
    case '8':
     if (board[1][6] == ' ')
     {
      X=6; Y=1;
     }
     break;
    case '9':
     if (board[1][10] == ' ')
     {
      X=10; Y=1;
     }
     break;
    case '4':
     if (board[3][2] == ' ')
     {
      X=2; Y=3;
     }
     break;
    case '5':
     if (board[3][6] == ' ')
     {
      X=6; Y=3;
     }
     break;
    case '6':
     if (board[3][10] == ' ')
     {
      X=10; Y=3;
     }
     break;
    case '1':
     if (board[5][2] == ' ')
     {
      X=2; Y=5;
     }
     break;
    case '2':
     if (board[5][6] == ' ')
     {
      X=6; Y=5;
     }
     break;
    case '3':
     if (board[5][10] == ' ')
     {
      X=10; Y=5;
     }
     break;

    case 13:
     if(playerCheck==true)
     {
       board[Y][X] = 'O';
       playerCheck=false;
     }
     else
     {
       board[Y][X] = 'X';
       playerCheck=true;
     }
     break;
    }
 }
}

void gotoxy(int x, int y)
{
 COORD Pos;
 Pos.X = x;
 Pos.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int Tic_Tac_Toe(char arr[7][14])
{
  if((((arr[1][2]==arr[3][6] && arr[1][2]==arr[5][10])) && arr[1][2] != ' ') || (((arr[5][2]==arr[3][6] && arr[5][2]==arr[1][10])) && arr[5][2] != ' '))
    return 1;

  for(int i=1; i<6; i+=2)
  {
    if(((arr[i][2]==arr[i][6]) && (arr[i][2]==arr[i][10])) && arr[i][2] != ' ')
      return 1;
  }
  for(int i=2; i<11; i+=4)
  {
    if(((arr[1][i]==arr[3][i]) && (arr[1][i]==arr[5][i])) && arr[1][i] != ' ')
      return 1;
  }

  int count=0;
  for(int i=1; i<6; i+=2)
  {
    for(int j=2; j<11; j+=4)
    {
      if(arr[i][j] != ' ')
        count++;
    }
  }
  if(count==9)
    return 2;

  return 0;
}
