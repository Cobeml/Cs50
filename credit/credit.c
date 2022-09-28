#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int cardNumber = get_long("Number: ");

    int numLength = floor(log10(cardNumber) + 1);

//use card number digits to calculate the luhn number
    int luhnNum = 0;
    int everyOtherDigit = 0;
    int doubledDigits = 0;
    for (int i = 0; i < floor(numLength / 2))
    {
        everyOtherDigit = floor((cardNumber % pow(100, i + 1)) / (10 * pow(10, i)));
        doubledDigit = everyOtherDigit * 2
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
    for (int i = 0; i < floor(numLength / 2))
// get individual digits of doubled nums ???
    if (cardNumber < 0)
    {
        printf("INVALID\n");
    }
    else if
}
//if last digit of luhn number is not 0 then print INVALID
//if cardnumber begins with 4 and is 13 or 16 digits long then print VISA
//if cardnumber is 15 digits print AMEX
//if cardnumber is 16 digits print MASTERCARD
//else print INVALID