//Including libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_SIZE 64


//-------------------------------
// Bank action functions
//--------------------------------


//Deposit function, simply adding an amount to the users balance
void Deposit(int *userBalance, int *userWallet){

    //Creating deposit variable
    int depositAmount;

    //Asking user for DEP Amount, then receiving input
    printf("Enter deposit amount:  ");
    scanf("%d", &depositAmount);

    //Checking if user has the minimum amount to deposit, if not state insufficient funds
    if(depositAmount <= *userWallet) {

        //Adding DEP amount to users balance, and removing DEP amount from users wallet, then printing balances
        *userBalance += depositAmount;
        *userWallet -= depositAmount;
        printf(" \n");
        printf("Your new bank balance is: %d \n", *userBalance);
        printf("Your wallet balance is now: %d", *userWallet);
    } else {
        printf(" \n");
        printf("Insufficient Funds");
    }


}

//Same as Deposit function except subtracting an amount from the users balance.
void Withdrawal(int *userBalance, int *userWallet){

    //Creating withdrawal amount
    int withdrawalAmount;

    //Asking user for WD Amount, then receiving input
    printf("Enter withdrawal amount: ");
    scanf("%d", &withdrawalAmount);

    //Checking if user has the minimum amount to withdraw, if not state insufficient funds
    if(withdrawalAmount <= *userBalance) {

        //Removing WD amount from users balance, and adding WD amount to users wallet, then printing new balance
        *userBalance -= withdrawalAmount;
        *userWallet += withdrawalAmount;
        printf(" \n");
        printf("Your new bank balance is: %d \n", *userBalance);
        printf("Your wallet balance is now: %d \n", *userWallet);
    } else {
        printf(" \n");
        printf("Insufficient Funds");
    }

}

//---------------------------------
// Main function
//--------------------------------

int main (int argc, char *argv[]) {


//--------------------------------
// User Information
//--------------------------------



    //Adding user login info
    int userID = 4068;
    int userPin = 8163;
    int userID_input;
    int userPin_input;

    //Creating user balances
    int userBalance = 10000;
    int userWallet = 1840;


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
        printf(" \n");

        //Checking if users pin input equals the correct user pin, if so log user in and continue
        if(userPin == userPin_input){
            //Welcoming user, displaying balances
            printf("Welcome, user %d \n", userID);
            printf(" \n");
            printf("Your current bank balance is: %d \n", userBalance);
            printf("Your current wallet balance is: %d \n", userWallet);

            //Stating PIN is invalid, and exiting
        } else {
            printf(" \n");
            printf("Invalid PIN");
            return 0;
        }

    //Stating id is invalid
    } else {
        printf(" \n");
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
    printf(" \n");
    printf("Would you like to Withdrawal (W), Deposit (D) or Exit? (E) \n");

    if (fgets(userAction, sizeof(userAction), stdin) != NULL) {
        //Removing newline character
        userAction[strcspn(userAction, "\n")] = '\0';
    } else {
        printf("Error");
        return 1;
    }

    //If userAction is Deposit, call Deposit function, else call Withdrawal Function
    if (strcmp(userAction, "D") == 0) {
        Deposit(&userBalance, &userWallet);

    } else if (strcmp(userAction, "W") == 0) {
        Withdrawal(&userBalance, &userWallet);

    } else if (strcmp(userAction, "E") == 0){
        printf(":Exiting");
        return 0;


    } else {
        printf(" \n");
        printf("Invalid Option");
        return 1;
    }



return 0;

}
