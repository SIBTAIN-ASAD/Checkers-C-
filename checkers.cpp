//======================================================
//======================================================

//                THE CHECKERS GAME

//======================================================
//======================================================


#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;

/*
 This class is used to populate the board according to given size 
 It initialize the array variables and to to display the board anytime called 
 this show black areas with occupied and useable way and
 while area in unusable blocks
*/
class board
{

public:
  void populateTheBoard(char ** board, int size)
  {
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
          board[i][j] = ' ';
          if(i < size/2 -1)
          {
            if((i+j) % 2 == 1)
            {
              board[i][j] = 'X';
            }
          }
          if(i > size/2)
          {
            if((i+j) % 2 == 1)
            {
              board[i][j] = '0';
            }
          }
        }
      }
  }


  //function which is used to display the board anytime called 
// this show black areas with occupied and useable way and
// while area in unusable blocks
void DisplayBoard(char ** board, int size)
{
 system("cls");
 cout << "===================================== \n";
 cout << "|        THE CHECKERS GAME          | \n";
 cout << "|    PLAYER 01 <r> : king = R       | \n";
 cout << "|    PLAYER 02 <b> : king = B       | \n";
 cout << "===================================== \n\n";

//============================================================
// First version display
//============================================================


  cout << "    ";
  for(int i = 0; i < size; i++)
  {
    cout << i+1 << "   ";
  }
  cout << endl;
  for(int i = 0; i < size; i++)
  {
    cout << i+1 << " ";
    for(int j = 0; j < size; j++)
    {
      if(i % 2 == 0 && j% 2 == 0)
      {
          cout << "|\033[30;47m " << board[i][j] << " ";
      }
      else
      {
        if(i % 2 == 1 && j% 2 == 1)
        {
          cout << "|\033[30;47m " << board[i][j] << " ";
        }
        else
        {
           cout << "|\033[0m " << board[i][j] << " ";
        }
      }
        cout << "\033[0m";
    }
    cout << endl;
  }

//============================================================
// second version display
//============================================================
//cout << "--1 2 3 4 5 6 7 8\n";
//
//char ch = ' ';
//for(int i = 0; i < 8; i++)
//{
//  cout << i+1 << " ";
//  for(int j = 0; j < 8; j++)
//  {
//    // if(board[i][j] == '!')
//    // {
//    //   ch = '!';
//    // }
//    if(board[i][j] == ' ')
//    {
//      ch = '.';
//    }
//    if(i == 3 && j % 2 == 0)
//    {
//      ch = '*';
//    }
//    if(i == 4 && j% 2 != 0)
//    {
//      ch = '*';
//    }
//
//    if(i == 3 && j == 0 || i == 4 && j == 7) 
//    {
//      ch = '!';
//    }
//
//    if(board[i][j] == 'X')
//    {
//      ch = 'r';
//    }
//    if(board[i][j] == 'M')
//    {
//      ch = 'R';
//    }
//    if(board[i][j] == '0')
//    {
//      ch = 'b';
//    }
//    if(board[i][j] == 'G')
//    {
//      ch = 'B';
//    }
//
//
//
//
//    cout << ch << " ";
//  }
//  cout << "\n";
//}

}

};





class RegularPiece
{
private:
  board bd;
  char ** arr;
  int size= 64;
public:
     char getMark()
     {
          int count = 0;
        char * check = new char[4]{'0'};
        cout << "Select where you want to move the piece\n";
      
        int i = 0;
        int j= 0;
        if(i+1 < size && j-1 >= 0)
        {
          if(arr[i+1][j-1] == ' ')
          {
            check[count] = 'a';
            count++;
            cout << "Select \"a\" for: " << i+1+1 << " " << j-1+1 << endl;
          }
        }
        if(i+1 < size && j+1 < size)
        {
          if(arr[i+1][j+1] == ' ')
          {
            check[count] = 'b';
            count++;
            cout << "Select \"b\" for: " << i+1+1 << " " << j+1+1 << endl;
          }
        }
        if(i+2 < size && j-2 >= 0)
        {
          if((arr[i+1][j-1] == '0' || arr[i+1][j-1] == 'G') && arr[i+2][j-2] == ' ')
          {
              check[count] = 'c';       
              count++;
              cout << "Select \"c\" for: " << i+2+1 << " " << j-2+1 << endl;
            }  
        }
        if(i+2 < size && j+2 < size)
        {
          if((arr[i+1][j+1] == '0' || arr[i+1][j+1] == 'G') && arr[i+2][j+2] == ' ')
          {
              check[count] = 'd';
              count++;
              cout << "Select \"d\" for: " << i+2+1 << " " << j+2+1 << endl;
          }
        }

        char ch;
        cin >> ch;
        while(true)
        {
          for(int i = 0; i < count; i++)
          {
            if(ch == check[i])
            {
              return ch;
            }
          }
          cout << "Invalid destination \nEnter again \n";
          cin >> ch;
        }
    }

