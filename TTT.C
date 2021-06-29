#include<conio.h>
#include<stdio.h>

/* function for check win */
int checkWin(int *board)
{
  if((board[0]=='X' && board[1]=='X' && board[2]=='X') ||
     (board[0]=='X' && board[3]=='X' && board[6]=='X') ||
     (board[0]=='X' && board[4]=='X' && board[8]=='X') ||
     (board[3]=='X' && board[4]=='X' && board[5]=='X') ||
     (board[6]=='X' && board[7]=='X' && board[8]=='X') ||
     (board[1]=='X' && board[4]=='X' && board[7]=='X') ||
     (board[2]=='X' && board[5]=='X' && board[8]=='X') ||
     (board[2]=='X' && board[4]=='X' && board[6]=='X') )
     {
       return 1;
     }
  else if((board[0]=='O' && board[1]=='O' && board[2]=='O') ||
	  (board[0]=='O' && board[3]=='O' && board[6]=='O') ||
	  (board[0]=='O' && board[4]=='O' && board[8]=='O') ||
	  (board[3]=='O' && board[4]=='O' && board[5]=='O') ||
	  (board[6]=='O' && board[7]=='O' && board[8]=='O') ||
	  (board[1]=='O' && board[4]=='O' && board[7]=='O') ||
	  (board[2]=='O' && board[5]=='O' && board[8]=='O') ||
	  (board[2]=='O' && board[4]=='O' && board[6]=='O') )
	{
	  return 2;
	}
  else
  {
    return 0;
  }

}

/* main function */
void main()
{
int board[9]={'1','2','3','4','5','6','7','8','9'};
int position,arr[50],i,j,times,end,temp;
char a,player1[15],player2[15];
clrscr();

 /* player name enter */
 printf("\t\t\t\t-----TIC TAC TOE -----\n");
 printf("Player 1 - 'X' & Player 2 - 'O'\n");
 printf("player 1 name : ");
 scanf("%s",&player1);
 printf("Player 2 name : ");
 scanf("%s",&player2);

   /* Board visuals */
	printf("\n\n\t\t\t\t|    |");
	printf("\n\t\t\t      %c | %c  | %c",board[0],board[1],board[2]);
	printf("\n\t\t\t   -----|----|-----");
	printf("\n\t\t\t      %c | %c  | %c",board[3],board[4],board[5]);
	printf("\n\t\t\t   -----|----|-----");
	printf("\n\t\t\t      %c | %c  | %c",board[6],board[7],board[8]);
	printf("\n\t\t\t\t|    |");

 arr[0]=0;

 /* continuous play loop */
do
{
textcolor(15);
times=0;
for(i=0;i<9;i++)
{
 //because it takes only characters ASCII value of 0 is 48
 board[i]= i+49;
}
 end=0;
 for(j=0;j<9;j++)
   {
    times++;

    /* position enter */
	printf("\n\n\tEnter (zero) 0 for exit:\n");
	printf("\n\nEnter position: ");
	if(times%2!=0)
	{
	  printf("\n%s -> ",player1);
	}
	else
	{
	  printf("\n%s -> ",player2);
	}
	scanf("%d",&position);
	/* check for out from game */
	if(position==0)
	 {
	  break;
	 }
	clrscr();
	arr[times]=position;

	/* check duplicasy of position */
	for(i=0;i<times;i++)
	 {
	  if(position==arr[i])
	  {
	   temp=arr[times];
	    times--;
	    j--;

	    textcolor(5+BLINK);
	    cprintf("\nAlready filled, enter another position");
	    textcolor(15);
	    break;
	  }
	 }

	 if(times%2!=0)
	   {
	     board[--position]='X';
	   }
	 else
	   {
	     board[--position]='O';
	   }

	   /* Board design */
	printf("\n\t\t\t\t-----TIC TAC TOE -----\n");
	printf("\n\n\t\t\t\t|    |");
	printf("\n\t\t\t      %c | %c  | %c",board[0],board[1],board[2]);
	printf("\n\t\t\t   -----|----|-----");
	printf("\n\t\t\t      %c | %c  | %c",board[3],board[4],board[5]);
	printf("\n\t\t\t   -----|----|-----");
	printf("\n\t\t\t      %c | %c  | %c",board[6],board[7],board[8]);
	printf("\n\t\t\t\t|    |");

	/* check winning of players */
	if(times>4)
	 {
	   int check = checkWin(board);
	 if(check==1)
	  {
	   textcolor(5+BLINK);
	   cprintf("\n\n- Congratulation %s, You win -",player1);
	   end=1;
	   break;
	  }
	 else if(check==2)
	  {
	   textcolor(6+BLINK);
	   cprintf("\n\n- Congratulation %s, You win -",player2);
	   end=1;
	   break;
	  }
	 else
	  {
	   if(times==9)
	   {
	     textcolor(2+BLINK);
	     cprintf(" \n\n- NO ONE WIN : Better Luck Next TIME -");
	     end=1;
	     break;
	   }
	  }
	 }

   }

   /* ask for continuous play or exit */
   if(end==1)
   {
     printf("\nYou want to play again 'Y' or 'N' : ");
     *arr=0;
     a=getch();
   }

}while((a=='y')||(a=='Y'));
textcolor(RED);
 cprintf("\nThanks for Playing :)");
 getch();

}
