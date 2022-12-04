#include <stdio.h>

#include <conio.h>

#include <string.h>

struct log_in
{
    char user_Name[30], password[30];
};

typedef struct log_in L;

L log_of_user[200];

unsigned int number_of_users;



void read_Data();

void sign_up();

void sign_in();

void write_Data();



void read_Data()
{
    FILE *fl = fopen("log_in.txt", "r");

    if (fl == 0)
    {
        printf("File not found\n");
    }

    else
    {
        unsigned int i, j;

        fscanf(fl, "%u", &number_of_users);


        for ( i = 0; i < number_of_users; i++)
        {
            fscanf(fl, " %[^\n]\n", log_of_user[i].user_Name);

            fscanf(fl, " %[^\n]\n", log_of_user[i].password);
        }
    }

    fclose(fl);
}




void write_Data()
{
    FILE *fl;

    fl = fopen("log_in.txt", "w");

    unsigned int i;

    fprintf(fl, "%u\n\n\n\n", number_of_users);

    for ( i = 0; i < number_of_users; i++)
    {
        fprintf(fl, "%s\n", log_of_user[i].user_Name);

        fprintf(fl, "%s\n\n\n\n", log_of_user[i].password);
    }

    fclose(fl);

}




void sign_up()
{
    read_Data();
    
    unsigned int i, j, com, f;


    printf("Enter your username :-  ");

    again:;

    scanf(" %[^\n]", log_of_user[number_of_users].user_Name);

    for ( i = 0, com = 0, f = 0; i < number_of_users; i++)
    {
        com = strcmp(log_of_user[number_of_users].user_Name , log_of_user[i].user_Name);

        if (com == 0)
        {
            f = 1;

            goto find;
        }
        
        
    }

    find:;

    if (f == 1)
    {
        system("cls");

        printf("You can't enter this username. Because this username is already used.\n\n\nEnter your username again :-  ");

        goto again;
    }
    
    printf("\n");

    printf("Enter your password :- ");

    scanf(" %[^\n]", log_of_user[number_of_users].password);

    printf ("\n\n\n");

    printf("Thanks for sign up\n");

    number_of_users++;

    write_Data();

}




void sign_in()
{
    char input_u[30], input_p[30];

    read_Data();

    unsigned int i, j, com_u, com_p, fu, fp;

    again_informations:;

    printf("Enter your username:-  ");

    scanf(" %[^\n]", input_u);

    printf("\n");

    printf("Enter your password :-  ");

    scanf(" %[^\n]", input_p);

    for ( i = 0, com_u = 0, com_p = 0, fu = 0, fp = 0; i < number_of_users; i++)
        {
            com_u = strcmp(input_u , log_of_user[i].user_Name);

            com_p = strcmp(input_p , log_of_user[i].password);

            if (com_u == 0)
            {
                fu = 1;
            }

            if (com_p == 0)
            {
                fp = 1;
            }
            

        }

        if (fu == 1 && fp == 1)
        {
            system("cls");

            printf("\n\nYou are successfully log in\n\nWelcome\n\n");
        }

        else
        {
            system("cls");

            printf("\n\nYour information is incorrect\n\n");

            printf("1.Enter your information again.........\n\nOR\n\n2.Exit\n\n===>>>  ");

            unsigned short ex;

            scanf("%hu", &ex);

            if (ex == 1)
            {
                goto again_informations;
            }
            else if (ex == 2)
            {
                goto exit_f;
            }
            
            
        }

exit_f:;

}



int main()
{
    system("cls");

    printf("1. Sign up\n\nOR\n\n2. Sign in\n\n3. Exit\n\n===>>>  ");

    unsigned short command;

    scanf("%hu", &command);

    printf("\n\n\n");

    system("cls");

    if (command == 1)
    {
        sign_up();
    }
    else if (command == 2)
    {
        sign_in();
    }
    else if (command == 3)
    {
        goto exit;
    }
    
    else
    {
        printf("Your command is wrong.\n");
    }
    
    exit:;

    return 0;
}