    bool isValidMove(int i,int j,int size,int ty,board bd)
    {
         if(i+1 < size && j-1 >= 0)
        {
          if(arr[i+1][j-1] == ' ')
          {
            return 1;
          }
        }
        if(i+1 < size && j+1 < size)
        {
          if(arr[i+1][j+1] == ' ')
          {
            return 2;
          }
        }
        if(i+2 < size && j+2 < size)
        {
          if((arr[i+1][j+1] == '0' || arr[i+1][j+1] == 'G') && arr[i+2][j+2] == ' ')
          {
            return 4;
          }
        }
        if(i+2 < size && j-2 >= 0)
        {
          if((arr[i+1][j-1] == '0' || arr[i+1][j-1] == 'G') && arr[i+2][j-2] == ' ')
          {
            return 3;
          }
        }

        return 0;
    }


    //this function is used to show the suggenstions for the 
    //user according to his given/ selected number
    // for player 01 <X>
    char suggestion01(char ** arr, int i, int j, int size)
    {
    int count = 0;
    char * check = new char[4]{'0'};
    cout << "Select where you want to move the piece\n";
    if(i+1 < size && j-1 >= 0)
    {
      if(arr[i+1][j-1] == ' ')
      {
        check[count] = 'a';
        count++;
        cout << "Select \"a\" for: " << i+1+1 << " " << j-1+1 << endl;
      }
    }
    if(i+1 < size && j+1 < size)
    {
      if(arr[i+1][j+1] == ' ')
      {
        check[count] = 'b';
        count++;
        cout << "Select \"b\" for: " << i+1+1 << " " << j+1+1 << endl;
      }
    }
    if(i+2 < size && j-2 >= 0)
    {
      if((arr[i+1][j-1] == '0' || arr[i+1][j-1] == 'G') && arr[i+2][j-2] == ' ')
      {
          check[count] = 'c';       
          count++;
          cout << "Select \"c\" for: " << i+2+1 << " " << j-2+1 << endl;
        }  
    }
    if(i+2 < size && j+2 < size)
    {
      if((arr[i+1][j+1] == '0' || arr[i+1][j+1] == 'G') && arr[i+2][j+2] == ' ')
      {
          check[count] = 'd';
          count++;
          cout << "Select \"d\" for: " << i+2+1 << " " << j+2+1 << endl;
      }
    }

    char ch;
    cin >> ch;
    while(true)
    {
      for(int i = 0; i < count; i++)
      {
        if(ch == check[i])
        {
          return ch;
        }
      }
      cout << "Invalid destination \nEnter again \n";
      cin >> ch;
    }
    }




    //this function is used to show the suggenstions for the 
    //user according to his given/ selected number
    // for player 02 <0>
    char suggestion02(char ** arr, int i, int j, int size)
    {
    int count = 0;
    char * check = new char[4]{'0'};
    cout << "Select where you want to move the piece\n";
    if(i-1 >= 0 && j-1 >= 0)
    {
      if(arr[i-1][j-1] == ' ')
      {
        check[count] = 'a';
        count++;
        cout << "Select \"a\" for: " << i-1+1 << " " << j-1+1 << endl;
      }
    }
    if(i-1 >= 0 && j+1 < size)
    {
      if(arr[i-1][j+1] == ' ')
      {
        check[count] = 'b';
        count++;
        cout << "Select \"b\" for: " << i-1+1 << " " << j+1+1 << endl;
      }
    }
    if(i-2 >= 0 && j-2 >= 0)
    {
      if((arr[i-1][j-1] == 'X' || arr[i-1][j-1] == 'M') && arr[i-2][j-2] == ' ')
      {
        check[count] = 'c';
        count++;
        cout << "Select \"c\" for: " << i-2+1 << " " << j-2+1 << endl;
      }
    }
    if(i-2 >= 0 && j+2 < size)
    {
      if((arr[i-1][j+1] == 'X' || arr[i-1][j+1] == 'M') && arr[i-2][j+2] == ' ')
      {
        check[count] = 'd';
        count++;
        cout << "Select \"d\" for: " << i-2+1 << " " << j+2+1 << endl;
      }
    }


    char ch;
    cin >> ch;
    while(true)
    {
      for(int i = 0; i < count; i++)
      {
        if(ch == check[i])
        {
          return ch;
        }
      }
      cout << "Invalid destination \nEnter again \n";
      cin >> ch;
    }
    }

};


//promotedPiece class inherited from regularPiece class
class PromotedPiece : public RegularPiece
{
private:
  board bd;
  char ** arr;
  int size= 64;
public:

