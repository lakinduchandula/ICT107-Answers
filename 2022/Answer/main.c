// ICT 107 1.0 Computer Programing- Laboratory 1
// Mock Test -  October 2022
// Automated Teller Machine (ATM)

#include <stdio.h>

// global varaible declaration
double accBalance = 0.0;

void mainMenu();           // function prototype
void checkBalance();       // function prototype
void anotherTransaction(); // function prototype
void atmExit();            // function prototype
void deposit();            // function prototype

// function main begins program execution
int main() {
  for (int x = 2; x > 1; x++) {
    int userResponse;

    mainMenu();
    scanf("%d", &userResponse);
    // contentSeparator();

    switch (userResponse) {
    case 1:
      checkBalance();
      break;
    case 2:
      deposit();
      break;
    case 3:
      printf(" Select 03");
      break;
    case 4:
      atmExit();
      return 0;
    default:
      printf("You have entered incorrect number! Try again...\n");
    }

    printf("\n=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
    anotherTransaction();

    scanf("%d", &userResponse);
    switch (userResponse) {
    case 1:
      break;
    case 2:
      atmExit();
      return 0;
    default:
      printf("You have entered incorrect number! Try again...\n");
    }

    printf("\n");
  }

  return 0;
}

// mainMenu of ATM
void mainMenu() {
  printf("********************Hello!********************\n");
  printf("************Welcome to ATM Banking************\n\n");

  printf("****Please choose one of the options below****\n\n");

  printf("< 1 > Check Blance\n");
  printf("< 2 > Deposite\n");
  printf("< 3 > Withdraw\n");
  printf("< 4 > Exit\n");

  printf("=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_\n");
  printf("Your Selection : ");
}

// checkBalance of ATM
void checkBalance() {
  printf("You Choose to See you Balance\n\n\n");
  printf("****Your Available balance is : $%.2f\n", accBalance);
}

// anotherTransaction of ATM
void anotherTransaction() {
  printf("Would you like to do another transaction:\n");
  printf("< 1 > Yes \n");
  printf("< 2 > No \n");
}

// exit function
void atmExit() {
  printf("-------------Take you receipt!!!--------------\n");
  printf("--Thank you for using ATM Banking Machine!!!--\n");
  printf("------BROUGHT TO YOU BY itsourcecode.com------\n");
}

// deposit function
void deposit() {
  double amount;
  printf("Enter the amount you want to deposit : ");
  scanf("%lf", &amount);
  accBalance += amount;
  printf("Your New Balance is: $%.2f\n", accBalance);
}

