/*  PROGRAM RUNNED & COMPILED ON DEV-C++ 5.11 COMPILER   */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"bank.h"				//function prototypes, Structure declarations declared on this header file.

void main()
{
	int ch,choice,i,j;
	char code[10];
	FILE *fp,*fp1;
	fp=fopen("account.dat","rb+");
	fp1=fopen("register.dat","rb+");
	if(fp==NULL)
	{ fp=fopen("account.dat","wb+");
	   if(fp==NULL)
    {   printf("\nError opening file !!!");
		   exit(0);
	}
    }
    if(fp1==NULL)
	{ fp1=fopen("register.dat","wb+");
	   if(fp1==NULL)
    {   printf("\nError opening file !!!");
		   exit(0);
	}
	}
system("cls");
FMENU:																						//Goto label for FMENU
printf("\n\n*************************************************************************************");
printf("\n\n\t\t\t\t   BANK APPLICATION\t\t\t");
printf("\n\n*************************************************************************************\n");
printf("\n\n\t{1} Admin Area");
printf("\t\t{2} User Area");
printf("\t\t{3} Exit Menu");
printf("\n\n\nPlease enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
	case 1: 
	admin(fp1,"admin");
	strcpy(code,"admin");
	break;
	case 2: 
	user(fp,"user");
	strcpy(code,"user");
	break;
	case 3:
		goto EXIT;
		break;
	default:
		system("cls");
		printf("\nPlease enter a valid option.");
		goto FMENU;
}
do{
    if(strcmp(code,"admin")==0){
 do{
    system("cls");                                              // For clear screen, or you can use clrscr();
	printf("\n\n*************************************************************************************");
	printf("\n\n\t\t\t\t   BANK APPLICATION\t\t\t");
	printf("\n\n*************************************************************************************\n"); 
		beg:																				//Goto label for beg
	    printf("\n\n\n\n\t\t\t\t[1] - INSERT A NEW RECORD.");
		printf("\n\t\t\t\t[2] - CHECK ACCOUNT.");
		printf("\n\t\t\t\t[3] - DELETE RECORD.");
		printf("\n\t\t\t\t[4] - LIST ALL RECORDS.");
		printf("\n\t\t\t\t[5] - MODIFY RECORD.");	
		printf("\n\t\t\t\t[6] - LOAN OPERATIONS.");
		printf("\n\t\t\t\t[7] - ABOUT PROGRAM.");
		printf("\n\t\t\t\t[8] - EXIT MENU PROGRAM."); 
		printf("\n\t\t\t\t[0] - GO TO MAIN MENU.\n\n");
		printf("\n\n\tEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert(fp,"user");
				break;
			case 2:
				check(fp);
				break;
			case 3:
				del(fp);
				break;
			case 4:
				list(fp);
				break;
			case 5:
				modify(fp);
				break;
			case 6:
				loan(fp);
				break;
			case 7:
				about();
				break;
			case 8:
			{ fclose(fp);
			  fclose(fp1); goto EXIT;
			    break;    }
			case 0:
				main();
			default:
				system("cls");
				printf("\nEnter a valid option between (1 or 9): \n\n");
				goto beg; 
        }
    }while(ch>=1 && ch<=7);
	}
	else {
	do
	{
	system("cls");                                              // For clear screen, or you can use clrscr();
	printf("\n\n*************************************************************************************");
	printf("\n\n\t\t\t\t   BANK APPLICATION\t\t\t");
	printf("\n\n*************************************************************************************\n");
	beg1:																		  // Goto label for beg1
    	printf("\n\n\n\n\t\t\t\t[1] - CHECK ACCOUNT.");
		printf("\n\t\t\t\t[2] - DELETE RECORD.");
		printf("\n\t\t\t\t[3] - MODIFY RECORD.");
		printf("\n\t\t\t\t[4] - WITHDRAW MONEY.");
		printf("\n\t\t\t\t[5] - CREDIT MONEY.");
		printf("\n\t\t\t\t[6] - VIEW LAST TRANSACTION.");
		printf("\n\t\t\t\t[7] - LOAN OPERATIONS.");
		printf("\n\t\t\t\t[8] - ABOUT PROGRAM.");
		printf("\n\t\t\t\t[9] - EXIT MENU PROGRAM.");
		printf("\n\t\t\t\t[0] - GO TO MAIN MENU.\n\n");
		printf("\n\n\tEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				check(fp);
				break;
			case 2:
				del(fp);
				break;
			case 3:
				modify(fp);
				break;
			case 4:
				withdraw(fp);
				break;
			case 5:
				credit(fp);
				break;
			case 6:
				trans(fp);
				break;
			case 7:
				loan(fp);
				break;
			case 8:
			    about();
			    break;
			case 9:
			{ fclose(fp);
			  fclose(fp1); goto EXIT;
			    break;    }
			case 0:
				main();
			default:
				system("cls");
				printf("\nEnter a valid option between (1 or 9): \n\n");
				goto beg1; 
        }
    }while(ch>=1 && ch<=8);
	}
	}while(-1);
EXIT:
system("cls");
printf("\n\n*************************************************************************************\n");
printf("\n\t\t END OF PROGRAM, THANKS FOR USING OUR BANK APPLICATION ... \n");
printf("\n\n*************************************************************************************\n");
}
void admin(FILE *fp1,const char *code)
{
 int choice;
 system("cls");
 printf("\n\n#####################################################################################\n");
 printf("\n\n\t\t\t\t WELCOME TO ADMIN ZONE\n");
 printf("\n\n#####################################################################################\n");
 beg:
 printf("\n\n\t\t\t\t[1] - LOGIN");
 printf("\n\t\t\t\t[2] - SIGNUP");
 printf("\n\t\t\t\t[3] - EXIT MENU");
 printf("\n\t\t\t\tEnter your choice : ");
 scanf("%d",&choice);
 switch(choice)
 {
 	case 1: 
 	login(fp1,"admin");
 	break;
 	case 2:
 	rewind(fp1);
	while(fread(&regst,sizeof(regst),1,fp1)==1){
		if(strcmp(code,regst.code)==0){
		system("cls");
		printf("\n\n\t\tYou can\'t signup as admin because there is already an admin.");
		goto beg;
		}
	}
	reg(fp1,"admin");
 	break;
 	case 3:
 	 exit(0);
 	break;
 	default:
 	system("cls");
 	printf("\nEnter a valid option.");
 	goto beg;
 }
 system("cls");
}
void user(FILE *fp1,const char *code)
{
 int choice;
 system("cls");
 printf("\n\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
 printf("\n\n\t\t\t\t WELCOME TO USER ZONE\n");
 printf("\n\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
 beg:
 printf("\n\n\t\t\t\t[1] - LOGIN");
 printf("\n\t\t\t\t[2] - SIGNUP");
 printf("\n\t\t\t\t[3] - EXIT MENU");
 printf("\n\t\t\t\tEnter your choice : ");
 scanf("%d",&choice);
 switch(choice)
 {
 	case 1: 
 	 login(fp1,"user");
 	break;
 	case 2:
 	 reg(fp1,"user");
 	break;
 	case 3:
 	 exit(0);
 	break;
 	default:
 	 system("cls");
 	 printf("\nEnter a valid option.");
 	 goto beg;
 }
 system("cls");
}
void reg(FILE *fp1,const char *code)
{
    int z=0; char name[50],save_opt;
    fseek(fp1,0,2);
    system("cls");
    printf("\n\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("\n\n\t\t\t\t WELCOME TO REGISTERISATION ZONE\n");
    printf("\n\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\n\n\tEnter your username : ");
    scanf("%s",name); 
    if(search(fp1,name)==0){
		printf("\n\n\tUsername already exists, please use some other name.");
		getch();
		reg(fp1,code);
	}
    else{
	strcpy(regst.name,name); 	}
	printf("\n\tEnter person address : ");
	scanf("%s",regst.add);
	printf("\n\tEnter person email : ");
	scanf("%s",regst.mail);
	printf("\n\tEnter person phone number : ");
	scanf("%lld",&regst.phno);
	printf("\n\tEnter person designation : ");
	scanf("%s",regst.desg);
	printf("\n\tEnter person password : ");
    while((c=getch())!=13)
        {
           regst.pswd[z++]=c;
           printf("%c",'*');
        } regst.pswd[z]='\0';
    printf("\n\tYour current balance is  0 Rs.");
    regst.bal=0;	
    regst.amt=0;
    strcpy(regst.code,code);
    strcpy(regst.tcode,"\0");
    strcpy(regst.date,"\0");
    strcpy(regst.l_status,"UNACTIVE");
    regst.l_amt=0;
    printf("\n\tDo you want to save data to the file, Press Y to save Or anykey to cancel...");
    save_opt= getch();
    if(save_opt =='Y' || save_opt=='y')
	{
	fwrite(&regst,sizeof(regst),1,fp1);
	printf("\n\n\t\tYou are successfully registered");
    printf("\n\n\t\tPress enter to try login your account.\n\n\t\t");
	login(fp1,code);
	}
	else{
	printf("\n\nRedirecting you to registration zone >>> ");
	reg(fp1,code);
	}
	printf("\n\t\t\tPress anykey to continue...");
	getch();
	system("cls");
}
void login(FILE *fp1,const char *code)
{
    char name[50],pass[50],opt; 
    int z=0,flag=1;
    system("cls");
	printf("\n\n_____________________________________________________________________________________\n");
    printf("\n\n\t\t\t\t WELCOME TO LOGIN ZONE\n");
    printf("\n\n_____________________________________________________________________________________\n");
    printf("\n\t\t\t\t\t\t\t You\'re logging as %s.",code);
    printf("\n\n\t\t\tEnter your username : ");
    scanf("%s",name);
    if(search(fp1,name)==0){
    rewind(fp1);
	while(fread(&regst,sizeof(regst),1,fp1)==1){
		if(strcmp(code,regst.code)==0){
			flag=0;
			break;
		}  
	}
	if(flag==1){
	printf("\n\t\tName not found in the file...");
	goto VC;
	}
	printf("\n\n\t\t\tEnter your password : ");
    while((c=getch())!=13)
    {
        pass[z++]=c;
        printf("%c",'*');
    } pass[z]='\0';
	}
	if(serpswd(fp1,name,pass)==0){  
    printf("\n\n\t\t\tYou\'ve successfully logged in...");
    }
	else if(search(fp1,name)==1 || serpswd(fp1,name,pass)==1){
		VC:	
		printf("\n\n\t\t Unsuccessful login attempt.");
		printf("\n\n\t\t Press R to register Or anykey to retry login again.");
		opt=getch();
		if(opt=='r' || opt=='R'){
			reg(fp1,code);
		}
		else{
		login(fp1,code);
		}
	}
   	printf("\n\t\t\tPress anykey to continue ...");
	getch();
    system("cls");
}
void insert(FILE *fp,const char *code)
{
	int z=0;
	char save_opt,name[50];
	fseek(fp,0,2);
	system("cls");
	printf("\n\n\n\n\tEnter person name : ");
	scanf("%s",name);
	if(search(fp,name)==0){
		printf("\n\n\t\tUsername already exists, please select other name.");
		getch();
		insert(fp,code);
	}
	strcpy(regst.name,name);
	printf("\n\tEnter person address : ");
	scanf("%s",regst.add);
	printf("\n\tEnter person email : ");
	scanf("%s",regst.mail);
	printf("\n\tEnter person phone number : ");
	scanf("%lld",&regst.phno);
	printf("\n\tEnter person designation : ");
	scanf("%s",regst.desg);
	printf("\n\tEnter person password : ");
    while((c=getch())!=13)
        {
           regst.pswd[z++]=c;
           printf("%c",'*');
        } regst.pswd[z]='\0';
    printf("\n\tYour current balance is  0 Rs.");
    regst.bal=0;	
    regst.amt=0;
    strcpy(regst.tcode,"\0");
    strcpy(regst.code,code);
    strcpy(regst.date,"\0");
    strcpy(regst.l_status,"UNACTIVE");
    regst.l_amt=0;
	printf("\n\n\tDo you want to save data to the file, Press Y to confirm or anykey to cancel...");
    save_opt=getch();
    if(save_opt=='Y' || save_opt=='y'){
	fwrite(&regst,sizeof(regst),1,fp);
	printf("\n\n\tData saved to the file...");
	}
	else 
	printf("\n\n\tData not saved to the file!!!");
	printf("\n\n\tPress anykey to continue...");
	getch();
	system("cls");
}
void check(FILE *fp)
{
char name[50],psswd[50];
int z=0; char c;
system("cls");
printf("\n\n\n\tEnter your name : ");
scanf("%s",name);
if(search(fp,name)==0)
{
 printf("\n\tEnter your password : ");
 while((c=getch())!=13)
    {
           psswd[z++]=c;
           printf("%c",'*');
    } psswd[z]='\0';
if(serpswd(fp,name,psswd)==0)
{
printf("\n\n\tPerson name : %s.",regst.name);
printf("\n\tPerson address : %s.",regst.add);
printf("\n\tPerson mail : %s.",regst.mail);
printf("\n\tPerson phone number : %lld.",regst.phno);
printf("\n\tPerson designation : %s.",regst.desg);
printf("\n\tPerson balance : %lld Rs.",regst.bal+regst.l_amt);
printf("\n\tLoan status : %s",regst.l_status);
if(strcmp(regst.l_status,"ACTIVE")==0)
printf("\n\tLoan Amount : %lld",regst.l_amt);
}
else
{
	printf("\n\n\tIncorrect password for user....");
}
}
else 
printf("\n\t\tName not found in the file...");
printf("\n\n\tPress anykey to continue...");
getch();
system("cls");
}
void del(FILE *fp)
{
FILE *fptmp;
int z=0;
char name[50],psswd[50];
system("cls");
printf("\n\n\n\tEnter the name of the person whose record is to be deleted from database : ");
scanf("%s",name);
if(search(fp,name)==0){
printf("\n\tEnter password of the person : ");
while((c=getch())!=13)
{
        psswd[z++]=c;
        printf("%c",'*');
} psswd[z]='\0';
if(serpswd(fp,name,psswd)==0){
fptmp=fopen("tempregst.dat","wb");
rewind(fp);
while(fread(&regst,sizeof(regst),1,fp)==1)
 {
	if(strcmp(name,regst.name)!=0)
	fwrite(&regst,sizeof(regst),1,fptmp);
 } 
	fclose(fp);
	fclose(fptmp);
	remove("account.dat");
	rename("tempregst.dat","account.dat");
	printf("\nRecord deleted...\n\n");
	fp=fopen("account.dat","rb+");	
}
else
printf("\n\n\tIncorrect Password for the user...");
}
else 
printf("\n\n\tName not found in the file....");
printf("\n\n\tPress anykey to continue...");
getch();
system("cls");
}
int search(FILE *fp1,const char *name)
{
	unsigned flag=1;
	rewind(fp1);
	while(fread(&regst,sizeof(regst),1,fp1)==1)
	{  if(strcmp(name,regst.name)==0)
		{
			flag=0;
		    break;
		}
	}
	return flag;
}
int serpswd(FILE *fp,const char *name,const char *pswd)
{
	unsigned flag=1;
	rewind(fp);
	while(fread(&regst,sizeof(regst),1,fp)==1)
	{  if(strcmp(pswd,regst.pswd)==0 && strcmp(name,regst.name)==0)
		{
			flag=0;
		    break;
		}
	}
	return flag;
}
void list(FILE *fp)
{
	rewind(fp);
	system("cls");
	printf("\n********************************ACCOUNT HOLDER DETAILS*******************************");
	while(fread(&regst,sizeof(regst),1,fp)==1)
	{  
		printf("\n\n______________________________________________________________________________________\n"); 
  		printf("\nAccount Holder Name : %s\t",regst.name);
		printf("Balance : Rs %lld",regst.bal);
		printf("\nEmail : %s",regst.mail);
		printf("\tContact Number : %lld",regst.phno);
		printf("\tLoan Status : %s\n",regst.l_status);
		printf("\n\n______________________________________________________________________________________");
	}
	printf("\n\n\tPress anykey to continue...");
	getch();
	system("cls");	
}
void modify(FILE *fp)
{
	char name[50],psswd[50],cg;
	int z=0;
	long size=sizeof(regst);
	system("cls");
	printf("\n\n\n\tEnter the name of the person whose record is to be modified : ");
	scanf("%s",name);
	if(search(fp,name)==0)
	{
		printf("\n\tEnter your password : ");
        while((c=getch())!=13)
        {
           psswd[z++]=c;
           printf("%c",'*');
        } psswd[z]='\0';
        if(serpswd(fp,name,psswd)==0)
    {
		printf("\n\n\n\t\tEnter new data -->>>\n");
		printf("\t\tEnter - to not change the values ... \n\n");      //When values are not to be modified, User can enter '-' to make no changes in the given field.
	    	printf("\nEnter person name : "); 
	    	if((cg=getch())!=45){
				scanf("%s",regst.name);
		    } 
			printf("\nEnter person address : "); 
			if((cg=getch())!=45)
			{  scanf("%s",regst.add);
		    }
			printf("\nEnter person email : "); 
			if((cg=getch())!=45)
		    { scanf("%s",regst.mail);
			}
			printf("\nEnter person phone number : ");
			if((cg=getch())!=45)
			{   scanf("%lld",&regst.phno);
			}
			printf("\nEnter person designation : ");
			if((cg=getch())!=45)
			{
				scanf("%s",regst.desg);
			}
			printf("\nEnter person current balance : ");   
			if((cg=getch())!=45)
			{   scanf("%lld",&regst.bal);
			}
			printf("\nEnter your new password : ");
			if((cg=getch())!=45)
			{  
			scanf("%s",regst.pswd);
	        }
            fseek(fp,-size,1);
		    fwrite(&regst,sizeof(regst),1,fp);
		    printf("\n\n\t\tRecord modified sucessfully ...\n\n");
	}
	else 
	printf("\n\n\tIncorrect password for the user...");
}
else
printf("\n\n\tName not found in the file...");
printf("\n\n\tPress anykey to continue...");
getch();
system("cls");
}
void withdraw(FILE *fp)
{
	int z=0;
	long size=sizeof(regst);
	char name[50],psswd[50];
	system("cls");
	printf("\n\n\n\tEnter your name : ");
	scanf("%s",name);
	if(search(fp,name)==0)
	{ 
	  printf("\n\tEnter your password : ");
      while((c=getch())!=13)
        {
           psswd[z++]=c;
           printf("%c",'*');
        }psswd[z]='\0';
    if(serpswd(fp,name,psswd)==0)
    {   
		printf("\n\n\n\tEnter the amount you want to withdraw : ");
		scanf("%lld",&regst.amt);
		if(regst.amt > regst.bal)
		{
		  printf("\n\n\tInsufficent Balance to Withdraw!!!");
		}
		else
		{   time_t t;
			time(&t);
			strcpy(regst.date,ctime(&t));
			strcpy(regst.tcode,"DEBIT");
			regst.bal-=regst.amt;
			fseek(fp,-size,1);
			fwrite(&regst,sizeof(regst),1,fp);
		    printf("\n\n\tAmount successfully withdrawn....\n\n");
		}
	}
	else 
	printf("\n\n\tIncorrect password for the user...");
    }
else
printf("\n\n\tName not found in the file...");
printf("\n\n\tPress anykey to continue...");
getch();
system("cls");
}
void credit(FILE *fp)
{
	long long amt; int z=0;
	long size=sizeof(regst);
	system("cls");
	char name[50],psswd[50];
	printf("\n\n\n\tEnter your name : ");
	scanf("%s",name);
	if(search(fp,name)==0)
	{ 
	  printf("\n\tEnter your password : ");
      while((c=getch())!=13)
        {
           psswd[z++]=c;
           printf("%c",'*');
        } psswd[z]='\0';
    if(serpswd(fp,name,psswd)==0)
    {
		printf("\n\n\n\tEnter the amount you want to save to : ");
		scanf("%lld",&regst.amt);
		time_t t;
		time(&t);
		strcpy(regst.date,ctime(&t));
		strcpy(regst.tcode,"CREDIT");
		regst.bal+=regst.amt;
		fseek(fp,-size,1);
		fwrite(&regst,sizeof(regst),1,fp);
	    printf("\n\n\tAmount successfully credited....\n\n");
	}
	else
	printf("\n\n\tIncorrect password for the user...");
}
else
printf("\n\n\tName not found in the file...");
printf("\n\n\tPress anykey to continue...");
getch();
system("cls");
}
void trans(FILE *fp)
{ 
    system("cls");
	int i=1,z=0; char name[50],psswd[50];
	rewind(fp);
	printf("\n\n\n\n\t\tEnter your name : ");
	scanf("%s",name);
	if(search(fp,name)==0)
	{
		printf("\n\t\tEnter your password : ");
		while((c=getch())!=13)
        {
           psswd[z++]=c;
           printf("%c",'*');
        }  psswd[z]='\0';
        if(serpswd(fp,name,psswd)==0)
        { 
		rewind(fp);
        while(fread(&regst,sizeof(regst),1,fp)==1)
        	{  
        	if(strcmp(regst.name,name)==0) 
			{
        	  printf("\n\n\tName : %s",regst.name);
        	  printf("\tDate : %s ",regst.date);
        	  printf("\t%s",regst.tcode); 
        	  printf("\t%lld",regst.amt);
        	  printf("\tCurrent Balance : %lld\n",regst.bal+regst.l_amt);
			}
		}
		} 
		else
		printf("\n\n\tIncorrect password for the user...");
    }
    else
    printf("\n\n\tName not found in the file...");
	printf("\n\n\tPress anykey to continue...");
	getch();
	system("cls");
}
void loan(FILE *fp)
{
	char z,name[50],psswd[50];
	long long amt;
	long size=sizeof(regst);
	int op;
	system("cls");
	printf("\n\n\tEnter the name : ");
	scanf("%s",name);
	if(search(fp,name)==0)
	{
		printf("\n\tEnter the password : ");
		while((c=getch())!=13)
        {
           psswd[z++]=c;
           printf("%c",'*');
        }  psswd[z]='\0';
        if(serpswd(fp,name,psswd)==0)
        {
    	 system("cls");
         printf("\n\n\t\t[1] Apply for Loan.");
         printf("\n\t\t[2] Clear Previous Loan.");
         printf("\n\n\t\tEnter your choice : ");
         scanf("%d",&op);
         switch(op)
         {
         	case 1:
		 	{
		 	if(strcmp(regst.l_status,"ACTIVE")==0)
            {
        	printf("\n\n\t\tPlease clear your previous loan first.\n\n");
		    }
		    else
		 	{ 
		 	printf("\n\n\t\tEnter the amount of loan you wish to take : ");
		 	scanf("%lld",&amt);
		 	strcpy(regst.l_status,"ACTIVE");
		 	regst.l_amt = amt;		
		 	fseek(fp,-size,1);
			fwrite(&regst,sizeof(regst),1,fp);
		 	}	
			}
			break;
			case 2:
			{
		 	if(strcmp(regst.l_status,"ACTIVE")==0)
         	{
        	printf("\n\t\tYour loan amount was %lld.",regst.l_amt);
        	if(regst.bal<regst.l_amt)
        	{
        		printf("\n\t\tYou don\'t have sufficient balance to clear your due.\n");
			}
			else
			{
				regst.bal = regst.bal-regst.l_amt;
				printf("\n\t\tThe loan amount has been recovered from your account.\n");
				strcpy(regst.l_status,"UNACTIVE");
				regst.l_amt=0;
				fseek(fp,-size,1);
				fwrite(&regst,sizeof(regst),1,fp);
			}
		 	}
			else
			{
			printf("\n\n\t\tUser has no pending loan.");	
			}	
			}
			break;
			default:
				printf("\n\n\t\tInvalid choice...");
			}	
		 	}
		}
	printf("\n\n\t\tPress anykey to continue...");
	getch();
	system("cls");
}
void about(void)
{
	system("cls");
	printf("\n\n*************************************************************************************\n");
	printf("\n\t\tPROGRAM TO DISPLAY HOW A TYPICAL BANK PROGRAM WORKS. ");
	printf("\n\t\tPROGRAM DESIGNED & DEVELOPED BY AMIT SINGH...");
	printf("\n\t\tSTUDENT OF SGRRITS, PATEL NAGAR, DEHRADUN, U.K, INDIA .");
	printf("\n\t\tBCA Ist SEMESTER, AND A BEGINNER TO C/C++ LANGUAGE.");
	printf("\n\t\tFOR ANY HELP VISIT AMIT\'S BLOG : http://www.asmitblog.blogspot.com/  ");
	printf("\n\t\tOR KINDLY MAIL HIM AT : asamitdbz@gmail.com  ");
	printf("\n\n*************************************************************************************\n");
	printf("\n\n\tPress anykey to continue...");
	getch();
	system("cls");
}