    virtual char getMark() 
     {
          int count = 0;
        char * check = new char[4]{'0'};
        cout << "Select where you want to move the piece\n";
      
        int i = 0;
        int j= 0;
        if(i+1 < size && j-1 >= 0)
        {
          if(arr[i+1][j-1] == ' ')
          {
            check[count] = 'a';
            count++;
            cout << "Select \"a\" for: " << i+1+1 << " " << j-1+1 << endl;
          }
        }
        if(i+1 < size && j+1 < size)
        {
          if(arr[i+1][j+1] == ' ')
          {
            check[count] = 'b';
            count++;
            cout << "Select \"b\" for: " << i+1+1 << " " << j+1+1 << endl;
          }
        }
        if(i+2 < size && j-2 >= 0)
        {
          if((arr[i+1][j-1] == '0' || arr[i+1][j-1] == 'G') && arr[i+2][j-2] == ' ')
          {
              check[count] = 'c';       
              count++;
              cout << "Select \"c\" for: " << i+2+1 << " " << j-2+1 << endl;
            }  
        }
        if(i+2 < size && j+2 < size)
        {
          if((arr[i+1][j+1] == '0' || arr[i+1][j+1] == 'G') && arr[i+2][j+2] == ' ')
          {
              check[count] = 'd';
              count++;
              cout << "Select \"d\" for: " << i+2+1 << " " << j+2+1 << endl;
          }
        }

        char ch;
        cin >> ch;
        while(true)
        {
          for(int i = 0; i < count; i++)
          {
            if(ch == check[i])
            {
              return ch;
            }
          }
          cout << "Invalid destination \nEnter again \n";
          cin >> ch;
        }
    }

    virtual bool isValidMove(int i,int j,int size,int ty,board bd)
    {
         if(i+1 < size && j-1 >= 0)
        {
          if(arr[i+1][j-1] == ' ')
          {
            return 1;
          }
        }
        if(i+1 < size && j+1 < size)
        {
          if(arr[i+1][j+1] == ' ')
          {
            return 2;
          }
        }
        if(i+2 < size && j+2 < size)
        {
          if((arr[i+1][j+1] == '0' || arr[i+1][j+1] == 'G') && arr[i+2][j+2] == ' ')
          {
            return 4;
          }
        }
        if(i+2 < size && j-2 >= 0)
        {
          if((arr[i+1][j-1] == '0' || arr[i+1][j-1] == 'G') && arr[i+2][j-2] == ' ')
          {
            return 3;
          }
        }

        return 0;
    }
    //this function is used to show the suggenstions for the 
    //user according to his given/ selected number if it is a king
    // for player 01 <X>
    char suggestionKing01(char ** arr, int i, int j, int size)
    {
    int count = 0;
    char * check = new char[8]{'0'};
    cout << "Select where you want to move the king piece\n";
    if(i+1 < size && j-1 >= 0)
    {
      if(arr[i+1][j-1] == ' ')
      {
        check[count] = 'a';
        count++;
        cout << "Select \"a\" for: " << i+1+1 << " " << j-1+1 << endl;
      }
    }
    if(i+1 < size && j+1 < size)
    {
      if(arr[i+1][j+1] == ' ')
      {
        check[count] = 'b';
        count++;
        cout << "Select \"b\" for: " << i+1+1 << " " << j+1+1 << endl;
      }
    }
    if(i+2 < size && j-2 >= 0)
    {
      if((arr[i+1][j-1] == '0' || arr[i+1][j-1] == 'G') && arr[i+2][j-2] == ' ')
      {
          check[count] = 'c';       
          count++;
          cout << "Select \"c\" for: " << i+2+1 << " " << j-2+1 << endl;
        }  
    }
    if(i+2 < size && j+2 < size)
    {
      if((arr[i+1][j+1] == '0' || arr[i+1][j+1] == 'G')  && arr[i+2][j+2] == ' ')
      {
          check[count] = 'd';
          count++;
          cout << "Select \"d\" for: " << i+2+1 << " " << j+2+1 << endl;
      }
    }


    //==========================================================================

    if(i-1 >= 0 && j-1 >= 0)
    {
      if(arr[i-1][j-1] == ' ')
      {
        check[count] = 'e';
        count++;
        cout << "Select \"e\" for: " << i-1+1 << " " << j-1+1 << endl;
      }
    }
    if(i-1 >= 0 && j+1 < size)
    {
      if(arr[i-1][j+1] == ' ')
      {
        check[count] = 'f';
        count++;
        cout << "Select \"f\" for: " << i-1+1 << " " << j+1+1 << endl;
      }
    }
    if(i-2 >= 0 && j-2 >= 0)
    {
      if((arr[i-1][j-1] == '0' || arr[i-1][j-1] == 'G') && arr[i-2][j-2] == ' ')
      {
        check[count] = 'g';
        count++;
        cout << "Select \"g\" for: " << i-2+1 << " " << j-2+1 << endl;
      }
    }
    if(i-2 >= 0 && j+2 < size)
    {
      if((arr[i-1][j+1] == '0' || arr[i-1][j+1] == 'G') && arr[i-2][j+2] == ' ')
      {
        check[count] = 'h';
        count++;
        cout << "Select \"h\" for: " << i-2+1 << " " << j+2+1 << endl;
      }
    }

    //==========================================================================



    char ch;
    cin >> ch;
    while(true)
    {
      for(int i = 0; i < count; i++)
      {
        if(ch == check[i])
        {
          return ch;
        }
      }
      cout << "Invalid destination \nEnter again \n";
      cin >> ch;
    }
    }






