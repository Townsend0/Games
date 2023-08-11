#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void PrintBoard(int **a);
void AI(int **a,int (*m)[9]);
int main(){
    int **a=(int**)malloc(sizeof(int*)*9),b,c,*d,e[2],f,g=0,h,i,j,k,l,m[9][9]={0};
    char s[5],t[9],r;
    for(b=0;b<9;b++)
    a[b]=(int*)malloc(sizeof(int)*9);    
    srand(time(NULL));
    for(d=*a;d<=(*(a+8)+8);d++)
    *d=' ';
    AI(a,m);
    for(b=38;b<1000;b++){
        PrintBoard(a);
        do{
            do{
                c=0;
                printf("\nRow's number: ");
                s[0]=getche();
                (s[0]<'1'||s[0]>'9')&&printf("\nEnter a number between 1 and 9 only")&&c++;
            }while(c);
            do{
                c=0;
                printf("\nColumn's number: ");
                s[1]=getche();
                (s[1]<'1'||s[1]>'9')&&printf("\nEnter a number between 1 and 9 only")&&c++;
            }while(c);
            c=0;
            (m[s[0]-49][s[1]-49]!=0)&&printf("\nThe slot u picked can not be changed")&&c++;
        }while(c);
        do{
            c=0;
            printf("\nEnter a value: ");
            s[2]=getche();
            (s[2]<'1'||s[2]>'9')&&printf("\nThe value must be a number between 1 and 9")&&c++;
            for(f=0;f<9;f++)
            (a[f][s[1]-49]==s[2]&&f!=s[0]-49)&&printf("\nThe value you enter already exists in the same column")&&c++;
            for(f=0;f<9;f++)
            (a[s[0]-49][f]==s[2]&&f!=s[1]-49)&&printf("\nThe value you enter already exists in the same row")&&c++;
        }while(c);
        a[s[0]-49][s[1]-49]=s[2];
        system("cls");
        l=0;
        for(d=*a;d<=(*(a+8)+8);d++)
        (*d==' ')&&l++;
        if(l==0)
        break;
    }
    PrintBoard(a);
    printf("\n\t\t{ You have won }");
    getche();
    return 0;
}
void AI(int **a,int (*m)[9]){
    int b,c,f,h,i,j,k,g,x;
    for(b=0;b<38;b++){
        do{
            c=rand()%9;
            f=rand()%9;
            g=0;
            x=rand()%9+1+'0';
            for(h=0;h<9;h++)
            (a[c][h]==x||a[h][f]==x||a[c][f]!=' ')&&g++;
            for(h=0;h<9;h+=3){
                for(i=0;i<9;i+=3){
                    for(j=h;j<h+3;j++){
                        for(k=i;k<i+3;k++)
                        (c-h>=0&&c-h<3&&f-i>=0&&f-i<3&&x==a[j][k])&&g++;
                    }
                }
            }
        }while(g);
        a[c][f]=x;
        m[c][f]=x;
    }
}
void PrintBoard(int **a){
    printf("\t\t\t      { sudoko }\n\n");
        printf("\t\t    ___________________________________\n");
        for(int c=0;c<9;c++){
            for(int f=0;f<9;f++){
                (f==0)&&printf("\t\t   ");
                (f==8)? printf("|   |"): printf("|   ");
            }
            printf("\n");
            for(int f=0;f<9;f++){
                (f==0)&&printf("\t\t%d  ",c+1);
                (f==8)? printf("|_%c_|",a[c][f]): printf("|_%c_",a[c][f]);
            }
            printf("\n");
        }
    printf("\n\t\t     1   2   3   4   5   6   7   8   9\n");
}