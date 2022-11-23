// ICT 107 1.0 Computer Programing- Laboratory 1
// 2017

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gloabl variables

int yearsOfService;
int staffTitleNumber;
int employeeNumber;
int year;
int monthNumber;
int genderNumber;
char inputMonth[4];

double monthlyBasicSalary;
double monthlyQuota;

double commissionOnSales;
double commissionOnService;
double commissionOnTitle;

double allCommissions;
double grossSalary;

// defined global variables
char months[12][10] = {"January",   "February", "March",    "April",
                       "May",       "June",     "July",     "August",
                       "September", "October",  "November", "December"};

char staffTitles[3][30] = {"Senior sales representative",
                           "Junior sales representative", "Sales trainee"};

char gender[3][6] = {"null", "Male", "Female"};

// function prototypes
void mainForm();
void printPaySlip();
int staffGender();
int staffTitleNumberInput();
int monthNumberInput();
double commissionOnSalesCalculation(double commissionOnSales);
double commissionOnServiceCalculation(double yearOfService);
double commissionOnStaffTitleCalculation(int staffTitleNumber);
double yearEndBonous();
int employeeNumberInput();

// function main begins program execution
int main() {
  mainForm();

  // calculate the commission of sales
  commissionOnSales = commissionOnSalesCalculation(monthlyQuota);

  // calculate the commission of service
  commissionOnService = commissionOnServiceCalculation(yearsOfService);

  // calculate the commission of staff title
  commissionOnTitle = commissionOnStaffTitleCalculation(staffTitleNumber);

  // all commissions
  allCommissions = commissionOnSales + commissionOnService + commissionOnTitle;

  grossSalary = monthlyBasicSalary + allCommissions;

  printPaySlip();
}

void mainForm() {
  printf("=============================================\n");
  printf("Sooriya Holdings (Pvt) Ltd\n");
  printf("Pay Slip Generator\n");
  printf("---------------------------------------------\n");

  printf("Enter the following details to generate the pay slip\n\n");

  employeeNumber = employeeNumberInput();

  staffTitleNumber = staffTitleNumberInput();

  genderNumber = staffGender();

  printf("Year of Pay slip      : ");
  scanf("%d", &year);

  monthNumber = monthNumberInput();

  printf("Monthly basic salary  : ");
  scanf("%lf", &monthlyBasicSalary);

  printf("Monthly Quota         : ");
  scanf("%lf", &monthlyQuota);

  printf("Years of service      : ");
  scanf("%d", &yearsOfService);
}

int employeeNumberInput() {

  while (1) {
    printf("Employee number       : ");
    scanf("%d", &employeeNumber);

    if (1001 < employeeNumber && employeeNumber < 9999) {
    } else if (employeeNumber == -9999) {
      exit(1);
    } else {
      printf("Invalid employee number. Please enter again ; \n");
    }
  }
}

int staffGender() {
  while (1) {
    char gender;

    printf("Gender of Employee    : ");
    scanf(" %c", &gender);

    switch (gender) {
    case 'M':
    case 'm':
      return 1;
      break;
    case 'F':
    case 'f':
      return 2;
      break;
    default:
      break;
    }
  }
}

int staffTitleNumberInput() {
  while (1) {
    char staffTitle;

    printf("Staff title           : ");
    scanf(" %c", &staffTitle);

    switch (staffTitle) {
    case 'S':
    case 's':
      return 0;
      break;
    case 'J':
    case 'j':
      return 1;
      break;
    case 'T':
    case 't':
      return 2;
      break;
    default:
      printf("Invalid Character code");
    }
  }
}

int monthNumberInput() {
  while (1) {

    printf("Month of Pay slip     : ");
    scanf("%s", inputMonth);

    if (strcmp(inputMonth, "JAN") == 0) {
      return 0;
    } else if (strcmp(inputMonth, "FEB") == 0) {
      return 1;
    } else if (strcmp(inputMonth, "MAR") == 0) {
      return 2;
    } else if (strcmp(inputMonth, "APR") == 0) {
      return 3;
    } else if (strcmp(inputMonth, "MAY") == 0) {
      return 4;
    } else if (strcmp(inputMonth, "JUN") == 0) {
      return 5;
    } else if (strcmp(inputMonth, "JUL") == 0) {
      return 6;
    } else if (strcmp(inputMonth, "AUG") == 0) {
      return 7;
    } else if (strcmp(inputMonth, "SEP") == 0) {
      return 8;
    } else if (strcmp(inputMonth, "OCT") == 0) {
      return 9;
    } else if (strcmp(inputMonth, "NOV") == 0) {
      return 10;
    } else if (strcmp(inputMonth, "DEC") == 0) {
      return 11;
    } else {
      printf("Invalid Three charaters of month");
    }
  }
}

// commission on sales
double commissionOnSalesCalculation(double commissionOnSales) {

  if (monthlyQuota < 25000) {
    commissionOnSales += monthlyQuota * 0.03;
  } else if (monthlyQuota < 50000) {
    commissionOnSales += monthlyQuota * 0.05;
  } else if (monthlyQuota < 100000) {
    commissionOnSales += monthlyQuota * 0.07;
  } else if (monthlyQuota < 150000) {
    commissionOnSales += monthlyQuota * 0.09;
  } else {
    commissionOnSales += monthlyQuota * 0.10;
  }

  // additional 4% bonus for sales above 125,000
  if (monthlyQuota > 125000) {
    commissionOnSales += monthlyQuota * 0.04;
  }

  return commissionOnSales;
}

// commission on service
double commissionOnServiceCalculation(double yearOfService) {
  double commissionOnService;

  if (yearOfService < 10) {
    commissionOnService = yearOfService * 0.15 * commissionOnSales;
  } else {
    commissionOnService = commissionOnSales * 1.5;
  }

  return commissionOnService;
}

// commission on staff title
double commissionOnStaffTitleCalculation(int staffTitleNumber) {
  double commissionOnStaffTitle;

  switch (staffTitleNumber) {
  case 0:
    commissionOnStaffTitle = commissionOnSales * 0.05;
    break;
  case 1:
    commissionOnStaffTitle = commissionOnSales * 0.03;
    break;
  case 2:
    commissionOnStaffTitle = commissionOnSales * 0.00;
    break;
  default:
    break;
  }

  return commissionOnStaffTitle;
}

// year end-bonous
double yearEndBonous() {
  double yearEndBonous = monthlyBasicSalary * 0.05 * genderNumber;
  return yearEndBonous;
}

void printPaySlip() {
  printf("=============================================\n");
  printf("Sooriya Holdings (Pvt) Ltd\n");
  printf("Pay Slip for %s-%d\n", months[monthNumber], year);
  printf("Employee No: %d\n", employeeNumber);
  printf("Staff title: %s\n", staffTitles[staffTitleNumber]);
  printf("---------------------------------------------\n\n");

  printf("Basic salary      : %.2lf\n", monthlyBasicSalary);
  printf("Commissions       : %.2lf\n", allCommissions);

  if (strcmp(inputMonth, "DEC") == 0) {

    double yearEndBonousPrint = yearEndBonous();

    if (monthlyBasicSalary < 100000) {
      yearEndBonousPrint += monthlyBasicSalary * 0.02;
    }

    printf("Bonus             : %.2lf\n", yearEndBonousPrint);
    printf("Gross salary      : %.2lf\n", grossSalary + yearEndBonousPrint);

  } else {
    printf("Gross salary      : %.2lf\n", grossSalary);
  }

  printf("---------------------------------------------\n\n");
}

// This code may have bugs,
// didn't test with proper test-cases
// if any errors, please let me know

// Last Updated: 2020-11-23