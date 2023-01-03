#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>

#define XS 22
#define YS 7

struct IdenData
{
    char usr[100], pass[100];
};

struct AdminData
{
    char usr[100], pass[100];
};

struct RecordData
{
    char usr[100], name[100], location[100], type[100], num[100];
    long long int price;
};

struct RecordData r[100];
int I;

struct AdminData A[100];
int Ai;

struct IdenData a[100];
int Li;

char CurrentUser[100] = "Not Logged in";
char DelUsr[100];

void setColor(int ForgC);
void gotoxy(int x, int y);

void consoleUI();
void Welcome();
int M_opt();
void Exit_Sequence();
int view_Opt();
int User_Opt();
int Login();
void IdRead();
void SellerMenu();
void Signup();
void AddRec();
void Show_Curr_User();
void ViewAll();
void RecRead();
void AdminPanel();
int AdminVerify();
void AdminRead();
void DelRec();
void AccView();
void AccDel();
int QueryMenu();
void VBP();
void RD();
void mm();
void um();
void sm();
void vm();
void qm();
void am();


int main()
{
    consoleUI();
    gotoxy(XS+14, YS);
    printf("> WELCOME TO THE REAL-ESTATE ADVISOR APP <");
    gotoxy(XS+20, YS+2);
    system("pause");

    int inp, inp2, inp1, inp3, inp4, logRet;

    /// -----------Main Option Section-----------

    while(1)
    {
        inp = M_opt();

        if(inp == 1)
        {
            while(1)
            {
                inp1 = User_Opt();
                if(inp1 == 1)
                {
                    logRet = Login();

                    if(logRet == 1)
                    {
                        SellerMenu();
                    }
                    else
                    {
                        system("cls");
                        consoleUI();
                        gotoxy(XS+29, YS + 1);
                        printf("Login failed.");
                        gotoxy(XS+20, YS + 3);
                        system("pause");
                    }

                }
                else if(inp1 == 2)
                {
                    Signup();
                }
                else if(inp1 == 3)
                {
                    break;
                }
            }
        }
        else if(inp == 2)
        {
            while(1)
            {
                inp2 = view_Opt();
                if(inp2 == 1)
                {
                    ViewAll();
                }
                else if(inp2 == 2)
                {
                    while(1)
                    {
                        inp4 = QueryMenu();
                        if(inp4 == 1)
                        {
                            VBP();
                        }
                        else if(inp4 == 2)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            consoleUI();

                            printf("Wrong parameter. Try again.");
                            gotoxy(XS, YS + 1);
                            system("pause");
                        }
                    }


                }
                else if(inp2 == 3)
                {
                    break;
                }
            }
        }
        else if(inp == 3)
        {
            inp3 = AdminVerify();

            if(inp3 == 1)
            {
                AdminPanel();
            }
        }
        else if(inp == 4)
        {
            Exit_Sequence();
            break;
        }
        else
        {
            system("cls");
            consoleUI();

            printf("Wrong parameter. Try again.");
            gotoxy(XS, YS + 1);
            system("pause");
        }
    }

    ///-----------Main Option Section End--------------


    return 0;
}

void VBP()
{

    system("cls");
    consoleUI();

    long long int min, max;
    int i, j, k;
    struct RecordData R[100];

    printf("============================> View by price <===========================");
    gotoxy(XS + 28, YS + 3);
    printf("Minimum price: ");
    scanf("%lld", &min);

    gotoxy(XS + 28, YS + 4);
    printf("Maximum price: ");
    scanf("%lld", &max);

    RecRead();
    for(i = 0, j = 0 ; i < I ; i++)
    {
        if(r[i].price >= min && r[i].price <= max)
        {
            strcpy(R[j].usr, r[i].usr);
            strcpy(R[j].name, r[i].name);
            strcpy(R[j].location, r[i].location);
            strcpy(R[j].type, r[i].type);
            strcpy(R[j].num, r[i].num);
            R[j].price = r[i].price;
            j++;
        }
    }

    if(j == 0)
    {
        system("cls");
        consoleUI();

        printf("No lands of this price range exists.");
        gotoxy(XS, YS + 1);
        system("pause");
        return;
    }

    k = 0;
    while(1)
    {
        system("cls");
        consoleUI();

        printf("=============================> by Price <===============================");

        gotoxy(XS + 3, YS + 2);
        setColor(11);
        printf("Use the Left and Right arrow keys to navigate. Press Enter to exit.");

        gotoxy(XS + 50, YS + 4);
        setColor(6);
        printf("land(s) for sale: %d", j);
        setColor(15);

        setColor(14);
        gotoxy(XS+23, YS+7);
        printf("Owner: %s", R[k].name);
        gotoxy(XS+23, YS + 9);
        printf("Location: %s", R[k].location);
        gotoxy(XS+23, YS + 11);
        printf("Type: %s", R[k].type);
        gotoxy(XS+23, YS + 13);
        printf("Price:  $%lld", R[k].price);
        gotoxy(XS+23, YS + 15);
        printf("Contact No.: %s", R[k].num);
        setColor(15);

        gotoxy(XS+63, YS + 17);
        printf("Page: %d", k+1);

        if(getch() == 224)
        {
            switch(getch())
            {
                case 75: ///Left
                    k--;
                    break;
                case 77: ///Right
                    k++;
                    break;
            }
        }
        else
        {
            break;
        }

        if(k < 0)
        {
            k = 0;
        }
        else if(k >= j)
        {
            k = j - 1;
        }

    }

}

