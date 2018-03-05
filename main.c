// for my strategy I am assuming , I am player=2 i.e. O. I start off by choosing a random position in the center
// such that in all positions around me I can get 5 in a row. I continue my offensive move by building up 5 in a row.
// If I detect at least 3 in a row for my opponent I use the checkOppWin function to detect and return a 1 along with the position
//,then I block the opponent and then continue my offense. If the function returns 0 i.e. no 3 in a row I continue my offense without
// blocking anything. If an opponent blocks my direction, I go back to starting point and start building again in the
// opposite direction, if that is blocked I choose another one. If all are blocked I choose another random position.

#include <stdio.h>
#include <stdlib.h>
#include "Student.h"

                // assume that this is player 1, X
int* getMove2(int board[][SIZE], int *move)
{
  do
  {
    static int first_move_bool2 = 1;
    int i,j;
    int check2;//row and column
    static int first_r2;
    static int first_c2;
    static int start_r2,start_c2;
    static int direc2 = 0;
    static int ran;
    if (first_move_bool2 == 1)
    {
        move[0] = 4//rand()%7 + 5;
        first_r2 = move[0];
        start_r2 = first_r2;
        move[1] = 10//rand()%7 + 5;
        first_c2 = move[1];
        start_c2 = first_c2;
        direc2 = 1;
        first_move_bool2 = 0;
    }
    else
    {
    int* place = malloc(2 * sizeof(int));
    check2 = checkOppWin2(board, place);
    if (check2 == 0)
    {
        if(board[first_r2 + 1][first_c2] != 2 && board[first_r2 + 1][first_c2] != 1 && (first_r2+1< 15) && direc2 == 1 && first_c2 < 15)
            {
             first_r2 = first_r2 + 1;
             move[0] = first_r2;
             move[1] = first_c2;
            }
        else if ((board[first_r2 + 1][first_c2] == 2 || board[first_r2 + 1][first_c2] == 1) && direc2 == 1)
            {direc2 =2;
              first_r2 = start_r2;
              first_c2 = start_c2;}
        if (board[first_r2-1][first_c2] != 2 && board[first_r2 - 1][first_c2] != 1 && direc2 == 2 && first_r2 - 1 < 15 && first_c2 < 15)
        {

            first_r2 = first_r2 - 1;
            first_c2 = first_c2;
            move[0] = first_r2;
            move[1] = first_c2;

        }

        else if ((board[first_r2 - 1][first_c2] == 2 || board[first_r2 - 1][first_c2] == 1) && direc2 == 2)
            {direc2 =3;
              first_r2 = start_r2;
              first_c2 = start_c2;}

        if (board[first_r2 - 1][first_c2 - 1] != 2 && board[first_r2 - 1][first_c2 - 1] != 1 && direc2 == 3 && first_r2 - 1 < 15 && first_c - 1 < 15)
        {

            first_r2 = first_r2 - 1;
            first_c2 = first_c2 - 1;
            move[0] = first_r2;
            move[1] = first_c2;

        }
        else if ((board[first_r2 - 1][first_c2 - 1] == 2 || board[first_r2 - 1][first_c2 - 1] == 1) && direc2 == 3)
            {direc2=4;
              first_r2 = start_r2;
              first_c2 = start_c2;}

        if (board[first_r2 + 1][first_c2 + 1] != 2 && board[first_r2 + 1][first_c2 + 1] != 1 && direc2 == 4 && first_r2 + 1 < 15 && first_c2 + 1 < 15)
        {

            first_r2 = first_r2 + 1;
            first_c2 = first_c2 + 1;
            move[0] = first_r2;
            move[1] = first_c2;

        }
        else if((board[first_r2 + 1][first_c2 + 1] == 2 || board[first_r2 + 1][first_c2 + 1] == 1) && direc2 == 4)
            {direc2=5;
              first_r2 = start_r2;
              first_c2 = start_c2;}

        if (board[first_r2 + 1][first_c2 - 1] != 2 && board[first_r2 + 1][first_c2 - 1] != 1 && direc2 == 5 && first_r2 + 1 < 15 && first_c2 - 1 < 15)
        {

            first_r2 = first_r2 + 1;
            first_c2 = first_c2 - 1;
            move[0] = first_r2;
            move[1] = first_c2;

        }
        else if ((board[first_r2 + 1][first_c2 - 1] == 2 || board[first_r2 + 1][first_c2 - 1] == 1) && direc2 == 5)
            {direc2=6;
              first_r2 = start_r2;
              first_c2 = start_c2;}
        if (board[first_r2 - 1][first_c2 + 1] != 2 && board[first_r2 - 1][first_c2 + 1] != 1 && direc2 == 6 && first_r2 - 1 < 15 && first_c2 + 1 < 15)
        {

            first_r2 = first_r2 - 1;
            first_c2 = first_c2 + 1;
            move[0] = first_r2;
            move[1] = first_c2;

        }
        else if ((board[first_r2 - 1][first_c2 + 1] == 2 || board[first_r2 - 1][first_c2 + 1] == 1) && direc2 == 6)
            {direc2=7;
              first_r2 = start_r2;
              first_c2 = start_c2;}


        if (board[first_r2][first_c2 - 1] != 2 && board[first_r2][first_c2 - 1] != 1 && direc2 == 7 && first_r2 < 15 && first_c2 - 1 < 15)
        {

            first_r2 = first_r2;
            first_c2 = first_c2 - 1;
            move[0] = first_r2;
            move[1] = first_c2;

        }
        else if((board[first_r2][first_c2 - 1] == 2 || board[first_r2][first_c2 - 1] == 1) && direc2 == 7)
            {direc2=8;
              first_r2 = start_r2;
              first_c2 = start_c2;}

        if (board[first_r2][first_c2 + 1] != 2 && board[first_r2][first_c2 + 1] != 1 && direc2 == 8 && first_r2 < 15 && first_c2 + 1 < 15)
        {

            first_r2 = first_r2;
            first_c2 = first_c2 + 1;
            move[0] = first_r2;
            move[1] = first_c2;

        }

        else if((board[first_r2][first_c2 + 1] == 2 || board[first_r2][first_c2 + 1] == 1) && direc2 == 8)
            { ran = rand()%5;
              move[0] = rand()%7 + ran;
              first_r2 = move[0];
              start_r2 = first_r2;
              move[1] = rand()%7 + ran;
              first_c2 = move[1];
              start_c2 = first_c2;
              direc2 = 1;}

    }
    else if (check2 == 1)
    {   if(board[place[0]][place[1]] != 2 && board[place[0]][place[1]] != 1)
        {printf("yes 1 ");
        move[0] = place[0];
        move[1] = place[1];
        }
        else {continue;}
    }

    }

  }while (checkMove2(board, move) == 0);

  return move;
}

