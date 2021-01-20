#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>


// THREE BY THREE GLOBAL VARIABLES

int  playersPreviousChoice3x3, resumeGame3x3 = 0, resumeStart3x3 = 0, noPosLeft3x3=0;
char p1name3x3[50],p2name3x3[50];

char check3x3[9] = {'1','2','3','4','5','6','7','8','9'};			  	// Array that Check for Wins and Draws (every elements must be different)

char a=' ',b=' ',c=' ',d=' ',e=' ',f=' ',g=' ',h=' ',z=' ',j=' ';    	// Position Characters in 3x3 Board

// THREE BY THREE FUNCTIONS PROTOTYPES

void Board3x3();
void Game3x3();
char Position3x3(int position, int whichPlayerTurn, char choicePlayer1 , char choicePlayer2);
void Restart3x3();



// FIVE BY FIVE GLOBAL VARIABLES

int  playersPreviousChoice5x5, resumeGame5x5 = 0, resumeStart5x5 = 0, noPosLeft5x5=0;
char p1name5x5[50] , p2name5x5[50];

char check[25] = "abcdefghijklmnopqrstuvwxy" ;							// Array that Check for Wins and Draws (every elements must be different)		

char p1=' ',p2=' ',p3=' ',p4=' ',p5=' ';                        		// Position Characters in 5x5 Board
char p6=' ',p7=' ',p8=' ',p9=' ',p10=' ';
char p11=' ',p12=' ',p13=' ',p14=' ',p15=' ';
char p16=' ',p17=' ',p18=' ',p19=' ',p20=' ';
char p21=' ',p22=' ',p23=' ',p24=' ',p25=' ';

// FIVE BY FIVE FUNCTIONS PROTOTYPES

void Board();
void Game();
char Position(int position, int whichPlayerTurn, char choicePlayer1 , char choicePlayer2);
void Restart();


// OTHER GLOBAL VARIABLES AND FUNCTIONS PROTOTYPES
int  end,scoreP1=0,scoreP2=0;
void whichgame();
void MENU();


void main(){
	do 
	{
		system("cls");
		
		if (resumeGame3x3 == 0)
		{
			Restart3x3();
		}
		
		if (resumeGame5x5 == 0)
		{
			Restart();
		}
		
		MENU();

		if (end == 2)
		{
			system("cls");
			printf("\n\t\t\t\tA GAME BY:\n");
			printf("\t\t\t\t==========\n\n");
			printf("MAHAD KHALID TARAR\n");
			printf("\nABDULLAH RAHEEL\n");
			printf("\nJAHANZEB RAZA\n");
			printf("\nMOHAMMAD AMMAR");
			exit(1);
		}
	
	} while (end != 2);
}


//  THREE BY THREE FUNCTIONS

void Board3x3(){                                   // Shows 3x3 Board


	printf("\t|\t|\n   %c    |   %c   |   %c    \t\t\tScore %s = %d\n\t|\t|\t\t\t\tScore %s = %d\n",a,b,c,p1name3x3,scoreP1,p2name3x3,scoreP2);
	printf("--------|-------|--------\n");
	printf("\t|\t|\n   %c    |   %c   |   %c   \n\t|\t|\n",d,e,f);
	printf("--------|-------|--------\n");
	printf("\t|\t|\n   %c    |   %c   |   %c   \n\t|\t|\n",g,h,z);

}