    //this function is used to show the suggenstions for the 
    //user according to his given/ selected number if it is a king
    // for player 02 <0>
    char suggestionKing02(char ** arr, int i, int j, int size)
    {
    int count = 0;
    char * check = new char[8]{'0'};
    cout << "Select where you want to move the king piece\n";
    if(i+1 < size && j-1 >= 0)
    {
      if(arr[i+1][j-1] == ' ')
      {
        check[count] = 'a';
        count++;
        cout << "Select \"a\" for: " << i+1+1 << " " << j-1+1 << endl;
      }
    }
    if(i+1 < size && j+1 < size)
    {
      if(arr[i+1][j+1] == ' ')
      {
        check[count] = 'b';
        count++;
        cout << "Select \"b\" for: " << i+1+1 << " " << j+1+1 << endl;
      }
    }
    if(i+2 < size && j-2 >= 0)
    {
      if((arr[i+1][j-1] == 'X' || arr[i+1][j-1] == 'M') && arr[i+2][j-2] == ' ')
      {
          check[count] = 'c';       
          count++;
          cout << "Select \"c\" for: " << i+2+1 << " " << j-2+1 << endl;
        }  
    }
    if(i+2 < size && j+2 < size)
    {
      if((arr[i+1][j+1] == 'X' || arr[i+1][j+1] == 'M') && arr[i+2][j+2] == ' ')
      {
          check[count] = 'd';
          count++;
          cout << "Select \"d\" for: " << i+2+1 << " " << j+2+1 << endl;
      }
    }


    //==========================================================================

    if(i-1 >= 0 && j-1 >= 0)
    {
      if(arr[i-1][j-1] == ' ')
      {
        check[count] = 'e';
        count++;
        cout << "Select \"e\" for: " << i-1+1 << " " << j-1+1 << endl;
      }
    }
    if(i-1 >= 0 && j+1 < size)
    {
      if(arr[i-1][j+1] == ' ')
      {
        check[count] = 'f';
        count++;
        cout << "Select \"f\" for: " << i-1+1 << " " << j+1+1 << endl;
      }
    }
    if(i-2 >= 0 && j-2 >= 0)
    {
      if((arr[i-1][j-1] == 'X' || arr[i-1][j-1] == 'M') && arr[i-2][j-2] == ' ')
      {
        check[count] = 'g';
        count++;
        cout << "Select \"g\" for: " << i-2+1 << " " << j-2+1 << endl;
      }
    }
    if(i-2 >= 0 && j+2 < size)
    {
      if((arr[i-1][j+1] == 'X' || arr[i-1][j+1] == 'M') && arr[i-2][j+2] == ' ')
      {
        check[count] = 'h';
        count++;
        cout << "Select \"h\" for: " << i-2+1 << " " << j+2+1 << endl;
      }
    }

    //==========================================================================



    char ch;
    cin >> ch;
    while(true)
    {
      for(int i = 0; i < count; i++)
      {
        if(ch == check[i])
        {
          return ch;
        }
      }
      cout << "Invalid destination \nEnter again \n";
      cin >> ch;
    }
    }

};






class ImpassibleSquare
{

public:
    //function is used to check weither is any valid input or not
    // for the given block
    // For player 01 <X>
    int canMove1(char ** arr, int i, int j, int size)
    {
    if(i+1 < size && j-1 >= 0)
    {
      if(arr[i+1][j-1] == ' ')
      {
        return 1;
      }
    }
    if(i+1 < size && j+1 < size)
    {
      if(arr[i+1][j+1] == ' ')
      {
        return 2;
      }
    }
    if(i+2 < size && j+2 < size)
    {
      if((arr[i+1][j+1] == '0' || arr[i+1][j+1] == 'G') && arr[i+2][j+2] == ' ')
      {
        return 4;
      }
    }
    if(i+2 < size && j-2 >= 0)
    {
      if((arr[i+1][j-1] == '0' || arr[i+1][j-1] == 'G') && arr[i+2][j-2] == ' ')
      {
        return 3;
      }
    }

    return 0;
    }


    //function is used to check weither is any valid input or not
    // for the given block
    // For player 02 <0>
    int canMove2(char ** arr, int i, int j, int size)
    {
    if(i-1 >= 0 && j-1 >= 0)
    {
      if(arr[i-1][j-1] == ' ')
      {
        return 1;
      }
    }
    if(i-1 >= 0 && j+1 < size)
    {
      if(arr[i-1][j+1] == ' ')
      {
        return 2;
      }
    }
    if(i-2 >= 0 && j+2 < size)
    {
      if((arr[i-1][j+1] == 'X' || arr[i-1][j+1] == 'M') && arr[i-2][j+2] == ' ')
      {
        return 4;
      }
    }
    if(i-2 >= 0 && j-2 >= 0)
    {
      if((arr[i-1][j-1] == 'X' || arr[i-1][j-1] == 'M') && arr[i-2][j-2] == ' ')
      {
        return 3;
      }
    }

    return 0;
    }


