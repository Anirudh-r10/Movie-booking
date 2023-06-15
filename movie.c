#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu();
void addmov();
void dispmov();
void updmov();
void delmov();
void book();
void cancel();


struct movie
{
char mname[20];
int mprice;
int mtime;
};

struct user
{
char cname[10],sname[10];
int price;
int pno;
int nos;
};

void main()
{
menu();
}

void menu()
{
int n;
int ch;
printf("MAJESTIC THEATRE");
printf("\n------------------------------\n");
printf("\nADD ,UPDATE ,DELETE MOVIE(MANAGER)\n");
printf("\nBOOK A TICKET\n");
printf("\nchoose an option(1-2):\n");
scanf("%d",&n);
if(n==1)
{
do
	{
printf("1.ADD A MOVIE\n");
printf("2.DELETE A MOVIE\n");
printf("3.UPDATE A MOVIE\n");
printf("4.DISPLAY THE MOVIES\n");
printf("5.BACK TO MAIN MENU\n");
printf("Enter an option\n:");
scanf("%d",&ch);
switch(ch)
     {
case 1 :
addmov();
break;
case 2:
delmov();
break;
case 3:
updmov();
break;
case 4:
dispmov();
break;
case 5:
printf("\n SEE YOU AGAIN");
break;
default :("WRONG CHOICE!!!");
    }
	}
while(1);
}
else if(n==2)
{
dispmov();
int c;
do
	{
printf("1. BOOK A TICKET\n");
printf("2.CANCEL A TICKET\n");
printf("3.BACK TO MAIN MANU\n");
scanf("%d",&c);
switch(c)
		{
case 1:book();
break;
case 2:cancel();
break;
case 3:printf("go back to main menu\n");
       menu();
break;
default:printf("invalid choice!!\n");
		}
	}while(1);

} 
void addmov()
{
struct movie m;
FILE *f;
f=fopen("movie","ab");
printf("enter movie name:\n");
scanf("%s",m.mname);
printf("enter price:\n");
scanf("%d",&m.mprice);
printf("enter time:\n");
scanf("%d",&m.mtime);
fwrite(&m,sizeof(m),1,f);
fclose(f);
}
void delmov()
{
struct movie m;
FILE *f1,*f2;
char name[20];
f1= fopen("movie","ab");
f2=fopen("temp","wb");
printf("enter the movie name to be deleted:\n");
scanf("%s",name);
while (fread(&m,sizeof(m),1,f1)==1);
{
if(strcmp(m.mname,name)!=0)
	{
		fwrite(&m,sizeof(m),1,f2);
	}
fclose(f1);
fclose(f2);
remove("movie");
rename("temp","movie");
}
}
void updmov()
{
struct movie m,m2;
FILE *f;
char name[20];
f=fopen("movie","r+b");
printf("enter movie name to be updated");
scanf("%s",name);
while(fread(&m,sizeof(m),1,f)==1)
	{
		if(strcmp(m.mname,name)==0)
		{
		fseek(f,(-1)+sizeof(m),SEEK_CUR);
		}
	}	
printf("enter the new movie name,price,time:\n");
scanf("%s%d%d",m2.mname,&m2.mprice,&m2.mtime);
fwrite(&m2,sizeof(m2),1,f);
fclose(f);
}

void dispmov()
{
struct movie m;
FILE *f;
f=fopen("movie","rb");
while(fread(&m,sizeof(m),1,f)==1)
	{
		printf("%s\n %d\n %d\n",m.mname,m.mprice,m.mtime);
	}
fclose(f);

}

void book()
{
struct user u;
struct movie m;
FILE *f1,*f2;
f1=fopen("movie","wb");
f2=fopen("ticket","ab");
printf("enter user name:\n");
scanf("%s",u.cname);
printf("Enter movie name:\n");
scanf("%s",u.sname);
while(fread(&m,sizeof(m),1,f1)==1)
{
if(strcmp(m.mname,u.sname)==0)
	{
	printf("enter phone number :\n");
	scanf("%d",&u.pno);
	printf("enter no ofseats:\n");
	scanf("%d",&u.nos);
	u.price=u.nos*m.mprice;
	}
}

printf("\n\n booking succesfull...!!!");
printf("\n\n\n Booking summary\n\n");
printf("\n Movie name=%s",u.sname);
printf("\n Cinema name=%s",u.cname);
printf("\n Ph no=%d",u.pno);
printf("no of seats=%d",u.nos);
printf("total price=%d",u.price);
fclose(f2);
fclose(f1);
}

void cancel()
{
struct movie m; 
struct user u;
int n;
FILE *f1,*f2;
f1=fopen("ticket","rb");
f2=fopen("temp","wb");
printf("Enter ph no to cancel a ticket");
scanf("%d",&n);
while(fread(&m,sizeof(m),1,f1)==1)
{
	if(u.pno!=n)
	{
		fwrite(&m,sizeof(m),1,f2);
	}
}
fclose(f1);
fclose(f2);
remove("ticket");
rename("temp","ticket");
}
 
if(n==3)
{

menu();

}
}