void Game3x3(){                                    // Driver Function that handles 3x3 Tic Tac Toe Game
	
	int position=0, whichPlayerTurn=0, timestart=9, resume=0, start=1, finish=9, flag, i, x;
	char win = 'D',choicePlayer1,choicePlayer2,reset = 'N';
	
	system("color F");

//=========================================================================================================================//	

	if (resumeGame3x3 == 0)
	{
		printf("%s: Enter Your Marker X/O\n", p1name3x3 );
		scanf(" %c", &choicePlayer1 );

	
		while(choicePlayer1 != 'X')
		{
			if(choicePlayer1 == 'O')
			{ 
				break;
			}
			printf("ERROR! Must be X or O.\n%s: Enter Your Marker X/O\n", p1name3x3 );
			scanf(" %c", &choicePlayer1 );
		}
			
		system("cls");
		
		if (choicePlayer1 == 'X')
		{
			choicePlayer2 = 'O';
			playersPreviousChoice3x3 = 0;
		}
		
		else 
		{
			choicePlayer2 = 'X';
			playersPreviousChoice3x3 = 1;
		}
	}
	
	else
	{
		if ( playersPreviousChoice3x3 == 0 )
		{
			choicePlayer1 = 'X';
			choicePlayer2 = 'O';
		}
		
		else
		{
			choicePlayer1 = 'O';
			choicePlayer2 = 'X';	
		}
		 
		start = start + resumeStart3x3;
		finish = finish + resumeStart3x3;
	}

//=========================================================================================================================//	
	
	Board3x3();
	
	if ( resumeGame3x3 != 0 )
	{
		printf("\nPress Y if you want to Reset ElSE N\n");
		scanf(" %c", &reset );
		if (reset == 'Y')
		{
			scoreP1 = 0;
			scoreP2 = 0;
			resumeGame3x3 = 0;
			resumeStart3x3 = 0;
			playersPreviousChoice3x3 = 0;
			noPosLeft3x3 = 0;
			main();
		}
	}

//=========================================================================================================================//	

	for (i = start ; i <= finish ; i++)
	{		
				if (resume == 2)
				{
					resumeGame3x3 = 1;
					resumeStart3x3 = i-3,
					main();
				}
		
			flag = 0;
				
				if (i%2 == 0)
				{
					printf("\n\n%s TURN (%c)\n", p2name3x3, choicePlayer2);
					whichPlayerTurn = 2;
				}
				else 
				{
					printf("\n\n%s TURN (%c)\n", p1name3x3, choicePlayer1);
					whichPlayerTurn = 1;
				}
				
				printf("If Both Players Press -1 , The Game will Stop.\n");
				printf("At Which Position (1-9) Do You Want To Place Your Marker.\n");
			    
				while(timestart != 0)
				{
				
					printf("\rTime left = %d", timestart);
					
					sleep(1);
					timestart--;
					
					if(kbhit())
					{
					printf("\n");
						do
						{
							position = 0;
							scanf(" %d",&position);
							
							if (position != -1){
								if(position <= 0 || position > 9)
								{
									printf("ERROR! - Position number must be between 1 & 9 inclusive.\n");
								}
								else if(check3x3[position-1] == 'X' || check3x3[position-1] == 'O')
								{
									printf("ERROR! - Position taken. Position Number must be empty.\n");
								}
								else
								{
									flag = 1;
								}
							}
						
							fflush(stdin);	
		
						}while(flag == 0 && position != -1);
						
					break;
					}
				}

				if ( position == -1 )
				{
					resume++;
					finish++;
					timestart = 9;
					continue;
				}
				
				if( timestart == 0 )
				{
					if (i%2 == 0){
						printf("\n\n%s (%c) JUST LOST HIS/HER TURN!\n\a", p2name3x3, choicePlayer2);
						whichPlayerTurn = 2;
					}
					else
					{
						printf("\n\n%s (%c) JUST LOST HIS/HER TURN!\n\a", p1name3x3, choicePlayer1);
						whichPlayerTurn = 1;
					}
				}
				else
				{
					resume = 0;
					Position3x3( position, whichPlayerTurn, choicePlayer1, choicePlayer2 );	
				}
			
			timestart = 9;
			    
				if (check3x3[0] == check3x3[1] && check3x3[0] == check3x3[2]){
			    	win = check3x3[0];
			    	break;
				}
				else if (check3x3[0] == check3x3[3] && check3x3[0] == check3x3[6]){
					win = check3x3[0];
			    	break;
				}
				else if (check3x3[2] == check3x3[5] && check3x3[2] == check3x3[8]){
					win = check3x3[2];
			    	break;
				}
				else if (check3x3[6] == check3x3[7] && check3x3[6] == check3x3[8]){
					win = check3x3[6];
			    	break;
				}
				else if (check3x3[0] == check3x3[3] && check3x3[0] == check3x3[6]){
					win = check3x3[0];
			    	break;
				}
				else if (check3x3[2] == check3x3[4] && check3x3[2] == check3x3[6]){
					win = check3x3[2];
			    	break;
				}
				else if (check3x3[0] == check3x3[4] && check3x3[0] == check3x3[8]){
					win = check3x3[0];
			    	break;
				}
				else if (check3x3[3] == check3x3[4] && check3x3[3] == check3x3[5]){
					win = check3x3[3];
			    	break;
				}
				else if (check3x3[1] == check3x3[4] && check3x3[1] == check3x3[7]){
					win = check3x3[1];
			    	break;
				}
				
				else
				{
					noPosLeft3x3 = 0;
					for (x=0;x<9;x++)
					{
						if (check3x3[x] == 'X' || check3x3[x] == 'O')
						{
							noPosLeft3x3++;	
						}
					}
				}
				
				if ( noPosLeft3x3 == 9)
				{
					break;
				}
	}

//=========================================================================================================================//	

	if ( win == choicePlayer1 )
	{
		printf("\n\n\n%s WINS !!!", p1name3x3);
		resumeGame3x3 = 0;
		resumeStart3x3 = 0;
		playersPreviousChoice3x3 = -1;
		noPosLeft3x3 = 0;
		scoreP1++;
	}
	
	else if ( win == choicePlayer2 )
	{
		printf("\n\n\n%s WINS !!!", p2name3x3);
		resumeGame3x3 = 0;
		resumeStart3x3 = 0;
		playersPreviousChoice3x3 = -1;
		noPosLeft3x3 = 0;
		scoreP2++;
	}
	
	else
	{
		printf("IT'S A DRAW !!!");
		resumeGame3x3 = 0;
		resumeStart3x3 = 0;
		playersPreviousChoice3x3 = -1;
		noPosLeft3x3 = 0;
	}
}


