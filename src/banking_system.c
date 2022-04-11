/*
Module: banking_system.c
Function:
        To create and manage a Bank Account.
Copyright notice:
        This file copyright (C) 2022 by
        MCCI Corporation
        3520 Krums Corners Road
        Ithaca, NY 14850
        An unpublished work. All rights reserved.
        This file is proprietary information, and may not be disclosed or
        copied without the prior permission of MCCI Corporation.
Author:
        Pranau R, MCCI Corporation   April 2022
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user
    {
    char name[20];
    char mob[12];
    //char pass[15];
    char type[10];
    double balance;
    };

void open();
void display();
void deposit();
void withdraw();
void close();

/****************************************************************************\
|
|   Main Function.
|
\****************************************************************************/

/*
Name: main()
Function:
        To display an user interactive Menu for Banking System.
Definition:
        void main (void);
Returns:
        Functions returning type void: nothing.
*/

void main()
    {
    //struct user user;
    //char num[50];
    //char cash[50];
    int ch;
    printf("\n---You selected Account Details---\n\n");

    /*printf("\nEnter your Registered Mobile Number:\n");
    scanf("%s", num);
    printf("the num is:\n", num);*/
    //display(num);

    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("This is banking_system.exe v1.0.0\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n");
    printf("It can able to create and maintain a Bank Acccount\n");
    printf("An interactive menu is given to perform various operations as per user's need. Now...\n\n");

    while(1)
        {
        printf("\n======== WELCOME TO MCCI BANK!!! ======== \n");
        printf("======== WHAT DO YOU WANT TO DO? ======== \n\n");
        printf("1. Open Account: \n");
        printf("2. Account Details: \n");
        printf("3. Deposit Fund: \n");
        printf("4. Withdraw Fund: \n");
        printf("5. Close Account: \n");
        printf("6. Exit: \n");
        printf("\n");
    
        printf("\nEnter the Choice: \n");
        scanf("%d", &ch);

        switch(ch)
            {
            case 1:
                {
                open();
                break;
                }
            case 2:
                {
                display();
                break;
                }
            case 3:
                {
                deposit();
                break;
                }
            case 4:
                {
                withdraw();
                break;
                }
            case 5:
                {
                close();
                break;
                }
            case 6:
                {
                return;
                }
            default:
                {
                printf("Invalid Entry!!!\n\n");
                break;
                }
            }
        }
    }

/****************************************************************************\
|
|   Function.
|
\****************************************************************************/

/*
Name: open()
Function:
        To get information from user and to open a Bank Account.
Definition:
        void open();
Returns:
        Functions returning type void: nothing.
*/

void open ()
    {
    FILE *fp;
    struct user user;
    user.balance = 0;

    //printf("Balance is: %lf\n", user.balance);    

    fp = fopen("username.txt", "ab");

    system("cls");

    printf("OPEN ACCOUNT!!\n");

    printf("\n\nEnter Name:\t");
    scanf("%s", user.name);
    //printf("\n\nName is: %s\n", user.name);

    printf("\n\nEnter Mobile Number:\t");
    scanf("%s", user.mob);
    //printf("\n\nNumber is: %s\n", user.mob);

    printf("\n\nEnter Account Type:\t");
    scanf("%s", user.type);

    /*printf("\n\nEnter a Password:\t");
    scanf("%s", user.pass);*/

    fwrite(&user, sizeof(user), 1, fp);

    if(fwrite != 0)
        {
        printf("\nAccount Succesfully Created!\n\n");
        }

    fclose(fp);

    printf("Press any key to Display Main Menu...!\n\n");
    getchar();
    }

/****************************************************************************\
|
|   Function.
|
\****************************************************************************/

/*
Name: display()
Function:
        To display a mini statement.
Definition:
        void display(char mobnum[]);
Parameters and Arguments:
        A character array is passed as argument. By comparing this array with file's data (unique mobile number),
        the function displays required user's details.
Returns:
        Functions returning type void: nothing.
*/

void display()
    {
    FILE *fp;
    struct user user;
    char num[12];

    printf("\n---You selected Account Details---\n\n");
    printf("\nEnter your Registered Mobile Number:\n");
    scanf("%s", num);

    printf("\n\nName is: %s\n", user.name);
    printf("the num is:%s\n", num);
    fp = fopen("username.txt", "rb");
    fread(&user, sizeof(user), 1, fp);

    printf("\n\nFRName is: %s\n", user.name);
    printf("the user.mob is:%s\n", user.mob);

    if (strcmp(num, user.mob) != 0)
        {
        printf("the user.mob is:%s\n", user.mob);
        printf("\nThe Mobile Number you entered is not registered!...\n");

        printf("Press any key to Display Main Menu...!\n\n");
        getch();
        }
    else
        {
        system("cls");
        printf("MINI STATEMENT!\n\n");
    
        if (fp == NULL)
            {
            printf("Error occurred while opening the file\n");
            }
        //while (fread(&user, sizeof(user), 1, fp)) 
        else if(strcmp(num, user.mob) == 0) 
            {
            printf("WELCOME, %s", user.name);
            printf("\n\n..........................\n");
            printf("==== YOUR ACCOUNT INFO ====\n");
            printf("***************************\n");
            printf("\nNAME: %s", user.name);

            printf("\nMobile Number: %s", user.mob);

            printf("\nAccount Type: %s", user.type);

            printf("\nBalance: %lfRs\n\n", user.balance);

            printf("Press any key to Display Main Menu...!\n\n");
            getch();
            }
        }
    fclose(fp);
    }