void qm()
{
    system("cls");
    consoleUI();

    printf("================================> View by <=============================");
    gotoxy(XS + 28, YS + 3);
    printf("1.VIEW BY PRICE RANGE");
    gotoxy(XS + 28, YS + 5);
    printf("2.EXIT");
}

int QueryMenu()
{
    int inp = 1;
    qm();

    while(1)
    {
        if(inp == 1)
            {
                gotoxy(XS + 50 , YS + 5);
                printf(" ");
                gotoxy(XS + 50 , YS + 3);
                printf("<");

            }
            else if(inp == 2)
            {
                gotoxy(XS + 50 , YS + 3);
                printf(" ");
                gotoxy(XS + 50 , YS + 5);
                printf("<");


            }

            if(getch() == 224)
            {
                switch(getch())
                {
                    case 80:
                        inp++;
                        break;
                    case 72:
                        inp--;
                        break;
                }
            }
            else
            {
                return inp;
            }

            if(inp < 1)
            {
                inp = 1;
            }
            if(inp > 2)
            {
                inp = 2;
            }
    }



}

void AccDel()
{
    system("cls");
    consoleUI();

    struct IdenData R[100];

    IdRead();
    int i, j, f = 0, d = 0, ii;

    i = 0;

    if(Li == 0)
    {
        system("cls");
        consoleUI();

        printf("No Accounts to delete. ");
        system("pause");
        return;
    }

    while(1)
    {
        system("cls");
        consoleUI();

        printf("===========================> Delete Account <===========================");

        gotoxy(XS + 3, YS + 2);
        setColor(11);
        printf("Use the Left and Right arrow keys to navigate and press the down ");
        gotoxy(XS + 3, YS + 3);
        printf("arrow key to delete. Press Enter to exit.");

        gotoxy(XS + 50, YS + 5);
        setColor(6);
        printf("No. of Accounts: %d", Li);
        setColor(15);

        setColor(14);
        gotoxy(XS+23, YS+7);
        printf("Username: %s", a[i].usr);
        gotoxy(XS+23, YS + 9);
        printf("Password: %s", a[i].pass);
        setColor(15);

        gotoxy(XS+63, YS + 16);
        printf("Page: %d", i+1);

        if(getch() == 224)
        {
            switch(getch())
            {
                case 75: ///Left
                    i--;
                    break;
                case 77: ///Right
                    i++;
                    break;
                case 80:
                    d = 1;
                    break;
            }
        }
        else
        {
            break;
        }

        if(i < 0)
        {
            i = 0;
        }
        else if(i >= Li)
        {
            i = Li - 1;
        }

        ii = i;

        if(d == 1)
        {
            system("cls");
            consoleUI();

            IdRead();
            FILE *fw = fopen("LoginDB.txt", "w");

            int k;
            for(k = 0 ; k < Li ; k++)
            {
                if(strcmp(a[k].usr, a[ii].usr) == 0 && strcmp(a[k].pass, a[ii].pass) == 0)
                {
                    strcpy(DelUsr, a[k].usr);
                    RD();
                    printf("Record Deleted.");
                    gotoxy(XS, YS + 1);
                    system("pause");
                }
                else
                {
                    fprintf(fw , "%s\n", a[k].usr);
                    fprintf(fw , "%s\n", a[k].pass);
                }
            }

            fclose(fw);

            d = 0;

            break;

        }

    }
}