char Position3x3(int position, int whichPlayerTurn, char choicePlayer1 , char choicePlayer2){  // handles marker(X/O) position on the 5x5 Board
	char temp;
	switch (position){
		case 1:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			a = temp;
			check3x3[0] = temp;
			system("cls");
			Board3x3();
		break;
		case 2:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			b = temp;
			check3x3[1] = temp;
			system("cls");
			Board3x3();
		break;
		case 3:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			c = temp;
			check3x3[2] = temp;
			system("cls");
			Board3x3();
		break;
		case 4:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			d = temp;
			check3x3[3] = temp;
			system("cls");
			Board3x3();
		break;
		case 5:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			e = temp;
			check3x3[4] = temp;
			system("cls");
			Board3x3();
		break;
		case 6:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			f = temp;
			check3x3[5] = temp;
			system("cls");
			Board3x3();
		break;
		case 7:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			g = temp;
			check3x3[6] = temp;
			system("cls");
			Board3x3();
		break;
		case 8:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			h = temp;
			check3x3[7] = temp;
			system("cls");
			Board3x3();
		break;
		case 9:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			z = temp;
			check3x3[8] = temp;
			system("cls");
			Board3x3();
		break;
	
	}
}


void Restart3x3(){                                // Reset Global Variables of 3x3 Board etc for Rematching
	a=' ' ; b=' ' ; c=' ' ; d=' ' ; e=' ' ; f=' ' ; g=' ' ; h=' ' ; z=' ' ; j=' ';
	int i ;
	for (i=0;i<9;i++){
		check3x3[i] = i + 1;
	}
}



// FIVE BY FIVE FUNCTIONS

void Board(){                                          // Shows 5x5 Board

	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c    \t\tScore %s = %d\n\t|\t|\t|\t|\t\t\tScore %s = %d\n",p1,p2,p3,p4,p5,p1name5x5,scoreP1,p2name5x5,scoreP2);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\n",p6,p7,p8,p9,p10);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\n",p11,p12,p13,p14,p15);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\n",p16,p17,p18,p19,p20);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\n",p21,p22,p23,p24,p25);

}


