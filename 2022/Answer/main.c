// ICT 107 1.0 Computer Programing- Laboratory 1
// Mock Test -  October 2022
// Automated Teller Machine (ATM)

#include <stdio.h>

// global variable declaration
double accBalance = 0.0;

void mainMenu();           // function prototype
void checkBalance();       // function prototype
void anotherTransaction(); // function prototype
void atmExit();            // function prototype
void deposit();            // function prototype
void withdraw();           // function prototype

// function main begins program execution
int main() {
  while(1) {
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
      withdraw();
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

  printf("< 1 > Check Balance\n");
  printf("< 2 > Deposit\n");
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

// withdraw function
void withdraw() {
  printf("You choose to Withdraw a money\n");
  printf("$$$$$Your Balance is : $%.2f\n\n", accBalance);

  double amount; // hold withdraw amount

  printf("Enter the amount to withdraw : \n");
  scanf("%lf", &amount);

  // check whether the amount is greater than the balance
  if (amount > accBalance) {
    printf("You have insufficient balance!\n");
  } else {
    printf("$$$$Your Withdrawing money is: $%.2f\n", amount);
    accBalance -= amount;
    printf("****Your New Balance is: $%.2f\n", accBalance);
  }
}

// End of Mock Paper -  Last Update 2022-11-20