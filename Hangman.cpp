#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void img(int);     ////prototype for image function
void game(void); 
void hint(int);  //// prototype for header
 
////HANGMAN GAME PROJECT
/*
  
  Group Members:
  Syed Hammad Jaffery 15K-2890
  Zoya Rehman         15K-2333  
  Vajiha Raza         15K-2135 
  Saqib Ahmed         15K-2810 
*/

main()
{
	char ch2;
	do
	{
	if(ch2=='y' || ch2=='Y')
	{
    system("cls");
	system("COLOR 07");
	}
	FILE *fp,*fp1,*fp2; //fp1 for reading count value,fp for reading word,fp2 for increment in count
	char W[50];
	int h,c,n,d,i,j=0,k; // n is no. of mistakes allowed,d is length of string(word),i & j are some variables used for loops
	
	fp1=fopen("count.txt","r");
	fscanf(fp1,"%d",&i);
	h=i;
	if(i>20)
	i=i-20;
	fclose(fp1); // count has been read here and if it exceeds no. of lines then -20 is done
	game();
	fp=fopen("word.txt","r");
	for(j=1;j<=i;j++)
	fgets(W,50,fp);
	fclose(fp); // word is read from the file successfully.
	
	fp2=fopen("count.txt","w");
	j=i+3;
	fprintf(fp1,"%d",j);
	fclose(fp2);
    d=strlen(W); //increment of count is done here.
	for(i=1;i<d;i++)
	printf("_ ");
    hint(h);
    char ch,C[d],I[5]; //where C is array for correct words and I is array of incorrect words
    char P[d]; //previous correct char array
    int c1=0,c2=0;
    n=0; //now coming towards the looping part. here n is number of mistakes allowed
    int t=1;
	while(n!=5)
    {
    	c=0;       //count
    	fflush(stdin);
    	ch=getche();
    	for(j=0;j<d;j++)
    	{
    		if(ch==W[j])
    		{
    			for(k=0;P[k]!='\0';k++)
    			{
    				if(P[k]==ch)
    				{
    					n++;
    			        I[c2]=ch;
		                c2++;
		                goto skip;
    			    }
				}
			t=t+1;
			P[c1]=ch;
			C[c1]=ch;
			c1++;
			break;
			}         // t is a counter which increments when a letter is correct
    		else
    		c=c+1;
	    }
	    if(c==d)
	    {
		n++;
		I[c2]=ch;
		c2++;
		}                //here n is number of mistakes allowed    
	
	skip:system("cls");
	for(i=1;i<d;i++)
	printf("_ ");
	hint(h);
	img(n);
	printf("\nCorrect:");
	for(i=0;i<c1;i++)
	printf("%c",C[i]);
	printf("\nIncorrect:");
	for(i=0;i<c2;i++)
	printf("%c",I[i]);
	   if(t==d)
	   {
	   system("COLOR 27");  //green color
	   printf("\nCongratulations You Won and guessed correct word which was '%s'",W);
	   break;
       }
	}
	if(n==5)
	printf("\nAll Mistakes availed, Sorry you lost\nWord was %s",W);
	printf("\nDo you want to play again? (Y/N)");
	ch2=getche();
    }while(ch2=='y' || ch2=='Y');
}
void hint(int h)
{
	if(h>=1 && h<=5)
	printf("\nHint :Land Animal\n");
	else if(h>=6 && h<=10)
	printf("\nHint :Sea Animal\n");	
	else if(h>=11 && h<=15)
	printf("\nHint :City\n");
	else if(h>=16 && h<=20)
	printf("\nHint :Bird\n");
}
void img(int a)
{
	
	if(a==1)
	{
		printf("\n  _\n");
		printf(" |_|\n");
		printf("  |\n");
	}
	else if(a==2)
	{
		printf("\n   _\n");
		printf("  |_|\n");
		printf(" --|\n");
		
	} 
	else if(a==3)
	{
		printf("\n  _\n");
		printf(" |_|\n");
		printf("--|--\n");
	}
	else if(a==4)
	{
		system("COLOR 6B"); //yellow color
		printf("\n  _\n"); 
		printf(" |_|\n");
		printf("--|--\n");
		printf(" /   \n");
	}
	else if(a==5)
	{
	    system("COLOR 4F"); //red color
		printf("\n  _\n");
		printf(" | |\n");
		printf("--|--\n");
		printf(" / \\ \n ");
	}
}
void game(void)
{
    printf("--------------------------------------------\n");
    printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
    printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
    printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
    printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
    printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
    printf("--------------------------------------------\n\n");
	printf("\n");
	printf("\nRules:Guess the words for FIVE number of chances before you hang the hangman\nJust press the letters(small letters only)\n");
	printf("\nBegin guessing!\n");
	printf("\n");
}


//END OF PROGRAM!