void Game(){                                           // Driver Function that handles 5x5 Tic Tac Toe Game
	
	int  position = 0, whichPlayerTurn = 0, timestart = 9, resume = 0, start = 1, finish = 25, flag, i, x;
	char choicePlayer1, choicePlayer2, reset = 'N', win = 'D';

	system("Color E");

//=========================================================================================================================//	

	if (resumeGame5x5 == 0)
	{
		printf("%s: Enter Your Marker X/O\n", p1name5x5 );
		scanf(" %c", &choicePlayer1 );
		
		while(choicePlayer1 != 'X')
		{
			if(choicePlayer1 == 'O')
			{
				break;
			}
			printf("ERROR! Must be X or O\n%s: Enter Your Marker X/O\n");
			scanf(" %c", &choicePlayer1 );
		}
		
		
		system("cls");
		
		if (choicePlayer1 == 'X')
		{
			choicePlayer2 = 'O';
			playersPreviousChoice5x5 = 0;
		}
		else
		{
			choicePlayer2 = 'X';
			playersPreviousChoice5x5 = 1;
		}
	}
	
	else
	{
		if (playersPreviousChoice5x5 == 0)
		{
			choicePlayer1 = 'X';
			choicePlayer2 = 'O';
		}
		else
		{
			choicePlayer1 = 'O';
			choicePlayer2 = 'X';	
		}	
		
		start = start + resumeStart5x5;
		finish = finish + resumeStart5x5;
	}

//=========================================================================================================================//	
	
	Board();
	
	if (resumeGame5x5 != 0)
	{
		printf("\nPress Y if you want to Reset\n");
		scanf(" %c", &reset );
		if (reset == 'Y')
		{
			resumeGame5x5 = 0;
			playersPreviousChoice5x5 = 0;
			noPosLeft5x5 = 0;
			scoreP1 = 0;
			scoreP2 = 0;
			main();
		}
	}

//=========================================================================================================================//	

	for (i = start ; i <= finish ; i++)
	{
				if ( resume == 2 ){
					resumeGame5x5 = 1;
					resumeStart5x5++;
					main();
				}	
			
			flag = 0;
				
				if (i%2 == 0)
				{
					printf("\n\n%s TURN (%c)\n", p2name5x5, choicePlayer2);
					whichPlayerTurn = 2;
				}
				else
				{
					printf("\n\n%s TURN (%c)\n", p1name5x5, choicePlayer1);
					whichPlayerTurn = 1;
				}
		
				printf("At Which Position (1-25) Do You Want To Place Your Marker.\n");
				
				while(timestart != 0)
				{
					
					printf("\rTime left = %d", timestart);
					
					sleep(1);
					timestart--;
					
					if(kbhit())
					{
					printf("\n");
						do
						{
							position = 0;
							scanf(" %d",&position);
							
							if (position != -1){
								if(position <= 0 || position > 25)
								{
									printf("ERROR! - Position number must be between 1 & 9 inclusive.\n");
								}
								else if(check[position-1] == 'X' || check[position-1] == 'O')
								{
									printf("ERROR! - Position taken. Position Number must be empty.\n");
								}
								else
								{
									flag = 1;
								}		
							}
							fflush(stdin);	
		
						}while(flag == 0 && position != -1);
						
					break;
					}
				}
			
				if ( position == -1 )
				{
					resume++;
					finish++;
					timestart = 9;
					continue;
				}
				
				if( timestart == 0 )
				{
					if (i%2 == 0){
						printf("\n\n%s (%c) JUST LOST HIS/HER TURN!\n\a", p2name5x5, choicePlayer2);
						whichPlayerTurn = 2;
					}
					else
					{
						printf("\n\n%s (%c) JUST LOST HIS/HER TURN!\n\a", p1name5x5, choicePlayer1);
						whichPlayerTurn = 1;
					}
				}
				else
				{	
					if ( position == -1 )
					{
						resume++;
					}
					else
					{
						resume = 0;
						Position( position, whichPlayerTurn, choicePlayer1, choicePlayer2 );	
					}
				}
			
			timestart = 9;
			    
				if (check[0] == check[1] && check[0] == check[2] && check[0] == check[4] && check[0] == check[3] ){
			    	win = check[0];
			    	break;
				}
				else if (check[0] == check[5] && check[0] == check[10]  && check[0] == check[15]  && check[0] == check[20]){
					win = check[0];
			    	break;
				}
				else if (check[5] == check[6] && check[5] == check[7]  && check[5] == check[8]  && check[5] == check[9] ){
					win = check[5];
			    	break;
				}
				else if (check[10] == check[11] && check[10] == check[12]  && check[10] == check[13]  && check[10] == check[14]){
					win = check[10];
			    	break;
				}
				else if (check[15] == check[16] && check[15] == check[17]  && check[15] == check[18] && check[15] == check[19]) {
					win = check[0];
			    	break;
				}
				else if (check[20] == check[21] && check[20] == check[22]  && check[20] == check[23]  && check[20] == check[24]){
					win = check[20];
			    	break;
				}
				else if (check[1] == check[6] && check[1] == check[11]  && check[1] == check[16]  && check[1] == check[21]){
					win = check[1];
			    	break;
				}
				else if (check[2] == check[7] && check[2] == check[12]  && check[2] == check[17]  && check[2] == check[22]){
					win = check[2];
			    	break;
				}
				else if (check[3] == check[8] && check[3] == check[13]  && check[3] == check[18]  && check[3] == check[23] ){
					win = check[3];
			    	break;
				}
				else if (check[4] == check[9] && check[4] == check[14]  && check[4] == check[19]  && check[4] == check[24] ){
					win = check[3];
			    	break;
				}
				else if (check[0] == check[6] && check[0] == check[12]  && check[0] == check[18]  && check[0] == check[24] ){
					win = check[0];
			    	break;
				}
				else if (check[4] == check[8] && check[4] == check[12]  && check[4] == check[16]  && check[4] == check[20] ){
					win = check[0];
			    	break;
				}
				else
				{
					noPosLeft5x5 = 0;
					for (x=0;x<25;x++)
					{
						if (check[x] == 'X' || check[x] == 'O')
						{
							noPosLeft5x5++;	
						}
					}
				}
				
				if (noPosLeft5x5 == 25)
				{
					break;
				}
	}

//=========================================================================================================================//
	
	if ( win == choicePlayer1 )
	{
		printf("\n\n\n%s WINS !!!",p1name5x5);
		playersPreviousChoice5x5 = -1;
		resumeGame5x5 = 0;
		noPosLeft5x5 = 0;
		scoreP1++;
	}
	else if  (win == choicePlayer2 )
	{
		printf("\n\n\n%s WINS !!!",p2name5x5);
		playersPreviousChoice5x5 = -1;
		resumeGame5x5 = 0;
		noPosLeft5x5 = 0;
		scoreP2++;
	}
	else
	{
		printf("IT'S A DRAW !!!");
		playersPreviousChoice5x5 = -1;
		resumeGame5x5 = 0;
		noPosLeft5x5 = 0;
	}
}


