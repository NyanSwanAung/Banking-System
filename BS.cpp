
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <windows.h>
using namespace std;

void new_acc();
void modify_acc();
void menu();
void check_acc();
void deposit();
void close_acc();
void deleteC();
void bal_enquiry();
void withdraw();
void holder_list();
void modifyC();
void quit();
int display();

struct birthday
{
    int d, m, y;
};

struct customer
{
    long long int ph_num;
    unsigned long acc_num, age, c_num;
    long Ideposit, Fdeposit, totalD = 0;
    char name[100];
    char address[100];
    char email[100];
    char type_acc[100];
    int goback;
    struct birthday b1;
};

long pos;

int main()
{
    display();
    menu();
    return 0;
}

void menu()
{
    system("cls");
    system("color F9");
    int choice;
    cout << "\n\n\t\t\t";
    char *crea4 = "CUSTOMER ACCOUNT BANKING SYSTEM";
    for (int i = 0; i < strlen(crea4); i++)
    {
        Sleep(30);
        std::cout << crea4[i];
    }
    std::cout << endl;
    cout << "\n\n\t   ";
    cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    //char*crea5="\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    //for(int i=0;i<strlen(crea5);i++)
    //{Sleep(30);
    //std::cout<<crea5[i];
    //}
    std::cout << endl
              << endl
              << endl
              << endl;
    std::cout << "";
    std::cout << "   1.  "
              << "Create a new account\n\n";
    std::cout << "   2.  "
              << "Check the details of an account\n\n";
    std::cout << "   3.  "
              << "Deposit amount\n\n";
    std::cout << "   4.  "
              << "Withdraw amount\n\n";
    std::cout << "   5.  "
              << "Balance Enquiry\n\n";
    std::cout << "   6.  "
              << "Close an account\n\n";
    std::cout << "   7.  "
              << "View customer's list\n\n";
    std::cout << "   8.  "
              << "Exit\n\n";

    std::cout << "\t    Enter your choice:";
    std::cin >> choice;
    std::cout << endl
              << endl
              << endl
              << endl;
goback:
    while (choice <= 8 && choice != 0)
    {

        switch (choice)
        {
        case 1:
            new_acc();
            break;

            //case 2:modify_acc();
            //	       break;

        case 2:
            check_acc();
            break;

        case 3:
            deposit();
            break;

        case 4:
            withdraw();
            break;

        case 5:
            bal_enquiry();
            break;

        case 6:
            close_acc();
            break;

        case 7:
            holder_list();
            break;

        case 8:
            quit();
            break;
        }
    }
    std::cout << "\n\t     (ENTER AGAIN!): ";
    std::cin >> choice;
    goto goback;
}

void new_acc()
{
    char *crea = "  \xB2\xB2\xB2\xB2 NEW ACCOUNT ENTRY FORM \xB2\xB2\xB2\xB2";
    system("color F9");
    system("cls");
    birthday b1;
    int choiceagain;
    customer add;
    FILE *fp;

    unsigned long check;

    char ascii;
    int j = 4;
    int k = 2;
    ascii = (char)j;
    std::cout << endl
              << endl;

    for (int i = 0; i < strlen(crea); i++)
    {
        Sleep(30);
        std::cout << crea[i];
    }
    std::cout << endl;
acc_no:
    fp = fopen("Accounts.txt", "ab");
    printf("\n\n  Account Number : ");
    scanf("%ld", &check);
    fflush(stdin);
    fclose(fp);

    fp = fopen("Accounts.txt", "rb+");
    while (fread(&add, sizeof(add), 1, fp))
        ;
    {
        if (check == add.acc_num)
        {
            cout << "\n  Account Number Already in use! Try again! ";
            cout << "\n\n  ___________________________________________";
            goto acc_no;
        }
        else

            add.acc_num = check;
        fclose(fp);
    }

    fp = fopen("Accounts.txt", "ab");
    printf("\n  Name : ");
    scanf("%s", add.name);
    fflush(stdin);

    printf("\n  Date of Birth(dd/mm/yy) : ");
    scanf("%ld%ld%ld", &add.b1.d, &add.b1.m, &add.b1.y);
    fflush(stdin);

    printf("\n  Age : ");
    scanf("%ld", &add.age);
    fflush(stdin);

    printf("\n  Address : ");
    scanf("%s", add.address);
    fflush(stdin);

    printf("\n  Phone Number : ");
    cin >> add.ph_num;
    fflush(stdin);

    printf("\n  Citizenship Number : ");
    scanf("%ld", &add.c_num);
    fflush(stdin);

    printf("\n  Email : ");
    scanf("%s", add.email);
    fflush(stdin);

    printf("\n  Type of Account(teen/adult ): ");
    scanf("%s", add.type_acc);
    fflush(stdin);

    add.totalD == add.Ideposit;
    printf("\n  Initial Deposit :MMK ");
    scanf("%ld", &add.totalD);
    fwrite(&add, sizeof(add), 1, fp);
    fflush(stdin);
    fclose(fp);

    ascii = (char)k;
    char *crea1 = "   \xB2\xB2 ACCOUNT CREATED SUCCESSFULLY! \xB2\xB2 ";
    cout << endl
         << endl;
    for (int i = 0; i < strlen(crea1); i++)
    {
        Sleep(30);
        std::cout << crea1[i];
    }
    std::cout << endl;

    std::cout << "\n\n  Press any key to go back to main menu ";
    choiceagain = getch();

    if (choiceagain = 'a')
    {
        menu();
    }
    else
    {
        menu();
    }
}