void RD()
{
    RecRead();

    FILE *fw = fopen("RecordDB.txt", "w");
    int i;
    for(i = 0 ; i < I ; i++)
    {
        if(strcmp(DelUsr, r[i].usr) == 0)
        {
            continue;
        }
        else
        {
            fprintf(fw , "%s\n", r[i].usr);
            fprintf(fw , "%s\n", r[i].name);
            fprintf(fw , "%s\n", r[i].location);
            fprintf(fw , "%s\n", r[i].type);
            fprintf(fw , "%lld\n", r[i].price);
            fprintf(fw , "%s\n", r[i].num);
        }
    }
    fclose(fw);
}

void DelRec()
{
    system("cls");
    consoleUI();

    struct RecordData R[100];

    RecRead();
    int i, j, f = 0, d = 0, ii;
    for(i = 0, j = 0, f = 0 ; i < I ; i++)
    {
        if(strcmp(CurrentUser, r[i].usr) == 0)
        {
            strcpy(R[j].usr, r[i].usr);
            strcpy(R[j].name, r[i].name);
            strcpy(R[j].location, r[i].location);
            strcpy(R[j].type, r[i].type);
            strcpy(R[j].num, r[i].num);
            R[j].price = r[i].price;
            j++;
            f = 1;
        }
    }

    if(f == 0)
    {
        system("cls");
        consoleUI();
        gotoxy(XS+15, YS);
        printf("You don't have any land posted for sale.");
        gotoxy(XS+19, YS + 1);
        system("pause");
        return;
    }

    i = 0;

    while(1)
    {
        system("cls");
        consoleUI();

        printf("========================> Your Lands for Sale <=========================");

        gotoxy(XS + 3, YS + 2);
        setColor(11);
        printf("Use the Left and Right arrow keys to navigate and press the down ");
        gotoxy(XS + 3, YS + 3);
        printf("arrow key to delete. Press Enter to exit.");

        gotoxy(XS + 50, YS + 5);
        setColor(6);
        printf("land(s) for sale: %d", j);
        setColor(15);

        setColor(14);
        gotoxy(XS+23, YS+7);
        printf("Owner: %s", R[i].name);
        gotoxy(XS+23, YS + 9);
        printf("Location: %s", R[i].location);
        gotoxy(XS+23, YS + 11);
        printf("Type: %s", R[i].type);
        gotoxy(XS+23, YS + 13);
        printf("Price: $%lld", R[i].price);
        gotoxy(XS+23, YS + 15);
        printf("Contact No.: %s", R[i].num);
        setColor(15);

        gotoxy(XS+63, YS + 17);
        printf("Page: %d", i+1);

        if(getch() == 224)
        {
            switch(getch())
            {
                case 75: ///Left
                    i--;
                    break;
                case 77: ///Right
                    i++;
                    break;
                case 80:
                    d = 1;
                    break;
            }
        }
        else
        {
            break;
        }

        if(i < 0)
        {
            i = 0;
        }
        else if(i >= j)
        {
            i = j - 1;
        }

        ii = i;

        if(d == 1)
        {
            system("cls");
            consoleUI();

            RecRead();
            FILE *fw = fopen("RecordDB.txt", "w");

            int k;
            for(k = 0 ; k < I ; k++)
            {
                if(strcmp(R[ii].usr, r[k].usr) == 0 && strcmp(R[ii].name, r[k].name) == 0 && strcmp(R[ii].location, r[k].location) == 0 && strcmp(R[ii].type, r[k].type) == 0 && strcmp(R[ii].num, r[k].num) == 0)
                {
                    gotoxy(XS+28, YS + 1);
                    printf("Record Deleted.");
                    gotoxy(XS+22, YS + 3);
                    system("pause");
                }
                else
                {
                    fprintf(fw , "%s\n", r[k].usr);
                    fprintf(fw , "%s\n", r[k].name);
                    fprintf(fw , "%s\n", r[k].location);
                    fprintf(fw , "%s\n", r[k].type);
                    fprintf(fw , "%lld\n", r[k].price);
                    fprintf(fw , "%s\n", r[k].num);

                }
            }

            fclose(fw);


            d = 0;

            break;

        }

    }


}

void am()
{
    system("cls");
    consoleUI();

    printf("============================> ADMIN PANEL <=============================");
    gotoxy(XS + 27, YS + 3);
    printf("1.VIEW EXISTING ACCOUNTS");
    gotoxy(XS + 27, YS + 5);
    printf("2.REMOVE AN ACCOUNT");
    gotoxy(XS + 27, YS + 7);
    printf("3.LOGOUT");
}

