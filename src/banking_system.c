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
#include<math.h>

#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif

struct user
    {
    char name[25];
    char mob[15];
    char pass[15];
    char type[10];
    double balance;
    };

void open_account();
void display_details();
void deposit_fund();
void withdraw_fund();
void close_account();

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
    int ch;

    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("This is banking_system v1.1.0\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n");
    printf("It is used to create and maintain a Bank Acccount\n");
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
                open_account();
                break;
                }
            case 2:
                {
                display_details();
                break;
                }
            case 3:
                {
                deposit_fund();
                break;
                }
            case 4:
                {
                withdraw_fund();
                break;
                }
            case 5:
                {
                close_account();
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
Name: open_account()
Function:
        To get information from user and to open a Bank Account.
Definition:
        void open_account();
Returns:
        Functions returning type void: nothing.
*/

void open_account()
    {
    FILE *fp;
    struct user user;
    char filename[15];
    char ty[15];
    user.balance = 0;
    int c, ch, choice;

    system("cls");

    printf("OPEN ACCOUNT!!\n");


    while ((c = getchar()) != '\n' && c != EOF);
    printf("\n\nEnter Name:\t");
    fgets(user.name, 20, stdin);

    Number:

    printf("\n\nEnter Mobile Number:\t");

    if (scanf("%12[0123456789]", user.mob) !=1 || strlen(user.mob) != 10)
        {
        printf("\nEnter a Valid 10 digit phone number!\n");
        while ((c = getchar()) != '\n' && c != EOF);
        goto Number;
        }

    strcpy(filename, user.mob);

    if (access (strcat(filename, ".txt"), F_OK) == 0)
        {
        printf("\nThis account number is already registered.\n");
        printf("Please enter a New 10 digit mobile number to Register!\n");
        while ((c = getchar()) != '\n' && c != EOF);
        goto Number;
        }

    printf("\n\nAvailable Account Types:\n");
    printf("1. Savings Account.\n");
    printf("2. Fixed Account.\n");
    printf("3. Salary Account.\n");

    printf("\n\nChoose your Account Type [1 or 2 or 3]:\t");
    scanf("%d", &choice);

    if (choice == 1)
        {
        char ty[15] = "Savings";
        strcpy (user.type, ty);
        }
    else if (choice == 2)
        {
        char ty[15] = "Fixed";
        strcpy (user.type, ty);
        }
    else if (choice == 3)
        {
        char ty[15] = "Salary";
        strcpy (user.type, ty);
        }
    else
        {
        printf("Invalid Entry!!\n");

        getchar();
        }

    Password:

    printf("\n\nEnter a Password:\t");
    scanf("%s", user.pass);

    if (strlen(user.pass) > 10)
        {
        printf("\nPassword should be less than 10 characters!\n");
        goto Password;
        }

    fp = fopen(filename, "wb");

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
Name: display_details()
Function:
        To display a mini statement.
Definition:
        void display_details();
Returns:
        Functions returning type void: nothing.
*/

void display_details()
    {
    FILE *fp;
    struct user user;
    char num[15];
    char passwd[15];

    printf("\n---You selected Account Details---\n\n");

    printf("\nEnter your Registered Mobile Number:\n");
    scanf("%s", num);

    printf("\nEnter your Password:\n");
    scanf("%s", passwd);

    fp = fopen(strcat(num, ".txt"), "rb");

    if (fp == NULL)
        {
        printf("Account Number not registered!\n");
        }
    else
        {
        fread(&user, sizeof(user), 1, fp);

        if (strcmp (passwd, user.pass) == 0)
            {
            system("cls");
            printf("\n\nMINI STATEMENT!\n\n");

            printf("WELCOME, %s", user.name);
            printf("\n\n...........................\n");
            printf("==== YOUR ACCOUNT INFO ====\n");
            printf("***************************\n");
            printf("\nNAME: %s", user.name);

            printf("Mobile Number: %s", user.mob);

            printf("\nAccount Type: %s", user.type);

            printf("\nBalance: %.2lfRs\n\n", user.balance);
            }
        else
            {
            printf("\nIncorect Password!!.\n");
            }
        }
    fclose(fp);

    printf("Press any key to Display Main Menu...!\n\n");
    getch();
    }

/****************************************************************************\
|
|   Function.
|
\****************************************************************************/

/*
Name: deposit_fund()
Function:
        To add fund in Bank Account.
Definition:
        void deposit_fund();
Returns:
        Functions returning type void: nothing.
*/

void deposit_fund()
    {
    FILE *fp;
    struct user user;
    double amount;
    char num[15];
    char passwd[15];
    char cash[15];
    int c;

    printf("\n---You Selected Cash Deposit---\n\n");

    printf("\nEnter your Registered Mobile Number:\n");
    scanf("%s", num);

    printf("\nEnter your Password:\n");
    scanf("%s", passwd);

    fp = fopen(strcat(num, ".txt"), "rb+");

    if (fp == NULL)
        {
        printf("Account Number not registered!\n");
        }
    else
        {
        fread(&user, sizeof(user), 1, fp);

        if (strcmp(passwd, user.pass) == 0)
            {
            deposit:

            system("cls");

            printf("CASH DEPOSIT!\n\n");
            printf("Hello! %s \n", user.name);

            printf("Enter the amount to be deposited:\n");
            scanf("%12lf[0123456789]", &amount);

            //fgets(cash, 80, stdin);

            while ((c = getchar()) != '\n' && c != EOF);

            if (fmod(amount, 500) != 0)
                {
                printf("\nSorry... The amount should be a multiple of 500");
                printf("\nPress any key to redirect to CASH DEPOSIT!...");

                getch();
                goto deposit;
                }
            else if (amount > 1000000)
                {
                printf("\nSorry... The deposit amount should not exceed 10 lakhs");
                printf("\nPress any key to redirect to CASH DEPOSIT!...");

                getch();
                goto deposit;
                }
            /*else if (sscanf(cash, "%lf", &amount) == 1)
                {
                printf("\nSorry... The deposit amount should only be numbers");
                printf("\nPress any key to redirect to CASH DEPOSIT!...");

                getch();
                goto deposit;
                }*/
            else
                {
                user.balance += amount;

                fseek(fp, 0, SEEK_SET);
                fwrite(&user, sizeof(struct user), 1, fp);

                if(fwrite != 0)
                    {
                    printf("\n\nYou have successfully depostied Rs.%.2lf",amount);
                    printf("\nAvailable Balance: %.2lfRs\n", user.balance);
                    }
                }
            }
        else
            {
            printf("\nIncorect Password!!.\n");
            }
        }
    fclose(fp);

    printf("\nPress any key to Display Main Menu...!\n\n");
    getch();
    }

/****************************************************************************\
|
|   Function.
|
\****************************************************************************/

/*
Name: withdraw_fund()
Function:
        To withdraw fund in Bank Account.
Definition:
        void withdraw_fund();
Returns:
        Functions returning type void: nothing.
*/

void withdraw_fund()
    {
    FILE *fp;
    struct user user;
    double amount;
    char num[15];
    char passwd[15];

    printf("\n---You Selected Cash Withdrawal---\n");

    printf("\nEnter your Registered Mobile Number:\n");
    scanf("%s", num);

    printf("\nEnter your Password:\n");
    scanf("%s", passwd);

    fp = fopen(strcat(num, ".txt"), "rb+");

    if (fp == NULL)
        {
        printf("Account Number not registered!\n");
        }
    else
        {
        fread(&user, sizeof(user), 1, fp);

        if (strcmp(passwd, user.pass) == 0)
            {
            withdraw:

            system("cls");

            printf("CASH WITHDRAWAL!\n\n");
            printf("Hello! %s \n", user.name);

            printf("Available Balance: %.2lfRs \n", user.balance);
            printf("Enter the amount to be withdrawn:\n");
            scanf("%lf", &amount);

            if (user.balance < 500)
                {
                printf("\nSorry, Your balance is insufficient for WITHDRAWAL!");
                }
            else if (fmod(amount, 500) != 0)
                {
                printf("\nSorry... The amount should be multiple of 500");
                printf("\n\nPress any key to redirect to CASH WITHDRAWAL!...");

                getch();
                goto withdraw;
                }
            else if (amount > 1000000)
                {
                printf("\nSorry... The withdraw amount should not exceed 10 lakhs");
                printf("\n\nPress any key to redirect to CASH WITHDRAWAL!...");

                getch();
                goto withdraw;
                }
            else if (amount > user.balance)
                {
                printf("\nSorry insufficient balance!");
                printf("\nWithdraw an amount lesser than available balance...");
                printf("\n\nPress any key to redirect to CASH WITHDRAWAL!...");

                getch();
                goto withdraw;
                }
            else
                {
                user.balance -= amount;

                fseek(fp, 0, SEEK_SET);
                fwrite(&user, sizeof(struct user), 1, fp);

                if(fwrite !=0)
                    {
                    printf("\n\nYou have sucessfully withdrawn Rs.%.2lf",amount);
                    printf("\nAvailable Balance: %.2lfRs \n", user.balance);
                    }
                }
            }
        else
            {
            printf("\nIncorect Password!!.\n");
            }
        }
    fclose(fp);

    printf("\nPress any key to Display Main Menu...!\n\n");
    getch();
    }

/****************************************************************************\
|
|   Function.
|
\****************************************************************************/

/*
Name: close_account()
Function:
        To close a Bank Account.
Definition:
        void close_account();
Returns:
        Functions returning type void: nothing.
*/

void close_account()
    {
    FILE *old,*new;
    struct user user;
    int amount;
    char num[15];
    char passwd[15];
    int choice; 

    printf("\n---You Selected Account Deletion---\n");

    printf("\nEnter your Registered Mobile Number:\n");
    scanf("%s", num);

    printf("\nEnter your Password:\n");
    scanf("%s", passwd);

    old = fopen(strcat(num, ".txt"), "r");;

    if (old == NULL)
        {
        printf("\nAccount Number not registered!\n");
        }
    else
        {
        fread(&user, sizeof(user), 1, old);

        if (strcmp(passwd, user.pass) == 0)
            {
            system("cls");

            printf("CLOSE ACCOUNT!\n\n");
            printf("Hello! %s \n", user.name);

            fclose(old);

            printf("Do you really want to close your account??\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);

            switch (choice) 
                {
                case 1:
                    {
                    remove (num);
                    printf("\n\n Your Account DELETED successfully!\n");
                    break;
                    }
                case 2:
                    {
                    printf("\nAccount DELETION cancelled!!\n");
                    break;
                    }
                default:
                    {
                    printf("\nInvalid Entry!!\n\n");
                    printf("\nAccount DELETION request is cancelled!\n");
                    break;
                    }
                }
            }
        else
            {
            printf("\nIncorect Password!!\n");
            }
        }

    printf("\nPress any key to Display Main Menu...!\n");
    getch();
    }