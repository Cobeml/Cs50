#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int cardNumber = get_long("Number: ");
    int numLength = floor(log10(cardNumber) + 1);
    if (cardNumber < 0) {
        printf("INVALID");
    }
    else if (numLength < 13 || numLength == 14 || numLength > 16)
    {
        printf("INVALID");
    }
    else if ()
}