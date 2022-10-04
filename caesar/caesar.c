#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isNumber(string arg);
string cipher(string text);

int main(int argc, string argv[])
{
    // turn argv into integer
    int keyArray[strlen(argv[1])]
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        keyArray[i] = argv[1][i] - 48;
    }
    int key = 0;
    for (int i = 0, i < strlen(argv[1]); i++)
    {
        key += keyArray[i] * pow(10, strlen(argv[1]) - i - 1;
    }

    // if input is not key print error message
    if (!isNumber(argv[1]) && key)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // otherwise get input of plaintext and use key to rotate into cypher text
    else
    {
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
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            int plainLetterAsNumber = text[i];
            int cipherLetterAsNumber = (plainLetterAsNumber - 97 + key)

        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
    }
}