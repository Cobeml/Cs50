#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// declare function
float lettersPer100(string words);
float sentencesPer100(string words);

int main(void)
{
    // get user input
    string text = get_string("Text: ");
    // find index from text
    double index = 0.0588 * lettersPer100(text) - 0.296 * sentencesPer100(text) - 15.8;
    int roundedIndex = round(index);
    // print output based on index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", roundedIndex);
    }
}

//funtion to find amount of letters
float findLetterNum(string input)
{
    float numOfLetters = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            numOfLetters ++;
        }
    }
    return numOfLetters;
}

//function to find amount of words
float findWordNum(string input)
{
    float numOfWords = 0;
    for (int i = 0; i < strlen(input) + 1; i++)
    {
        if ((input[i] == ' ' || input[i] == '\0') && input[i - 1] >= '!' && input[i - 1] <= 'z')
        {
            numOfWords ++;
        }
    }
    return numOfWords;
}

//function to fing amount of sentences
float findSentenceNum(string input)
{
    int numOfSentences = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            numOfSentences ++;
        }
    }
    return numOfSentences;
}

//functions to compute letters and sentences per 100 words
float lettersPer100(string words)
{
    float lettersPer100Num = findLetterNum(words) / findWordNum(words);
    return lettersPer100Num * 100.0;
}

float sentencesPer100(string words)
{
    float sentencesPer100Num = findSentenceNum(words) / findWordNum(words);
    return sentencesPer100Num * 100.0;
}