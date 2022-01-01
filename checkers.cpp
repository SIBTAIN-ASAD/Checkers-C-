#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

//prototypes
void startGame(char ** board, int size);
void DisplayBoard(char ** board, int size);
char suggestion01(char ** arr, int i, int j, int size);
char suggestion02(char ** arr, int i, int j, int size);
int canMove1(char ** arr, int i, int j, int size);
int canMove2(char ** arr, int i, int j, int size);
bool player1_Turn(char ** arr, int &num01, int &num02, int size);
bool player2_Turn(char ** arr, int &num01, int &num02, int size);
void setdestination01(char ** arr, int i, int j, int size, int & num02);
void setdestination02(char ** arr, int i, int j, int size, int & num01);
bool checkwinner1(char ** arr,int size,int & num02);
bool checkwinner2(char ** arr,int size,int & num01);
void setDestinationKing02(char ** arr, int i, int j, int size, int & num01);
void setDestinationKing01(char ** arr, int i, int j, int size, int & num02);
int canmoveKing02(char ** arr, int i, int j, int size);
int canmoveKing01(char ** arr, int i, int j, int size);
char suggestionKing02(char ** arr, int i, int j, int size);
char suggestionKing01(char ** arr, int i, int j, int size);


/*
 This function is used to populate the board according to given size 
 It initialize the array variables
*/
void startGame(char ** board, int size)
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
 cout << "|    PLAYER 01 <X> : king = M       | \n";
 cout << "|    PLAYER 02 <0> : king = G       | \n";
 cout << "===================================== \n\n";


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










//this function is used to set the destination for given block
//i.e it places the block to the new positition
// also tackle shot of opponenet bloack
//for player 01 <X>
void setdestination01(char ** arr, int i, int j, int size, int & num02)
{
   char ch = suggestion01(arr, i, j, size);
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
           DisplayBoard(arr, size);
           cout << "\n\nPlayer 01 <X> turn \n\n";
           cout << "\n\nNice shot!!!";
           num02--;

           if(canmoveKing01(arr, i,j, size) > 0)
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
       else
       {

         if(ch == 'c' || ch == 'd')
         {
           DisplayBoard(arr, size);
           cout << "\n\nPlayer 01 <X> turn \n\n";
           cout << "\n\nNice shot!!!";
           num02--;

           if(canMove1(arr, i,j, size) > 2)
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
   char ch = suggestion02(arr, i, j, size);

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
           DisplayBoard(arr, size);
           cout << "\n\nPlayer 02 <0> turn \n\n";
           cout << "\n\nNice shot!!!";
           num01--;
           if(canmoveKing02(arr, i,j, size) > 0)
           {
             cout << " You got another chance \n\n";
             setDestinationKing02(arr, i, j, size, num01);
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
           DisplayBoard(arr, size);
           cout << "\n\nPlayer 02 <0> turn \n\n";
           cout << "\n\nNice shot!!!";
           num01--;
           if(canMove2(arr, i,j, size) > 2)
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


//this function is used to set the destination for given block
//i.e it places the block to the new positition
// also tackle shot of opponenet bloack if block is KING
//for player 01 <X>
void setDestinationKing01(char ** arr, int i, int j, int size, int & num02)
{
   char ch = suggestionKing01(arr, i, j, size);

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
         DisplayBoard(arr, size);
         cout << "\n\nPlayer 01 <X> turn \n\n";
         cout << "\n\nNice shot!!!";
         num02--;
         if(canmoveKing01(arr, i,j, size) > 0)
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
   char ch = suggestionKing02(arr, i, j, size);

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
         DisplayBoard(arr, size);
         cout << "\n\nPlayer 02 <0> turn \n\n";
         cout << "\n\nNice shot!!!";
         num01--;
         
         if(canmoveKing02(arr, i,j, size) > 0)
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
       count = count + canMove2(arr, i, j, size);
       count2++;
     }
     if(arr[i][j] == 'G')
     {
       count = count + canmoveKing02(arr, i, j, size);
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
       count = count + canMove1(arr, i, j, size);
       count2++;
     }
     if(arr[i][j] == 'M')
     {
       count = count + canmoveKing01(arr, i, j, size);
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

//function for player 1 turn
bool player1_Turn(char ** arr, int & num01, int & num02, int size)
{
   DisplayBoard(arr, size);
   bool check =  checkwinner2(arr, size, num01);
   if(check)
   {
     return true;
   }
   int i, j;

   cout << "\n\nPlayer 01 <X> turn \n\n";
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
       cout << "Error!!! Please select valid piece location \"X\" \n";
       cout << "\tenter row: ";
       cin >> i;
       i--;
       cout << "\tenter col: ";
       cin >> j;
       j--;
     }

     if(arr[i][j] == 'X')
     {
       if(canMove1(arr, i, j, size) == 0)
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
         if(canmoveKing01(arr, i, j, size) == 0)
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
     setdestination01(arr, i, j, size, num02);
   }
   else
   {
     setDestinationKing01(arr, i,j,size, num02);
   }
   return false;

}



//function for player 2 turn
bool player2_Turn(char ** arr, int &num01, int &num02, int size)
{
   DisplayBoard(arr, size);
   
   bool check =  checkwinner1(arr, size, num02);
   if(check)
   {
     return true;
   }
   int i, j;

   cout << "\n\nPlayer 02 <0> turn \n\n";
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
       cout << "Error!!! Please select valid piece location \"0\" \n";
       cout << "\tenter row: ";
       cin >> i;
       i--;
       cout << "\tenter col: ";
       cin >> j;
       j--;
     }
     if(arr[i][j] == '0')
     {
       if(canMove2(arr, i, j, size) == 0)
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
         if(canmoveKing02(arr, i, j, size) == 0)
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
     setdestination02(arr, i, j, size, num01);
   }
   else
   {
     setDestinationKing02(arr, i,j,size, num01);
   }

   return false;
}



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

 startGame(board, size);

 while(true)
 {
   if(player1_Turn(board, num01, num02, size))
   {
     DisplayBoard(board, size);
       cout << "===== Congratulations ===== \n";
       cout << "Player 02 <0> have won the game \n";
     break;
   }

   if(player2_Turn(board, num01, num02, size))
   {
     DisplayBoard(board, size);
       cout << "===== Congratulations ===== \n";
       cout << "Player 01 <X> have won the game \n";
     break;
   }
 }

 for(int i = 0; i < size; i++)
 {
   delete[] board[i];
 }
 delete[] board;

}




int main(int argc, char* argv[])
{
 if(argc != 2)
 {
   cout << "Invalid Argumets \n";
   exit(0);    
 }  
 string str(argv[1]);
 if(str != "8" && str != "10" && str != "12")
 {
   cout << "Invalid Size \n";
   exit(0);
 }

 int size = stoi(str);
 char input;
 
 do{
   Run_Game(size);
   cout << "Press Y to play again and N to exit \n";
   cin >> input;
 }while(input == 'Y' || input == 'y');



 return 0;
}