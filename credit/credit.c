#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int cardNumber = get_long("Number: ");

    int numLength = floor(log10(cardNumber) + 1);

    int digitArray[numLength];
    for (int i = 0; i < numLength; i++)
    {
        digitArray[i] = floor(cardNumber / pow(10, numLength - i));
        cardNumber -= digitArray[i] * pow(10, numLength);
    }
printf("%i%i%i\n")
    int luhnNum = 0;

    if (cardNumber)

    if (cardNumber < 0)
    {
        printf("INVALID");
    }
}