    //function is used to check weither is any valid input or not
    // for the given block if block is king
    // For player 01 <X>
    int canmoveKing01(char ** arr, int i, int j, int size)
    {
    //========================================================

    if(i+1 < size && j-1 >= 0)
    {
      if(arr[i+1][j-1] == ' ')
      {
        return 1;
      }
    }
    if(i+1 < size && j+1 < size)
    {
      if(arr[i+1][j+1] == ' ')
      {
        return 2;
      }
    }
    if(i+2 < size && j+2 < size)
    {
      if((arr[i+1][j+1] == '0' || arr[i+1][j+1] == 'G')  && arr[i+2][j+2] == ' ')
      {
        return 4;
      }
    }
    if(i+2 < size && j-2 >= 0)
    {
      if((arr[i+1][j-1] == '0' || arr[i+1][j-1] == 'G') && arr[i+2][j-2] == ' ')
      {
        return 3;
      }
    }
    //========================================================
    if(i-1 >= 0 && j-1 >= 0)
    {
      if(arr[i-1][j-1] == ' ')
      {
        return 5;
      }
    }
    if(i-1 >= 0 && j+1 < size)
    {
      if(arr[i-1][j+1] == ' ')
      {
        return 6;
      }
    }
    if(i-2 >= 0 && j+2 < size)
    {
      if((arr[i-1][j+1] == '0' || arr[i-1][j+1] == 'G') && arr[i-2][j+2] == ' ')
      {
        return 8;
      }
    }
    if(i-2 >= 0 && j-2 >= 0)
    {
      if((arr[i-1][j-1] == '0' || arr[i-1][j-1] == 'G') && arr[i-2][j-2] == ' ')
      {
        return 7;
      }
    }


    return 0;


    //=============================================================


    }



    //function is used to check weither is any valid input or not
    // for the given block if block is king
    // For player 02 <0>
    int canmoveKing02(char ** arr, int i, int j, int size)
    {
    //========================================================

    if(i+1 < size && j-1 >= 0)
    {
      if(arr[i+1][j-1] == ' ')
      {
        return 1;
      }
    }
    if(i+1 < size && j+1 < size)
    {
      if(arr[i+1][j+1] == ' ')
      {
        return 2;
      }
    }
    if(i+2 < size && j+2 < size)
    {
      if((arr[i+1][j+1] == 'X' || arr[i+1][j+1] == 'M') && arr[i+2][j+2] == ' ')
      {
        return 4;
      }
    }
    if(i+2 < size && j-2 >= 0)
    {
      if((arr[i+1][j-1] == 'X' || arr[i+1][j-1] == 'M') && arr[i+2][j-2] == ' ')
      {
        return 3;
      }
    }
    //========================================================
    if(i-1 >= 0 && j-1 >= 0)
    {
      if(arr[i-1][j-1] == ' ')
      {
        return 5;
      }
    }
    if(i-1 >= 0 && j+1 < size)
    {
      if(arr[i-1][j+1] == ' ')
      {
        return 6;
      }
    }
    if(i-2 >= 0 && j+2 < size)
    {
      if((arr[i-1][j+1] == 'X' || arr[i-1][j+1] == 'M') && arr[i-2][j+2] == ' ')
      {
        return 8;
      }
    }
    if(i-2 >= 0 && j-2 >= 0)
    {
      if((arr[i-1][j-1] == 'X' || arr[i-1][j-1] == 'M') && arr[i-2][j-2] == ' ')
      {
        return 7;
      }
    }


    return 0;
    //=============================================================
    }

};

class winner
{

private:
    ImpassibleSquare IS;
public:
    bool checkwinner1(char ** arr,int size,int & num02)
    {
    if(num02 <= 0)
    {
      return true;
    }
    int count = 0;
    int count2 = 0;
    for(int i = 0; i < size; i++)
    {
      for(int j = 0; j < size; j++)
      {
        if(arr[i][j] == '0')
        {
          count = count + IS.canMove2(arr, i, j, size);
          count2++;
        }
        if(arr[i][j] == 'G')
        {
          count = count + IS.canmoveKing02(arr, i, j, size);
          count2++;
        }
      }
    }

    if(count <= 0 || count2 <= 0)
    {
      return true;
    }  
    else
    {
      return false;
    }


    }



    bool checkwinner2(char ** arr,int size,int & num01)
    {
    if(num01 <= 0)
    {
      return true;
    }
    int count = 0;
    int count2 = 0;
    for(int i = 0; i < size; i++)
    {
      for(int j = 0; j < size; j++)
      {
        if(arr[i][j] == 'X')
        {
          count = count + IS.canMove1(arr, i, j, size);
          count2++;
        }
        if(arr[i][j] == 'M')
        {
          count = count + IS.canmoveKing01(arr, i, j, size);
          count2++;
        }
      }
    }

    if(count <= 0 || count2 <= 0)
    {
      return true;
    }  
    else
    {
      return false;
    }


    }

};



