#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <gtk-4.0/gtk/gtk.h>
#include <gtk-4.0/gtk/css/gtkcss.h>

#define BUFFER_SIZE 64


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


int main (int argc, char *argv[]) {

    //Creating a variable to store the users action and creating an initial balance
    char userAction[BUFFER_SIZE];
    int userBalance = 10000;

    //Asking the user what they would like to do, then receiving input
    printf("Would you like to make a Withdrawal or Deposit? \n");

    if(fgets(userAction, sizeof(userAction), stdin) != NULL){
        //Removing newline character
        userAction[strcspn(userAction, "\n")] = '\0';
    }


    if(strcmp(userAction, "Deposit") == 0){
        Deposit(&userBalance);

    } else if (strcmp(userAction, "Withdrawal") == 0){
        Withdrawal(&userBalance);

    }

return 0;

}
