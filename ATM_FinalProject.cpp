#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#define N 10000
#define currentYear 2022
#define currentMonth 1
#define currentDay 1

union chef
{
	char username[6];
	int password;
};

struct Attendant
{
	char password[9];
	char username[11];
};
struct Birth_Date
{
	char year[5];
	char month[3];
	char day[3];
};

struct User
{
	char accountNum[13];
	char password[9];
	char username[11];
	char recentChanges[20][200];
	long long int accBalance;
	struct Birth_Date date;
};

bool mainMenu();
void chefLogIn();
void attendantLogIn();
void userSignUp();
void userLogIn();
void feedback();
void help();
void confirmExit();
bool checkChefUsername(char[]);
bool checkChefPassword(int);
void chefMenu();
void openAttAccount();
void changeAttUsername();
void changeAttPassword();
void deleteAttAccount();
void setAttUsername(int);
void setAttPassword(int);
void showAllAttendants();
void displayAllAttendants();
int searchAttUsername(char[]);
bool checkAttUsername(char[]);
int searchAttPassword(char[]);
bool checkAttPassword(int,char[]);
bool checkAttPassword(char[]);
void showForgottenPassword();
void openUserAccount(int);
bool checkDate(struct User);
int checkAge(struct User);
void setUserUsername(int);
void suggestedUsernames();
void swap(char *, char *);
void permute(char *, int, int);
void setUserPassword(int);
bool isPassword(char[]);
void omitAllSpaces(char[]);
void setAccountNumber(int);
int whichBank();
bool isAccountNumber(char[]);
bool checkUserUsername(char[]);
int searchUserUsername(char[]);
int searchUserPassword(char[]);
bool checkUserPassword(char[]);
bool checkUserPassword(int, char[]);
bool checkAccountNumber(char[]);
bool checkAccountNumber(char[], int);
int searchAccountNumber(char[]);
void attendantMenu();
void editUser();
void changeUserUsername();
void changeUserPassword();
void deleteUserAccount();
void increaseBalance();
void setRecentChanges(int, char []);
void printRecentUpdates(int);
void showAllUsers();
void showUserInfo();
void arrangeUsers();
void displayAllUsers();
void displaySelectedUser(int);
void userSignUp();
void userLogIn();
void userMenu(int);
void changeUserUsername(int);
void changeUserPassword(int);
void accountBalance(int);
void cashTransfer(int);
void concatenate(char[],char[],int);
void appendStrings(char[], char[], int);
void cashWithdrawal(int);
bool isEnough(int,int);
void printReceipt(int,int);
void saveUsersInformation(int);
void saveUsersInfo(int);
void saveAttendantsInfo(int);
void saveEditedAttendantsInfo(int, int);
void saveEditedUsersInfo(int, int);

int i, j;
int usersCount, attendantsCount;
int userIndex, attIndex, lastAvailUserIndex, lastAvailAttIndex, lastChangeIndex;
struct Attendant attendants[N];
struct User users[N];

main()
{
	mainMenu();
}

bool mainMenu()
{
	system("cls");
	system("Color 7C");
	char choice;
	do
	{
		printf("\n\n\t\t\t/|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Main Menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|\\\n");
		printf("\n\t\t\t|1.Log in as the chef\t\t\t |\n");
		printf("\n\t\t\t|2.Log in as an attendant\t\t |\n");
        printf("\n\t\t\t|3.Sign Up as an user\t\t\t |\n");
        printf("\n\t\t\t|4.Log in as an user\t\t\t |\n");
        printf("\n\t\t\t|5.Send us a feedback\t\t\t |\n");
        printf("\n\t\t\t|6.Help\t\t\t\t\t |\n");
        printf("\n\t\t\t|7.Exit\t\t\t\t\t |\n");
		choice = getche();
		switch(choice)
		{
			case '1': {
				chefLogIn();
				break;
			}
			case '2': {
				attendantLogIn();
				break;
			}
			case '3': {
				userSignUp();
				break;
			}
			case '4': {
				userLogIn();
				break;
			}
			case '5': {
				feedback();
				break;
			}
			case '6': {
				help();
				break;
			}
			case '7': 
				confirmExit();
			
			default:printf("%c\n\t\t\tOops!\n\t\t\tyou have entered %c while the options are from 1 to 7.\n",7,choice);	
		}	
		
	}while(choice >= '1' && choice < '7');
}

void chefLogIn()
{
	system("cls");
	chef chf;
	printf("\n\t\tPlease enter your Username: ");
	scanf(" %s",chf.username);
	if (checkChefUsername(chf.username))
	{
		printf("\n\t\tEnter your password:");
		scanf("%d",&chf.password);
		if(checkChefPassword(chf.password))
			chefMenu();
		else
			printf("\n\t\tSomething went wrong!");
	}
	else
		printf("\n\t\tSomething went wrong!");
}

bool checkChefUsername(char chefUsername[])
{
	if (strcmp(chefUsername,"admin") == 0)
		return true;
	return false;
}

bool checkChefPassword(int chefPass)
{
	if (chefPass == 1234)
		return true;
	return false;
}

void chefMenu()
{
	system("cls");
	system("Color 7D");
	printf("\n\t\t1.Add attendant.\n");
	printf("\n\t\t2.Delete attendant.\n");
	printf("\n\t\t3.Change attendant's username.\n");
	printf("\n\t\t4.Change attendant's password.\n");
	printf("\n\t\t5.Show All Attendants\n");
	printf("\n\t\t6.Exit\n");
	char choice;
	choice = getche();
	switch(choice)
	{
		case '1':{
			openAttAccount();
			break;
		}
		case '2':{
			deleteAttAccount();
			break;
		}
		case'3':{
			changeAttUsername();
			break;
		}
		case '4':{
			changeAttPassword();
			break;
		}
		case '5':{
			showAllAttendants();
			break;
		}
		case '6':
			exit(1);
	}
}

void openAttAccount()
{
	FILE *info;
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","r");
	fscanf(info,"%d\n",&attendantsCount);
	int index;
	for (i = 0 ; i < attendantsCount ; i++)
	{
		fscanf(info,"%d. Username: %s Password: %s",&index,attendants[i].username,attendants[i].password);
	}
	lastAvailAttIndex = attendantsCount;
	fclose(info);
	setAttUsername(lastAvailAttIndex);
	setAttPassword(lastAvailAttIndex);
	attendantsCount++;
	saveAttendantsInfo(attendantsCount);
	printf("\n\t\tInformation has saved.");
}

void setAttUsername(int lastAvailAttIndex)
{
	Attendant att;
	printf("\n\t\tEnter an username: ");
	getchar();
	gets(att.username);
	if (strlen(att.username) < 4 || strlen(att.username) > 10)
	{
		printf("\n\t\tUsername can not be less than 4 or more than 10 characters.\n");
		Sleep(2000);
		setAttUsername(lastAvailAttIndex);
	}
    else if (strlen(att.username) >= 4 && strlen(att.username) <= 10)
	{
		if(!checkAttUsername(att.username))
		{
			strcpy(attendants[lastAvailAttIndex].username,att.username);
			printf("\n\t\tDone!\n");
		}
		else
		{
			printf("\n\t\tSorry! this username has been taken before, try again.\n");	
			Sleep(2000);	
			setAttUsername(lastAvailAttIndex);
		}
	}
}

