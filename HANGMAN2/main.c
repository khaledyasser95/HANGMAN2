#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[20];
    int score;
} player;
int test=0,quit=0,score=0;
void read (player s)
{
    FILE *f;
    f = fopen("score.txt", "a");
    printf("\nPlayer Name: ");
    scanf("%s", s.name);
    printf("\t\t\tThank yo u for playing hope you enjoyed playing\n");
    fprintf(f,"%s %d\n", s.name,s.score);
    fclose(f);
    test=0;
    quit=0;
    main();
}
void Logo()
{
    printf("\t\t--------------------------------------------\n");
    printf("\t\t| #  #   #   #   #  #### #   #   #   #   # |\n");
    printf("\t\t| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
    printf("\t\t| #### ##### # # # #  ## # # # ##### # # # |\n");
    printf("\t\t| #  # #   # #  ## #   # #   # #   # #  ## |\n");
    printf("\t\t| #  # #   # #   #  ###  #   # #   # #   # |\n");
    printf("\t\t--------------------------------------------\n\n");
}
void menu()
{
    printf("\t\t\t****Game Rules******\n");
    printf("      You must Guess the word before word D O N K E Y is completed\n");
    printf("      \t \t     if you want to quit just type 'quit'\n");
    printf("Please choose a number\n");
    printf("1. New game\n");
    printf("2. Players score\n");
    printf("3. Top Player\n");
    printf("4. Players score ascending\n");
    printf("5. Players score descending \n");
    printf("6. Exit\n");
}
void game ()
{
    srand(time(NULL));
    int i,j,WL;
    char wordfromfile[20];
    char words[194][20];
    char word_guess[20];
    j=rand()%194;
    FILE *hang;
    hang=fopen("Hangman.txt","r");
    for (i=0; i<=j; i++)
        fscanf(hang, "%s\n", words[j]);

    strcpy(wordfromfile,words[j]);
    WL=strlen(wordfromfile);
    check(wordfromfile,WL,word_guess);

    fclose(hang);
}
void check(char wordfromfile[],int wordlength,char wordguess[])
{

    int i,wrong=0, flag,correct=0;
    char letter[10],letterin;
    printf("Let the game begin\n");
    printf("  Number of Letters = %d  ",wordlength);

    for (i=0; i<wordlength; i++)
    {
        printf(" _ ");
    }

    wordguess[wordlength]=NULL;
    for (i=0; i<wordlength; i++)
        wordguess[i]='-';

    printf("\n");

    while (wrong>=0 && wrong<6 )
    {
        printf("\n");
        printf("%s\n",wordfromfile);
        printf("\n Enter letter: ");
        //fgetchar();
        fgets( letter,10, stdin );
        flag=0;
        if( strncmp(letter, "quit", 4) == 0)
        {
            quit = 1;
            break;
        }
        letterin=letter[0];
        for (i=0; i<wordlength; i++)
        {
            if (letterin==wordfromfile[i])
            {
                wordguess[i]=letterin;
                flag=1;
            }
        }
        printf(" \t%s \n",wordguess);
        if  (strcmp(wordguess,wordfromfile)==0)
        {
            printf(" Congratulation %s\n");
            score=1;
            break;
        }
        if (flag==0)
        {
            wrong++;
            error(wrong,wordfromfile,wordlength);
        }
    }
}

void error(int wrong, char word[],int length)
{

    char error[]= {'D','o','n','k','e','y'};
    int i,count=0;
    for (i=0; i<wrong; i++)
    {
        printf(" %c ",error[i]);
        count++;
    }
    if (count==6)
    {
        printf("\n The word was '%s' \n",word);
        test=1;
    }
}
void maximumscore()
{
    player record[100];
    player maximum;
    int i,j;
    char s[20];
    int n,x=0;
    FILE *score;
    score=fopen("score.txt","r");
    while (fscanf(score,"%s %d",s,&n) !=EOF)
    {
        strcpy(record[x].name,s);
        record[x].score=n;
        x++;
    }
    fclose(score);
    maximum=record[0];
    for (i=0; i<x; i++)
    {
        if (record[i].score>maximum.score)
            maximum=record[i];
    }
    printf("TOP Player is '%s' with score %d\n",maximum.name,maximum.score);
}
void playerscores()
{
    player record[100];
    int i;
    char s[20];
    int n,x=0;
    FILE *score;
    score=fopen("score.txt","r");
    while (fscanf(score,"%s %d",s,&n) !=EOF)
    {
        strcpy(record[x].name,s);
        record[x].score=n;
        printf("%s %d \n",s,record[x].score);
        x++;
    }
    fclose(score);
}
void assortplayers()
{
    player record[100];
    player sortplayer[100];
    player swap;
    int i,d, position;
    char s[20];
    int n,x=0;
    FILE *score;
    score=fopen("score.txt","r");
    while (fscanf(score,"%s %d",s,&n) !=EOF)
    {
        strcpy(record[x].name,s);
        record[x].score=n;
        x++;
    }
    fclose(score);
    for ( i = 0 ; i < ( x - 1 ) ; i++ )
    {
        position = i;

        for ( d = i + 1 ; d < x ; d++ )
        {
            if ( record[position].score > record[d].score )
                position = d;
        }
        if ( position != i )
        {
            swap = record[i];
            record[i] = record[position];
            record[position] = swap;
        }
    }
    printf("Players in ascending order:\n");
    printf("----------------------\n");
    printf("|Name\t\tScore| \n");
    printf("|--------------------| \n");
    for ( i = 0 ; i < x ; i++ )
        printf("|%s\t\t %d  |\n",record[i].name, record[i].score);
    printf("|____________________| \n");
}
void dsortplayers()
{
    player record[100];
    player sortplayer[100];
    player swap;
    int i,d, position;
    char s[20];
    int n,x=0;
    FILE *score;
    score=fopen("score.txt","r");
    while (fscanf(score,"%s %d",s,&n) !=EOF)
    {
        strcpy(record[x].name,s);
        record[x].score=n;
        x++;
    }
    fclose(score);
    for ( i = 0 ; i < ( x - 1 ) ; i++ )
    {
        position = i;

        for ( d = i + 1 ; d < x ; d++ )
        {
            if ( record[position].score < record[d].score )
                position = d;
        }
        if ( position != i )
        {
            swap = record[i];
            record[i] = record[position];
            record[position] = swap;
        }
    }
    printf("Players in descending  order:\n");
    printf(" -------------------- \n");
    printf("|Name\t\tScore| \n");
    printf("|--------------------| \n");
    for ( i = 0 ; i < x ; i++ )
        printf("|%s\t\t %d  |\n",record[i].name, record[i].score);
    printf("|____________________| \n");
}
void main2()
{
    int choice,score=0;
    player player1;
    while(choice!=6)
    {
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:

            while (test != 1 && quit !=1)
            {
                game();
                score+=5;
                player1.score=score;
                printf("\t\t\t\t\t\tYour score is =%d\n",player1.score);
            }
            test=0;
            player1.score=score-5;
            read(player1);
            break;
        case 2:
            playerscores();
            printf("\nChoose what to do again:\n");
            main2();
            break;
        case 3:
            maximumscore();
             printf("\nChoose what to do again:\n");
            main2();
            break;
        case 4:
            assortplayers();
             printf("\nChoose what to do again:\n");
            main2();
            break;
        case 5:
            dsortplayers();
             printf("\nChoose what to do again:\n");
            main2();
            break;
        case 6:
            printf("Good Bye\n");
        }
    }
    printf("Thank you for playing");

}
int main()
{
    Logo();
    menu();
    main2();
}