/****************************************************************************\
|
|   Function.
|
\****************************************************************************/

/*
Name: deposit()
Function:
        To add fund in Bank Account.
Definition:
        void deposit(char mobnum[]);
Parameters and Arguments:
        A character array is passed as argument. By comparing this array with file's data (unique mobile number),
        the function adds user entered fund to account.
Returns:
        Functions returning type void: nothing.
*/

void deposit()
    {
    FILE *fp;
    struct user user;
    int amount;
    char num[12];

    printf("\n---You Selected Cash Deposit---\n");

    printf("\nEnter your Registered Mobile Number:\n");
    scanf("%s", num);

    if (strcmp(num, user.mob) != 0)
        {
        printf("\nThe Mobile Number you entered is not registered!...\n");
        printf("Process Failed!!!...\n");
        printf("\nPress any key to Display Main Menu...!\n\n");
        getch();
        }
    else
        {
        system("cls");

        printf("CASH DEPOSIT!\n\n");
        printf("Hello! %s \n", user.name);

        printf("Enter the amount to be deposited:\n");
        scanf("%d", &amount);

        user.balance += amount;

        fp = fopen("username.txt", "wb");
        fwrite(&user,sizeof(struct user),1,fp);

        if(fwrite != 0)
            {
            printf("\n\nYou have depostied Rs.%d",amount);
            printf("\nYour Amount is Successfully Deposited\n");
            }

        fclose(fp);

        printf("\nPress any key to Display Main Menu...!\n\n");
        getch();
        }
    }

/****************************************************************************\
|
|   Function.
|
\****************************************************************************/

/*
Name: deposit()
Function:
        To withdraw fund in Bank Account.
Definition:
        void withdraw(char mobnum[]);
Parameters and Arguments:
        A character array is passed as argument. By comparing this array with file's data (unique mobile number),
        the function subtracts user entered fund from account.
Returns:
        Functions returning type void: nothing.
*/

void withdraw ()
    {
    FILE *fp;
    struct user user;
    int amount;
    char num[12];

    printf("\n---You Selected Cash Deposit---\n");

    printf("\nEnter your Registered Mobile Number:\n");
    scanf("%s", num);

    if (strcmp(num, user.mob) != 0)
        {
        printf("\nThe Mobile Number you entered is not registered!...\n");
        printf("Process Failed!!!...\n");
        printf("\nPress any key to Display Main Menu...!\n\n");
        getch();
        }
    else
        {
        system("cls");

        printf("CASH WITHDRAWL!\n\n");
        printf("Hello! %s \n", user.name);

        printf("Available Balance: %s \n", user.balance);
        printf("Enter the amount to be withdrawn:\n");
        scanf("%d", &amount);

        if (amount % 500 != 0)
            {
            printf("\nSorry amount should be multiple of 500");
            }
        else if (amount > user.balance)
            {
            printf("\nSorry insufficient balance");
            }
        else
            {
            user.balance -= amount;
            }

        fp = fopen("username.txt","w");

        fwrite(&user, sizeof(struct user), 1, fp);

        if(fwrite !=0)
            {
            printf("\n\nYou have withdrawn Rs.%d",amount);
            }
        fclose(fp);
        }
    }

/*
Name: close()
Function:
        To close a Bank Account.
Definition:
        void close(char mobnum[]);
Parameters and Arguments:
        A character array is passed as argument. By comparing this array with file's data (unique mobile number),
        the function deletes/removes that particular account from file..
Returns:
        Functions returning type void: nothing.
*/

void close()
    {
    FILE *old,*new;
    struct user user;
    int amount;
    char num[12];

    printf("\n---You Selected Account Deletion---\n");
    printf("\nEnter your Registered Mobile Number:\n");
    scanf("%s", num);

    if (strcmp(num, user.mob) != 0)
        {
        printf("\nThe Mobile Number you entered is not registered!...\n");
        printf("Process Failed!!!...\n");
        printf("\nPress any key to Display Main Menu...!\n\n");
        getch();
        }
    else
        {
        system("cls");

        printf("CLOSE ACCOUNT!\n\n");
        printf("Hello! %s \n", user.name);

        old = fopen("username.txt","r");
        new=fopen("new.txt","w");

        while (fscanf(old,"%s %s %s %s %s %s",user.name, user.mob, user.type, user.balance, user.type) != EOF)
            {
            if(strcmp(num, user.mob) != 0)
                {
                fprintf(new,"%s %s %s %s %s %s",user.name, user.mob, user.type, user.balance, user.type);
                }
            else
                {
                printf("\nAccount deleted successfully!\n");
                }
            }
        fclose(old);
        fclose(new);
        remove("username.txt");
        rename("new.txt","username.txt");
        }
    }