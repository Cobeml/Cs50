#include <cs50.h>
#include <stdio.h>

bool isNumber(string arg);
string cipher(string text);

int main(int argc, string argv[])
{
    if (!isNumber(argv))
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
        string plainText = get_string("plaintext:  ");
        string cipherText = cipher(plainText);
    }
}