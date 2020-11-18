#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define USERCOUNT 3

typedef struct User {
    char login[10];
    char password[10];
};

//Global variables
struct User users[USERCOUNT];
struct User loggedUser;

//Function headers
void initialize(void);
void addUser(char newLogin[10], char newPassword[10],int index);
void printUsers(void);
bool login(void);
void menu(void);
int readChoice(void);
void printLoggedUser(void);
void clearScreen(void);


int main(void)
{
    initialize();
    if(login())
        menu();

    return(0);
}
bool login(void)
{
    bool isLogged = false;

    printf("Type your username:");
    scanf("%s",loggedUser.login);
    printf("Type your password:");
    scanf("%s",loggedUser.password);

    for(int c = 0; c < USERCOUNT; c++)
    {
        if((strcmp(users[c].login,loggedUser.login) == 0) &&
            (strcmp(users[c].password,loggedUser.password) == 0))
        {
            isLogged = true;
            printLoggedUser();
            break;
        }
    }
    if(!isLogged)
        printf("The provided credentials are invalid");

    return isLogged;
}

void menu(void)
{
    int operation = 0;
    do {
        operation = readChoice();
        switch(operation)
        {
            case 1:

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                scanf("Invalid choice.\n");
                break;

        }
    } while(operation != 4);

    printf("\nYour session has ended.\n");
}

int readChoice()
{
    int choice = 0;
    printLoggedUser();

    printf("╔═══════ MENU ═══════╗\n");
    printf("║ 1 - Add Patient    ║\n");
    printf("║ 2 - List Patients  ║\n");
    printf("║ 3 - Search patient ║\n");
    printf("║ 4 - Exit           ║\n");
    printf("╚════════════════════╝\n");
    printf("Type the number of your choice:");
    scanf("%d",&choice);

    return choice;
}

void printLoggedUser(void)
{
    clearScreen();
    printf("Logged as: %s\n\n",loggedUser.login);
}

void clearScreen(void)
{
    system("clear");
}

void initialize()
{
    addUser("John","1234",0);
    addUser("Mary","2345",1);
    addUser("Paul","3456",2);

    printUsers();

}

void addUser(char newLogin[10], char newPassword[10],int index)
{
    strcpy(users[index].login,newLogin);
    strcpy(users[index].password,newPassword);
}

void printUsers(void)
{
    for(int c = 0; c < USERCOUNT; c++)
    {
        printf("Username: %s, Password: %s\n",users[c].login, users[c].password);
    }
}


