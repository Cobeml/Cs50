#include <cs50.h>
#include <stdio.h>

// declare function
long lettersPer100(string words);
long sentencesPer100(string words);

int main(void)
{
    // get user input
    string text = get_string("Text: ");
    // find index from 
    int index = round(0.0588 * lettersPer100(string text) - 0.296 * sentencesPer100(string text) - 15.8);
}