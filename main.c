//Including libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 64


//------------------------
// Bank action functions
//-------------------------


//Deposit function, simply adding an amount to the users balance
void Deposit(int *userBalance){

    //Creating deposit variable
    int depositAmount;

    //Asking user for Dep Amount, then receiving input
    printf("Enter deposit amount:  ");
    scanf("%d", &depositAmount);

    //Adding amount to users balance, and printing new balance
    *userBalance += depositAmount;
    printf("Your new balance is: %d", *userBalance);

}

//Same as Deposit function except subtracting an amount from the users balance.
void Withdrawal(int *userBalance){

    //Creating withdrawal amount
    int withdrawalAmount;

    //Asking user for WD Amount, then receiving input
    printf("Enter withdrawal amount: ");
    scanf("%d", &withdrawalAmount);

    //Removing amount from users balance, and printing new balance
    *userBalance -= withdrawalAmount;
    printf("Your new balance is: %d", *userBalance);

}

//---------------------------
// Main function
//---------------------------

int main (int argc, char *argv[]) {


    //Adding user login info
    int userID = 4068;
    int userPin = 8163;
    int userID_input;
    int userPin_input;

    //Creating user balance
    int userBalance = 10000;


    //Welcoming User, asking for ID
    printf("Welcome to the Bank of Seth, please enter your user ID: ");
    scanf("%d", &userID_input);


//-------------------------------------
// Login conditionals
//-------------------------------------


    //Checking if ID exists, if it does continue, else state invalid and exit
    if(userID_input == userID){
        printf("User ID: %d \n", userID);
        printf("Enter your pin:");
        scanf("%d", &userPin_input);

        //Checking if users pin input equals the correct  user pin, if so log user in and continue
        if(userPin == userPin_input){
            printf("Welcome, user %d \n", userID);
            printf("Your current balance is %d: \n", userBalance);

            //Stating PIN is invalid, and exiting
        } else {
            printf("Invalid PIN");
            return 0;
        }

    //Stating id is invalid
    } else {
        printf("Invalid ID");
        return 0;
    }

    //Emptying input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);



//-------------------------------------
// userAction conditionals
//-------------------------------------


    //Creating a variable to store the users action and creating an initial balance
    char userAction[BUFFER_SIZE];


    //Asking the user what they would like to do, then receiving input
    printf("Would you like to Withdrawal, Deposit or Exit? \n");

    if (fgets(userAction, sizeof(userAction), stdin) != NULL) {
        //Removing newline character
        userAction[strcspn(userAction, "\n")] = '\0';
    } else {
        printf("Error");
        return 1;
    }

    //If userAction is Deposit, call Deposit function, else call Withdrawal Function
    if (strcmp(userAction, "Deposit") == 0) {
        Deposit(&userBalance);

    } else if (strcmp(userAction, "Withdrawal") == 0) {
        Withdrawal(&userBalance);

    } else if (strcmp(userAction, "Exit") == 0){
        printf(":Exiting");
        return 0;


    } else {
        printf("Invalid Option");
        return 1;
    }



return 0;

}