void check_acc()
{
    system("cls");
    system("color F9");
    birthday b1;
    customer add;
    int test = 0;
    int choice1;
    char sname[100];
    int choiceagain;
    long sno;

    FILE *fp;
    fp = fopen("Accounts.txt", "rb+");
    char *crea2 = "\n  Do you want to check account by";
    cout << endl
         << endl;
    for (int i = 0; i < strlen(crea2) + 1; i++)
    {
        Sleep(30);
        std::cout << crea2[i];
    }
    std::cout << endl;

    std::cout << "\n \n 1.  Account number\n 2.  Name\n";
    std::cout << "\n  Enter your choice:";
    std::cin >> choice1;

    if (choice1 == 1)
    {
        printf("\n Enter Account No. : ");
        scanf("%ld", &sno);

        while (fread(&add, sizeof(add), 1, fp))
        {
            if (add.acc_num == sno)
            {

                printf("\n\n ----ACCOUNT STATUS----\n");
                std::cout << " Account Number : " << add.acc_num << endl;
                std::cout << " Name : " << add.name << endl;
                std::cout << " Birthday date : " << add.b1.d << "/" << add.b1.m << "/" << add.b1.y << endl;
                std::cout << " Age : " << add.age << endl;
                std::cout << " Address : " << add.address << endl;
                std::cout << " Citizen Number : " << add.c_num << endl;
                std::cout << " Phone Number : 0" << add.ph_num << endl;
                std::cout << " Email :" << add.email << endl;
                std::cout << " Type of account : " << add.type_acc << endl;
                std::cout << " Balance Amount :MMK " << add.totalD << endl;

                test = 1;

                std::cout << "\n\n  Press any key to go back to main menu ";
                choiceagain = getch();

                if (choiceagain = 'a')
                {
                    menu();
                }
                else
                {
                    menu();
                }

                break;
            }
        }

        fclose(fp);
    }

    else if (choice1 == 2)
    {
        printf("\n Enter your name :");
        scanf("%s", sname);

        while (fread(&add, sizeof(add), 1, fp))
        {
            if (strcmp(sname, add.name) == 0)
            {
                printf("\n\n ----ACCOUNT STATUS----\n");
                //add.totalD= add.Ideposit;
                std::cout << " Account Number : " << add.acc_num << endl;
                std::cout << " Name : " << add.name << endl;
                std::cout << " Birthday date : " << add.b1.d << "/" << add.b1.m << "/" << add.b1.y << endl;
                std::cout << " Address : " << add.address << endl;
                std::cout << " Citizen Number : " << add.c_num << endl;
                std::cout << " Phone Number : 0" << add.ph_num << endl;
                std::cout << " Email :" << add.email << endl;
                std::cout << " Type of account : " << add.type_acc << endl;
                std::cout << " Balance Amount :MMK " << add.totalD << endl;

                test = 1;

                std::cout << "\n\n  Press any key to go back to main menu ";
                choiceagain = getch();

                if (choiceagain = 'a')
                {
                    menu();
                }
                else
                {
                    menu();
                }
                break;
            }
        }
        fclose(fp);
    }

    if (test != 1)
    {
        system("cls");
        cout << "\n\n\n\n\n                               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout << "                                                            \xB2                  \xB2";
        cout << "\n                               \xB2 RECORD NOT FOUND\a\a\a \xB2\n";
        cout << "                               \xB2                  \xB2";
        cout << "\n                               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    see_invalid:
        std::cout << "\n\n  Enter 0 to try again,1 to return to main menu and 2 to exit:";
        std::cin >> choiceagain;
        system("cls");
        if (choiceagain == 0)
        {
            check_acc();
        }
        else if (choiceagain == 1)
        {
            menu();
        }
        else if (choiceagain == 2)
        {
            quit();
        }
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
}

void deposit()
{

    system("cls");
    system("color F9");
    birthday b1;
    customer add;
    char snameD[100];
    long sno;
    int choice2;
    int choiceagain;
    int test = 0;

    FILE *fp;
    fp = fopen("Accounts.txt", "rb");

    char *crea3 = "\n ==== ACCOUNT TRANSACATION FORM ==== ";
    char *text = "\n\t Record Updated";
    for (int i = 0; i < strlen(crea3); i++)
    {
        Sleep(30);
        std::cout << crea3[i];
    }
    std::cout << endl;
    std::cout << "\n\n Do you want to search the account by\n\n  1.Account number\n  2.Name\n";
    std::cout << "\n  Enter your choice : ";
    std::cin >> choice2;

    if (choice2 == 1)
    {

        printf("\n\n  Enter Account No. : ");
        scanf("%ld", &sno);

        while (fread(&add, sizeof(add), 1, fp))
        {
            if (add.acc_num == sno)
            {

                printf("\n\n ----ACCOUNT STATUS----\n");

                std::cout << "\n   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                std::cout << "\n   \xB2 Account Number : " << add.acc_num << "   \xB2" << endl;
                std::cout << "   \xB2 Name : " << add.name << "              \xB2" << endl;
                std::cout << "   \xB2 Type of account : " << add.type_acc << "   \xB2" << endl;
                std::cout << "   \xB2 Balance amount : " << add.totalD << "   \xB2" << endl;
                std::cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                pos = ftell(fp);
                fclose(fp);

                fp = fopen("Accounts.txt", "ab");

                std::cout << "\n\n   Enter the amount to deposit : MMK ";
                std::cin >> add.Fdeposit;

                add.totalD += add.Fdeposit;

                fwrite(&add, sizeof(add), 1, fp);
                fflush(fp);
                fclose(fp);
                test = 1;

                char a[sizeof(add)] = {0};
                FILE *fp = fopen("Accounts.txt", "rb+");
                fseek(fp, pos - sizeof(add), SEEK_SET);

                if (fwrite(a, sizeof(a), 1, fp))
                {
                    fflush(fp);
                }

                for (int i = 0; i < strlen(text); i++)
                {
                    Sleep(65);
                    std::cout << text[i];
                }

                std::cout << "\n\n  Press any key to go back to main menu ";
                choiceagain = getch();

                if (choiceagain = 'a')
                {
                    menu();
                }
                else
                {
                    menu();
                }
                break;
            }
        }
    }

    if (choice2 == 2)
    {

        printf("\n\n Enter your account name : ");
        scanf("%s", snameD);

        while (fread(&add, sizeof(add), 1, fp))
        {
            if (strcmp(snameD, add.name) == 0)
            {

                printf("\n\n ----ACCOUNT STATUS----\n");

                std::cout << "\n   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                std::cout << "\n   \xB2 Account Number : " << add.acc_num << "   \xB2" << endl;
                std::cout << "   \xB2 Name : " << add.name << "              \xB2" << endl;
                std::cout << "   \xB2 Type of account : " << add.type_acc << "   \xB2" << endl;
                std::cout << "   \xB2 Balance amount : " << add.totalD << "   \xB2" << endl;
                std::cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                pos = ftell(fp);
                fclose(fp);

                fp = fopen("Accounts.txt", "ab");

                std::cout << "\n\n Enter the amount to deposit : MMK ";
                std::cin >> add.Fdeposit;

                add.totalD += add.Fdeposit;

                fwrite(&add, sizeof(add), 1, fp);
                fflush(fp);
                fclose(fp);
                test = 1;

                char a[sizeof(add)] = {0};
                FILE *fp = fopen("Accounts.txt", "rb+");
                fseek(fp, pos - sizeof(add), SEEK_SET);

                if (fwrite(a, sizeof(a), 1, fp))
                {
                    fflush(fp);
                }

                for (int i = 0; i < strlen(text); i++)
                {
                    Sleep(65);
                    std::cout << text[i];
                }

                std::cout << "\n\n  Press any key to go back to main menu ";
                choiceagain = getch();

                if (choiceagain = 'a')
                {
                    menu();
                }
                else
                {
                    menu();
                }
                break;
            }
        }
    }

    if (test != 1)
    {
        system("cls");
        cout << "\n\n\n\n\n                               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout << "                                                            \xB2                  \xB2";
        cout << "\n                               \xB2 RECORD NOT FOUND\a\a\a \xB2\n";
        cout << "                               \xB2                  \xB2";
        cout << "\n                               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    see_invalid:
        std::cout << "\n\n  Enter 0 to try again,1 to return to main menu and 2 to exit:";
        std::cin >> choiceagain;
        system("cls");
        if (choiceagain == 1)
            menu();
        else if (choiceagain == 2)
            quit();
        else if (choiceagain == 0)
            deposit();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }

    fclose(fp);
}

void withdraw()
{

    system("cls");
    system("color F9");
    birthday b1;
    customer add;
    char snameD[100];
    long sno;
    int choice2;
    int choiceagain;
    int test = 0;

    FILE *fp;
    fp = fopen("Accounts.txt", "rb");

    char *in = "  Insufficient amount to withdraw";
    char *crea3 = "\n  ====ACCOUNT TRANSACATION FORM====";
    char *text = "\n\t Record Updated";

    for (int i = 0; i < strlen(crea3); i++)
    {
        Sleep(30);
        std::cout << crea3[i];
    }
    std::cout << endl;
    std::cout << "\n\n Do you want to search the account by\n\n  1.Account number\n  2.Name\n";
    std::cout << "\n  Enter your choice:";
    std::cin >> choice2;

    if (choice2 == 1)
    {
        printf("\n\n Enter Account No. : ");
        scanf("%ld", &sno);

        while (fread(&add, sizeof(add), 1, fp))
        {
            if (add.acc_num == sno)
            {

                printf("\n\n ----ACCOUNT STATUS----\n");
                std::cout << "\n   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                std::cout << "\n   \xB2 Account Number : " << add.acc_num << "   \xB2" << endl;
                std::cout << "   \xB2 Name : " << add.name << "              \xB2" << endl;
                std::cout << "   \xB2 Type of account : " << add.type_acc << "   \xB2" << endl;
                std::cout << "   \xB2 Balance amount : " << add.totalD << "   \xB2" << endl;
                std::cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                pos = ftell(fp);
                fclose(fp);

                fp = fopen("Accounts.txt", "ab");
            goback:
                std::cout << "\n\n Enter the amount to WITHDRAW : MMK ";
                std::cin >> add.Fdeposit;

                if (add.Fdeposit > add.totalD)
                {
                    cout << endl;

                    for (int i = 0; i < strlen(in); i++)
                    {
                        Sleep(30);
                        std::cout << in[i];
                    }

                    goto goback;
                }

                else
                {

                    add.totalD -= add.Fdeposit;

                    fwrite(&add, sizeof(add), 1, fp);
                    fflush(fp);
                    fclose(fp);
                    test = 1;

                    char a[sizeof(add)] = {0};
                    FILE *fp = fopen("Accounts.txt", "rb+");
                    fseek(fp, pos - sizeof(add), SEEK_SET);

                    if (fwrite(a, sizeof(a), 1, fp))
                    {
                        fflush(fp);
                    }

                    for (int i = 0; i < strlen(text); i++)
                    {
                        Sleep(65);
                        std::cout << text[i];
                    }

                    std::cout << "\n\n  Press any key to go back to main menu ";
                    choiceagain = getch();

                    if (choiceagain = 'a')
                    {
                        menu();
                    }
                    else
                    {
                        menu();
                    }
                    break;
                }
            }
        }
    }
    else if (choice2 == 2)
    {

        printf("\n\n Enter your account name : ");
        scanf("%s", snameD);

        while (fread(&add, sizeof(add), 1, fp))
        {
            if (strcmp(snameD, add.name) == 0)
            {

                printf("\n\n ----ACCOUNT STATUS----\n");
                std::cout << "\n   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                std::cout << "\n   \xB2 Account Number : " << add.acc_num << "   \xB2" << endl;
                std::cout << "   \xB2 Name : " << add.name << "              \xB2" << endl;
                std::cout << "   \xB2 Type of account : " << add.type_acc << "   \xB2" << endl;
                std::cout << "   \xB2 Balance amount : " << add.totalD << "   \xB2" << endl;
                std::cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                pos = ftell(fp);
                fclose(fp);

                fp = fopen("Accounts.txt", "ab");
            goback2:
                std::cout << "\n\n Enter the amount to WITHDRAW : MMK ";
                std::cin >> add.Fdeposit;

                if (add.Fdeposit > add.totalD)
                {
                    for (int i = 0; i < strlen(in); i++)
                    {
                        Sleep(30);
                        std::cout << in[i];
                    }

                    goto goback2;
                }

                else
                {

                    add.totalD -= add.Fdeposit;

                    fwrite(&add, sizeof(add), 1, fp);
                    fflush(fp);
                    fclose(fp);
                    test = 1;

                    char a[sizeof(add)] = {0};
                    FILE *fp = fopen("Accounts.txt", "rb+");
                    fseek(fp, pos - sizeof(add), SEEK_SET);

                    if (fwrite(a, sizeof(a), 1, fp))
                    {
                        fflush(fp);
                    }

                    for (int i = 0; i < strlen(text); i++)
                    {
                        Sleep(65);
                        std::cout << text[i];
                    }

                    std::cout << "\n\n  Press any key to go back to main menu ";
                    choiceagain = getch();

                    if (choiceagain = 'a')
                    {
                        menu();
                    }
                    else
                    {
                        menu();
                    }
                    break;
                }
            }
        }
    }
    if (test != 1)
    {
        system("cls");
        cout << "\n\n\n\n\n                               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout << "                                                            \xB2                  \xB2";
        cout << "\n                               \xB2 RECORD NOT FOUND\a\a\a \xB2\n";
        cout << "                               \xB2                  \xB2";
        cout << "\n                               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    see_invalid:
        std::cout << "\nEnter 0 to try again,1 to return to main menu and 2 to exit:";
        std::cin >> choiceagain;
        system("cls");
        if (choiceagain == 1)
            menu();
        else if (choiceagain == 2)
            quit();
        else if (choiceagain == 0)
            deposit();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }

    fclose(fp);
    std::cout << "\n\t";
    char *crea2 = "Record Updated";
    for (int i = 0; i < strlen(crea2); i++)
    {
        Sleep(30);
        std::cout << crea2[i];
    }
    std::cout << endl;
}

void bal_enquiry()

{
    system("cls");
    system("color F9");
    birthday b1;
    customer add;
    char snameD1[100];
    long sno;
    int choice3;
    int choiceagain;
    int test1 = 0;

    FILE *fp;
    fp = fopen("Accounts.txt", "rb");

    char *crea3 = "\n ====BALANCE DETAILS==== ";
    for (int i = 0; i < strlen(crea3); i++)
    {
        Sleep(30);
        std::cout << crea3[i];
    }
    std::cout << endl;
    std::cout << "\n\n\n Do you want to check account by\n\n  1.Account number\n  2.Name\n";
    std::cout << "\n  Enter your choice :";
    std::cin >> choice3;

    if (choice3 == 1)
    {
        printf("\n Enter Account No. : ");
        scanf("%ld", &sno);

        while (fread(&add, sizeof(add), 1, fp))
        {
            if (add.acc_num == sno)
            {

                printf("\n\n ----ACCOUNT RECORD----\n");

                std::cout << "\n   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                std::cout << "\n   \xB2 Account Number : " << add.acc_num << "   \xB2" << endl;
                std::cout << "   \xB2 Name : " << add.name << "              \xB2" << endl;
                std::cout << "   \xB2 Type of account : " << add.type_acc << "   \xB2" << endl;
                std::cout << "   \xB2 Balance amount : " << add.totalD << "   \xB2" << endl;
                std::cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                test1 = 1;

                std::cout << "\n\n  Press any key to go back to main menu ";
                choiceagain = getch();

                if (choiceagain = 'a')
                {
                    menu();
                }
                else
                {
                    menu();
                }
                break;
            }
        }
        fclose(fp);
    }

    else if (choice3 == 2)

    {
        printf("\n\n Enter your account name : ");
        scanf("%s", snameD1);

        while (fread(&add, sizeof(add), 1, fp))
        {
            if (strcmp(snameD1, add.name) == 0)
            {
                printf("\n\n ----ACCOUNT RECORD----\n");

                std::cout << "\n   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                std::cout << "\n   \xB2 Account Number : " << add.acc_num << "   \xB2" << endl;
                std::cout << "   \xB2 Name : " << add.name << "              \xB2" << endl;
                std::cout << "   \xB2 Type of account : " << add.type_acc << "   \xB2" << endl;
                std::cout << "   \xB2 Balance amount : " << add.totalD << "   \xB2" << endl;
                std::cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                test1 = 1;

                std::cout << "\n\n  Press any key to go back to main menu ";
                choiceagain = getch();

                if (choiceagain = 'a')
                {
                    menu();
                }
                else
                {
                    menu();
                }
                break;
            }
        }
        fclose(fp);
    }

    if (test1 != 1)
    {
        system("cls");
        cout << "\n\n\n\n\n                               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout << "                                                            \xB2                  \xB2";
        cout << "\n                               \xB2 RECORD NOT FOUND\a\a\a \xB2\n";
        cout << "                               \xB2                  \xB2";
        cout << "\n                               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";

    see_invalid:
        std::cout << "\n\n  Enter 0 to try again,1 to return to main menu and 2 to exit:";
        std::cin >> choiceagain;
        system("cls");
        if (choiceagain == 1)
            menu();
        else if (choiceagain == 2)
            quit();
        else if (choiceagain == 0)
            bal_enquiry();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
}

void holder_list()
{
    system("color F9");
    system("cls");
    birthday b1;
    customer add;
    int test2 = 0;
    FILE *fp;
    fp = fopen("Accounts.txt", "rb+");
    int choiceagain;

    cout << "\n\t\t\t      ACCOUNT HOLDER LIST  \n";
    cout << " ============================================================================\n";

    cout << setw(11) << "    Account No\t         " << setw(15) << " Name\t          " << setw(6) << "        Type\t          " << setw(7) << "Balance\n";
    cout << " ============================================================================\n\n";

    fseek(fp, -1, SEEK_SET);
    fread(&add, sizeof(add), 1, fp);
    while (!feof(fp))
    {
        if (add.acc_num != 0)
        {

            cout << "       " << setfill(' ') << setiosflags(ios::left) << setw(15) << add.acc_num;
            cout << "    " << setiosflags(ios::left) << setw(18) << add.name << "  ";
            cout << "\t  " << setfill(' ') << setw(7) << add.type_acc << "  ";
            cout << "\t" << setiosflags(ios::left) << setw(7) << " MMK " << add.totalD << "  \n";
        }

        fread(&add, sizeof(add), 1, fp);
    }
    test2 = 1;
    fclose(fp);

    if (test2 != 1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        std::cout << "\nEnter 1 to return to main menu and 2 to exit:";
        std::cin >> choiceagain;
        system("cls");
        if (choiceagain == 1)
            menu();
        else if (choiceagain == 2)
            quit();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }

    std::cout << "\n\n  Press any key to go back to main menu ";
    choiceagain = getch();

    if (choiceagain = 'a')
    {
        menu();
    }
    else
    {
        menu();
    }
}

void quit()
{

    system("cls");
    system("color F9");
    std::cout << endl
              << endl
              << endl
              << endl
              << endl
              << endl
              << endl;
    std::cout << "                           \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    std::cout << "                                                 \xB2                     \t \xB2  \n";
    std::cout << "                           \xB2 THANK YOU FOR USING OUR APP \xB2                         ";
    std::cout << "                        \xB2                             \xB2\n";
    std::cout << "                           \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    getch();
    exit(0);
}

int display()
{
    system("cls");
    system("color F9");
    cout << "\n\n\n\n\n                           -------------------------";
    cout << "\n\n\n                                      BANK";
    cout << "\n\n\n                                   MANAGEMENT";
    cout << "\n\n\n                                     SYSTEM";
    cout << "\n\n\n\n                           ---------------------------";
    cout << "\n\n                              PRESENTED BY : Group-3 ";
    cout << endl
         << endl
         << endl
         << endl
         << endl;
    getche();

    return 0;
}

void close_acc()
{
    system("cls");
    system("color F9");
    birthday b1;
    customer add;
    int test = 0;
    int choice1;
    char sname[100];
    long sno;
    int choiceagain;
    char ch3;

    char *crea3 = "\n\n  Account Deleted!";
    FILE *fp;
    fp = fopen("Accounts.txt", "rb");

    std::cout << " ----Delte Record----\n";
    std::cout << "\n Do you want to search the account by\n\n  1.Account number\n  2.Name\n";
    std::cout << "\n  Enter your choice:";
    std::cin >> choice1;

    if (choice1 == 1)
    {
        printf("\n Enter Account No. : ");
        scanf("%ld", &sno);

        while (fread(&add, sizeof(add), 1, fp))
        {
            if (add.acc_num == sno)
            {

                std::cout << "\n   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                std::cout << "\n   \xB2 Account Number : " << add.acc_num << "    \xB2" << endl;
                std::cout << "   \xB2 Name : " << add.name << "              \xB2" << endl;
                std::cout << "   \xB2 Type of account : " << add.type_acc << "  \xB2" << endl;
                std::cout << "   \xB2 Balance amount : " << add.totalD << "   \xB2" << endl;
                std::cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                test = 1;
                pos = ftell(fp);
                break;
                ;
            }
        }
        fclose(fp);
    }

    else if (choice1 == 2)
    {
        std::cout << "\n------------------------------------";
        printf("\n\n\n  Enter your name :");
        scanf("%s", sname);

        while (fread(&add, sizeof(add), 1, fp))
        {
            if (strcmp(sname, add.name) == 0)
            {
                std::cout << "\n   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                std::cout << "\n   \xB2 Account Number : " << add.acc_num << "    \xB2" << endl;
                std::cout << "   \xB2 Name : " << add.name << "              \xB2" << endl;
                std::cout << "   \xB2 Type of account : " << add.type_acc << "  \xB2" << endl;
                std::cout << "   \xB2 Balance amount : " << add.totalD << "   \xB2" << endl;
                std::cout << "   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
                test = 1;
                pos = ftell(fp);
                break;
            }
        }
    }

    if (test != 1)
    {
        system("cls");
        cout << "\n\n\n\n\n                               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout << "                                                            \xB2                  \xB2";
        cout << "\n                               \xB2 RECORD NOT FOUND\a\a\a \xB2\n";
        cout << "                               \xB2                  \xB2";
        cout << "\n                               \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    see_invalid:
        std::cout << "\n\n\n\n  Enter 0 to try again,1 to return to main menu and 2 to exit: ";
        std::cin >> choiceagain;
        system("cls");
        if (choiceagain == 1)
            menu();
        else if (choiceagain == 2)
            quit();
        else if (choiceagain == 0)
            close_acc();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }

    std::cout << "\n\n    Do you want to delete this account?(Y/N) : ";
    std::cin >> ch3;

    if (toupper(ch3) == 'Y')
    {
        deleteC();
        for (int i = 0; i < strlen(crea3); i++)
        {
            Sleep(30);
            std::cout << crea3[i];
        }

        std::cout << "\n\n  Press any key to go back to main menu ";
        choiceagain = getch();

        if (choiceagain = 'a')
        {
            menu();
        }
        else
        {
            menu();
        }
    }

    else
    {
        std::cout << "\n  Press 0 to try again, 1 to return to the main menu and 2 to exit : ";
        std::cin >> add.goback;

        if (add.goback == 0)
        {
            close_acc();
        }

        else if (add.goback == 1)
        {
            menu();
        }

        else
        {
            quit();
        }
    }
}

void deleteC()
{
    customer add;
    char a[sizeof(add)] = {0};
    FILE *del = fopen("Accounts.txt", "rb+");
    char ch2;
    fseek(del, pos - sizeof(add), SEEK_SET);

    if (fwrite(a, sizeof(a), 1, del))
    {
        fflush(del);
    }
    else
    {
        std::cout << "\nError occurred!";
        std::cout << "\n Press 0 to try again, 1 to return to the main menu and 2 to exit:";
        std::cin >> ch2;

        if (ch2 == 0)
        {
            close_acc();
        }

        else if (ch2 == 1)
        {
            menu();
        }

        else
        {
            quit();
        }
    }
}
