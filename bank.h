// bank.h -- structure templates and function prototypes
// structure templates
#ifndef BANK_H_
#define BANK_H_
struct reg{
	char name[50],pswd[50];
	char add[100],mail[50],desg[50];
	long long phno,bal,amt,l_amt;
	char code[10],tcode[7],date[100];
	char l_status[10];
}regst;

void admin(FILE *fp1,const char *code);			// function for admin (admin)
void user(FILE *fp1,const char *code);			// function for user (user)
void reg(FILE *fp1,const char *code);                   // registration for new user
void login(FILE *fp1,const char *code);			// login for existing user
void insert(FILE *fp,const char *code);			// function for inserting new record (admin)
void check(FILE *fp);					// function for checking the reord of a user (user + admin)
void del(FILE *fp);					// function for deleting the record (user + admin)
int search(FILE *fp1,const char *name);			// serching name (user)
int serpswd(FILE *fp1,const char *name,const char *pswd);  	// searching password (user)
void list(FILE *fp);                              	// lists all the user details (admin)
void modify(FILE *fp);					// function for modifying a user record (user + admin)
void withdraw(FILE *fp);				// function for withdrawing money (user)
void credit(FILE *fp);					// function for crediting money (user)
void trans(FILE *fp);					// function to display last transaction of the account
void loan(FILE *fp);					// function for providing loan 
void about(void);					// function to provide info about program

char c; 

#endif