void AdminPanel()
{
    int inp = 1;

    while(1)
    {
        am();
        while(1)
        {
            if(inp == 1)
            {
                gotoxy(XS + 52 , YS + 7);
                printf(" ");
                gotoxy(XS + 52 , YS + 5);
                printf(" ");
                gotoxy(XS + 52 , YS + 3);
                printf("<");

            }
            else if(inp == 2)
            {
                gotoxy(XS + 52 , YS + 7);
                printf(" ");
                gotoxy(XS + 52 , YS + 3);
                printf(" ");
                gotoxy(XS + 52 , YS + 5);
                printf("<");
            }
            else if(inp == 3)
            {
                gotoxy(XS + 52 , YS + 3);
                printf(" ");
                gotoxy(XS + 52 , YS + 5);
                printf(" ");
                gotoxy(XS + 52 , YS + 7);
                printf("<");
            }

            if(getch() == 224)
            {
                switch(getch())
                {
                    case 80:
                        inp++;
                        break;
                    case 72:
                        inp--;
                        break;
                }
            }
            else
            {
                break;
            }

            if(inp < 1)
            {
                inp = 1;
            }
            if(inp > 3)
            {
                inp = 3;
            }
        }

        if(inp == 1)
        {
            AccView();
        }
        else if(inp == 2)
        {
            AccDel();
        }
        else if(inp == 3)
        {
            strcpy(CurrentUser, "Not Logged in");
            break;
        }

    }

}

int AdminVerify()
{
    char username[100], password[100], in;
    int i, f = 0;


    while(1)
    {
        system("cls");
        consoleUI();

        printf("========================> ADMIN VERIFICATION <==========================");

        gotoxy(XS + 20, YS + 2);
        printf("Username(No spaces): ");
        scanf("%s", username);

        gotoxy(XS + 20 , YS + 4);
        printf("Password: ");
        scanf(" %s", password);

        AdminRead();

        for(i = 0 ; i < Ai ; i++)
        {
            if((strcmp(username, A[i].usr) == 0) && (strcmp(password, A[i].pass) == 0))
            {
                f = 1;
                break;
            }
        }

        if(f == 1)
        {
            strcpy(CurrentUser, "ADMIN");
            system("cls");
            consoleUI();
            gotoxy(XS+20, YS + 1);
            printf("Successfully logged in.");
            gotoxy(XS+20, YS + 3);
            system("pause");


            return 1;
        }
        else
        {
            system("cls");
            consoleUI();
            gotoxy(XS+4, YS);
            printf("Wrong credentials or Account with this username does not exist.");
            gotoxy(XS+18, YS + 2);
            printf("Would you like to try again?[Y/N]");
            gotoxy(XS+28, YS + 4);
            printf("---> ");
            scanf(" %c", &in);

            if(in == 'N' || in == 'n')
            {
                return 0;
            }
            else if(in == 'Y' || in == 'y')
            {
                continue;
            }
            else
            {
                gotoxy(XS+17, YS + 6);
                printf("Wrong parameter. Defaulted to 'No'");
                gotoxy(XS+18, YS + 8);
                system("pause");
                return 0;
                break;
            }

        }
    }

}

void AdminRead()
{
    FILE *fr = fopen("AdminDB.txt", "r");

    int i = 0;

    while(fscanf(fr, "%s", A[i].usr) != EOF)
    {
        fscanf(fr, " %s", A[i].pass);
        i++;
    }
    fclose(fr);

    Ai = i;
}

void AccView()
{
    system("cls");
    consoleUI();

    IdRead();

    int i = 0;

    if(Li == 0)
    {
        gotoxy(XS+24, YS + 1);
        printf("No Accounts registered yet.");
        gotoxy(XS+20, YS + 3);
        system("pause");
        return;
    }

    while(1)
    {
        system("cls");
        consoleUI();

        printf("=============================> Accounts <===============================");

        gotoxy(XS + 3, YS + 2);
        setColor(11);
        printf("Use the Left and Right arrow keys to navigate. Press Enter to exit.");

        gotoxy(XS + 50, YS + 4);
        setColor(6);
        printf("Registered account: %d", Li);
        setColor(15);

        setColor(14);
        gotoxy(XS+23, YS+7);
        printf("Username: %s", a[i].usr);
        gotoxy(XS+23, YS + 9);
        printf("Password: %s", a[i].pass);
        setColor(15);

        gotoxy(XS+63, YS + 16);
        printf("Page: %d", i+1);

        if(getch() == 224)
        {
            switch(getch())
            {
                case 75: ///Left
                    i--;
                    break;
                case 77: ///Right
                    i++;
                    break;
            }
        }
        else
        {
            break;
        }

        if(i < 0)
        {
            i = 0;
        }
        else if(i >= Li)
        {
            i = Li - 1;
        }


    }

}

