#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void PrintBoard(int *a);
int CheckNumber(int b,int *a);
void Names(char **t);
void Turns(int c,char **t);
int CheckWin(int *a,char *r);
int main(){
    int a[9],b,c,d,e,f,g,h,i,j;
    char s='1',**t=(char**)malloc(sizeof(char*)*3),r[20];
    for(b=0;b<2;b++)
    t[b]=(char*)malloc(sizeof(char)*20);
    for(b=0;b<9;b++)
    a[b]=s++;
    srand(time(0));
    printf("Press A to play against AI.\nPress any other character to play against friend.\n? ");
    e=getche();
    system("cls");
    if(e=='a'||e=='A'){
        printf("Enter your name: ");
        gets(t[0]);
        for(c=0;c<9;c++){
            PrintBoard(a);
            if(c%2==0){
                do{
                    printf("Your turn %s: ",t[0]);
                    b=getche();
                }while(CheckNumber(b,a));
                a[b-49]='X';
                system("cls");
                strcpy(r,t[0]);
                d=CheckWin(a,r);
                if(d==0)
                break;
                
            }
            else{
                do{
                    b=rand()%9+1+'0';
                }while(CheckNumber(b,a));
                a[b-49]='O';
                system("cls");
                strcpy(r,"AI");
                d=CheckWin(a,r);
                if(d==0)
                break;
            }
            if(c==8&&d!=0){
                printf("        { Draw }\n\n");
                PrintBoard(a);
                getche();
                return 0;
            }
        }
    }
    else{
        Names(t);
        for(c=0;c<9;c++){
            PrintBoard(a);
            do{
                Turns(c,t);
                b=getche();
            }while(CheckNumber(b,a));
            (c%2)? a[b-49]='O': a[b-49]='X';
            system("cls");
            (c%2)? strcpy(r,t[1]): strcpy(r,t[0]);
            d=CheckWin(a,r);
            if(d==0)
            break;
            if(c==8&&d!=0){
                printf("        { Draw }\n\n");
                PrintBoard(a);
                getche();
                return 0;
            }
        }
    }
    PrintBoard(a);
    getche();
    return 0;    
}
void PrintBoard(int *a){
    printf("\n        |        |        \n    %c   |    %c   |    %c    \n________|________|________\n        |        |        \n    %c   |    %c   |    %c    \n________|________|________\n        |        |        \n    %c   |    %c   |    %c    \n        |        |        \n\n",*a,a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
}
int CheckNumber(int b,int *a){
    int c=0;
    (b<49||b>57)&&printf("\n\n( Invalid number! ) Enter a number between 1 and 9 only!\n")&&c++;
    (a[b-49]=='X'||a[b-49]=='O')&&printf("\n\n( Invalid number! ) Already choosen!\n")&&c++;
    return c;
}
void Turns(int c,char **t){
    (c%2)? printf("\n%s's turn (O).\nEnter a number from 1 to 9: ",t[1]): printf("\n%s's turn (X).\nEnter a number from 1 to 9: ",t[0]);
}
int CheckWin(int *a,char *r){
    for(int b=0;b<9;b+=3)
    if((a[b]==a[b+1]&&a[b]==a[b+2])||(a[2]==a[4]&&a[2]==a[6])){
        printf("      { %s has won }\n\n",r);
        return 0;
    }
    for(int b=0;b<3;b++)
    if((a[b]==a[b+3]&&a[b]==a[b+6])||(a[0]==a[4]&&a[0]==a[8])){
        printf("      { %s has won }\n\n",r);
        return 0;
    }
    return 1;
}
void Names(char **t){
    printf("first player's name (X): ");
    scanf("%s",t[0]);
    printf("first player's name (O): ");
    scanf("%s",t[1]);
    system("cls");
}