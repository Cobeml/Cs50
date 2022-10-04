#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// declare function
double lettersPer100(string words);
double sentencesPer100(string words);

int main(void)
{
    // get user input
    string text = get_string("Text: ");
    // find index from text
    double index = 0.0588 * lettersPer100(text) - 0.296 * sentencesPer100(text) - 15.8;
    double roundedIndex = round(index);
    // print output based on index
    if (index >= 16) {
        printf ("Grade 16+\n");
    }
    else if (index < 1) {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", roundedIndex);
    }
}


int findLetterNum(string input)
{
    int numOfLetters = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            numOfLetters ++;
        }
    }
    printf("%i\n", numOfLetters);
    return numOfLetters;
}

int findWordNum(string input)
{
    int numOfWords = 0;
    for (int i = 0; i < strlen(input) + 1; i++)
    {
        if ((input[i] == ' ' || input[i] == '\0') && input[i - 1] >= '!' && input[i - 1] <= 'z')
        {
            numOfWords ++;
        }
    }
    printf("%i\n", numOfWords);
    return numOfWords;
}

int findSentenceNum(string input)
{
    int numOfSentences = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            numOfSentences ++;
        }
    }
    printf("%i\n", numOfSentences);
    return numOfSentences;
}

double lettersPer100(string words)
{
    return findLetterNum(words) / findWordNum(words) * 100;
}

double sentencesPer100(string words)
{
    return findSentenceNum(words) / findWordNum(words) * 100;
}