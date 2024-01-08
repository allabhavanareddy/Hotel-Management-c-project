#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>


void add();  //FUNCTIONS
void list();
void delete1();
void search();


struct CustomerDetails   //STRUCTURE DECLARATION
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];	
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;

int main(){     // MAIN FUNCTION
	int i=0;
	char customername;
	char choice;
    
	while (choice!=6)     
	{   printf("\n WELCOME TO HOTEL MANAGEMENT\n");
	    printf("\n WELCOME TO HOTEL RATNA\n ");
		printf(" \n Enter 1 : Book a room");
        printf(" \n Enter 2 : View Customer Details");
	    printf(" \n Enter 3 : Delete Customer Details");
        printf(" \n Enter 4 : Search Customer Details");
		printf(" \n Enter 5 : Exit \n");
	    scanf("%d",&choice);

		switch(choice)   //switch statement
		{	
			case 1:
				add();
				break;
			case 2:
				list();
				break;
			case 3:
				delete1();
				break;
			case 4:
				search();
				break;
			case 5:
				printf("\n\n\t THANK YOU ");
				printf("\n\t VISIT AGAIN"); 
				exit(0);
				break;
			default:
				printf("\n Incorrect Choice");
				break;
	}
}
}

	
void add()
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold ");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter Customer Details:");
		printf("\n Enter Room number:\n");
		scanf("\n%s",s.roomnumber);
		fflush(stdin);
		printf("Enter Name:\n");
		scanf("%s",s.name);
		printf("Enter Address:\n");
		scanf("%s",s.address);
		printf("Enter Phone Number:\n");
		scanf("%s",s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s",s.nationality);
		printf("Enter Email:\n");
		scanf(" %s",s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%s",&s.period);
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",&s.arrivaldate);
		fwrite(&s,sizeof(s),1,f);
	//	fflush(stdin);
		printf("\n\n1 Room is successfully booked");
		printf("\n Press esc key to exit,  any other key to add another customer detail:\n\n");
		test=getche();
		if(test==27)// 27 is ASCII value of Escape (ESC)
			break;
			
	}
	fclose(f);
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)
		exit(0);
	system("cls");

	while(fread(&s,sizeof(s),1,f))
	{
	
	printf("\nROOM          :%s",s.roomnumber);
	printf("\nNAME          :%s ",s.name);
	printf("\nADDRESS       :%s ",s.address);
	printf("\nPHONENUMBER   :%s",s.phonenumber);
	printf("\nNATIONALITY   :%s",s.nationality);
	printf("\nEMAIL         :%s",s.email);
	printf("\nPERIOD        :%s ",s.period);
	printf("\nARRIVALDATE   :%s\n",s.arrivaldate);
}

	fclose(f);
	getch();
}


void delete1()
{
	FILE *f,*t;
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)
	exit(0);
	system("cls");//to clear screen
	printf("Enter the Room Number of the hotel to be deleted : \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f))
	{
		if(strcmp(s.roomnumber,roomnumber)==0)
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       
		printf("\n\n Details of Customer in this  Room number is not found\n\n");
		
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");
	printf("\n Details are removed\n\n");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;
	f=fopen("add.txt","r+");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\nRecord Found\n ");
			printf("\nRoom Number     :%s",s.roomnumber);
			printf("\nName            :%s",s.name);
			printf("\nAddress         :%s",s.address);
			printf("\nPhone number    :%s",s.phonenumber);
			printf("\nNationality     :%s",s.nationality);
			printf("\nEmail           :%s",s.email);
			printf("\nPeriod          :%s",s.period);
			printf("\nArrival date    :%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){	
		printf("\nRequested Customer could not be found\n\n");
	}
	getch();
	fclose(f);
}


