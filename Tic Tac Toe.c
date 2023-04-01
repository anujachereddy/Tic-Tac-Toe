#include<stdio.h>

#include<conio.h>

#include<stdlib.h>

char TIC_TAC_TOE_MATRIX[3][3];

char CHECK(void);

void MATRIX_INITIALIZATION(void);

void PLAYER_MOVE(void);

void COMPUTER_MOVE(void);

void DISPLAY_MATRIX(void);


 int main(void)
 {
     char done;
     printf("\033[0;32m");

     printf("TIC TAC TOE -----(PLAYER VS COMPUTER)\n");

     printf("YOU ARE PLAYING AGANIST THE COMPUTER\n");

     printf("COMPUTER :- ALL THE BEST \n");

     printf("YOU CAN START THE GAME BY MAKING YOUR FIRST MOVE\n");

     printf("\033[0m");
     done =' ';

     MATRIX_INITIALIZATION();

     do
     {
         DISPLAY_MATRIX();

         PLAYER_MOVE();

         done=CHECK();

         if(done != ' ')

         break;

         COMPUTER_MOVE();

         done = CHECK();

     }while(done == ' ');

     if(done == 'x')

     {
         printf("\033[0;35m");

     printf("PLAYER WON THE GAME\n");

     printf("\033[0m");
     }

     else

    {
        printf("\033[0;36m");

     printf("COMPUTER WON THE GAME\n");

     printf("\033[0m");
    }

     DISPLAY_MATRIX();

     return 0;
 }

 void MATRIX_INITIALIZATION()

 {
     int i,j;

     for(i=0;i<3;i++)

     for(j=0;j<3;j++)

     TIC_TAC_TOE_MATRIX[i][j] = ' ';

 }

 void PLAYER_MOVE()

 {
     int  x,y;
     printf("\033[0;34m");

     printf("ENTER THE COORDINATES OF ROW AND COLUMN :- ");

     scanf("%d %d",&x,&y);

     printf("\033[0m");
     x--;

     y--;

     if(TIC_TAC_TOE_MATRIX[x][y] != ' ')
     {
        printf("\033[0;35m");

        printf("THE COORDINATES WHICH YOU SELECTED ARE ALREADY SELECTED BY YOU (OR) BY THE COMPUTER (or) THE COORDINATES MAY NOT EXISTS IN THE TIC TAC TOE MATRIX\n");

         printf("SO PLEASE SELECT DIFFERENT COORDINATES\n");

         printf("\033[0m");

         PLAYER_MOVE();
     }

     else

     TIC_TAC_TOE_MATRIX[x][y] = 'x';

 }

 void COMPUTER_MOVE()

 {
     int i,j;

     for(i=0; i<3; i++)

     {

     for(j=0; j<3; j++)

     if(TIC_TAC_TOE_MATRIX[i][j] == ' ')

     break;

     if(TIC_TAC_TOE_MATRIX[i][j] == ' ')

     break;

 }

    if(i*j==9)

    {
     printf("\033[0;33m");

     printf("THE MATCH ENDS WITH A TIE\n");

    printf("\033[0m");

     exit(0);

    }

    else

    TIC_TAC_TOE_MATRIX[i][j] = 'O';

}

void DISPLAY_MATRIX()

{
  int l;

for(l=0; l<3; l++)
{

printf("\033[0;31m");

printf(" %c | %c | %c ",TIC_TAC_TOE_MATRIX[l][0],TIC_TAC_TOE_MATRIX[l][1], TIC_TAC_TOE_MATRIX [l][2]);

if(l!=2)

printf("\n---|---|---\n");

printf("\033[0m");
}

printf("\n");

}

char CHECK(void)

{
    int i;

    for(i=0;i<3;i++)

    if((TIC_TAC_TOE_MATRIX[i][0]==TIC_TAC_TOE_MATRIX[i][1]) && (TIC_TAC_TOE_MATRIX[i][0]==TIC_TAC_TOE_MATRIX[i][2]))

    return TIC_TAC_TOE_MATRIX[i][0];

    for(i=0; i<3; i++)

    if((TIC_TAC_TOE_MATRIX[0][i]==TIC_TAC_TOE_MATRIX[1][i]) && (TIC_TAC_TOE_MATRIX[0][i]==TIC_TAC_TOE_MATRIX[2][i]))

    return TIC_TAC_TOE_MATRIX[0][i];

    if((TIC_TAC_TOE_MATRIX[0][0]==TIC_TAC_TOE_MATRIX[1][1]) && (TIC_TAC_TOE_MATRIX[1][1]==TIC_TAC_TOE_MATRIX[2][2]))

    return TIC_TAC_TOE_MATRIX[0][0];

    if((TIC_TAC_TOE_MATRIX[0][2]==TIC_TAC_TOE_MATRIX[1][1]) && (TIC_TAC_TOE_MATRIX[1][1]==TIC_TAC_TOE_MATRIX[2][0]))

    return TIC_TAC_TOE_MATRIX[0][2];

    return ' ';
}
