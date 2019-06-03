//author AKASH KUMAR SAW
//5TH SEMESTER CHAIBASA ENGINEERING COLLEGE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TRUE 1
char password[8]="library";
struct book
{
    int id;
    char name[20];
    char author[20];
    int copies;
    int copiesleft;
}b,bc;
struct date
{
    int dd,mm,yy;
};
struct user
{
    int id;
    char name[20];
    int bookid;
    struct date issue;
    struct date due;
}u,uc;
FILE *pb,*pu;

void main_menu(void);//y
void admin(void);//y
void user(void);//y
void exitcheck(void);//y
void bookmenu(void);//y
void addbook(void);//y
void editbook(void);//
void deletebook(int);//
void usermenu(void);//y
void adduser(void);//y
void edituser(void);//
void deleteuser(int);//
void listbook(void);//y
void listuser(void);//y
void issuebook(void);
void collectbook(void);
void searchbook(void);
void userinfo(void);
int bidcheck(int);
int uidcheck(int);
int validdatecheck(struct date);
void duedate(void);
int fine(struct date,int);

int main(void)
{
    system("cls");
    printf("\n\n\n\t\t\t Library Management Software \n\n\n\n\n\t\t\t\t\t\t\t\t By \n\t\t\t\t\t\t\t\t AKASH KUMAR SAW \n\t\t\t\t\t\t\t\t CHAIBASA ENGINEERNG COLLEGE");
    printf("\n Press any key to continue");
    getch();
    main_menu();
    return 0;
}
void main_menu(void)
{
	int choice;
	do{
		system("cls");
		printf("\n\n\n \t\t\t Main menu");
		printf("\n\n \t\t 1.Administrato");
		printf("\n\n \t\t 2.User");
		printf("\n\n \t\t 3.Exit");
		printf("\n\n\n \t\t Enter your choice:");
		scanf("%d ",&choice);
		switch(choice)
		{
			case 1:
				admin();
			case 2:
			    user();
			case 3:
				break;	
			default:
				printf("\n\n Invalid choice enter ");
				getch();
		}
	}while(TRUE);
	exitcheck();	

}