bool checkAttUsername(char attUsername[])
{
	FILE *infor;
	int index, i = 0;
	char str[500];
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","r");
	fscanf(infor,"%d\n",&attendantsCount);
	while(feof(infor) == 0)
	{
		fscanf(infor,"%d. Username: %s Password: %s",&index,attendants[i].username,attendants[i].password);
		if (strcmp(attUsername,attendants[i].username) == 0)
		{
			return true;
		}
		i++;
		fgets(str,499,infor);
	}
	fclose(infor);
	return false;		
}

void setAttPassword(int lastAvailAttIndex)
{
	char pass[9], passConfirm[9];
	int digitCount = 0, upperCount = 0, lowerCount = 0;
	do 
	{
		printf("\n\t\tEnter your password\n\t\t(your password should contain at least 8 characters include 1 digit 1 upper and 1 lower letter):\n\t\t");
		for (i = 0; i < 8; i++) 
		{
			pass[i] = getch();
			printf("*");
		}
		pass[i] = '\0';
		getchar();
		int count = 0;
		for (i = 0; i < 8; i++)
		{
			if (isdigit(pass[i]))
				digitCount++;
			else if (isalpha(pass[i]))
			{
				if (isupper(pass[i]))
					upperCount++;
				else if(islower(pass[i]))
					 lowerCount++;
			}	
		}
		if (digitCount>=1 && upperCount >= 1 && lowerCount >= 1 && isPassword(pass))
		{
			printf("\n\t\tConfirm your password: ");
			for (i = 0; i < 8; i++) 
			{
				passConfirm[i] = getch();
				printf("*");
			}
			passConfirm[i] = '\0';
			getchar();
		}
		else
		{
			printf("\n\t\tWeek password! please pick a strong one.");
		}	
		
	} while(strcmp(pass,passConfirm) != 0);
	
    if (!checkAttPassword(passConfirm))
	{
		strcpy(attendants[lastAvailAttIndex].password,passConfirm);
	}
	else if (checkAttPassword(passConfirm))
	{		
		printf("\n\t\tSorry! this password has been taken before, try another one.\n");
		Sleep(2000);
		setAttPassword(lastAvailAttIndex);		
	}
}

bool checkAttPassword(char attPass[])
{
	FILE *infor;
	int index, i = 0;
	char str[500];
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","r");
	fscanf(infor,"%d\n",&attendantsCount);
	while(feof(infor) == 0)
	{	
		fscanf(infor,"%d. Username: %s Password: %s",&index,attendants[i].username,attendants[i].password);
		if (strcmp(attPass,attendants[i].password) == 0)
		{
			return true;
		}
		i++;
		fgets(str,499,infor);
	}
	fclose(infor);
	return false;
}

void changeAttUsername()
{
	int index, i = 0;
	char str[500];
	FILE *info;
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","r");
	fscanf(info,"%d\n",&attendantsCount);
	while(!feof(info))
	{
		fscanf(info,"%d. Username: %s Password: %s",&index,attendants[i].username,attendants[i].password);
		i++;
		fgets(str,499,info);
	}
	fclose(info);
	
	system("cls");
	Attendant att;
	printf("\n\t\tEnter the current username: ");
	scanf("%s",att.username);
	if (checkAttUsername(att.username))
	{
		attIndex = searchAttUsername(att.username);	
		printf("\n\t\tNow, you can change it to the new one.\n");
		setAttUsername(attIndex);	
		saveEditedAttendantsInfo(attIndex,attendantsCount);
		printf("\n\t\tUsername has changed to %s.",attendants[attIndex].username);
	}
	else
		printf("\n\t\tThe username not found!");		
}  

void changeAttPassword()
{	
    int index, i = 0;
	char str[500];
	FILE *info;
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","r");
	fscanf(info,"%d\n",&attendantsCount);
	while(!feof(info))
	{
		fscanf(info,"%d. Username: %s Password: %s",&index,attendants[i].username,attendants[i].password);
		i++;
		fgets(str,499,info);
	}
	fclose(info);
	
	system("cls");
	Attendant att;
	printf("\n\t\tEnter your current password: ");
	getchar();
	gets(att.password);
	if (checkAttPassword(att.password))
	{
		attIndex = searchAttPassword(att.password);	
		printf("\n\t\tNow, you can change it to the new one.\n");
		setAttPassword(attIndex);
		saveEditedAttendantsInfo(attIndex,attendantsCount);
		printf("\n\t\tPassword has changed to %s.",attendants[attIndex].password);
	}
	else
		printf("\n\t\tThe password not found!");
}

void attendantLogIn()
{
	system("cls");
	Attendant att;
	printf("\n\t\tEnter your username: ");
	gets(att.username);
	if(checkAttUsername(att.username))
	{
		attIndex = searchAttUsername(att.username);
		printf("\n\t\tEnter your passsword: ");
	    gets(att.password);
	    if (checkAttPassword(attIndex,att.password))
	    	attendantMenu();

		else
			printf("\n\t\tThis password doesn't match with the username.");
	}
	else
	{
		printf("\n\t\tThe Username not found!\n");
		Sleep(2000);
		attendantLogIn();
	}
}

int searchAttUsername(char attUsername[])
{
	FILE *infor;
	int index, i = 0;
	char str[500];
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","r");
	fscanf(infor,"%d\n",&attendantsCount);
	while(feof(infor) == 0)
	{	
		fscanf(infor,"%d. Username: %s Password: %s",&index,attendants[i].username,attendants[i].password);
		if (strcmp(attUsername,attendants[i].username) == 0)
		{
			return i;
		}
		i++;
		fgets(str,499,infor);
	}
	fclose(infor);
	return -1;
}

int searchAttPassword(char attPass[])
{
	char str[500];
	int index, i = 0;
	FILE *infor;
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","r");
	fscanf(infor,"%d\n",&attendantsCount);
	while(feof(infor) == 0)
	{
		fscanf(infor,"%d. Username: %s Password: %s",&index,attendants[i].username,attendants[i].password);
		if (strcmp(attPass,attendants[i].password) == 0)
		{
			return i;
		}
		i++;
		fgets(str,499,infor);
	}
	fclose(infor);
	return -1;
}   

bool checkAttPassword(int attIndex,char attPassword[])
{
	char str[500];
	int index, i = 0;
	FILE *infor;
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","r");
	fscanf(infor,"%d\n",&attendantsCount);
	while(feof(infor) == 0)
	{
		fscanf(infor,"%d. Username: %s Password: %s",&index,attendants[i].username,attendants[i].password);
		if (strcmp(attPassword,attendants[i].password) == 0 && i == attIndex)
		{
			return true;
		}
		i++;
		fgets(str,499,infor);
	}
	fclose(infor);
	return false;
}

void deleteAttAccount()
{
	system("cls");
	Attendant att;
	printf("\n\t\tEnter the username please: ");
	getchar();
	gets(att.username);
	
	if (checkAttUsername(att.username))
	{
		attIndex = searchAttUsername(att.username);
		printf("\n\t\tNow enter your password: ");
		gets(att.password);
		if (checkAttPassword(attIndex,att.password))
		{
			int index;
			FILE *info;
			info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","r");
			fscanf(info,"%d\n",&attendantsCount);
			for (i = 0 ; i < attendantsCount ; i++)
				fscanf(info,"%d. Username: %s Password: %s",&index,attendants[i].username,attendants[i].password);
			for (i = attIndex ; i < attendantsCount ; i++)
				attendants[i] = attendants[i + 1];
			attendantsCount--;
			fclose(info);
			
			saveAttendantsInfo(attendantsCount);
			printf("\n\t\tYour account has deleted successfully.");
		}	
	}
	else
		printf("\n\t\tThere's no attendant with this username.\n");
}