void ViewAll()
{
    system("cls");
    consoleUI();

    RecRead();

    int i = 0;

    if(I == 0)
    {
        gotoxy(XS+3, YS );
        printf("Sorry :( , We have nothing to sell. Please excuse the inconvenience.");
        gotoxy(XS+15, YS + 2);
        system("pause");
        return;
    }

    while(1)
    {
        system("cls");
        consoleUI();

        printf("==============================> Market <================================");

        gotoxy(XS + 3, YS + 2);
        setColor(11);
        printf("Use the Left and Right arrow keys to navigate. Press Enter to exit.");

        gotoxy(XS + 50, YS + 4);
        setColor(6);
        printf("land(s) for sale: %d", I);
        setColor(15);

        setColor(14);
        gotoxy(XS+23, YS+7);
        printf("Owner: %s", r[i].name);
        gotoxy(XS+23, YS + 9);
        printf("Location: %s", r[i].location);
        gotoxy(XS+23, YS + 11);
        printf("Type: %s", r[i].type);
        gotoxy(XS+23, YS + 13);
        printf("Price:  $%lld", r[i].price);

        gotoxy(XS+23, YS + 15);
        printf("Contact No.: %s", r[i].num);
        setColor(15);

        gotoxy(XS+63, YS + 17);
        printf("Page: %d", i+1);

        if(getch() == 224)
        {
            switch(getch())
            {
                case 75: ///Left
                    i--;
                    break;
                case 77: ///Right
                    i++;
                    break;
            }
        }
        else
        {
            break;
        }

        if(i < 0)
        {
            i = 0;
        }
        else if(i >= I)
        {
            i = I - 1;
        }


    }
}

void RecRead()
{
    FILE *fr = fopen("RecordDB.txt", "r");

    int i = 0;
    while(fscanf(fr, "%s", r[i].usr) != EOF)
    {
        fscanf(fr, " %[^\n]", r[i].name);
        fscanf(fr, " %[^\n]", r[i].location);
        fscanf(fr, " %[^\n]", r[i].type);
        fscanf(fr, "%lld", &r[i].price);
        fscanf(fr, " %[^\n]", r[i].num);

        i++;
    }

    fclose(fr);

    I = i;
}

void Show_Curr_User()
{
    gotoxy(XS + 45, YS - 3);

    if(strcmp(CurrentUser, "Not Logged in") == 0)
    {
        printf("Current user : ");
        setColor(4);
        printf("%s", CurrentUser);
        setColor(15);
    }
    else if(strcmp(CurrentUser, "ADMIN") == 0)
    {
        printf("Current user : ");
        setColor(5);
        printf("%s", CurrentUser);
        setColor(15);
    }
    else
    {
        printf("Current user : ");
        setColor(2);
        printf("%s", CurrentUser);
        setColor(15);
    }
}

void AddRec()
{
    system("cls");
    consoleUI();

    struct RecordData rr[10];

    printf("=============================> ADD RECORDS <============================");
    gotoxy(XS + 1, YS + 2);
    printf("There are 5 main types of land: Residential, Commercial, Industrial, ");
    gotoxy(XS + 1, YS + 3);
    printf("Raw land and Special use. Make sure not use outside these types.");
    gotoxy(XS + 1, YS + 5);
    printf("Enter your full name: ");
    scanf(" %[^\n]", rr[1].name);
    gotoxy(XS + 1, YS + 7);
    printf("Enter location: ");
    scanf(" %[^\n]", rr[1].location);
    gotoxy(XS + 1, YS + 9);
    printf("Enter the type: ");
    scanf(" %[^\n]", rr[1].type);
    gotoxy(XS + 1, YS + 11);
    printf("Enter the price: ");
    scanf("%lld", &rr[1].price);
    gotoxy(XS + 1, YS + 13);
    printf("Enter your number: ");
    scanf(" %[^\n]", rr[1].num);

    FILE *fw = fopen("RecordDB.txt", "a");

    fprintf(fw , "%s\n", CurrentUser);
    fprintf(fw , "%s\n", rr[1].name);
    fprintf(fw , "%s\n", rr[1].location);
    fprintf(fw , "%s\n", rr[1].type);
    fprintf(fw , "%lld\n", rr[1].price);
    fprintf(fw , "%s\n", rr[1].num);

    fclose(fw);

    gotoxy(XS + 1, YS + 15);
    printf("Record successfully placed in the market.");
    gotoxy(XS + 1, YS + 16);
    system("pause");
}