void admin()
{
	char str[20];
    char ch;int i=0;
	system("clr");
	printf("\n\n\t\t Please enter the password : ");
	while((ch=getch())!='\r'&&i<20)
    {
        putch('*');
        str[i++]=ch;
    }
    if("strcmp(str, password)==0")
    {
        printf("\n\n\t\t Authentication successful");
        printf("\n\n\t\t Press any key to continue");
        getch();
    }
    else
    {
        printf("\n\n\t\t Incorrect password entered");
        printf("\n\n\t\t Press any key to continue");
        getch();
        return;
    }
   int choice;
   do
    {
    system("cls");
    printf("\n\n\t\t\t\t Administrator Menu");
    printf("\n\n\t\t 1. Add/Edit Book \n\t\t 2. Add/Edit User \n\t\t 3. List Books \n\t\t 4. List Users \n\t\t 5. Issue Book \n\t\t 6. Collect Book \n\t\t 7. Main Menu \n\t\t 8. Exit");
    printf("\n\n\t\t Please Enter the choice : ");
    scanf("%d",&choice);
    switch(choice)
        {
            case 1: bookmenu();break;
            case 2: usermenu();break;
            case 3: listbook();break;
            case 4: listuser();break;
            case 5: issuebook();break;
            case 6: collectbook();break;
            case 7: return;
            case 8: exitcheck();break;
            default: printf("\n\n\t\t Invalid Choice");
                 getch();
        }
    }while(TRUE);
    
} 	
void bookmenu(void)
{
	system("clr");
	do{
	printf("\n\n\n \t\t\t\t BOOK MENU");
	printf("\n\n \t\t 1. Add book \n\t\t 2.Edit book details \n\t\t 3.Delete book \n\t\t 4.Administrator menu \n\t\t 5.Exit ");
	printf("\n enter your choice: ");
	int choice;
	scanf("%d",&choice);
	switch(choice)
        {
            case 1: addbook();break;
            case 2: editbook();break;
            case 3: deletebook();break;
            case 4: return;
            case 5: exitcheck();break;
			default: printf("\n\n\t\t Invalid Choice");
            getch();
	    }
     }while(TRUE);
}
void addbook(void)
{
	fopen("Books.txt","a");
	char ch;
	do{
	label:	
	system("clr");
	printf("\n\n \t\t\t\t Add books");
	printf("\n\n \t\t pleace enter the following details");
	printf("\n \t\t Book ID");
	scanf("%d",&b.id);
	if(bidcheck(b.bi)==0)
	{
		printf("\n \t Book name");
		scanf(" %[^\n]s",b.name);
		printf("\n\t Autor name");
		scanf(" %[^\n]s",b.author);
		printf("\n\t Number of copies :");
        scanf("%d",&b.copies);
        b.copiesleft=b.copies;
		fwrite(&b,sizeof(struct book), 1, pb);
		printf("\n\t Book Successfully added");
        printf("\n\t Do you want to enter details of another book? (Y/N)");
        scanf(" %c",&ch);	
	}
	else
	{
	    printf("\n\t BookId already exists ");
        printf("\n\t Press any key to continue ");
        getch();
        goto label;	
	}	    	
	}while(ch=='Y'||ch=='y')
	fclose(pb);
	return ;
}
int bidcheck(int id)
{
    FILE *b;
    int i=0;
    u=fopen("Users.txt","r");
    while(!feof(u))
    {
        if(fread(&uc,sizeof(struct user),1,u)==1)
            if(uc.id==id)
        {
            i=1;
            break;
        }
    }
    fclose(u);
    return i;
}
// no idea how to make
void editbook(void)
{
	int id, choice;
	char ch;
	system("clr");
	printf("\n\n \t\t\t\t edit book details");
	printf("\n \t Enter the book ID:");
	scanf("%d",&id);
	if(bidcheck(id)==1)
	{
		
	}
	else
    {
        printf("\n\n\t Entered BookId does not exist");
        printf("\n\n\t Press any key to continue");
        getch();
    }
    return;
}
void issuebook(void)
{
	
}
void collectbook(void);
//   USER 
void user(void)
{
	int choice;
    do
    {
        system("cls");
        printf("\n\n\t\t\t\t User Menu");
        printf("\n\n\t\t 1. Search Book \n\t\t 2. UserInfo \n\t\t 3. Main Menu \n\t\t 4. Exit");
        printf("\n\n\t\t Please Enter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: searchbook();break;
            case 2: userinfo();break;
            case 3: main_menu();break;
            case 4: exitcheck();break;
            default: printf("\n\n\t\t Invalid Choice");
                     getch();
        }
    }while(TRUE);	
}
// NO IDEA HOW IT WORKS
void searchbook(void)
{
	int i;
	char ch,name[20];
	pb=fopen("book.txt","r");
    do
    {
        system("cls");
        i=0;
        rewind(pb);
        printf("\n\n\t\t\t\t Book Search ");
        printf("\n\t Enter the name of the book to search : ");
        scanf(" %[^\n]s",name);
        while(!feof(pb))
        {
            if(fread(&b,sizeof(struct book),1,pb)==1)
            if(strcmpi(b.name,name)==0)
            {
                i++;
                printf("\n\t Search Result : %d",i);
                printf("\n\t BookId : %d \n\t Book Name : %s \n\t Author : %s \n\t Number of copies : %d \n\t Number of copies left : %d",b.id,b.name,b.author,b.copies,b.copiesleft);
            }
        }
    if(i==0)
        printf("\n\t No such book found");
    printf("\n Do you want to search for any other book ? (Y/N)");
    scanf(" %c",&ch);
    }while(ch=='Y'||ch=='y');
    fclose(pb);
    return;
}
void listbooks(void)
{
	pb=fopen("Books.txt","r");
    system("cls");
    printf("\n\n\t\t Book Record");
    printf("\n %5s %20s %20s %12s %11s","Id","Book Name","Author Name","No.of Copies","Copies Left");
    while(!feof(pb))
    {
        if(fread(&b,sizeof(struct book),1,pb)==1)
        printf("\n %5d %20s %20s %12d %11d",b.id,b.name,b.author,b.copies,b.copiesleft);
    }
    fclose(pb);
    printf("\n\n\t Press any key to continue");
    getch();
    return;
}
int uidcheck(int id)
{
    int i=0;
    FILE *u;
    u=fopen("Users.txt","r");
    while(!feof(u))
    {
        if(fread(&uc,sizeof(struct user),1,u)==1)
            if(uc.id==id)
        {
            i=1;
            break;
        }
    }
    fclose(u);
    return i;
}
edituser()

void listuser(void)
{
    pu=fopen("Users.txt","r");
    system("cls");
    printf("\n\n\t\t User Record");
    printf("\n %5s %20s %6s %11s %11s","Id","Name","BookId","Issue Date ","Due Date   ");
    while(!feof(pu))
    {
        if(fread(&u,sizeof(struct user),1,pu)==1)
        printf("\n %5d %20s %6d %2d-%2d-%4d %2d-%2d-%4d",u.id,u.name,u.bookid,u.issue.dd,u.issue.mm,u.issue.yy,u.due.dd,u.due.mm,u.due.yy);
    }
    fclose(pu);
    printf("\n\n\t Press any key to continue");
    getch();
    return;
}
void exitcheck(void)
{
    system("cls");
    printf("\n\n\t\t Do you really want to exit ?(Y/N) : ");
    char ch;
    scanf(" %c",&ch);
    if(ch=='Y'||ch=='y')
        exit(1);
    return;
}
