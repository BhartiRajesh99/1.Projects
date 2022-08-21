#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void up_mover(int (*)[],int);
void down_mover(int (*)[],int);
void left_mover(int (*)[],int);
void right_mover(int (*)[],int);
void num_generator(int (*)[],int);
int winning(int (*)[],int);
void swap(int*,int*);
void game(char*);
void pattern(int (*)[],int);
void sample_pattern(int (*)[],int);
int main()
{
    char name[20];
    int a[4][4],i;
    system("cls");
    printf("\n\n\n");
    printf("\e[1;96m");
    printf("\t\tPlayer Name: ");
    fgets(name,20,stdin);
    printf("\e[0m");
    name[strlen(name)-1]='\0';
    system("cls");
    printf("\t\t\e[1;95mNUMBER PUZZLE\e[0m\n");
    printf("\n\t%6c\e[1;31mRULES OF THIS GAME\e[0m\n",' ');
    printf("\n\e[0;36m1.You can move only 1 step at a time by arrow key.\e[0m\n");
    printf("\t%c Move Up    : by Up arrow key\n",26);
    printf("\t%c Move Down  : by Down arrow key\n",26);
    printf("\t%c Move Left  : by Left arrow key\n",26);
    printf("\t%c Move Right : by Right arrow key\n",26);
    printf("\e[0;36m");
    printf("\n2.You can move number at empty position only.\n");
    printf("\n3.For each valid move : Your total number of move will decreased by 1.\n");
    printf("\n4.Winning Situation : Number in a 4x4 matrix should be in order from 1 to 15.\e[0m\n");
    printf("\e[0m");
    printf("\n\t\t%2c\e[0;32mwinning situation:\e[0m\n",' ');
    printf("\e[0;35m");
    sample_pattern(a,4);  //winning situation pattern indicator
    printf("\e[0m");
    printf("\n\e[0;36m5.You can exit the game at any time by pressing 'E' or 'e'.\e[0m\n");
    printf("\n%3c\e[0;36m-->>\e[0;33m So try to win in minimum number of moves\e[0m\n",' ');
    printf("\n\t%6c\e[0;32mHappy Gaming,good luck!!\e[0m\n",' ');
    printf("\n\e[0;34mEnter any key to start.....\e[0m");
    getch();
    system("cls");
    game(name);  //matrix game
    printf("\n");
    getch();
    return 0;
}
void pattern(int (*f)[4],int size6)
{
    int i,j,s;
    printf("\e[1;93m");
    for(i=1;i<=6;i++)
    {
        s=1;
        printf("\t\t");
        for(j=1;j<=21;j+=5)
        {
            if(j==21)
            {
                switch(i)
                {
                    case 1:printf("-");break;
                    case 2:printf("|");break;
                    case 3:printf("|");break;
                    case 4:printf("|");break;
                    case 5:printf("|");break;
                    case 6:printf("-");
                }
            }
            else if(i==1||i==6)
                printf("-----");
            else
            {
                if(f[i-2][j+3-4*s]==32)
                    printf("%c%4c",'|',' ');
                else
                    printf("%c%c\e[1;92m%2d\e[1;93m%c",'|',' ',f[i-2][j+3-4*s],' ');
                s++;
            }
        }
        printf("\n");
    }
}
void game(char *w)
{
    int k,win;
    int c,d,b[4][4]={0},i;
    do
    {
        k=400;
        num_generator(b,4);  //generate random numbers in array b
        while(k>=1)
        {
            system("cls");
            printf("\n\t\e[0;35mPlayer name:\e[0;33m %s\e[0;31m ,\e[0;32m Move remaining:\e[0;31m %d\e[0m\n\n",w,k);
            pattern(b,4);  //printing game matrix
            c=getch();
            if(c==224||c==0)
            {
                i=getch();
                printf("\e[1;96m\n");
                switch(i)
                {
                    case 72:
                            up_mover(b,4); //moving up function
                            printf("\t\t%4cYou moved->Up",' ');
                            break;
                    case 80:
                            down_mover(b,4);  //moving down function
                            printf("\t\t%4cYou moved->Down",' ');
                            break;
                    case 75:
                            left_mover(b,4);  //moving left function
                            printf("\t\t%4cYou moved->Left",' ');
                            break;
                    case 77:
                            right_mover(b,4);  //moving right function
                            printf("\t\t%4cYou moved->Right",' ');
                            break;
                }
                printf("\e[0m");
                win=winning(b,4);  //comparing current array with sorted array
                if(win==1)
                    break;
                k--;
            }
            else if(c=='e'||c=='E')
            {
                printf("\e[0m");
                exit(0);
            }
            else
                printf("\n\t\e[1;96mPlease play with arrow keys.\e[0m\n\n");
        }
        system("cls");
        pattern(b,4);
        if(win==0)
            printf("\n\t\t%7c\e[1;91mYOU LOSE!\e[0m\n",' ');
        else
            printf("\n\n\t%7c\e[1;94mCONGRATULATIONS, YOU WIN!\e[0m\n\n",' ');
        printf("\n\t\t%2c\e[0;32mWant to play again?\n",' ');
        printf("\t\t\e[0;33mEnter 'y' to play again:");
        d=getch();
        printf("%c\e[0m",d);
        if(d=='y'||d=='Y')
            continue;
        else
            break;
    }while(d);
}
void num_generator(int (*u)[4],int size5)
{
    int m,n,l,y,x,temp;
    srand(time(NULL));
    for(m=0;m<size5;m++)
    {
        l=0;
        while(l<size5)
        {
            n=l;
            if(m==size5-1&&l==size5-1)
            {
                u[m][l]=' ';
                break;
            }
            temp=rand()%15+1;
            for(x=m;x>=0;x--)
            {
                for(y=n-1;y>=0;y--)
                    if(u[x][y]==temp)
                        break;
                if(y!=-1)
                    break;
                n=4;
            }
            if(x==-1&&y==-1)
            {
                u[m][l]=temp;
                l++;
            }
        }
    }
}
void up_mover(int (*p)[4],int size)
{
    int i,j,flag=0,n;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            if(i>=1)
            {
                if(*(p[i]+j)==32)
                {
                    flag=1;
                    swap(&p[i][j],&p[i-1][j]);
                    break;
                }
            }
            else
            {
                if(p[i][j]==32)
                {
                    flag=1;
                    for(n=0;n<3;n++)
                        swap(&p[n][j],&p[n+1][j]);
                    break;
                }
            }
        if(flag==1)
            break;
    }
}
void down_mover(int (*q)[4],int size1)
{
    int i,j,flag=0,n;
    for(i=0;i<size1;i++)
    {
        for(j=0;j<size1;j++)
            if(i<=2)
            {
                if(*(q[i]+j)==32)
                {
                    flag=1;
                    swap(&q[i][j],&q[i+1][j]);
                    break;
                }
            }
            else
            {
                if(q[i][j]==32)
                {
                    flag=1;
                    for(n=3;n>0;n--)
                        swap(&q[n][j],&q[n-1][j]);
                    break;
                }
            }
        if(flag==1)
            break;
    }
}
void left_mover(int (*r)[4],int size2)
{
    int i,j,flag,n;
    for(i=0;i<size2;i++)
    {
        flag=0;
        for(j=0;j<size2;j++)
            if(j>=1)
            {
                if(*(r[i]+j)==32)
                {
                    flag=1;
                    swap(&r[i][j],&r[i][j-1]);
                    break;
                }
            }
            else
            {
                if(*(r[i]+j)==32)
                {
                    flag=1;
                    for(n=0;n<3;n++)
                        swap(&r[i][n],&r[i][n+1]);
                    break;
                }
            }
        if(flag==1)
            break;
    }
}
void right_mover(int (*s)[4],int size3)
{
    int i,j,flag,n;
    for(i=0;i<size3;i++)
    {
        flag=0;
        for(j=0;j<size3;j++)
            if(j<=2)
            {
                if(*(s[i]+j)==32)
                {
                    flag=1;
                    swap(&s[i][j],&s[i][j+1]);
                    break;
                }
            }
            else
            {
                if(*(s[i]+j)==32)
                {
                    flag=1;
                    for(n=3;n>0;n--)
                        swap(&s[i][n],&s[i][n-1]);
                    break;
                }
            }
        if(flag==1)
            break;
    }
}
void swap(int *v,int *h)
{
    int z;
    z=*v;
    *v=*h;
    *h=z;
}
void sample_pattern(int (*sam)[4],int size4)
{
    int i,j,ai,k=1;
    for(i=0;i<size4;i++)
        for(j=0;j<size4;j++)
            if(i==3&&j==3)
                sam[i][j]==32;
            else
                sam[i][j]=k++;
    for(i=1;i<=6;i++)
    {
        ai=1;
        printf("\t\t");
        for(j=1;j<=21;j+=5)
        {
            if(j==21)
            {
                switch(i)
                {
                    case 1:printf("-");break;
                    case 2:printf("|");break;
                    case 3:printf("|");break;
                    case 4:printf("|");break;
                    case 5:printf("|");break;
                    case 6:printf("-");
                }
            }
            else if(i==1||i==6)
                printf("-----");
            else
            {
                if(i==5&&ai==4)
                    printf("%c%4c",'|',' ');
                else
                    printf("%c%c%2d%c",'|',' ',sam[i-2][j+3-4*ai],' ');
                ai++;
            }
        }
        printf("\n");
    }
}
int winning(int (*z)[4],int size7)
{
    int vic[4][4]={0},i,j,numbers=1;
    for(i=0;i<size7;i++)
        for(j=0;j<size7;j++)
            if(i==size7-1&&j==size7-1)
                vic[i][j]=' ';
            else
                vic[i][j]=numbers++;
    for(i=0;i<size7;i++)
    {
        for(j=0;j<size7;j++)
        {
            if(z[i][j]!=vic[i][j])
                return 0;
        }
    }
    if(i==4)
        return 1;
}


