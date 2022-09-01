#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void smart_computer(int*,char*);
void evil_computer(int*,char*);
void friend(int*,char*,char*);
void arrvalue(int*);
void gamepattern(int*);
int pyl(int*,char,char*,char*);
int player(int,int*,char);
int s_player(int*,char,char*,char*);
int e_player(int*,char,char*,char*);
int win_checker(int*);
int s_checker(int*);
void e_checker(int*);
int o_check(int*);
int detect(int*);
int f_value(int*);
int gr(int*,char*,char*);
void result(int,int,char*,char*);
void demo(char*,char*);
int main()
{
    int i,n,arr[9];
    char name[20],name1[20];
    arrvalue(arr);
    while(1)
    {
        system("cls");
        printf("   -------TIC-TAC-TOE-------\n\n");
        printf("1.Play with Smart computer.\n");
        printf("2.Play with Evil computer.\n");
        printf("3.Play with Player.\n");
        printf("4.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        fflush(stdin);
        system("cls");
        switch(n)
        {
            case 1:
                printf("Enter Player Name:");
                fgets(name,20,stdin);
                name[strlen(name)-1]='\0';
                system("cls");
                smart_computer(arr,name);
                break;
            case 2:
                printf("Enter Player Name:");
                fgets(name,20,stdin);
                name[strlen(name)-1]='\0';
                system("cls");
                evil_computer(arr,name);
                break;
            case 3:
                printf("Enter Player1 Name:");
                fgets(name,20,stdin);
                name[strlen(name)-1]='\0';
                printf("Enter Player2 Name:");
                fgets(name1,20,stdin);
                name1[strlen(name1)-1]='\0';
                system("cls");
                friend(arr,name,name1);
                break;
            case 4:
                exit(0);
            default:
                printf("/nInvalid Choice\n");
        }
    }
    getch();
    return 0;
}

void smart_computer(int *p,char *name)
{
    int win=0,win1=0;
    demo(name,"Computer");
    printf("\n\n\n");
    arrvalue(p);
    gamepattern(p);
    printf("\n\n\n");
    while(1)
    {
        win=pyl(p,'X',name,"Computer");
        if(win==1||win==2)
            break;
        win1=s_player(p,'O',name,"Computer");
        if(win1==1||win1==2)
            break;
    }
    result(win,win1,"You","Computer");
}
void evil_computer(int *q,char *name)
{
    int i,win=0,win1=0;
    demo(name,"Computer");
    printf("\n\n\n");
    arrvalue(q);
    gamepattern(q);
    printf("\n\n\n");
    while(1)
    {
        win=pyl(q,'X',name,"Computer");
        if(win==1||win==2)
            break;
        win1=e_player(q,'O',name,"Computer");
        if(win1==1||win1==2)
            break;
    }
    result(win,win1,"You","Computer");
}
void friend(int *r,char *n,char *n1)
{
    int win=0,win1=0;
    demo(n,n1);
    printf("\n\n\n");
    arrvalue(r);
    gamepattern(r);
    printf("\n\n\n");
    while(1)
    {
        win=pyl(r,'X',n,n1);
        if(win==1||win==2)
            break;
        win1=pyl(r,'O',n,n1);
        if(win1==1||win1==2)
            break;
    }
    result(win,win1,n,n1);
}
void arrvalue(int *b)
{
    int i;
    char k=1;
    for(i=0;i<9;i++)
        b[i]=k++;
}
void gamepattern(int *h)
{
    int i,j,flag,m=1,n;
    int row=0;
    for(i=0;i<9;i++)
    {
        n=2;
        flag=0;
        printf("      ");
        for(j=0;j<17;j++)
            if(j==5||j==11)
                printf("|");
            else if(i==2||i==5)
                printf("_");
            else if(i==m&&j==n)
            {
                if(h[row]=='X'||h[row]=='O')
                    printf("%c",h[row]);
                else
                    printf("%d",h[row]);
                flag=1;
                row++;
                n+=6;
            }
            else
                printf(" ");
        if(flag==1)
         {   
            m+=3;
         }
        printf("\n");
    }
}
int pyl(int *z,char b,char *n,char *n1)
{
    int num;
    while(1)
    {
        if(b=='X')
            printf("\n    %s, Enter mark place:",n);
        else
            printf("\n    %s, Enter mark place:",n1);
        fflush(stdin);
        scanf("%d",&num);
        system("cls");
        demo(n,n1);
        if(player(num,z,b)==1)
            break;
    }
    return gr(z,n,n1);
}
int player(int x,int *l,char t)
{
    if(x>=1&&x<=9)
        if(l[x-1]!='X'&&l[x-1]!='O')
        {
                l[x-1]=t;
                return 1;
        }
        else
            printf("\n          Occupied");
     else
            printf("\n       Invalid number");
    
    printf("\n\n\n");
    gamepattern(l);
    printf("\n\n\n");
    return 0;
}
int s_player(int*f,char r,char*s,char*z)
{
    if(f_value(f)==11)         
        f[s_checker(f)]='O';
    else
        f[f_value(f)]='O';
    return gr(f,s,z);
}
int e_player(int*f,char r,char*s,char*z)
{
    if(f_value(f)==11)
        e_checker(f);
    else
        f[f_value(f)]='O';
    return gr(f,s,z);
}
int s_checker(int *w)
{
    int i,j,diag1x,diag2x,rowx,colx,c=11,e=11,d=11,g=11;
    if(o_check(w)!=11)
        return o_check(w);
    else
    {
        for(i=0;i<3;i++)
        {
            colx=0;
            for(j=i;j<=i+6;j+=3)
            {
                if(w[j]=='O')
                    break;
                if(w[j]=='X')
                    colx++;
                if(w[j]!='X'&&w[j]!='O')
                    c=j;
                if((colx==2)&&(j==i+6)&&(c!=11))
                    return c;
            }
        }        
        for(i=0;i<=6;i+=3)
        {
            rowx=0;
            for(j=i;j<=i+2;j++)
            { 
                if(w[j]=='O')
                    break;
                if(w[j]=='X')
                    rowx++;
                if(w[j]!='X'&&w[j]!='O')
                    d=j;
                if((rowx==2)&&(j==i+2)&&(d!=11))
                    return d;
            }
        }   
        for(i=0;i<3;i+=2)
        {
            diag1x=0;
            diag2x=0;
            if(i==0)
            {
                for(j=i;j<=i+8;j+=4)
                {
                    if(w[j]=='O')
                        break;
                    if(w[j]=='X')
                        diag1x++;
                    if(w[j]!='X'&&w[j]!='O')
                        g=j;
                    if((diag1x==2)&&(j==i+8)&&(g!=11))
                        return g;
                }
            }
            else
            {
                for(j=i;j<=i+4;j+=2)
                {
                    if(w[j]=='O')
                        break;
                    if(w[j]=='X')
                        diag2x++;
                    if(w[j]!='X'&&w[j]!='O')
                        e=j;
                    if((diag2x==2)&&(j==i+4)&&(e!=11))
                        return e;
                }
            }
        }           
        return detect(w);
    }
}
void e_checker(int *w)
{
    int i,j,y,diag1x,diag2x,rowx,colx,c=11,d=11,g=11;
    int flag=0;
    if(o_check(w)!=11)
        w[o_check(w)]='O';
    else
    {
        for(i=0;i<3;i++)
        {
            colx=0;
            for(j=i;j<=i+6;j+=3)
            {
                if(w[j]=='O')
                    break;
                if(w[j]=='X')
                    colx++;
                if(w[j]!='X'&&w[j]!='O')
                    c=j;
                if(colx==2&&j==i+6&&c!=11)
                {    
                    w[c]='O';
                    flag=1;
                }
            }
        }        
        for(i=0;i<=6;i+=3)
        {
            rowx=0;
            for(j=i;j<=i+2;j++)
            { 
                if(w[j]=='O')
                    break;
                if(w[j]=='X')
                    rowx++;
                if(w[j]!='X'&&w[j]!='O')
                    d=j;
                if(rowx==2&&j==i+2&&d!=11)
                {    
                    w[d]='O';
                    flag=1;
                }
            }
        }   
        for(i=0;i<3;i+=2)
        {
            diag1x=0;
            diag2x=0;
            if(i==0)
            {
                for(j=i;j<=i+8;j+=4)
                {
                    if(w[j]=='O')
                        break;
                    if(w[j]=='X')
                        diag1x++;
                    if(w[j]!='X'&&w[j]!='O')
                        g=j;
                    if(diag1x==2&&j==i+8&&g!=11)
                    {   
                        w[g]='O';
                        flag=1;
                    }
                }
            }
            else
            {
                for(j=i;j<=i+4;j+=2)
                {
                    if(w[j]=='O')
                        break;
                    if(w[j]=='X')
                        diag2x++;
                    if(w[j]!='X'&&w[j]!='O')
                        g=j;
                    if(diag2x==2&&j==i+4&&g!=11)
                    {    
                        w[g]='O';
                        flag=1;
                    }
                }
            }
        }
        if(flag==0) 
        {
            y=detect(w);  
            w[y]='O';
        }
    }     
}
int win_checker(int *w)
{
    int i,j,diag1,diag1x,diag2,diag2x,row0,rowx,col0,colx;
    for(i=0;i<3;i++)
    {
        col0=0;colx=0;
        for(j=i;j<=i+6;j+=3)
            if(w[j]=='O')
                col0++;
            else if(w[j]=='X')
                colx++;
        if(col0==3||colx==3)
            return 1;
    }        
    for(i=0;i<=6;i+=3)
    {
        row0=0;rowx=0;
        for(j=i;j<i+3;j++) 
            if(w[j]=='O')
                row0++;
            else if(w[j]=='X')
                rowx++;
        if(row0==3||rowx==3)
            return 1;
    }   
    for(i=0;i<3;i+=2)
    {
        diag1=0;diag1x=0;diag2=0;diag2x=0;
        if(i==0)
        {
            for(j=i;j<=8;j+=4)
                if(w[j]=='O')
                    diag1++;
                else if(w[j]=='X')
                    diag1x++;
            if(diag1x==3||diag1==3)
                return 1;
        }
        else
        {
            for(j=i;j<=6;j+=2)
                if(w[j]=='O')
                    diag2++;
                else if(w[j]=='X')
                    diag2x++;
            if(diag2x==3||diag2==3)
                return 1;
        }
    }           
    return 0;
}
int o_check(int *cp)
{
    int i,j,diag1x,diag2x,rowx,colx,c=11,e=11,d=11,g=11;
    for(i=0;i<3;i++)
    {
        colx=0;
        for(j=i;j<=i+6;j+=3)
        {
            if(cp[j]=='X')
                break;
            if(cp[j]=='O')
                colx++;
            if(cp[j]!='X'&&cp[j]!='O')
                c=j;
            if((colx==2)&&(j==i+6)&&(c!=11))
                return c;
        }
    }        
    for(i=0;i<=6;i+=3)
    {
        rowx=0;
        for(j=i;j<=i+2;j++)
        { 
            if(cp[j]=='X')
                break;
            if(cp[j]=='O')
                rowx++;
            if(cp[j]!='X'&&cp[j]!='O')
                d=j;
            if((rowx==2)&&(j==i+2)&&(d!=11))
                return d;
        }
    }   
    for(i=0;i<3;i+=2)
    {
        diag1x=0;
        diag2x=0;
        if(i==0)
        {
            for(j=i;j<=i+8;j+=4)
            {
                if(cp[j]=='X')
                    break;
                if(cp[j]=='O')
                    diag1x++;
                if(cp[j]!='X'&&cp[j]!='O')
                    g=j;
                if((diag1x==2)&&(j==i+8)&&(g!=11))
                    return g;
            }
        }
        else
        {
            for(j=i;j<=i+4;j+=2)
            {
                if(cp[j]=='X')
                    break;
                if(cp[j]=='O')
                    diag2x++;
                if(cp[j]!='X'&&cp[j]!='O')
                    e=j;
                if((diag2x==2)&&(j==i+4)&&(e!=11))
                    return e;
            }
        }
    }
    return 11;
}
int detect(int*a)
{
     int i,j;
    for(i=0;i<3;i++)
    {
        for(j=i;j<=i+3;j+=3)
            if(a[j+3]=='O')
                if((a[j]!='X'&&a[j]!='O')&&a[j+3]=='O')
                    return j;
        for(j=i+6;j>=i+3;j-=3)
            if(a[j-3]=='O')
                if((a[j]!='X'&&a[j]!='O')&&a[j-3]=='O')
                    return j;
    }
    for(i=0;i<=6;i+=3)
    {
        for(j=i;j<=i+1;j++)
            if(a[j+1]=='O')
                if((a[j]!='X'&&a[j]!='O')&&a[j+1]=='O')
                    return j;
        for(j=i+2;j>=i+1;j--)
            if(a[j-1]=='O')
                if((a[j]!='X'&&a[j]!='O')&&a[j-1]=='O')
                    return j;
    }
}
int f_value(int *t)
{
    int i,j,n,c=0,index;
    for(i=0;i<9;i++)
    {
        if(t[i]=='X')
        {
            n=i;
            c++;
        }
        if(c>1)
            break;
    }
    if(c==1)
    {
        if(n==8)
            return 0;
        else
            return n+1;
    }
    return 11;
}
int gr(int *ui,char*n,char*n1)
{
    int i,tie=0;
    system("cls");
    demo(n,n1);
    printf("\n\n\n");
    gamepattern(ui);
    printf("\n\n\n");
    if(win_checker(ui)==1)
    {
        return 1;
    }
    for(i=0;i<9;i++)
    if(ui[i]=='O'||ui[i]=='X')
    {
        tie++;
    }
    if(tie==9)
        return 2;
}
void result(int win,int win1,char *name,char *name1)
{
    if(win==1)
        printf("            %s Win.\n\n",name);
    else if(win1==1)
        printf("           %s Win.\n\n",name1);
    else
        printf("            Game Tie.\n\n");
    printf("      Enter any key for menu.");
    getch();
}
void demo(char *name,char *Name)
{
    printf("   -------TIC-TAC-TOE-------\n\n");
    printf("   Player1 (Mark=X) --> %s\n",name);
    printf("   Player2 (Mark=O) --> %s\n",Name);
}