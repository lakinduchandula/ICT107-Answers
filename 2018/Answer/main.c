#include <stdio.h>

#define COST_PER_KM 50.00
#define WAITING_HOUR 150.00
#define NIGHT_PARKING 1500.00

// global variables, arrays
char pickupLocation[][20] = {"Maharagama", "Boralesgamuwa", "Piliyandala"};
float taxiFee[3] = {2500.00, 2750.00, 3000.00};

// function prototype
void initialScreen();
void airportRide();
void taxiFeeAirport(int index, int vehicleType);
void shortTrip();
float ratePerKM(int distance);
void longTrip();

int main() {
  while (1) {
    int userResponse;
    initialScreen();
    scanf("%d", &userResponse);

    switch (userResponse) {
    case 1:
      airportRide();
      break;
    case 2:
      shortTrip();
      break;
    case 3:
      longTrip();
      break;
    default:
      printf("---- Incorrect package number ----\n");
      printf("\t---- Re-Enter ----\n\n");
    }
  }

  return 0;
}

void initialScreen() {
  printf("\t  Select Package\n");
  printf("----------------------------------------\n");

  printf("1. Airport Ride\n");
  printf("2. Short Trip\n");
  printf("3. Long Trip\n");
  printf("\nEnter package Number(1 or 2 or 3) : ");
}

void airportRide() {
  // variables for this function
  int pickupLocation;
  int acType = 0;
  char vehicleType;
  char userInput;

  printf("%33s", "Select Pickup location\n");
  printf("----------------------------------------\n");

  printf("Maharagama      (M)\n");
  printf("Boralesgauwa    (B)\n");
  printf("Piliyandala     (P)\n\n");
  printf("Enter Location Code(M or B or P)    : ");
  scanf(" %c", &userInput);
  printf("Enter Vehicle type(A or N)          : ");
  scanf(" %c", &vehicleType);

  // check if user select ac car or not
  switch (vehicleType) {
  case 'A':
    acType = 1;
    break;
  case 'N':
    acType = 0;
    break;
  default:
    printf("---- Incorrect  Vehicle type ----\n");
    printf("\t---- Re-Enter ----\n\n");
    airportRide();
  }

  switch (userInput) {
  case 'M':
    taxiFeeAirport(0, acType);
    break;
  case 'B':
    taxiFeeAirport(1, acType);
    break;
  case 'P':
    taxiFeeAirport(2, acType);
    break;
  default:
    printf("---- Incorrect Location code ----\n");
    printf("\t---- Re-Enter ----\n\n");
    airportRide();
  }
}

void taxiFeeAirport(int index, int vehicleType) {
  float additionalAmount = 0;
  printf("\n\tTaxi Fare (Airport Ride)\n");
  printf("----------------------------------------\n");
  printf("Package         : Airport Ride\n");
  printf("From            : %s\n", pickupLocation[index]);
  printf("To              : Katunayake airport\n");
  printf("Vehicle Type    : %s\n\n", vehicleType == 1 ? "AC" : "Non-AC");

  if (vehicleType == 1) {
    additionalAmount = taxiFee[index] * 0.2;
  }

  printf("Amount          : Rs. %.2f\n\n", taxiFee[index] + additionalAmount);
}

void shortTrip() {
  int distance;
  int wait_Hour;
  int countHour;
  int acType = 0;
  char vehicleType;
  float additionalAmount = 0;
  float ridingCharge = 0.0;
  float totalAmount = 0.0;

  printf("\t  Short Trip\n");
  printf("----------------------------------------\n");

  printf("Enter Distance              : ");
  scanf("%d", &distance);

  printf("Waiting Hours               : ");
  scanf("%d", &countHour);

  wait_Hour = countHour;

  printf("Enter Vehicle Type (A or N) : ");
  scanf(" %c", &vehicleType);

  // check if user select ac car or not
  switch (vehicleType) {
  case 'A':
    acType = 1;
    break;
  case 'N':
    acType = 0;
    break;
  default:
    printf("---- Incorrect  Vehicle type ----\n");
    printf("\t---- Re-Enter ----\n\n");
    shortTrip();
  }

  if (distance <= 20) {
    ridingCharge = 20 * COST_PER_KM;
  } else {
    ridingCharge = distance * COST_PER_KM;
  }

  float waitingCost = WAITING_HOUR * wait_Hour;

  // ac facility charge
  if (acType == 1) {
    additionalAmount = ridingCharge * 0.2;
    totalAmount = ridingCharge + additionalAmount + waitingCost;
  } else {
    totalAmount = ridingCharge + waitingCost;
  }

  printf("\n\tTaxi Fare (Short Trip)\n");
  printf("----------------------------------------\n");
  printf("Package         : Short Trip\n");
  printf("Distance        : %d KM\n", distance);
  printf("Waiting Hours   : %d Hour(s)\n", wait_Hour);
  printf("Vehicle Type    : %s\n\n", acType == 1 ? "AC" : "Non-AC");

  printf("Amount          : Rs. %.2f\n\n", totalAmount);
}

void longTrip() {

  int distance;
  int countNight;
  int noDays;
  int acType = 0;
  char vehicleType;
  float additionalAmount = 0.0;
  float totalAmount = 0.0;
  float ridingCharge = 0.0;
  float nightParkCost = 0.0;

  printf("\t  Long Trip\n");
  printf("----------------------------------------\n");

  printf("Enter Distance              : ");
  scanf("%d", &distance);

  printf("Number of Night             : ");
  scanf("%d", &countNight);

  noDays = countNight;

  printf("Enter Vehicle Type (A or N) : ");
  scanf(" %c", &vehicleType);

  // check if user select ac car or not
  switch (vehicleType) {
  case 'A':
    acType = 1;
    break;
  case 'N':
    acType = 0;
    break;
  default:
    printf("---- Incorrect  Vehicle type ----\n");
    printf("\t---- Re-Enter ----\n\n");
    longTrip();
  }

  ridingCharge = ratePerKM(distance);
  nightParkCost = NIGHT_PARKING * noDays;

  // ac facility charge
  if (acType == 1) {
    additionalAmount = ridingCharge * 0.2;
    totalAmount = ridingCharge + additionalAmount + nightParkCost;
  } else {
    totalAmount = ridingCharge + nightParkCost;
  }

  printf("\n\tTaxi Fare (Long Trip)\n");
  printf("----------------------------------------\n");
  printf("Package         : Long Trip\n");
  printf("Distance        : %d KM\n", distance);
  printf("Number of Night : %d day(s)\n", noDays);
  printf("Vehicle Type    : %s\n\n", acType == 1 ? "AC" : "Non-AC");

  printf("Amount          : Rs. %.2f\n\n", totalAmount);
}

float ratePerKM(int distance) {
  float finalAmount = 0.0;

  if (distance <= 300) {
    finalAmount = COST_PER_KM * distance;
  } else if (distance <= 600) {
    finalAmount = COST_PER_KM * 300 + COST_PER_KM * 0.9 * (distance - 300);
  } else if (distance > 600) {
    finalAmount = COST_PER_KM * 0.8 * (distance - 600) + 28500;
  }
  return finalAmount;
}

/*
! NOTE
    * Since type is a char and the switch (vehicleType, userInput) can use
    * single characters, you could scan for one character using %c instead of %s
*/

// Last Update - 20-11-2022 (Complete Answer)