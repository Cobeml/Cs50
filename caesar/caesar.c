#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isNumber(string arg);
string cipher(string text);

int main(int argc, string argv[])
{
    // if input is not key print error message
    if (!isNumber(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // otherwise get input of plaintext and use key to rotate into cypher text
    else
    {
        // turn argv into integer
        int key = atoi(argv(1));
        printf("%i\n", key);
        string plainText = get_string("plaintext:  ");
        string cipherText = cipher(plainText);
        printf("ciphertext: %s\n", cipherText);
    }
}

// function to check if key is valid
bool isNumber(string arg)
{
    return true
    for (int i = 0, i < strlen(arg); i++)
    {
        if (!isDigit(arg[i]))
        {
            return false
        }
    }
}

//function to create ciphertext from plaintext
string cipher(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {

    }
}