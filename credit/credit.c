#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int cardNumber = get_long("Number: ");
    int numLength = floor(log10(abs(cardNumber)) + 1);
    if (numLength < 13 || numLength == 14 || numLength > 16)
    {
        printf("INVALID");
    }
    printf(cardNumber[1]);
}