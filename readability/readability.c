#include <cs50.h>
#include <stdio.h>

// declare function
long lettersPer100(string words);
long sentencesPer100(string words);

int main(void)
{
    // get user input
    string text = get_string("Text: ");
    // find index from text
    int index = round(0.0588 * lettersPer100(string text) - 0.296 * sentencesPer100(string text) - 15.8);
    // print output based on index
    if (index >= 16) {
        printf ("Grade 16+\n");
    }
    else if (index < 1) {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}


int numOfLetters = 0;
int numOfWords = 0;
int numOfSentences = 0;

for (i = 0; i < strlen(text) + 1; i++)
{
    if ((text[i] >= a && text[i] <= z) || (text[i] >= A && text[i] <= Z)
    {
        numOfLetters ++;
    }

    if ((text[i] == ' ' || text[i] == '\0') && text[i - 1] >= ! && text[i - 1] <= z)
    {
        numOfWords ++;
    }

    if (text[i] == '.' || text[i] == '?' || text[i] == '!')
    {
        numOfSentences ++
    }
}

long lettersPer100(string words)
{

}

long sentencesPer100(string words)