char Position(int position, int whichPlayerTurn, char choicePlayer1 , char choicePlayer2){  // handles marker(X/O) position on the 5x5 Board
	char temp;
	switch (position){
		case 1:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p1 = temp;
			check[0] = temp;
			system("cls");
			Board();
			break;
		case 2:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p2 = temp;
			check[1] = temp;
			system("cls");
			Board();
		break;
		case 3:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p3 = temp;
			check[2] = temp;
			system("cls");
			Board();
		break;
		case 4:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p4 = temp;
			check[3] = temp;
			system("cls");
			Board();
		break;
		case 5:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p5 = temp;
			check[4] = temp;
			system("cls");
			Board();
		break;
		case 6:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p6 = temp;
			check[5] = temp;
			system("cls");
			Board();
		break;
		case 7:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p7 = temp;
			check[6] = temp;
			system("cls");
			Board();
		break;
		case 8:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p8 = temp;
			check[7] = temp;
			system("cls");
			Board();
		break;
		case 9:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p9 = temp;
			check[8] = temp;
			system("cls");
			Board();
		break;
		case 10:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p10 = temp;
			check[9] = temp;
			system("cls");
			Board();
		break;
		case 11:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p11 = temp;
			check[10] = temp;
			system("cls");
			Board();
		break;
		case 12:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p12 = temp;
			check[11] = temp;
			system("cls");
			Board();
		break;
		case 13:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p13 = temp;
			check[12] = temp;
			system("cls");
			Board();
		break;
		case 14:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p14 = temp;
			check[13] = temp;
			system("cls");
			Board();
		break;
		case 15:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p15 = temp;
			check[14] = temp;
			system("cls");
			Board();
		break;
		case 16:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p16 = temp;
			check[15] = temp;
			system("cls");
			Board();
		break;
		case 17:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p17 = temp;
			check[16] = temp;
			system("cls");
			Board();
		break;
		case 18:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p18 = temp;
			check[17] = temp;
			system("cls");
			Board();
		break;
		case 19:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p19 = temp;
			check[18] = temp;
			system("cls");
			Board();
		break;
		case 20:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p20 = temp;
			check[19] = temp;
			system("cls");
			Board();
		break;
		case 21:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p21 = temp;
			check[20] = temp;
			system("cls");
			Board();
		break;
		case 22:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p22 = temp;
			check[21] = temp;
			system("cls");
			Board();
		break;
		case 23:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p23 = temp;
			check[22] = temp;
			system("cls");
			Board();
		break;
		case 24:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p24 = temp;
			check[23] = temp;
			system("cls");
			Board();
		break;
		case 25:
			if (whichPlayerTurn == 1){
				temp = choicePlayer1;
			}
			else temp = choicePlayer2;
			p25 = temp;
			check[24] = temp;
			system("cls");
			Board();
		break;
	}
}