void showAllAttendants()
{
	char str[400];
	int index;
	FILE *info;
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","r");
	fscanf(info,"%d\n",&attendantsCount);
	for (i = 0 ; i < attendantsCount ; i++)
		fscanf(info,"%d. Username: %s Password: %s",&index,attendants[i].username,attendants[i].password);
				
	displayAllAttendants();
	fclose(info);
}

void displayAllAttendants()
{
	for (i = 0 ; i < attendantsCount ; i++)
		printf("\n\t\tUsername: %s\n\t\tPassword: %s\n",attendants[i].username,attendants[i].password);	
}

void attendantMenu()
{
	system("cls");
	system("Color 8E");
	int attempt = 0;
	char choice;
	do
	{
		printf("\n\t\t1.Add an user's Account.\n");
		printf("\n\t\t2.Edit User Account.\n");
		printf("\n\t\t3.Search For User's Information.\n");
		printf("\n\t\t4.Show All Users.\n");
		printf("\n\t\t5.Back To The Main Menu.\n");
		choice = getche();
		switch(choice)
		{
			case '1':{
				openUserAccount(attempt);
				break;
			}
			case '2':{
				editUser();
				break;
			}
			case '3':{
				showUserInfo();
				break;
			}
			case '4':{
				showAllUsers();
				break;
			}	
			case '5':{
				mainMenu();
				break;
			}			
			default: printf("%c\n\t\t\tOops!\n\t\tyou have entered %c while the options are from 1 to 5\n.",7,choice);
		}		
		
	}while(choice >= '1' && choice <= '5');
}

void openUserAccount(int attempt)
{
	system("cls");
	User u;
	printf("\n\t\tEnter your birth date please,\nformat --> 2008 02 18:\n ");
	for (i = 0 ; i < 4 ; i++)
		u.date.year[i] = getche();
	u.date.day[i] = '\0';
	printf("\\");
	
	for (i = 0 ; i < 2 ; i++)
		u.date.month[i] = getche();
	u.date.month[i] = '\0';
	printf("\\");
	
	for (i = 0 ; i < 2 ; i++)
		u.date.day[i] = getche();
	u.date.day[i] = '\0';
	
	if(checkDate(u))
	{
		if(checkAge(u) == 1)
		{
			FILE *info;
			info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
			fscanf(info,"%d",&usersCount);
			lastAvailUserIndex = usersCount;
			fclose(info);
			strcpy(users[lastAvailUserIndex].date.year,u.date.year);
            strcpy(users[lastAvailUserIndex].date.month,u.date.month);
			strcpy(users[lastAvailUserIndex].date.day,u.date.day);
			suggestedUsernames();
			setUserUsername(lastAvailUserIndex);
			setAccountNumber(lastAvailUserIndex);
			setUserPassword(lastAvailUserIndex);
			usersCount++;
			saveUsersInformation(usersCount);
		}
		else if (checkAge(u) == 0)
		{
			printf("\n\t\tSorry! you're not old enough to open an account yet.");
			Sleep(2000);
			mainMenu();
		}
		else if (checkAge(u) == 2)
		{
			printf("\n\t\tSomething went wrong! please try again.\n");
			Sleep(2000);
			attempt++;
			if (attempt < 3)
				openUserAccount(attempt);
		}	
	}
	else
		printf("\n\t\tInvalid input!\n");	
}

bool checkDate(User u)
{
	int flag = 1;
	for (i = 3 ; i >= 0 ; i--)
	{
		if(!isdigit(u.date.year[i]))
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		for (i = 1 ; i >= 0 ; i--)
		{
			if(!isdigit(u.date.month[i]))
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			for (i = 1 ; i >= 0 ; i--)
			{
				if (!isdigit(u.date.day[i]))
				{
					flag = 0;
					break;
				}
			}
		}			
	}
	if(flag)
	    return true;
	    
	return false;
}

int checkAge(User u)
{
	int year = 0, month = 0, day = 0, p = 1;
	for (i = 3 ; i >= 0 ; i--)
	{
		year += (u.date.year[i] - 48) * p;
		p *= 10;
	}
	p = 1;
	for (i = 1 ; i >= 0 ; i--)
	{
		month += (u.date.month[i] - 48) * p;
		p *= 10;
	}   
	p = 1;
	for (i = 1 ; i >= 0 ; i--)
	{
		day += (u.date.day[i] - 48) * p;
		p *= 10;
	}
	if ((year <= currentYear && year >= 1922) && (month <= 12 && month >= 1) && (day <= 31 && day >= 1))
	{
	    if((currentYear - year > 18) || (currentYear - year == 18 && currentMonth - month > 0) || (currentYear - year == 18 && currentMonth - month == 0 && currentDay - day >= 0))
	        return 1;  
	    else
			return 0;
	}
	else
		return 2;
}

void suggestedUsernames()
{
	char name[15], str[15];
	int n, j = 0;
	printf("\n\t\tPlease enter your first name:\n");
	scanf(" %s",name);
	n = strlen(name);
	printf("\n\t\tEnter an username: (you can also pick one of the suggested usernames)\n");
	printf("\n\t\t-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-\n\n");
	permute(name,0,n-1);
	for (i = n-1 ; i >= 0 ; i--)
		str[j++] = name[i];
	str[j] = '\0';
	printf("\t\t%s%s\n",str,users[lastAvailUserIndex].date.year);
	printf("\t\t%s%s\n",str,users[lastAvailUserIndex].date.month);
	printf("\t\t%s%s\n\n",str,users[lastAvailUserIndex].date.day);
	getchar();
}

void permute(char *a, int first, int last)
{
	if (first == last)
	{
		printf("\t\t%s%s\n",a,users[lastAvailUserIndex].date.year);	
		printf("\t\t%s%s\n",a,users[lastAvailUserIndex].date.month);	
		printf("\t\t%s%s\n",a,users[lastAvailUserIndex].date.day);	
	}
	else
	{
		for (i = first ; i <= last ; i++)
		{
			swap((a+first),(a+i));
			permute(a,first+last,last);
			swap((a+first),(a+i));
		}
	}
}

