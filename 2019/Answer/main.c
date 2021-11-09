// this is the answer for B.Sc. (General) Degree First Year First Semester Terminal Course Unit Examination - June 2019
#include <stdio.h>

#define ADLUT_SPEND_DAY_PKG 6000
#define KID_SPEND_DAY_PKG 3000
#define POOL_GYM_SPEND_DAY_PKG 1500

void mainMenu(); // function prototype
void contentSeparator();
void spendDayPackage();
int stayNightPackage();
int checkIn();
void roomAvailability(int type);
void calculateBill();
void checkOut();
void checkAvalability();

int rooms[40] = {0};

int main()
{
    for (int x = 2; x > 1; x++)
    {
        int userResponse;

        mainMenu();
        scanf("%d", &userResponse);
        contentSeparator();

        switch (userResponse)
        {
        case 1:
            spendDayPackage();
            break;
        case 2:
            stayNightPackage();
            break;
        default:
            return 1;
            break;
        }
    }

    return 0;
}

void mainMenu()
{
    printf("---------------------------Main Menue---------------------------\n");
    printf("1. Spend the day package.\n");
    printf("2. Stay the night.\n");
    printf("3. Exit.\n");
    printf("Select an option from above list: ");
}

void spendDayPackage()
{
    int noAdults = 0;
    int noKids = 0;
    int usePoolGym = 0;
    float totalAmount = 0.0;

    printf("---------------------Spend the day package----------------------\n\n");
    printf("Number of Adults    : ");
    scanf("%d", &noAdults);
    printf("Number of Kids      : ");
    scanf("%d", &noKids);
    printf("Do you want to use pool/gym facility (1: yes, 2: no)    : ");
    scanf("%d", &usePoolGym);

    contentSeparator();
    usePoolGym = usePoolGym < 2 ? 1 : 0;
    totalAmount = ADLUT_SPEND_DAY_PKG * noAdults + KID_SPEND_DAY_PKG * noKids + POOL_GYM_SPEND_DAY_PKG * usePoolGym;

    printf("-------------------Spend the day package Bill-------------------\n\n");
    printf("Package Details: %d Adults, %d Kids %s pool/gym facility\n\n", noAdults, noKids, usePoolGym < 2 ? "with" : "without");
    printf("Total Amount: %.2f\n\n", totalAmount);
    contentSeparator();
}

int stayNightPackage()
{
    for (int i = 2; i > 1; i++)
    {

        int userResponseInStayNight; // store the userResponse in stay Night Package

        printf("---------------------Stay the Night Package----------------------\n\n");
        printf("1. Check In.\n");
        printf("2. Calculate Bill.\n");
        printf("3. Check Out.\n");
        printf("4. Calculate Availability.\n");
        printf("Select an option from above list: ");

        scanf("%d", &userResponseInStayNight);

        contentSeparator();

        switch (userResponseInStayNight)
        {
        case 1:
            checkIn();
            return 0;
        case 2:
            calculateBill();
            return 0;
        case 3:
            checkOut();
            return 0;
        case 4:
            checkAvalability();
            return 0;
        default:
            return 1;
            break;
        }
    }
}

int checkIn()
{
    int roomType;
    printf("---------------------Check In Process----------------------\n");
    printf("What is the room type you want to reserve (1: Double, 2: Triple) : ");

    scanf("%d", &roomType);
    roomAvailability(roomType);
}

void roomAvailability(int type)
{
    int start;
    int end;
    int foundRoom = 0;

    if (type == 1)
    {
        start = 0;
        end = 19;
    }
    else
    {
        start = 20;
        end = 39;
    }

    for (int i = start; start < end; i++)
    {
        if (rooms[i] == 0)
        {
            printf("\n---------------------Check In Process----------------------\n");
            printf("Room number %d (%s room) is reserved\n", i + 1, i < 20 ? "Double" : "Triple");
            rooms[i] = 1;
            foundRoom = 1;
            break;
        }
    }

    if (foundRoom == 0)
    {
        printf("rooms are not available.\n");
    }
}

void calculateBill()
{
    // variable decalration
    int roomType;
    int noNights;
    int paymentMethod;
    int amountForRoomsOnly;
    float finalAmount;
    float discountAmount;
    float maxDiscount[4] = {0.0, 0.0, 0.4, 0.35};
    float minDiscount[4] = {0.0, 0.0, 0.2, 0.15};

    int roomCharges[5] = {0, 40000, 50000, 45000, 55000};

    printf("\n-------------------- Calculate Bill Process --------------------\n");
    printf("Room Type : ");
    scanf("%d", &roomType);
    printf("Number of nights stayed in the hotel : ");
    scanf("%d", &noNights);
    printf("Payment method : ");
    scanf("%d", &paymentMethod);

    contentSeparator();

    amountForRoomsOnly = roomCharges[roomType] * noNights;

    if (amountForRoomsOnly > 50000)
    {
        discountAmount = amountForRoomsOnly * maxDiscount[paymentMethod];
    }
    else
    {
        discountAmount = amountForRoomsOnly * minDiscount[paymentMethod];
    }

    finalAmount = amountForRoomsOnly - discountAmount;

    printf("Package Details : %s room with %s Board for %d Nights.\n", roomType <= 2 ? "Double" : "Triple", roomType == 1 || roomType == 3 ? "Half" : "Full", noNights);
    printf("Total Amount    : %.2f\n", finalAmount);
}

void checkOut()
{
    int roomNumber;

    printf("\n-------------------- Check Out Process --------------------\n");
    printf("Enter the room number: ");
    scanf("%d", &roomNumber);

    if (rooms[roomNumber - 1] != 0)
    {
        rooms[roomNumber - 1] = 0;
        printf("Room %d is released and now it is avalable for new customers.\n", roomNumber);
    }
    else
    {
        printf("room number inside %d %d", roomNumber, rooms[roomNumber - 1]);
        printf("Selected room is already avalable.\n");
    }
}

void checkAvalability()
{
    int commaCondition = 0;

    printf("\n-------------------- Available room list --------------------\n");
    printf("Double Rooms: ");

    for (int i = 0; i < 20; i++)
    {
        if (commaCondition == 0)
        {

            if (rooms[i] == 0)
            {
                printf("%d", i + 1);
                commaCondition = 1;
            }
        }
        else
        {
            if (rooms[i] == 0)
            {
                printf(", %d", i + 1);
            }
        }
    }

    printf("\nTriple Rooms: ");
    commaCondition = 0;
    for (int i = 20; i < 40; i++)
    {
        if (commaCondition == 0)
        {

            if (rooms[i] == 0)
            {
                printf("%d", i + 1);
                commaCondition = 1;
            }
        }
        else
        {
            if (rooms[i] == 0)
            {
                printf(", %d", i + 1);
            }
        }
    }
    printf("\n");
}

void contentSeparator()
{
    printf("----------------------------------------------------------------\n");
}