void Signup()
{
    char usr[100], pass[100];
    int i;

    A:
    system("cls");
    consoleUI();

    printf("============================> SIGN-UP MENU <============================");
    gotoxy(XS + 10, YS + 3);
    printf("Enter your desired username(no-space): ");
    scanf("%s", usr);
    gotoxy(XS + 10, YS + 5);
    printf("Enter a password(no-spaces): ");
    scanf(" %s", pass);

    IdRead();

    for(i = 0 ; i < Li ; i++)
    {
        if(strcmp(usr, a[i].usr) == 0)
        {
            system("cls");
            consoleUI();
            gotoxy(XS+15, YS + 1);
            printf("This username already exists. Try again.");
            gotoxy(XS+15, YS + 3);
            system("pause");
            goto A;
        }
    }

    FILE *fw = fopen("LoginDB.txt", "a");

    fprintf(fw, "%s\n", usr);
    fprintf(fw, "%s\n", pass);

    fclose(fw);

    system("cls");
    consoleUI();
    gotoxy(XS + 10, YS + 3);
    printf("Account successfully created. Login to access features.");
    gotoxy(XS + 21, YS + 5);
    system("pause");
}

void sm()
{
    system("cls");
    consoleUI();

    printf("============================> SELLER MENU <=============================");
    gotoxy(XS + 27, YS + 3);
    printf("1.ADD RECORD.");
    gotoxy(XS + 27, YS + 5);
    printf("2.DELETE RECORD.");
    gotoxy(XS + 27, YS + 7);
    printf("3.VIEW CURRENT MARKET.");
    gotoxy(XS + 27, YS + 9);
    printf("4.lOGOUT");
}

void SellerMenu()
{
    int inp = 1;

    while(1)
    {
        sm();
        while(1)
        {
            if(inp == 1)
            {
                gotoxy(XS + 50 , YS + 9);
                printf(" ");
                gotoxy(XS + 50 , YS + 7);
                printf(" ");
                gotoxy(XS + 50 , YS + 5);
                printf(" ");
                gotoxy(XS + 50 , YS + 3);
                printf("<");

            }
            else if(inp == 2)
            {
                gotoxy(XS + 50 , YS + 9);
                printf(" ");
                gotoxy(XS + 50 , YS + 7);
                printf(" ");
                gotoxy(XS + 50 , YS + 3);
                printf(" ");
                gotoxy(XS + 50 , YS + 5);
                printf("<");

            }
            else if(inp == 3)
            {
                gotoxy(XS + 50 , YS + 9);
                printf(" ");
                gotoxy(XS + 50 , YS + 3);
                printf(" ");
                gotoxy(XS + 50 , YS + 5);
                printf(" ");
                gotoxy(XS + 50 , YS + 7);
                printf("<");

            }
            else if(inp == 4)
            {
                gotoxy(XS + 50 , YS + 3);
                printf(" ");
                gotoxy(XS + 50 , YS + 7);
                printf(" ");
                gotoxy(XS + 50 , YS + 5);
                printf(" ");
                gotoxy(XS + 50 , YS + 9);
                printf("<");

            }

            if(getch() == 224)
            {
                switch(getch())
                {
                    case 80:
                        inp++;
                        break;
                    case 72:
                        inp--;
                        break;
                }
            }
            else
            {
                break;
            }

            if(inp < 1)
            {
                inp = 1;
            }
            if(inp > 4)
            {
                inp = 4;
            }
        }

        if(inp == 1)
        {
            AddRec();
        }
        else if(inp == 2)
        {
            DelRec();
        }
        else if(inp == 3)
        {
            ViewAll();
        }
        else if(inp == 4)
        {
            strcpy(CurrentUser, "Not Logged in");
            break;
        }
        else
        {
            system("cls");
            consoleUI();

            printf("Wrong parameter. Try again.");
            gotoxy(XS, YS + 1);
            system("pause");
        }
    }


}