int checkOppWin2(int board[][SIZE],int* place)
{
    int r = 0;
    int c = 0;
    int x;
    int win_cnt[4] = {0};

    for (r = 14;r >= 0;r--)
    {
        for (c = 14;c >= 0;c--)
    {
        win_cnt[0] = 0;
        win_cnt[1] = 0;
        win_cnt[2] = 0;
        win_cnt[3] = 0;


            for(x = 0;x<5;x++)
            {
                if(board[r][c + x]==2)
                {
                    win_cnt[0] = win_cnt[0] + 1;
                    if (win_cnt[0] >= 3)//max_cnt[0])
                    {
                        for(x=0;x<5;x++)
                        {
                            if ((board[r][c + x] == 0 && board[r][c + x - 1] == 2 && board[r][c + x + 1] == 2) || (board[r][c + x] == 0 && board[r][c + x - 1] == 2) || (board[r][c + x] == 0 && board[r][c + x + 1] == 2))
                            {
                                place[0] = r;
                                place[1] = c+x;
                                return 1;
                            }
                            else {continue;}
                        }
                    }
                    else{continue;}
                }


                else if(board[r - x][c + x]==2)
                {
                    win_cnt[1] = win_cnt[1] + 1;
                    if (win_cnt[1] >= 3)// max_cnt[1])
                    {
                        //max_cnt[1] = win_cnt[1];
                        for(x=0;x<5;x++)
                        {
                            if ((board[r - x][c + x] == 0 && board[r-x-1][c + x + 1] == 2 && board[r-x+1][c + x - 1] == 2)|| (board[r - x][c + x] == 0 && board[r-x-1][c + x + 1] == 2)|| (board[r - x][c + x] == 0 && board[r-x+1][c + x - 1] == 2))
                            {
                                place[0] = r - x;
                                place[1] = c + x;
                                return 1;
                            }
                            else {continue;}
                        }
                    }
                    else{continue;}
                }

                else if(board[r-x][c]==2)
                {
                    win_cnt[2] = win_cnt[2] + 1;
                    if (win_cnt[2] >= 3)// max_cnt[2])
                    {
                        for(x=0;x<5;x++)
                        {
                            if ((board[r - x][c] == 0 && board[r-x-1][c] == 2 && board[r-x+1][c] == 2) || (board[r - x][c] == 0 && board[r-x-1][c] == 2) || (board[r - x][c] == 0 && board[r-x+1][c] == 2))
                            {
                                place[0] = r - x;
                                place[1] = c;
                                return 1;
                            }
                            else {continue;}
                        }
                    }
                    else{continue;}
                }

                else if(board[r - x][c - x]==2)
                {
                    win_cnt[3] = win_cnt[3] + 1;
                    if (win_cnt[3] > 3)//max_cnt[3])
                    {
                        for(x=0;x<5;x++)
                        {
                            if ((board[r - x][c - x] == 0 && board[r-x-1][c - x - 1] == 2 && board[r- x + 1][c - x + 1] == 2)||(board[r - x][c - x] == 0 && board[r-x-1][c - x - 1] == 2) || (board[r - x][c - x] == 0 && board[r- x + 1][c - x + 1] == 2))
                            {
                                place[0] = r - x;
                                place[1] = c - x;
                                return 1;
                            }
                            else {continue;}
                        }
                    }
                    else{continue;}

                    }
                }




        if (r == 0 && c == 0)
        {
            return 0;
        }
        else{continue;}

    }
    }
}