class ValidSquare
{
private:
  PromotedPiece par;
  board bd;
  ImpassibleSquare IS;
public:
    //this function is used to set the destination for given block
    //i.e it places the block to the new positition
    // also tackle shot of opponenet bloack if block is KING
    //for player 01 <X>
    void setDestinationKing01(char ** arr, int i, int j, int size, int & num02)
    {
      char ch = par.suggestionKing01(arr, i, j, size);

      int i2, j2;
      switch (ch)
      {
        case 'a':
          i2 = i+1;
          j2 = j-1;
        break;
        case 'b':
          i2 = i+1;
          j2 = j+1;
        break;
        case 'c':
          i2 = i+2;
          j2 = j-2;
          arr[i+1][j-1] = ' ';
        break;
        case 'd':
          i2 = i+2;
          j2 = j+2;
          arr[i+1][j+1] = ' ';
        break;    
        case 'e':
          i2 = i-1;
          j2 = j-1;
        break;
        case 'f':
          i2 = i-1;
          j2 = j+1;
        break;
        case 'g':
          i2 = i-2;
          j2 = j-2;
          arr[i-1][j-1] = ' ';
        break;
        case 'h':
          i2 = i-2;
          j2 = j+2;
          arr[i-1][j+1] = ' ';
        break;    

      default:
        break;
      }

          arr[i][j] =  ' ';
          arr[i2][j2] = 'M';

          i = i2;
          j = j2;

          if(ch == 'c' || ch == 'd' || ch == 'g'|| ch == 'h')
          {
            bd.DisplayBoard(arr, size);
            cout << "\n\nPlayer 01 <r> turn \n\n";
            cout << "\n\nNice shot!!!";
            num02--;
            if(IS.canmoveKing01(arr, i,j, size) > 0)
            {
              cout << " You got another chance \n\n";
              setDestinationKing01(arr, i,j,size, num02);
            }
            else
            {
              cout << " But You can't move this piece further\n";
              system("pause");
            }
          }
    }




    //this function is used to set the destination for given block
    //i.e it places the block to the new positition
    // also tackle shot of opponenet bloack if block is king
    //for player 02 <0>
    void setDestinationKing02(char ** arr, int i, int j, int size, int & num01)
    {
      char ch = par.suggestionKing02(arr, i, j, size);

      int i2, j2;
      switch (ch)
      {
        case 'a':
          i2 = i+1;
          j2 = j-1;
        break;
        case 'b':
          i2 = i+1;
          j2 = j+1;
        break;
        case 'c':
          i2 = i+2;
          j2 = j-2;
          arr[i+1][j-1] = ' ';
        break;
        case 'd':
          i2 = i+2;
          j2 = j+2;
          arr[i+1][j+1] = ' ';
        break;    
        case 'e':
          i2 = i-1;
          j2 = j-1;
        break;
        case 'f':
          i2 = i-1;
          j2 = j+1;
        break;
        case 'g':
          i2 = i-2;
          j2 = j-2;
          arr[i-1][j-1] = ' ';
        break;
        case 'h':
          i2 = i-2;
          j2 = j+2;
          arr[i-1][j+1] = ' ';
        break;    

      default:
        break;
      }

          arr[i][j] =  ' ';
          arr[i2][j2] = 'G';

          i = i2;
          j = j2;

          if(ch == 'c' || ch == 'd' || ch == 'g'|| ch == 'h')
          {
            bd.DisplayBoard(arr, size);
            cout << "\n\nPlayer 02 <b> turn \n\n";
            cout << "\n\nNice shot!!!";
            num01--;
            
            if(IS.canmoveKing02(arr, i,j, size) > 0)
            {
              cout << " You got another chance \n\n";
              setDestinationKing02(arr, i,j,size, num01);
            }
            else
            {
              cout << " But You can't move this piece further\n";
              system("pause");
            }
          }
    }

};


class Square
{
private:
  PromotedPiece par;
  board bd;
  ImpassibleSquare IS;
  ValidSquare VS;
public:
    //this function is used to set the destination for given block
    //i.e it places the block to the new positition
    // also tackle shot of opponenet bloack
    //for player 01 <X>
    void setdestination01(char ** arr, int i, int j, int size, int & num02)
    {
      char ch = par.suggestion01(arr, i, j, size);
      int i2, j2;
      switch (ch)
      {
        case 'a':
          i2 = i+1;
          j2 = j-1;
        break;
        case 'b':
          i2 = i+1;
          j2 = j+1;
        break;
        case 'c':
          i2 = i+2;
          j2 = j-2;
          arr[i+1][j-1] = ' ';
        break;
        case 'd':
          i2 = i+2;
          j2 = j+2;
          arr[i+1][j+1] = ' ';
        break;    
      
      default:
        break;
      }

          arr[i][j] =  ' ';
          arr[i2][j2] = 'X';

          i = i2;
          j = j2;

          if(i2 == size-1)
          {
            arr[i2][j2] = 'M';
            
            if(ch == 'c' || ch == 'd')
            {
              bd.DisplayBoard(arr, size);
              cout << "\n\nPlayer 01 <r> turn \n\n";
              cout << "\n\nNice shot!!!";
              num02--;

              if(IS.canmoveKing01(arr, i,j, size) > 0)
              {
                cout << " You got another chance \n\n";
                VS.setDestinationKing01(arr, i,j,size, num02);
              }
              else
              {
                cout << " But You can't move this piece further\n";
                system("pause");
              }
            }
          }
          else
          {

            if(ch == 'c' || ch == 'd')
            {
              bd.DisplayBoard(arr, size);
              cout << "\n\nPlayer 01 <r> turn \n\n";
              cout << "\n\nNice shot!!!";
              num02--;

              if(IS.canMove1(arr, i,j, size) > 2)
              {
                cout << " You got another chance \n\n";
                setdestination01(arr, i,j,size, num02);
              }
              else
              {
                cout << " But You can't move this piece further\n";
                system("pause");
              }
            }

          }
    }


