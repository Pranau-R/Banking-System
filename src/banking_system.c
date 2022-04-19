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

struct user
    {
    char name[25];
    char mob[15];
    char pass[15];
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

        printf("\n\nAvailable Account Types:\n");
        printf("1. Savings Account.\n");
        printf("2. Fixed Account.\n");
        printf("3. Salary Account.\n");

        printf("\n\nChoose your Account Type [1 or 2 or 3]:\t");
        scanf("%d", &choice);

        printf("Choice is: %d\n", choice);

        if (choice == 1)
            {
            printf("Inside case 1.\n");
            char ty[15] = "Savings";
            strcpy (user.type, ty);
            }
        else if (choice == 2)
            {
            printf("Inside case 2.\n");
            char ty[15] = "Fixed";
            strcpy (user.type, ty);
            }
        else if (choice == 3)
            {
            printf("Inside case 3.\n");
            char ty[15] = "Salary";
            strcpy (user.type, ty);
            }
        else
            {
            printf("Invalid Entry!!\n");

            getchar();
            }
        /*switch (choice)
            {
            case 1:
                {
                printf("Inside case 1.\n");
                char ty[15] = "Savings";
                strcpy (user.type, ty);
                break;
                }
            case 2:
                {
                printf("Inside case 2.\n");
                char ty[15] = "Fixed";
                strcpy (user.type, ty);
                break;
                }
            case 3:
                {
                printf("Inside case 3.\n");
                char ty[15] = "Salary";
                strcpy (user.type, ty);
                break;
                }
            default:
                {
                printf("Invalid Entry!!\n");

                getchar();
                break;
                }
            }*/

    printf("\n\nEnter a Password:\t");
    scanf("%s", user.pass);

    strcpy(filename, user.mob);

    fp = fopen(strcat(filename, ".txt"), "wb");

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
        void display();
Returns:
        Functions returning type void: nothing.
*/

void display()
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
Name: deposit()
Function:
        To add fund in Bank Account.
Definition:
        void deposit();
Returns:
        Functions returning type void: nothing.
*/

void deposit()
    {
    FILE *fp;
    struct user user;
    double amount;
    char num[15];
    char passwd[15];

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
            scanf("%lf", &amount);

            if (fmod(amount, 500) != 0)
                {
                printf("\nSorry... The amount should be a multiple of 500");
                printf("\nPress any key to redirect to CASH DEPOSIT!...");

                getch();
                goto deposit;
                }
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
Name: deposit()
Function:
        To withdraw fund in Bank Account.
Definition:
        void withdraw();
Returns:
        Functions returning type void: nothing.
*/

void withdraw ()
    {
    FILE *fp;
    struct user user;
    double amount;
    char num[15];
    char passwd[15];

    printf("\n---You Selected Cash Withdrawl---\n");

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
            printf("CASH WITHDRAWL!\n\n");
            printf("Hello! %s \n", user.name);

            printf("Available Balance: %.2lfRs \n", user.balance);
            printf("Enter the amount to be withdrawn:\n");
            scanf("%lf", &amount);

            if (user.balance < 500)
                {
                printf("\nSorry, Your balance is insufficient for WITHDRAWL!");
                }
            else if (fmod(amount, 500) != 0)
                {
                printf("\nSorry... The amount should be multiple of 500");
                printf("\n\nPress any key to redirect to CASH WITHDRAWL!...");

                getch();
                goto withdraw;
                }
            else if (amount > user.balance)
                {
                printf("\nSorry insufficient balance!");
                printf("\nWithdraw an amount lesser than available balance...");
                printf("\n\nPress any key to redirect to CASH WITHDRAWL!...");

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
Name: close()
Function:
        To close a Bank Account.
Definition:
        void close();
Returns:
        Functions returning type void: nothing.
*/

void close()
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