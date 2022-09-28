#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int cardNumber = get_long("Number: ");

    int numLength = floor(log10(cardNumber) + 1);

// creating an array with the digits from cardNumber
    int digitArray[numLength];
    for (int i = 0; i < numLength; i++)
    {
        digitArray[i] = floor(cardNumber / pow(10, numLength - i - 1));
        cardNumber -= digitArray[i] * pow(10, numLength - i - 1);
    }

// restore value of cardNumber
    for (int i = 0; i < numLength; i++)
    {
        cardNumber += digitArray[i] * pow(10, numLength - i - 1);
    }

//use card number digits to calculate the luhn number
    int luhnNum = 0;
    int doubledNums[floor(numLength / 2)];
    for (int i = 0; i < floor(numLength / 2));
    int everyOtherDigit = 0;
    {
        digit = cardNumber % (10 * pow(100, i));
        doubledNums[i] = digitArray[-2 * (i + 1)] * 2;
    }
// get individual digits of doubled nums ???
    if (cardNumber < 0)
    {
        printf("INVALID\n");
    }
}
//if last digit of luhn number is not 0 then print INVALID
//if cardnumber begins with 4 and is 13 or 16 digits long then print VISA
//if cardnumber is 15 digits print AMEX
//if cardnumber is 16 digits print MASTERCARD
//else print INVALID