    //this function is used to set the destination for given block
    //i.e it places the block to the new positition
    // also tackle shot of opponenet block 
    //for player 02 <0>
    void setdestination02(char ** arr, int i, int j, int size, int & num01)
    {
      char ch = par.suggestion02(arr, i, j, size);

      int i2, j2;
      switch (ch)
      {
        case 'a':
          i2 = i-1;
          j2 = j-1;
        break;
        case 'b':
          i2 = i-1;
          j2 = j+1;
        break;
        case 'c':
          i2 = i-2;
          j2 = j-2;
          arr[i-1][j-1] = ' ';
        break;
        case 'd':
          i2 = i-2;
          j2 = j+2;
          arr[i-1][j+1] = ' ';
        break;    
      
      default:
        break;
      }

          arr[i][j] =  ' ';
          arr[i2][j2] = '0';


          i = i2;
          j = j2;

          if(i2 == 0)
          {
              arr[i2][j2] = 'G';
            if(ch == 'c' || ch == 'd')
            {
              bd.DisplayBoard(arr, size);
              cout << "\n\nPlayer 02 <b> turn \n\n";
              cout << "\n\nNice shot!!!";
              num01--;
              if(IS.canmoveKing02(arr, i,j, size) > 0)
              {
                cout << " You got another chance \n\n";
                VS.setDestinationKing02(arr, i, j, size, num01);
              }
              else
              {
                cout << " But You can't move this piece \n";
                system("pause");
              }
            }
          }
          else
          {
            if(ch == 'c' || ch == 'd')
            {
              bd.DisplayBoard(arr, size);
              cout << "\n\nPlayer 02 <b> turn \n\n";
              cout << "\n\nNice shot!!!";
              num01--;
              if(IS.canMove2(arr, i,j, size) > 2)
              {
                cout << " You got another chance \n\n";
                setdestination02(arr, i, j, size, num01);
              }
              else
              {
                cout << " But You can't move this piece \n";
                system("pause");
              }
            }
          }

    }

};





class player
{
private:
  board bd;
  winner w1;
  ImpassibleSquare IS;
  Square S;
  ValidSquare VS;
public:
  //function for player 1 turn
  bool player1_Turn(char ** arr, int & num01, int & num02, int size)
  {
    bd.DisplayBoard(arr, size);
    bool check =  w1.checkwinner1(arr, size, num01);
    if(check)
    {
      return true;
    }
    int i, j;

    cout << "\n\nPlayer 01 <r> turn \n\n";
    do{

      cout << "\tSelect piece you want to move \n";

      cout << "\tenter row: ";
      cin >> i;
      i--;
      cout << "\tenter col: ";
      cin >> j;
      j--;
      while(i < 0 || i >= size || j < 0 || j >= size || (arr[i][j] != 'X' && arr[i][j] != 'M'))
      {
        cout << "Error!!! Please select valid piece location \"r\" \n";
        cout << "\tenter row: ";
        cin >> i;
        i--;
        cout << "\tenter col: ";
        cin >> j;
        j--;
      }

      if(arr[i][j] == 'X')
      {
        if(IS.canMove1(arr, i, j, size) == 0)
        {
          cout << "Sorry!!! You can't move this piece \n\n";
          continue;
        }
        else
        {
          break;
        }
      }
      else
      {
        if(arr[i][j] == 'M')
        {
          if(IS.canmoveKing01(arr, i, j, size) == 0)
          {
            cout << "Sorry!!! You can't move this piece \n\n";
            continue;
          }
          else
          {
            break;
          }
        }
      }
    }while(true);

    if(arr[i][j]== 'X')
    {
      S.setdestination01(arr, i, j, size, num02);
    }
    else
    {
      VS.setDestinationKing01(arr, i,j,size, num02);
    }
    return false;

  }



