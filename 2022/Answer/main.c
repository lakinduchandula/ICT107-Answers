// ICT 107 1.0 Computer Programing- Laboratory 1
// Mock Test -  October 2022
// Automated Teller Machine (ATM)

#include <stdio.h>

void mainMenu(); // function prototype

int main() {
  for (int x = 2; x > 1; x++) {
    int userResponse;

    mainMenu();
    scanf("%d", &userResponse);
    // contentSeparator();

    switch (userResponse) {
    case 1:
      printf(" Select 01");
      break;
    case 2:
      printf(" Select 02");
      break;
    case 3:
      printf(" Select 03");
      break;
    default:
      printf("You have entered incorrect number! Try again...\n");
    }

    printf("\n\n");
  }

  return 0;
}

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