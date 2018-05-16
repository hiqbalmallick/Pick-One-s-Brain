#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
void removescore()
{
	FILE *file;
	remove("High Score.txt");
	file=fopen("High Score.txt","w");
	fclose(file);
	system("cls");
	printf("Score Refreshed!");
	printf("\n\nPress Any Key to Continue!");
	getch();
}
void displayscore()
{
	char player_name[20];
	float high_score;
	FILE *file;
	system("cls");
	file=fopen("High Score.txt","r");
	fseek(file,0,SEEK_SET);
	fscanf(file,"%s%f",&player_name,&high_score);
	printf("\n\n\t\t ");
	printf("\n\n\t\t %s has secured the Highest Score %.2f",player_name,high_score);
	printf("\n\n\t\t	");
	fclose(file);
	printf("Press Any Key to continue!");
	getch();
}
void help()
{
	system("cls");
	printf("\n\n\n\tThis game is very easy to play. You'll be asked some general");
	printf("\n\n\tknowledge questions and the right answer is to be chosen among");
	printf("\n\n\tthe options provided. Your score will be calculated at the");
	printf("\n\n\tend. Remember that the more quicker you give your answer the more");
	printf("\n\n\tscore you will secure. Your score will be calculated and displayed");
	printf("\n\n\tat the end. If you secure highest score, your score will be recorded.");
	printf("\n\n\tSo BEST OF LUCK!");
	printf("\n\n\t\tPress Any Key to continue!");
}
void writescore(float score, char player_name[20])
{
	float high_score;
	char top_player[20];
	FILE *file;
	system("cls");
	file=fopen("High Score.txt","r");
	fseek(file,0,SEEK_SET);
	fscanf(file,"%s%f",&top_player,&high_score);
	if (score>=high_score)
	{
		high_score=score;
		file=fopen("High Score.txt","w");
		fprintf(file,"%s\n%.2f",player_name,high_score);
		fclose(file);
		return;
	}
	fclose(file);
}
int main()
	{
		FILE *file;
		int r, i, pa, nq[20], w, countq, countr, loop, loop2, line;
		float score;
		char choice, option, playername[20],que[500];
		time_t initialtime, finaltime;
		system("cls");
		mainhome:
		system("cls");
		puts("\n\t\t WELCOME TO I.Q. TEST PROGRAM\n\n") ;
		puts("\n\t\t-------------------------------");
		puts("\n\t\t Enter 'S' to Start Game		");
		puts("\n\t\t Enter 'V' to View High Score	");
		puts("\n\t\t Enter 'H' for Help				");
		puts("\n\t\t Enter 'R' to Remove High Score	");
		puts("\n\t\t Enter 'Q' to Quit Game			");
		printf("\n\t\t-------------------------------\n\n\t\t");
		choice=toupper(getch());
		if (choice=='V')
		{
			displayscore();
			goto mainhome;
		}
		else if (choice=='Q')
		exit(1);
		else if (choice=='H')
		{
			help();
			getch();
			goto mainhome;
		}
		else if (choice=='R')
		{
			removescore();
			goto mainhome;
		}
		else if(choice=='S')
		{
			system("cls");
			printf("\n\n\n\t\t\tEnter your name...");
			printf("\n\t\t\t(only one word)\n\n\t\t\t");
			gets(playername);
			home:
			system("cls");
			initialtime=time(NULL);
			countq=countr=0;
			i=1;
			start:
			srand ( time(NULL) );
			r=rand()%20+1;
			nq[i]=r;
			for (w=0;w<i;w++)
			if (nq[w]==r) goto start;
			switch(r)
			{
				case 1:
					line=1;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c1:
					option=getch();
					if (toupper(option)=='C')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++;
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='A' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is C. Snake\n\n");
						break;
					}
					else
					{
						printf ("\n\nInvalid Option!");
						goto c1;
					}
				case 2:
					line=4;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c2:
					option=getch();
					if (toupper(option)=='D')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++;
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='C' || toupper(option)=='A' )
					{
						printf("\n\nWrong!!! The correct answer is D. 21\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c2;
					}
				case 3:
					line=7;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c3:
					option=getch();
					if (toupper(option)=='C')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='A' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is C. 15264\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c3;
					}
				case 4:
					line=10;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
							{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c4:
					option=getch();
					if (toupper(option)=='C')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='A' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is C. 24\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c4;
					}
				case 5:
					line=13;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c5:
					option=getch();
					if (toupper(option)=='D')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;}
					else if (toupper(option)=='B' || toupper(option)=='C' || toupper(option)=='A' )
					{
						printf("\n\nWrong!!! The correct answer is D. Twig\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c5;
					}
				case 6:
					line=16;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c6:
					option=getch();
					if (toupper(option)=='A' )
					{
						printf("\n\nCorrect!!!\n\n");
						countr++;
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='C' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is A. Actor\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c6;
					}
				case 7:
					line=19;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c7:
					option=getch();
					if (toupper(option)=='C')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='A' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is C. Rome\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c7;
					}
				case 8:
					line=22;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c8:
					option=getch();
					if (toupper(option)=='C')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='A' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is C. Lukas Podolski\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c8;
					}
				case 9:
					line=25;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c9:
					option=getch();
					if (toupper(option)=='C')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='D' || toupper(option)=='A' )
					{
						printf("\n\nWrong!!! The correct answer is C. Herschelle Gibbs\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c9;
					}
				case 10:
					line=28;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c10:
					option=getch();
					if (toupper(option)=='B')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++;
						break;
					}
					else if (toupper(option)=='C' || toupper(option)=='A' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is B. Victoria City\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c10;
					}
				case 11:
					line=31;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c11:
					option=getch();
					if (toupper(option)=='C')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='A' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is C. George Wahington\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c11;
					}
				case 12:
					line=34;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c12:
					option=getch();
					if (toupper(option)=='A')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='B')
					{
						printf("\n\nWrong!!! The correct answer is A. True\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c12;
					}
				case 13:
					line=37;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c13:
					option=getch();
					if (toupper(option)=='B')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='A' || toupper(option)=='C' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is B. Reliable\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c13;
					}
				case 14:
					line=40;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c14:
					option=getch();
					if (toupper(option)=='D')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='C' || toupper(option)=='A' ) 
					{
						printf("\n\nWrong!!! The correct answer is D. 1600\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c14;
					}
				case 15:
					line=43;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c15:
					option=getch();
					if (toupper(option)=='D')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++;
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='C' || toupper(option)=='A')
					{
						printf("\n\nWrong!!! The correct answer is D. 3\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c15;
					}
				case 16:
					line=46;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c16:
					option=getch();
					if (toupper(option)=='B')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='A' || toupper(option)=='C' || toupper(option)=='D')
					{
						printf("\n\nWrong!!! The correct answer is B. Sky\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c16;
					}
				case 17:
					line=49;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c17:
					option=getch();
					if (toupper(option)=='B')
					{	
						printf("\n\nCorrect!!!\n\n");
						countr++; 
						break;
					}
					else if (toupper(option)=='C' || toupper(option)=='A' || toupper(option)=='D')
					{
						printf("\n\nWrong!!! The correct answer is B. Vague\n\n");
						break;
					}
					else
					{
						printf("\n\nInvalid Option!");
						goto c17;
					}
				case 18:
					line=52;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c18:
					option=getch();
					if (toupper(option)=='D')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++;
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='A' || toupper(option)=='C' )
					{
						printf("\n\nWrong!!! The correct answer is D. None of these (Answer: Today)\n\n");
						break;
					}
					else
					{
						printf ("\n\nInvalid Option!");
						goto c18;
					}
				case 19:
					line=55;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c19:
					option=getch();
					if (toupper(option)=='A')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++;
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='C' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is A. 2009\n\n");
						break;
					}
					else
					{
						printf ("\n\nInvalid Option!");
						goto c19;
					}
				case 20:
					line=58;
					file=fopen("Quiz File.txt","r");
					for (loop2=0;loop2<line;loop2++)
					{
						fgets(que,sizeof(que),file);
						if (loop2==(line-1))
						for (loop=0;loop<3;loop++)
						{
							fgets(que,sizeof(que),file);
							printf ("%s",que);
						}
					}
					fclose(file);
					countq++;
					c20:
					option=getch();
					if (toupper(option)=='A')
					{
						printf("\n\nCorrect!!!\n\n");
						countr++;
						break;
					}
					else if (toupper(option)=='B' || toupper(option)=='C' || toupper(option)=='D' )
					{
						printf("\n\nWrong!!! The correct answer is A. Brazil\n\n");
						break;
					}
					else
					{
						printf ("\n\nInvalid Option!");
						goto c20;
					}
   			}
			i++;
			if (i<=20) 
				goto start;
			finaltime=time(NULL);
			score=(float)countr/countq*100-difftime(finaltime,initialtime)/3;
			play_again:
			system("cls");
			if (score<0) score=0;
				printf("\n\n\nYour Score: %.2f",score);
			if (score==100)
				printf("\n\nEXCELLENT!!! KEEP IT UP");
			else if (score>=80 && score<100)
				printf("\n\nVERY GOOD!!");
			else if (score>=60 &&score<80) 
				printf("\n\nGOOD! BUT YOU NEED TO KNOW MORE.");
			else if (score>=40 && score<60)
				printf("\n\nSATISFACTORY RESULT, BUT THIS MUCH IS MUCH SUFFICIENT.");
			else 
				printf("\n\nYOU ARE VERY POOR IN G.K.,WORK HARD");
			printf("\n\nDo You Want To Play Again?(y/n)");
			choice=getch();
			if (toupper(choice)=='Y')
			{
				writescore(score,playername);
				goto home;
			}
			else if (toupper(choice)=='N')
			{
				writescore(score,playername);
				goto mainhome;
			}
			else
			{
				printf("\n\nEnter Correct Key!");
				Sleep(1000);
				goto play_again;
			}
		}
	else
		{
			printf("\n\n\t\t	Enter the right key!\n\n\t\t		");
			Sleep(1000);
			goto mainhome;
		}
return 0;
}
