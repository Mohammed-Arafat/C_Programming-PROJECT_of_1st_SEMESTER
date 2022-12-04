#include <stdio.h>

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
    
    unsigned int i, j, cnt, f;


    printf("Enter your user name :-  ");

    again:;

    scanf(" %[^\n]", log_of_user[number_of_users].user_Name);

    for ( i = 0, cnt = 0, f = 0; i < number_of_users; i++)
    {
        for ( j = 0; j < strlen(log_of_user[i].user_Name); j++)
        {
            if (log_of_user[number_of_users].user_Name[j] == log_of_user[i].user_Name[j])
            {
                cnt++;
            }
            
        }

        if (cnt == strlen(log_of_user[number_of_users].user_Name))
        {
            f = 1;

            goto find;
        }
        
        
    }

    find:;

    if (f == 1)
    {
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
    char input[30];

    read_Data();

    unsigned int i, j, cnt, f;

    printf("Enter your username:-  ");

    again_UserName:;

    scanf(" %[^\n]", input);

    for ( i = 0, cnt = 0, f = 0; i < number_of_users; i++)
        {
            for ( j = 0; j < strlen(log_of_user[i].user_Name); j++)
            {
                if (input[j] == log_of_user[i].user_Name[j])
                {
                    cnt++;
                }
                
            }

            if (cnt == strlen(input))
            {
                f = 1;
            }

        }

        if (f == 1)
        {
            printf("Enter your password :-  ");

            again_password:;

            scanf(" %[^\n]", input);

            for ( i = 0, cnt = 0, f = 0; i < number_of_users; i++)
            {
                for ( j = 0; j < strlen(log_of_user[i].password); j++)
                {
                    if (input[j] == log_of_user[i].password[j])
                    {
                        cnt++;
                    }
                
                }

                if (cnt == strlen(input))
                {
                    f = 1;
                }

            }

            if (f == 1)
            {
                printf("\n\nYou are successfully log in\n\nWelcome\n");
            }

            else
            {
                printf("\n\nYour password is incorrect\n\n");

                printf("Enter your password again :-  ");

                goto again_password;
            }
            
            
        }
        

        else
        {
            printf("\n\nUser name is incorrect\n\n");

            printf("Enter your username again :-  ");

            goto again_UserName;
        }

}



int main()
{
    printf("1. Sign up\nOR\n2. Sign in\n");

    unsigned short command;

    scanf("%hu", &command);

    printf("\n\n\n");

    if (command == 1)
    {
        sign_up();
    }
    else if (command == 2)
    {
        sign_in();
    }

}