void swap(char *p, char *q)
{
	char temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void setUserUsername(int lastAvailUserIndex)
{
	User u;
	printf("\n\t\tEnter an username: ");
	gets(u.username);
	omitAllSpaces(u.username);
	if (strlen(u.username) < 4 || strlen(u.username) > 10)
	{
		printf("\n\t\tUsername can not be less than 4 or more than 10 characters.\n");
		Sleep(2000);
		setUserUsername(lastAvailUserIndex);
	}
	else if (strlen(u.username) >= 4 && strlen(u.username) <= 10)
	{
		if(!checkUserUsername(u.username))
		{
			strcpy(users[lastAvailUserIndex].username,u.username);
			printf("\n\t\tDone!\n");
		}
		else
		{
			printf("\n\t\tSorry! this username has been taken before, try another one.\n");
			Sleep(2000);
			setUserUsername(lastAvailUserIndex);
		}
	}
}

void omitAllSpaces(char str[])
{
	register int j = 0;
	char newStr[9];
	for (i = 0 ; i < 8 ; i++)
	{
		if (str[i] != ' ')
		    newStr[j++] = str[i];
	}
	newStr[j] = '\0';
	strcpy(str,newStr);
}

void setAccountNumber(int lastAvailUserIndex)
{
	User u;
	int r, flag;
	char temp[7];
	r = whichBank();
	printf("\n\t\tPlease enter your account number: ");
	if (r == 1)
	{
		for (i = 0 ; i < 10 ; i++)
			u.accountNum[i] = getche();
		u.accountNum[i] = '\0';
		
		for (i = 0 ; i < 6 ; i++)
			temp[i] = u.accountNum[i];

		if(strcmp(temp,"627253") == 0)
			flag = 1;
			
		else
			flag = 0;
	}
	else if (r == 2)
	{
		for (i = 0 ; i < 11 ; i++)
			u.accountNum[i] = getche();
		u.accountNum[i] = '\0';
		
		for (i = 0 ; i < 6 ; i++)
			temp[i] = u.accountNum[i];
			
		if(strcmp(temp,"6101433") == 0)
			flag = 1;
		else
			flag = 0;
	}
	else if (r == 3)
	{
		for (i = 0 ; i < 12 ; i++)
			u.accountNum[i] = getche();
		u.accountNum[i] = '\0';
		
		for (i = 0 ; i < 6 ; i++)
			temp[i] = u.accountNum[i];
			
		if(strcmp(temp,"603799") == 0)
			flag = 1;
		else
			flag = 0;
	}
	if (isAccountNumber(u.accountNum) && flag == 1)
	{
		if(!checkAccountNumber(u.accountNum))
		{
			strcpy(users[lastAvailUserIndex].accountNum,u.accountNum);
			printf("\n\t\tThe account number has set.\n");
		}
		else if(checkAccountNumber(u.accountNum))
		{
			printf("\n\t\tOops! This account number belongs to someone else.\n");
			Sleep(2000);
			setAccountNumber(lastAvailUserIndex);
		}	
	}
	else if (!isAccountNumber(u.accountNum))
	{
		printf("\n\t\tInvalid input!\n");
		Sleep(2000);
		mainMenu();	
	}			
}
int whichBank()
{
	char bankName[8];
	printf("\n\t\tPlease enter the name of the bank (you can only choose Tejarat, Melat or Meli): ");
	gets(bankName);
	if(strcmpi(bankName,"Tejarat") != 0 && strcmpi(bankName,"Melat") != 0 && strcmpi(bankName,"Meli") != 0)
	{
		printf("\n\t\tSorry! you can only choose Tejarat, Melat or Meli bank.");
		whichBank();
	}
	else if(strcmpi(bankName,"Tejarat") == 0)
		return 1;
	else if (strcmpi(bankName,"Melat") == 0)
		return 2;
	else if (strcmpi(bankName,"Meli") == 0)
		return 3;
}

bool isAccountNumber(char accountNum[])
{
	int digitCount = 0;
	for (i = 0 ; i < accountNum[i] ; i++)
	{
		if (isdigit(accountNum[i]))
			digitCount++;
	}
	if (digitCount == strlen(accountNum))
		return true;
		
	return false;
}

void setUserPassword(int lastAvailUserIndex)
{
    char pass[9], passConfirm[9];
	int digitCount = 0, upperCount = 0, lowerCount = 0, attempt = 0;
	do 
	{
		printf("\n\t\tEnter your password (your password should contain at least 8 characters include 1 digit 1 upper and 1 lower letter): \n\t\t");
		for (i = 0; i < 8; i++) 
		{
			pass[i] = getch();
			printf("*");
		}
		pass[i] = '\0';
		getchar();
		int count = 0;
		for (i = 0; i < 8; i++)
		{
			if (isdigit(pass[i]))
				digitCount++;
			else if (isalpha(pass[i]))
			{
				if (isupper(pass[i]))
					upperCount++;
				else if(islower(pass[i]))
					 lowerCount++;
			}	
		}
		if (digitCount >= 1 && upperCount >= 1 && lowerCount >= 1 && isPassword(pass))
		{
			printf("\n\t\tConfirm your password: ");
			for (i = 0; i < 8; i++) 
			{
				passConfirm[i] = getch();
				printf("*");
			}
			passConfirm[i] = '\0';
			getchar();
		}
		else
			printf("\n\t\tWeek password! please pick a strong one");
		
	} while(strcmp(pass,passConfirm) != 0);

	if (!checkUserPassword(passConfirm))
	{
		strcpy(users[lastAvailUserIndex].password,passConfirm);
		printf("\n\t\tThe Confirmed password is: ");
		for (i = 0 ; i < 8 ; i++)
			printf("%c",users[lastAvailUserIndex].password[i]);
	}
	else if (checkUserPassword(passConfirm))
	{		
		printf("\n\t\tSorry! this password has been taken before, try another one.\n");
		Sleep(2000);
		setUserPassword(lastAvailUserIndex);		
	}
} 

bool isPassword(char passConfirm[])
{
	for(i = 0 ; i < 8 ; i++)
	{
		if (passConfirm[i] < 48 || (passConfirm[i] > 57 && passConfirm[i] < 65) || (passConfirm[i] > 90 && passConfirm[i] < 97 ) || passConfirm[i] > 122)
	        return false;
	}	
	return true;	
}

bool checkUserUsername(char userUsername[])
{
	FILE *info;
	int index, i = 0;
	char str[500];
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(info,"%d\n",&usersCount);
	while(feof(info) == 0)
	{	
		fscanf(info,"%d. Username: %s ",&index,users[i].username);
		fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(info,"Password: %s ",users[i].password);
		fscanf(info,"Account number: %s ",users[i].accountNum);
		fscanf(info,"Account balance: %lld",&users[i].accBalance);
		if (strcmp(userUsername,users[i].username) == 0)
		{
			return true;
		}
		i++;
		fgets(str,499,info);
	}
	fclose(info);
	return false;
}

bool checkUserUsername(int userIndex,char userUsername[])
{
	FILE *info;
	int index, i = 0;
	char str[500];
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(info,"%d\n",&usersCount);
	while(feof(info) == 0)
	{	
		fscanf(info,"%d. Username: %s ",&index,users[i].username);
		fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(info,"Password: %s ",users[i].password);
		fscanf(info,"Account number: %s ",users[i].accountNum);
		fscanf(info,"Account balance: %lld",&users[i].accBalance);
		if (strcmp(userUsername,users[i].username) == 0 && userIndex == i)
		{
			return true;
		}
		i++;
		fgets(str,499,info);
	}
	return false;
	fclose(info);	
}

int searchUserUsername(char userUsername[])
{
	FILE *info;
	int index, i = 0;
	char str[500];
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(info,"%d\n",&usersCount);
	while(feof(info) == 0)
	{	
		fscanf(info,"%d. Username: %s ",&index,users[i].username);
		fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(info,"Password: %s ",users[i].password);
		fscanf(info,"Account number: %s ",users[i].accountNum);
		fscanf(info,"Account balance: %lld",&users[i].accBalance);
		if (strcmp(userUsername,users[i].username) == 0)
		{
			return i;
		}
		i++;
		fgets(str,499,info);
	}
	return -1;
	fclose(info);
}

void editUser()
{
	system("cls");
	char choice;
	do
	{
		printf("\n\t\t1.Change Password.\n");
		printf("\n\t\t2.Delete Account.\n");
		printf("\n\t\t3.Increase Balance.\n");
		printf("\n\t\t4.Back.\n");
		printf("\n\t\t5.Back To The Main Menu.\n");
		choice = getche();
		switch(choice)
		{
			case '1':
					changeUserPassword();
					break;
			case '2':
					deleteUserAccount();
					break;
			case '3':
					increaseBalance();
					break;
			case '4':
					attendantLogIn();
					break;
			case '5':
					mainMenu();
					break;
					
			default: printf("\n\t\t%cOops!\nYou have entered %c while the options are from 1 to 5.\n",7,choice);
		}
		
	}while(choice >= '1' && choice <= '5');
}

void changeUserPassword()
{
	system("cls");
	int index, i = 0;
	char str[500];
	FILE *info;
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(info,"%d\n",&usersCount);
	while(!feof(info))
	{
		fscanf(info,"%d. Username: %s ",&index,users[i].username);
		fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(info,"Password: %s ",users[i].password);
		fscanf(info,"Account number: %s ",users[i].accountNum);
		fscanf(info,"Account balance: %lld",&users[i].accBalance);
		i++;
		fgets(str,499,info);
	}
	fclose(info);

	User u;
	int choice;
	printf("\n\t\tPress 1 if you remember your password otherwise Press 2.\n\t\t");
	choice = getche();
	switch(choice)
	{
		case '1':
		{
			printf("\n\t\tEnter your current password: ");
			scanf("%s",u.password);
			if (checkUserPassword(u.password))
			{
				userIndex = searchUserPassword(u.password);
				printf("\n\t\tNow, you can change it to the new one.\n");
				getchar();
				setUserPassword(userIndex);
				saveEditedUsersInfo(userIndex,usersCount);
				printf("\n\t\tYour Password has changed to %s.",users[userIndex].password);
			}
			else
				printf("\n\t\tThe password not found!");
			
			break;
		}
		case '2':
			showForgottenPassword();
	}
}

void showForgottenPassword()
{
	system("cls");
	User u;
	int code, input;
	FILE *ptf;
	ptf = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Temp_password.txt","w");
	srand(time(NULL)*time(NULL));
	code = rand();
	fprintf(ptf,"%d",code);
	fclose(ptf);
	printf("\n\t\tOkay! we send a code to Temp_password textFile enter the code to access your account.\n\t\t");
	scanf("%d",&input);
	if (input == code)
	{
		printf("\n\t\tNow enter your username: \n\t\t");
		scanf(" %s",u.username);
		userIndex = searchUserUsername(u.username);
		FILE *infor;
		int index, i = 0;
		char str[500];
		infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
		fscanf(infor,"%d\n",&usersCount);
		while(feof(infor) == 0)
		{	
			fscanf(infor,"%d. Username: %s ",&index,users[i].username);
			fscanf(infor,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
			fscanf(infor,"Password: %s ",users[i].password);
			fscanf(infor,"Account number: %s ",users[i].accountNum);
			fscanf(infor,"Account balance: %lld",&users[i].accBalance);
			if (strcmp(u.username,users[i].username) == 0 && userIndex == i)
			{
				printf("\n\t\tYou're password is: %s  ** Remeber it dear %s :)** ",users[i].password,users[i].username);
				break;
			}
			i++;
			fgets(str,499,infor);
		}
		fclose(infor);
	}
}

bool checkUserPassword(char userPass[])
{
	FILE *infor;
	int index, i = 0;
	char str[500];
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(infor,"%d\n",&usersCount);
	while(feof(infor) == 0)
	{	
		fscanf(infor,"%d. Username: %s ",&index,users[i].username);
		fscanf(infor,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(infor,"Password: %s ",users[i].password);
		fscanf(infor,"Account number: %s ",users[i].accountNum);
		fscanf(infor,"Account balance: %lld",&users[i].accBalance);
		if (strcmp(userPass,users[i].password) == 0)
		{
			return true;
		}
		i++;
		fgets(str,499,infor);
	}
	return false;
	fclose(infor);
}

bool checkUserPassword(int userIndex,char userPass[])
{
	FILE *infor;
	int index, i = 0;
	char str[500];
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(infor,"%d\n",&usersCount);
	while(feof(infor) == 0)
	{
			fscanf(infor,"%d. Username: %s ",&index,users[i].username);
			fscanf(infor,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
			fscanf(infor,"Password: %s ",users[i].password);
			fscanf(infor,"Account number: %s ",users[i].accountNum);
			fscanf(infor,"Account balance: %lld",&users[i].accBalance);
			if (strcmp(userPass,users[i].password) == 0 && i == userIndex)
			{
				return true;
			}
			i++;
			fgets(str,499,infor);
	}
	return false;
	fclose(infor);	
}

int searchUserPassword(char userPass[])
{
	FILE *infor;
	int index, i = 0;
	char str[500];
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(infor,"%d\n",&usersCount);
	while(feof(infor) == 0)
	{	
		fscanf(infor,"%d. Username: %s ",&index,users[i].username);
		fscanf(infor,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(infor,"Password: %s ",users[i].password);
		fscanf(infor,"Account number: %s ",users[i].accountNum);
		fscanf(infor,"Account balance: %lld",&users[i].accBalance);
		if (strcmp(userPass,users[i].password) == 0)
		{
			return i;
		}
		i++;
		fgets(str,499,infor);
	}
	return -1;
	fclose(infor);
}

void deleteUserAccount()
{
	system("cls");
	User u;
	printf("\n\t\tEnter the username please: ");
	gets(u.username);
	if (checkUserUsername(u.username))
	{
		userIndex = searchUserUsername(u.username);
		printf("\n\t\tNow enter your password: ");
		gets(u.password);
		if (checkUserPassword(userIndex,u.password))
		{
			int index;
			FILE *info;
			info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
			fscanf(info,"%d\n",&usersCount);
			for (i = 0 ; i < usersCount ; i++)
			{
				fscanf(info,"%d. Username: %s ",&index,users[i].username);
				fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
				fscanf(info,"Password: %s ",users[i].password);
				fscanf(info,"Account number: %s ",users[i].accountNum);
				fscanf(info,"Account balance: %lld",&users[i].accBalance);
			}
			for (i = userIndex ; i < usersCount ; i++)
				users[i] = users[i + 1];
			usersCount--;
			fclose(info);
			
			saveUsersInfo(usersCount);
			printf("\n\t\tYour account has deleted successfully.");
		}	
	}
	else
		printf("\n\t\tThere's no user with this username.");
}

void increaseBalance()
{
	system("cls");
	char str[500];
	int index;
	FILE *info;
	info = fopen ("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(info,"%d\n",&usersCount);
	User u;
	char s1[] = "This amount of money has been transfered to you through the bank: ", s2[12];
	int n, length;
	printf("\n\t\tEnter the account number of the user: ");
	scanf("%s",u.accountNum);
	if (checkAccountNumber(u.accountNum))
	{
		userIndex = searchAccountNumber(u.accountNum);
		while(feof(info) == 0)
		{
			if (i == userIndex)
			{
				fscanf(info,"%d. Username: %s ",&index,users[i].username);
				fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
				fscanf(info,"Password: %s ",users[i].password);
				fscanf(info,"Account number: %s ",users[i].accountNum);
				fscanf(info,"Account balance: %lld",&users[i].accBalance);	
				break;
			}	
			i++;
			fgets(str,499,info);
		}
		fclose(info);
		printf("\n\t\tEnter the amount of money that will be add to this account: ");
		scanf("%d",&n);
		users[userIndex].accBalance += n;
		sprintf(s2,"%d",n);
		length = strlen(s1);
		appendStrings(s1,s2,length);
		setRecentChanges(userIndex,s1);
	}
	else
		printf("\n\t\tThere's no user with this account number!\n");
}

bool checkAccountNumber(char accountNum[])
{
	FILE *info;
	int index, i = 0;
	char str[500];
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(info,"%d\n",&usersCount);
	while(feof(info) == 0)
	{	
		fscanf(info,"%d. Username: %s ",&index,users[i].username);
		fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(info,"Password: %s ",users[i].password);
		fscanf(info,"Account number: %s ",users[i].accountNum);
		fscanf(info,"Account balance: %lld",&users[i].accBalance);	
		if (strcmp(accountNum,users[i].accountNum) == 0)
		{
			return true;
		}
		i++;
		fgets(str,499,info);
	}
	return false;
	fclose(info);		
}

bool checkAccountNumber(char accountNum[], int userIndex)
{
	FILE *info;
	int index, i = 0;
	char str[500];
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(info,"%d\n",&usersCount);
	while(feof(info) == 0)
	{	
			fscanf(info,"%d. Username: %s ",&index,users[i].username);
			fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
			fscanf(info,"Password: %s ",users[i].password);
			fscanf(info,"Account number: %s ",users[i].accountNum);
			fscanf(info,"Account balance: %lld",&users[i].accBalance);	
			if (strcmp(accountNum,users[i].accountNum) == 0 && i == userIndex)
			{
				return true;
			}	
		i++;
		fgets(str,499,info);
	}
	return false;
	fclose(info);		
}

int searchAccountNumber(char accountNum[])
{
	FILE *infor;
	int index, i = 0;
	char str[500];
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(infor,"%d\n",&usersCount);
	while(feof(infor) == 0)
	{	
		fscanf(infor,"%d. Username: %s ",&index,users[i].username);
		fscanf(infor,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(infor,"Password: %s ",users[i].password);
		fscanf(infor,"Account number: %s ",users[i].accountNum);
		fscanf(infor,"Account balance: %lld",&users[i].accBalance);	
		if (strcmp(accountNum,users[i].accountNum) == 0)
		{
			return i;
		}
		i++;
		fgets(str,499,infor);
	}
	return -1;	
	fclose(infor);
}

void appendStrings(char s1[], char s2[], int length)
{
	for (i = 0; s2[i]; i++)
    	s1[length++] = s2[i];
	s1[length] = '\0';
}

void printRecentUpdates(int userIndex)
{
	for(int i = lastChangeIndex-1 ; i >= 0 ; i--)
	{
		printf(users[userIndex].recentChanges[i]);
		printf("\n");
	}
}

void setRecentChanges(int userIndex,char recentChange[])
{
	strcpy(users[userIndex].recentChanges[lastChangeIndex++],recentChange);
}

void showAllUsers()
{
	char str[400];
	int index;
	FILE *info;
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(info,"%d\n",&usersCount);
	for (i = 0 ; i < usersCount ; i++)
	{
		fscanf(info,"%d. Username: %s ",&index,users[i].username);
		fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(info,"Password: %s ",users[i].password);
		fscanf(info,"Account number: %s ",users[i].accountNum);
		fscanf(info,"Account balance: %lld",&users[i].accBalance);				
	}
	arrangeUsers();
	displayAllUsers();
	fclose(info);
}

void arrangeUsers()
{
	User temp[usersCount];
	for (i = 0 ; i < usersCount ; i++)
	{
		for (j = i+1 ; j < usersCount ; j++)
		{
			if (strcmp(users[i].username,users[j].username) > 0)
			{
				temp[i] = users[i];
				users[i] = users[j];
				users[j] = temp[i];
			}
		}
	}
}

void displayAllUsers()
{
	system("cls");
	for (i = 0 ; i < usersCount ; i++)
	{
		printf("\n\t\tUsername: %s\n",users[i].username);	
		printf("\t\tBirth date: %s\n",users[i].date.year,users[i].date.month,users[i].date.day);
		printf("\t\tPassword: %s\n",users[i].password);
		printf("\t\tAccount number: %s\n",users[i].accountNum);
		printf("\t\tAccount balance: %lld\n",users[i].accBalance);	
	}
	Sleep(2000);
}

void displaySelectedUser(int index)
{
	system("cls");
	printf("\n\t\tUsername: %s\n",users[index].username);
	printf("\t\tBirth date: %s\n",users[index].date.year,users[index].date.month,users[index].date.day);
	printf("\t\tPassword: %s\n",users[index].password);
	printf("\t\tAccount number: %s\n",users[index].accountNum);
	printf("\t\tAccount balance: %lld\n",users[index].accBalance);
	Sleep(2000);
}

void showUserInfo()
{
	User u;
	FILE *infor;
	int num, temp, flag = 0;
	char str[400];
	printf("\n\t\tEnter the number of the user that you're looking for: ");
	scanf("%d",&num);
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(infor,"%d\n",&usersCount);
	while(feof(infor) == 0)
	{
		fscanf(infor,"%d. ",&temp);
		if (temp == num)
		{
			flag = 1;
			fscanf(infor,"Username: %s ",users[temp].username);
			fscanf(infor,"Birth date: %s ",users[temp].date.year,users[temp].date.month,users[temp].date.day);
			fscanf(infor,"Password: %s ",users[temp].password);
			fscanf(infor,"Account number: %s ",users[temp].accountNum);
			fscanf(infor,"Account balance: %lld",&users[temp].accBalance);
			displaySelectedUser(temp);
			break;
		}
		fgets(str,399,infor);
	}
	if (!flag)
		printf("\n\t\tOut of range!\n");
	fclose(infor);
}

void userSignUp()
{
	system("cls");
	int attempt = 0;
	openUserAccount(attempt);
}

void userLogIn()
{
	system("cls");
	char tempUsername[10], tempPass[9];	
	printf("\n\t\tEnter your username: ");
	gets(tempUsername);
	if (checkUserUsername(tempUsername))
	{
		userIndex = searchUserUsername(tempUsername);
		printf("\n\t\tEnter your password please: ");
		gets(tempPass);
		if(checkUserPassword(userIndex,tempPass))
		{
			userMenu(userIndex);
		}
		else
			printf("\n\t\tPassword not found!\n");
	}
	else
		printf("\n\t\tSorry! username not found.\n");	
}

void userMenu(int userIndex)
{
	system("cls");
	system("Color 79");
    char choice;
	do
	{
		printf("\n\t\t1.Account Balance.\n");
		printf("\n\t\t2.Cash Transfer.\n");
		printf("\n\t\t3.Cash Withdrawal.\n");
		printf("\n\t\t4.Recent Account Updates(10).\n");
		printf("\n\t\t5.Change Username.\n");
		printf("\n\t\t6.Change Password.\n");
		printf("\n\t\t7.Back to the main menu.\n");
		choice = getche();
		switch(choice)
		{
			case '1': 
			{		accountBalance(userIndex);
					break;
			}
			case '2': 
			{		cashTransfer(userIndex);
					break;
			}
			case '3': 
			{		cashWithdrawal(userIndex);
					break;
			}
			case '4': 
			{		printRecentUpdates(userIndex);
				    break;
			}
			case '5': 
			{		changeUserUsername(userIndex);
				    break;
			}
			case '6': 
			{
					changeUserPassword(userIndex);
					break;
			}
			case '7':
			{
					mainMenu();
					break;
			}
			default: printf("%c\n\t\tOops! You have entered %c while the options are from 1 to 7.",7,choice);
		}	
		
	}while(choice >= '1' && choice <= '7');	
}

void accountBalance(int userIndex)
{
	system("cls");
	FILE *infor;
	int index, i = 0;
	char str[500];
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(infor,"%d\n",&usersCount);
	while(feof(infor) == 0)
	{	
		if (i == userIndex)
		{
			fscanf(infor,"%d. Username: %s ",&index,users[i].username);
			fscanf(infor,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
			fscanf(infor,"Password: %s ",users[i].password);
			fscanf(infor,"Account number: %s ",users[i].accountNum);
			fscanf(infor,"Account balance: %lld ",&users[i].accBalance);	
			printf("\n\t\tYour account balance is as below:\n%lld $",users[userIndex].accBalance);
			break;
		}
		i++;
		fgets(str,499,infor);
	}	
	fclose(infor);
}

void cashTransfer(int userIndex)
{
	system("cls");
	User u;
	int cash, receiverIndex, senderIndex = userIndex, length = 0, index;
	printf("\n\t\tPlease enter the username of the person whom you wanna transfer the cash for: ");
	scanf("%s",u.username);
	getchar();
	printf("\n\t\tNow enter the account number: ");
	scanf("%s",u.accountNum);
	if (checkUserUsername(u.username))
	{
		receiverIndex = searchUserUsername(u.username);
		if (checkAccountNumber(u.accountNum,receiverIndex))
		{
			if (strcmp(u.accountNum,users[userIndex].accountNum) != 0)
			{
				printf("\n\t\tNow enter the amount of money: ");
				scanf("%d",&cash);
				if (isEnough(cash,senderIndex))
				{
					users[receiverIndex].accBalance += cash;
					users[senderIndex].accBalance -= cash;
					
					char s1[] = "You have transfered this amount of money to             : ", s2[12];
					char accNum[13], tempAccBalance[12];
					char str[] = "\nYour account balance after operation: ";
					strcpy(accNum,users[receiverIndex].accountNum);
					index = 44;
					concatenate(s1,accNum,index);
					sprintf(s2,"%d",cash);
					while(s1[length] != '\0')
						length++;
					appendStrings(s1,s2,length);
					length = strlen(str);
					sprintf(tempAccBalance,"%d",users[senderIndex].accBalance);
					appendStrings(str,tempAccBalance,length);
					strcat(s1,str);
					setRecentChanges(senderIndex,s1);
					
					strcpy(str,"\nYour account balance after operation: ");
					strcpy(s1,"This amount of money has been transferd from             : ");
					strcpy(accNum,users[senderIndex].accountNum);
					index = 45;
					concatenate(s1,accNum,index);
					strcat(s1,s2);
					length = strlen(str);
					sprintf(tempAccBalance,"%d",users[receiverIndex].accBalance);
					appendStrings(str,tempAccBalance,length);
					strcat(s1,str);
					setRecentChanges(receiverIndex,s1);	
				}
				else
					printf("\n\t\tOops! your account balance is not enough.\n");
			}
			else if (strcmp(u.accountNum,users[userIndex].accountNum) == 0)
				printf("\n\t\tError!\n");
		}
		else
		   printf("\n\t\tAccount number doesn't match with the username!\n");
	}
	else
		printf("\n\t\tUsername not found!\n");	
}

void concatenate(char s1[], char s2[], int index)
{
	for (i = 0 ; i < s2[i] ; i++)
		s1[index++] = s2[i];	
}

bool isEnough(int money,int userIndex)
{
	FILE *infor;
	int index, i = 0;
	char str[500];
	infor = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(infor,"%d\n",&usersCount);
	while(feof(infor) == 0)
	{	
		if (i == userIndex)
		{
			fscanf(infor,"%d. Username: %s ",&index,users[i].username);
			fscanf(infor,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
			fscanf(infor,"Password: %s ",users[i].password);
			fscanf(infor,"Account number: %s ",users[i].accountNum);
			fscanf(infor,"Account balance: %lld ",&users[i].accBalance);	
			if(money < users[userIndex].accBalance - 20)
			    return true;
			else
			    return false;
		}
		i++;
		fgets(str,499,infor);
	}	
	fclose(infor);
}

void cashWithdrawal(int userIndex)
{
	system("cls");
	int cash, money, length = 0;
	printf("\n\t\tEnter the amount of cash withdrawal: ");
	scanf("%d",&cash);
	if (isEnough)
	{
		users[userIndex].accBalance -= cash;
		char s1[] = "This amount of money has been withdrawed: ", s2[12];
		char str1[] = "\nYour account balance after operation: ", str2[12];
		sprintf(s2,"%d",cash);
		while (s1[length] != '\0')
			length++;
		appendStrings(s1,s2,length);
		
		sprintf(str2,"%d",users[userIndex].accBalance);
		length = strlen(str1);
		appendStrings(str1,str2,length);
		strcat(s1,str1);
		setRecentChanges(userIndex,s1);
		printReceipt(userIndex,cash);
	}
	else
		printf("\n\t\tOops! insufficient account balance.\n");
}

void printReceipt(int userIndex, int cash)
{
	system("cls");
	char date[9];
	char time[9];
	_strdate(date);
	_strtime(time);
	printf("\n\n\t\tPrinting Receipt ");
	for (i = 0 ; i < 3 ; i++)
	{
		printf(". ");
		Sleep(1000);
	}
	printf("\n");
	system("cls");
	printf("\n\n\n\t|\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Thanks For Banking With Us! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2|");
	printf("\n\t|\t\t\t\t\t               |");
	printf("\n\t|\t                           \t               |");
	printf("\n\t|\t\t\t\t\t               |");
	printf("\n\t|\t\t\t\t\t               |");
	printf("\n\t|Date:\t\t\t%s\t               |",date);
	printf("\n\t|Time:\t\t\t%s\t               |",time);
	printf("\n\t|Location:\t\tSanandaj \t               |");
	printf("\n\t|Withdrawed Amount: %d\t\t               |",cash);
	printf("\n\t|Account Balance: %lld\t\t\t               |",users[userIndex].accBalance);
}

void changeUserUsername(int userIndex)
{	
	system("cls");
	int index, i = 0;
	char str[500];
	FILE *info;
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(info,"%d\n",&usersCount);
	while(!feof(info))
	{
		fscanf(info,"%d. Username: %s ",&index,users[i].username);
		fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(info,"Password: %s ",users[i].password);
		fscanf(info,"Account number: %s ",users[i].accountNum);
		fscanf(info,"Account balance: %lld",&users[i].accBalance);
		i++;
		fgets(str,499,info);
	}
	fclose(info);
	
	User u;
	printf("\n\t\tEnter the current username: ");
	scanf("%s",u.username);
	if (checkUserUsername(userIndex,u.username))
	{
		printf("\n\t\tNow, you can change it to the new one.\n");
		suggestedUsernames();
		setUserUsername(userIndex);
		saveEditedUsersInfo(userIndex,usersCount);
		printf("\n\t\tUsername has changed to %s.",users[userIndex].username);
	}
	else
		printf("\n\t\tThe username not found!\n");
}

void changeUserPassword(int userIndex)
{
	system("cls");
	int index, i = 0;
	char str[500];
	FILE *info;
	info = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","r");
	fscanf(info,"%d\n",&usersCount);
	while(!feof(info))
	{
		fscanf(info,"%d. Username: %s ",&index,users[i].username);
		fscanf(info,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fscanf(info,"Password: %s ",users[i].password);
		fscanf(info,"Account number: %s ",users[i].accountNum);
		fscanf(info,"Account balance: %lld",&users[i].accBalance);
		i++;
		fgets(str,499,info);
	}
	fclose(info);
	
	User u;
	printf("\n\t\tEnter your current password: ");
	scanf("%s",u.password);
	if (checkUserPassword(userIndex,u.password))
	{
		printf("\n\t\tNow, you can change it to the new one.\n");
		getchar();
		setUserPassword(userIndex);
		saveEditedUsersInfo(userIndex,usersCount);
		printf("\n\t\tYour Password has changed to %s.",users[userIndex].password);
	}
	else
		printf("\n\t\tThe password not found!");
}

void saveAttendantsInfo(int attendantsCount)
{
	FILE *newInfo;
	newInfo = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Attendants Information.txt","w");
	fprintf(newInfo,"%d\n",attendantsCount);
	for (i = 0 ; i < attendantsCount ; i++)
	{
		fprintf(newInfo,"%d. Username: %s Password: %s\n",i+1,attendants[i].username,attendants[i].password);
	}
	fclose(newInfo);	
}

void saveEditedAttendantsInfo(int attIndex, int attendantsCount)
{
	FILE *newInfo;
	newInfo = fopen("d:\\Codes\\dev\\Attendants Information.txt","w");
	fprintf(newInfo,"%d\n",attendantsCount);
	for (i = 0 ; i < attendantsCount ; i++)
	{
		if (i == attIndex)
			fprintf(newInfo,"%d. Username: %s Password: %s\n",i+1,attendants[attIndex].username,attendants[attIndex].password);
		else
			fprintf(newInfo,"%d. Username: %s Password: %s\n",i+1,attendants[i].username,attendants[i].password);
	}
	fclose(newInfo);	
}

void saveUsersInformation(int usersCount)
{
	FILE *newInfo;
	newInfo = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","w");
	fprintf(newInfo,"%d\n",usersCount);
	for (i = 0 ; i < usersCount ; i++)
	{
		fprintf(newInfo,"%d. Username: %s ",i+1,users[i].username);
		if (i != usersCount - 1)
			fprintf(newInfo,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		else
			fprintf(newInfo,"Birth date: %s/%s/%s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fprintf(newInfo,"Password: %s ",users[i].password);
		fprintf(newInfo,"Account number: %s ",users[i].accountNum);
		fprintf(newInfo,"Account balance: %lld\n",users[i].accBalance);	
	}
	fclose(newInfo);
	printf("\nWelcome! your information has saved successfully.\n");
}

void saveUsersInfo(int usersCount)
{
	int index;
	FILE *newInfo;
	newInfo = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","w");
	fprintf(newInfo,"%d\n",usersCount);
	for (i = 0 ; i < usersCount ; i++)
	{
		fprintf(newInfo,"%d. Username: %s ",i+1,users[i].username);
		fprintf(newInfo,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
		fprintf(newInfo,"Password: %s ",users[i].password);
		fprintf(newInfo,"Account number: %s ",users[i].accountNum);
		fprintf(newInfo,"Account balance: %lld\n",users[i].accBalance);	
	}
	fclose(newInfo);	
}

void saveEditedUsersInfo(int userIndex,int usersCount)
{
	int index;
	FILE *newInfo;
	newInfo = fopen("d:\\Codes\\Projects\\FinalProject_ATM\\Users Information.txt","w");
	fprintf(newInfo,"%d\n",usersCount);
	for (i = 0 ; i < usersCount ; i++)
	{
		if (i == userIndex)
		{
			fprintf(newInfo,"%d. Username: %s ",i+1,users[userIndex].username);
			fprintf(newInfo,"Birth date: %s ",users[userIndex].date.year,users[userIndex].date.month,users[userIndex].date.day);
			fprintf(newInfo,"Password: %s ",users[userIndex].password);
			fprintf(newInfo,"Account number: %s ",users[userIndex].accountNum);
			fprintf(newInfo,"Account balance: %lld\n",users[userIndex].accBalance);
		}
		else
		{
			fprintf(newInfo,"%d. Username: %s ",i+1,users[i].username);
			fprintf(newInfo,"Birth date: %s ",users[i].date.year,users[i].date.month,users[i].date.day);
			fprintf(newInfo,"Password: %s ",users[i].password);
			fprintf(newInfo,"Account number: %s ",users[i].accountNum);
			fprintf(newInfo,"Account balance: %lld\n",users[i].accBalance);
		}
	}
	fclose(newInfo);
}

void feedback()
{
	system("cls");
	system("color 8F");
	printf("\n\t\tYou can write your opinion or report a problem below(enter ctr+z when you done): \n\t\t");
	char ch;
	FILE *ptf;
	ptf = fopen("d:\\Feed Back\\Codes\\Projects\\FinalProject_ATM.txt","a");
	while((ch = getchar()) != EOF)
	{
		fputc(ch,ptf);
	}
	fclose(ptf);
}

void help()
{
	system("cls");
	system("color 73");
	char time[9];
	_strtime(time);
	i = 0;
	char str[500];
	FILE *ptf;
	ptf = fopen("d:\\codes\\Projects\\FinalProject_ATM\\help.txt","r");
	while(!feof(ptf))
	{
		str[i++] = fgetc(ptf);
	}
	str[i] = '\0';
	fclose(ptf);
	
	int k, t = 0, p = 1;
	for (k = 1 ; k >= 0 ; k--)
	{
		t += (time[k] - 48) * p;
		p *= 10;
	}
	if (t >= 1 && t <= 12)
		printf("\n\t\t***Hi! Good Morning***\n\n");
	else if (t > 12 && t <= 17)
		printf("\n\t\t***Hi! Good Afternoon***\n\n");
	else if (t > 17 && t <= 22)
		printf("\n\t\t***Hi! Good Evening***\n\n");
	else if (t > 22 && t <= 0)
		printf("\t\t***Hi! Good Night***\n\n");
	for (j = 0 ; j < i ; j++)
	{
		putchar(str[j]);
	}
	Sleep(5500);
	system("cls");
}

void confirmExit()
{
	char choice;
	printf("\n\t\tAre you sure that you wanna exit?\n");
	printf("\t\tPress 1 to exit.\n");
	printf("\t\tOtherwise press any key.\n");
	choice = getch();
	if (choice == '1')
	{
		printf("\n\t\tProgram Will be terminated after 3 seconds.  ");
		for(i = 3 ; i >= 0 ; i--)
		{
			printf("\b%d",i);
			Sleep(1000);
		}
		exit(1);
	}	
	else
		mainMenu();
}