void Restart(){                                       // Reset Global Variables of 5x5 Board etc for Rematching
	 p1 = ' ' ;  p2 = ' ' ;  p3 = ' ' ;  p4 = ' ' ;  p5 = ' ' ;
	 p6 = ' ' ;  p7 = ' ' ;  p8 = ' ' ;  p9 = ' ' ; p10 = ' ' ;
	p11 = ' ' ; p12 = ' ' ; p13 = ' ' ; p14 = ' ' ; p15 = ' ' ;
	p16 = ' ' ; p17 = ' ' ; p18 = ' ' ; p19 = ' ' ; p20 = ' ' ;
	p21 = ' ' ; p22 = ' ' ; p23 = ' ' ; p24 = ' ' ; p25 = ' ' ;
	
	 check[0] = 'a' ;  check[1] = 'b' ;  check[2] = 'c' ;  check[3] = 'd' ;  check[4] = 'e' ;
	 check[5] = 'f' ;  check[6] = 'g' ;  check[7] = 'h' ;  check[8] = 'i' ;  check[9] = 'j' ;
	check[10] = 'k' ; check[11] = 'l' ; check[12] = 'm' ; check[13] = 'n' ; check[14] = 'o' ;
	check[15] = 'p' ; check[16] = 'q' ; check[17] = 'r' ; check[18] = 's' ; check[19] = 't' ;
	check[20] = 'u' ; check[21] = 'v' ; check[22] = 'w' ; check[23] = 'x' ; check[24] = 'y' ; 
	
}



// OTHER FUNCTIONS 

void whichgame(){                                   // Ask USER which game to play and handle Rematching
	
	char rematch;
	int choicegame;
	
	system("cls");
	
	// Inner Menu
	printf("1 - Tic Tac Toe 3x3\n");
	printf("2 - Tic Tac Toe 5x5\n");
	printf("3 - Return to Main MENU\n");
	
	printf("\nWhat do you want to do?\n");
	scanf("%d",&choicegame);
	
	if (choicegame == 1)
	{
			system("cls");
			if (resumeGame3x3 == 0)
			{
				printf("Player 1: Enter Your Name.\n");
				fflush(stdin);
				gets(p1name3x3);
				system("cls");
				printf("Player 2: Enter Your Name.\n");
				fflush(stdin);
				gets(p2name3x3);
				system("cls");
			}
			
			do
			{
	    		rematch = 'N';	    		
				Game3x3();
				printf("\nIf you want to Play Again. Press Y\n");
				scanf(" %c",&rematch);
		
				if (rematch == 'Y'){

					system("cls");
					Restart3x3();
				}
				else
				{
					system("cls");
					Board3x3();
					getch();
					scoreP1 = 0;
					scoreP2 = 0;
					break;
				}
		
			}while(rematch == 'Y');

	}
	
	
	else if (choicegame == 2)
	{
			system("cls");
			if (resumeGame5x5 == 0)
			{
				printf("Player 1: Enter Your Name.\n");
				fflush(stdin);
				gets(p1name5x5);
				system("cls");
				printf("Player 2: Enter Your Name.\n");
				fflush(stdin);
				gets(p2name5x5);
				system("cls");
			}
			
			do
			{
	    		rematch = 'N';	    		
				Game();
				printf("\nIf you want to Play Again. Press Y\n");
				scanf(" %c",&rematch);
		
				if (rematch == 'Y'){
					system("cls");
					Restart();
				}
				else
				{
					system("cls");
					Board();
					getch();
					scoreP1 = 0;
					scoreP2 = 0;
					break;
				}
		
			}while(rematch == 'Y');
	}

	else if (choicegame == 3)
	{
		// return back to MENU
	}

	else
	{
		printf("WRONG CHOICE!\nPlease Enter Again.");
	 	getch();
	 	whichgame();
	}
}

void MENU(){                                        // Shows Menu
	
	int choicemenu;
	
	system("color E");

	// Outer Menu
	printf("\n\t\t\t\tTIC TAC TOE\n");
	printf("\t\t\t\t===========\n\n\n\n");
	printf("1 - Play GAME\n");
	printf("2 - Quit GAME\n");
	
	printf("\n\nWhat do you want to do?\n");
	scanf("%d",&choicemenu);
	
	if ( choicemenu == 1 )
	{
		whichgame();
	}
	
	else if ( choicemenu == 2 )
	{
		end = choicemenu;
	}
	else
	{
		printf("INCORRECT CHOICE ! Please Enter Again\n");
		getch();
		system("cls");
		MENU();
	}
	
}