int Login()
{
    char username[100], password[100], in;
    int i, f = 0;

    while(1)
    {
        system("cls");
        consoleUI();

        printf("===============================> Login <================================");
        gotoxy(XS + 4, YS + 2);
        printf("Enter your Username(No spaces): ");
        scanf("%s", username);

        gotoxy(XS + 4 , YS + 4);
        printf("Enter your Password: ");
        scanf(" %s", password);

        IdRead();

        for(i = 0, f = 0 ; i < Li ; i++)
        {
            if(strcmp(username, a[i].usr) == 0 && strcmp(password, a[i].pass) == 0)
            {
                f = 1;
                break;
            }
        }

        if(f == 1)
        {
            strcpy(CurrentUser, a[i].usr);
            system("cls");
            consoleUI();
            gotoxy(XS+21, YS+1);
            printf("You have successfully logged in.");
            gotoxy(XS+21, YS + 3);
            system("pause");


            return 1;
        }
        else
        {
            system("cls");
            consoleUI();
            gotoxy(XS+5, YS + 1);
            printf("Wrong credentials or Account with this username does not exist.");
            gotoxy(XS+18, YS + 3);
            printf("Would you like to try again? [Y/N] ");
            gotoxy(XS+27, YS + 5);
            printf("---> ");
            scanf(" %c", &in);

            if(in == 'N' || in == 'n')
            {
                return 0;
            }
            else if(in == 'Y' || in == 'y')
            {
                continue;
            }
            else
            {
                gotoxy(XS+18, YS + 7);
                printf("Wrong parameter. Defaulted to 'No'");
                gotoxy(XS+18, YS + 9);
                system("pause");
                return 0;
            }

        }
    }

}

void IdRead()
{
    FILE *fr = fopen("LoginDB.txt", "r");

    int i = 0;
    while(fscanf(fr, "%s ", a[i].usr) != EOF)
    {
        fscanf(fr, "%s", a[i].pass);
        i++;
    }

    Li = i;

    fclose(fr);
}

void um()
{
    system("cls");
    consoleUI();

    gotoxy(XS, YS);
    printf("============================> Validation <==============================");
    gotoxy(XS + 28, YS + 3);
    printf("1.LOGIN");
    gotoxy(XS + 28, YS + 5);
    printf("2.SIGNUP");
    gotoxy(XS + 28, YS + 7);
    printf("3.EXIT");
}

int User_Opt()
{
    int inp = 1;
    um();

    while(1)
    {
        if(inp == 1)
        {
            gotoxy(XS + 43 , YS + 7);
            printf(" ");
            gotoxy(XS + 43 , YS + 5);
            printf(" ");
            gotoxy(XS + 43 , YS + 3);
            printf("<");
        }
        else if(inp == 2)
        {
            gotoxy(XS + 43 , YS + 7);
            printf(" ");
            gotoxy(XS + 43 , YS + 3);
            printf(" ");
            gotoxy(XS + 43 , YS + 5);
            printf("<");
        }
        else if(inp == 3)
        {
            gotoxy(XS + 43 , YS + 3);
            printf(" ");
            gotoxy(XS + 43 , YS + 5);
            printf(" ");
            gotoxy(XS + 43 , YS + 7);
            printf("<");
        }

        if(getch() == 224)
        {
            switch(getch())
            {
                case 80:
                    inp++;
                    break;
                case 72:
                    inp--;
                    break;
            }
        }
        else
        {
            return inp;
        }

        if(inp < 1)
        {
            inp = 1;
        }
        if(inp > 3)
        {
            inp = 3;
        }
    }

}

void vm()
{
    system("cls");
    consoleUI();

    printf("=============================> Buyer Menu <=============================");
    gotoxy(XS + 28, YS + 3);
    printf("1.VIEW ALL");
    gotoxy(XS + 28, YS + 5);
    printf("2.VIEW BY QUERY");
    gotoxy(XS + 28, YS + 7);
    printf("3.EXIT");
}

