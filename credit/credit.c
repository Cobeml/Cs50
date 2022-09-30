#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long cardNumber = get_long("Number: ");

    int numLength = floor(log10(cardNumber) + 1);

//use card number digits to calculate the luhn number
    int luhnNum = 0;
    int everyOtherDigit = 0;
    int doubledDigits = 0;
    for (int i = 0; i < floor(numLength / 2); i++)
    {
// WHAT IS WRONG ON THE LINE BELOW!?
        everyOtherDigit = floor(fmod(cardNumber, pow(100, i + 1)) / (10 * pow(100, i)));
        doubledDigits = everyOtherDigit * 2
        if (everyOtherDigit * 2 >= 10)
        {
            luhnNum += doubledDigit % 10;
            luhnNum += 1;
        }
        else
        {
            luhnNum += doubledDigit;
        }
    }
    int notAddedDigit = 0;
    for (int i = 0; i < ceil(numLength / 2))
    {
        notAddedDigit = floor(fmod(cardNumber, (10 * pow(100, i))) / pow(100, i));
        luhnNum += notAddedDigit;
    }

    // create int that holds first and another that holds the first two digits
    int firstDigit = (floor(cardNumber / (pow(10, numLength) - 1)));
    int firstTwoDigits = (floor(cardNumber / (pow(10, numLength) - 2)));

    if (cardNumber < 0)
    {
        printf("INVALID\n");
    }
    else if (luhnNum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if ((numLength == 13 || numLength == 16) && firstDigit == 4)
    {
        printf("VISA\n");
    }
    else if (numLength == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
    {
        printf("AMEX\n");
    }
    else if (numLength == 16 && (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
//if last digit of luhn number is not 0 then print INVALID
//if cardnumber begins with 4 and is 13 or 16 digits long then print VISA
//if cardnumber is 15 digits print AMEX
//if cardnumber is 16 digits print MASTERCARD
//else print INVALID