  //function for player 2 turn
  bool player2_Turn(char ** arr, int &num01, int &num02, int size)
  {
    bd.DisplayBoard(arr, size);
    
    bool check =  w1.checkwinner2(arr, size, num02);
    if(check)
    {
      return true;
    }
    int i, j;

    cout << "\n\nPlayer 02 <b> turn \n\n";
    do{
      cout << "\tSelect piece you want to move \n";

      cout << "\tenter row: ";
      cin >> i;
      i--;
      cout << "\tenter col: ";
      cin >> j;
      j--;
      while(i < 0 || i > size || j < 0 || j > size || (arr[i][j] != '0' && arr[i][j] != 'G'))
      {
        cout << "Error!!! Please select valid piece location \"b\" \n";
        cout << "\tenter row: ";
        cin >> i;
        i--;
        cout << "\tenter col: ";
        cin >> j;
        j--;
      }
      if(arr[i][j] == '0')
      {
        if(IS.canMove2(arr, i, j, size) == 0)
        {
          cout << "Sorry!!! You can't move this piece \n\n";
          continue;
        }
        else
        {
          break;
        }
      }
      else
      {
        if(arr[i][j] == 'G')
        {
          if(IS.canmoveKing02(arr, i, j, size) == 0)
          {
            cout << "Sorry!!! You can't move this piece \n\n";
            continue;
          }
          else
          {
            break;
          }
        }
      }


    }while(true);

    if(arr[i][j]== '0')
    {
      S.setdestination02(arr, i, j, size, num01);
    }
    else
    {
      VS.setDestinationKing02(arr, i,j,size, num01);
    }

    return false;
  }

};


bool fromFile(char ** board, int size, ifstream& file)
{
  if(!file)
  {
    return false;
  }
  if(file.peek() == std::ifstream::traits_type::eof())
  {
    return false;
  }
  string str;
  getline(file, str);
  
  if(str.length() < size* size)
  {
    return false;
  }

  for(int i = 1; i < str.length(); i++)
  {
    if(str[i] != ' ' && str[i] != '0' && str[i] != 'X' )
    {
      return false;
    }
  }
  
  int pick = 1;
  char ch;
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      board[i][j] = str[pick];
      pick++;
    }
  }
  return true;
}

bool toFile(char ** board, int size, ofstream& file)
{
  // if(!file)
  // {
  //   return false;
  // }
  string str = "!";

  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      str += board[i][j];
    }
  }
  file << str;
  return true;
}

class game
{
private:
  board bd;
  player p;
public:
//function to run the game from start
  void Run_Game(int size)
  {
  int num01 = (((size/2)-1) * size)/2;
  int num02 = num01;

  char ** board = new char*[size];
  for(int i = 0; i < size; i++)
  {
    board[i] = new char[size];
  }



 system("cls");
 cout << "===================================== \n";
 cout << "|        THE CHECKERS GAME          | \n";
 cout << "===================================== \n\n";


  string name1 = "p1 ";
  string name2 = "p2 ";
  ifstream ifile;

    cout << "Enter the name of player 01 for <r> : ";
    cin >> name1;
    cout << "Enter the name of player 02 for <b> : ";
    cin >> name2;

 char see;
 cout << "\n\nPress \"s\" to start new game \n";
 cout << "Press \"l\" to load old game \n";
 cout << "Press \"q\" to quit game \n";
 cin >> see;

switch(see)
{ 
  case 's':
    bd.populateTheBoard(board, size);
    break;
  case 'l':
    ifile.open("data.txt");
    if((fromFile(board, size, ifile)) == false)
    {
      cout << "Sorry!!! There is no previous data to load, We are starting game from start\n";
      bd.populateTheBoard(board, size);
      system("pause");
      // cout << "Enter the name of player 01 for <X> : ";
      // cin >> name1;
      // cout << "Enter the name of player 02 for <0> : ";
      // cin >> name2;
    }
     ifile.close();
    break;
  case 'q':
    exit(0);
    break;
  default:
    cout << "\n\n OOPS !!! invalid input \n\n";
    exit(0);
    break;
}

  while(true)
  {
    //  if(ofile)
    // {
    //  ofile.open("data.txt");
    // }

    ofstream ofile;
    ofile.open("data.txt");
    toFile(board, size, ofile);
    ofile.close();

    


    if(p.player1_Turn(board, num01, num02, size))
    {
        bd.DisplayBoard(board, size);
        cout << "\n\n ===== Congratulations ===== \n";
        cout << name1 << " -->Player 01 <r> have won the game \n";
      break;

    }

    if(p.player2_Turn(board, num01, num02, size))
    {
      bd.DisplayBoard(board, size);
        cout << "\n\n ===== Congratulations ===== \n";
        cout << name2 << " -->Player 02 <B> have won the game \n";
      break;

    }
  }

  for(int i = 0; i < size; i++)
  {
    delete[] board[i];
  }
  delete[] board;

  }


};



//function used to run the game
void PlaytheGame()
{
    int size = 8;
    char input;
    game g1;
 
 do{
    g1.Run_Game(size);
   cout << "\n\nPress Y to play again and N to exit \n";
   cin >> input;
 }while(input == 'Y' || input == 'y');

}


//main function
int main(int argc, char* argv[])
{
  PlaytheGame();
 return 0;
}