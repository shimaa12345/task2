#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int isActive; 
} User;

User users[MAX_USERS];
int numUsers = 0;

int login();
void registerUser();
int validateCredentials(const char* username, const char* password);
void updateUserFlag(const char* username, int isActive);

int main() {
    int choice;
    int loggedIn = 0;

    while (1) {
        printf("Welcome to the Login System\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loggedIn = login();
                if (loggedIn) {
                    printf("Login successful!\n");
                    
                } else {
                    printf("Invalid username or password\n");
                }
                break;
            case 2:
                registerUser();
                printf("Registration successful!\n");
                break;
            case 3:
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

int login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    return validateCredentials(username, password);
}

void registerUser() {
    if (numUsers == MAX_USERS) {
        printf("Maximum number of users reached\n");
        return;
    }

    User newUser;

    printf("Enter a username: ");
    scanf("%s", newUser.username);

    
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists\n");
            return;
        }
    }

    printf("Enter a password: ");
    scanf("%s", newUser.password);

    
    printf("Is the user active? (1 for active, 0 for inactive): ");
    scanf("%d", &newUser.isActive);

    users[numUsers++] = newUser;
}

int validateCredentials(const char* username, const char* password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (users[i].isActive) {
                return 1; 
            } else {
                printf("User is not active\n");
                return 0; 
            }
        }
    }

    return 0; 
}