int view_Opt()
{
    int inp = 1;

    vm();

    while(1)
    {
        if(inp == 1)
        {

            gotoxy(XS + 44 , YS + 7);
            printf(" ");
            gotoxy(XS + 44 , YS + 5);
            printf(" ");
            gotoxy(XS + 44 , YS + 3);
            printf("<");

        }
        else if(inp == 2)
        {

            gotoxy(XS + 44 , YS + 7);
            printf(" ");
            gotoxy(XS + 44 , YS + 3);
            printf(" ");
            gotoxy(XS + 44 , YS + 5);
            printf("<");
        }
        else if(inp == 3)
        {

            gotoxy(XS + 44 , YS + 3);
            printf(" ");
            gotoxy(XS + 44 , YS + 5);
            printf(" ");
            gotoxy(XS + 44 , YS + 7);
            printf("<");
        }

        if(getch() == 224)
        {
            switch(getch())
            {
                case 80:
                    inp++;
                    break;
                case 72:
                    inp--;
                    break;
            }
        }
        else
        {
            return inp;
        }

        if(inp < 1)
        {
            inp = 1;
        }
        if(inp > 3)
        {
            inp = 3;
        }
    }


    return inp;
}

void Exit_Sequence()
{
    system("cls");
    consoleUI();
    gotoxy(XS+20, YS+1);
    printf("THANK YOU FOR USING OUR APP.");
    gotoxy(XS+25, YS+3);
    printf("HAVE GOOD DAY! :)");
    sleep(2);
    system("cls");

}

void mm()
{
    system("cls");
    consoleUI();

    printf("=============================> MAIN MENU <==============================");
    gotoxy(XS + 28, YS + 3);
    printf("1.SELLER MENU");
    gotoxy(XS + 28, YS + 5);
    printf("2.BUYER MENU");
    gotoxy(XS + 28, YS + 7);
    printf("3.ADMIN");
    gotoxy(XS + 28, YS + 9);
    printf("4.QUIT PROGRAM");
}

int M_opt()
{
    int inp = 1;
    mm();

    while(1)
    {
        if(inp == 1)
        {
            gotoxy(XS + 43 , YS + 9);
            printf(" ");
            gotoxy(XS + 43 , YS + 7);
            printf(" ");
            gotoxy(XS + 43 , YS + 5);
            printf(" ");
            gotoxy(XS + 43 , YS + 3);
            printf("<");
        }
        else if(inp == 2)
        {
            gotoxy(XS + 43 , YS + 9);
            printf(" ");
            gotoxy(XS + 43 , YS + 7);
            printf(" ");
            gotoxy(XS + 43 , YS + 3);
            printf(" ");
            gotoxy(XS + 43 , YS + 5);
            printf("<");
        }
        else if(inp == 3)
        {
            gotoxy(XS + 43 , YS + 9);
            printf(" ");
            gotoxy(XS + 43 , YS + 3);
            printf(" ");
            gotoxy(XS + 43 , YS + 5);
            printf(" ");
            gotoxy(XS + 43 , YS + 7);
            printf("<");
        }
        else if(inp == 4)
        {
            gotoxy(XS + 43 , YS + 3);
            printf(" ");
            gotoxy(XS + 43 , YS + 7);
            printf(" ");
            gotoxy(XS + 43 , YS + 5);
            printf(" ");
            gotoxy(XS + 43 , YS + 9);
            printf("<");
        }

        if(getch() == 224)
        {
            switch(getch())
            {
                case 80:
                    inp++;
                    break;
                case 72:
                    inp--;
                    break;
            }
        }
        else
        {
            return inp;
        }

        if(inp < 1)
        {
            inp = 1;
        }
        if(inp > 4)
        {
            inp = 4;
        }


    }

}

void consoleUI()
{
    int x, y;
    for(x = 20, y = 5 ; x <= 95 ; x++) /// Top Border
    {
        setColor(3);
        gotoxy(x, y);
        printf("%c", 219);
    }

    for(x = 20, y = 5 ; y <= 25 ; y++) /// Left Border
    {
        gotoxy(x, y);
        printf("%c", 219);
    }

    for(x = 20, y = 25 ; x < 96 ; x++) /// Bottom Border
    {
        gotoxy(x, y);
        printf("%c", 219);
    }

    for(x = 95, y = 5 ; y <= 25 ; y++) /// Right Border
    {
        gotoxy(x, y);
        printf("%c", 219);
    }
    
    setColor(6);

    Show_Curr_User();

    gotoxy(22, 7);
    //getch();
    setColor(15);
    //gotoxy(NULL, 27);
}

void setColor(int ForgC){

    //We will need this handle to get the current background attribute
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    //we use csbi for the wAttributes word.
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        //Mask out all but the background attribute
        //, and add in the foreground color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void gotoxy(int x, int y)
{
    COORD c = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}