#include <cs50.h>
#include <stdio.h>

bool isNumber(string arg);

int main(int argc, string argv[])
{
    if (!isNumber(argv))
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
        string plainText = get_string("plaintext:  ");
        
    }
}