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

int length = strlen()
long lettersPer100(string words)
{

}

long sentencesPer100(string words)