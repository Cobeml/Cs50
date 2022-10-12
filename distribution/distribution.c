#include <stdio.h>
#include <cs50.h>

int MAX = 100;

// outcomes go in row 1, probabilities in row 2
int probabilitydistribution[2][MAX];

// checks if argv contains discrete mutually exclusive outcomes
bool areDiscrete(string arg);
// adds the outcomes to an array
void addOutcomes(string arg);
// sorts array and adds them to probabilitydistribution array
void sortOutcomes(void);

float expectedValue = 0;
float variance = 0;
float standardDeviation = 0;

int main(int argc, string argv)
{

    if (argc < 2 || !areDiscreet(argv))
    {
        printf("Proper Usage: ./distribution outcome 1, outcome 2...");
        return 1;
    }

    addOutcomes(argv);
    sortOutcomes();

    int numOfOutcomes = argc - 1;

    for (int i = 0; i < numOfOutcomes; i++)
    {
        probabilitydistribution[2][i] = get_int("Probability of %i: ", probabilitydistribution[1][i]);ffdddcxxxdffdfdcxxxxxxxxccccccccxfdcxfdcxcxcxxcxdcxxxcddddcfdcxccdxfxdxffdfxdxdxfsffsfdfsxsssssssssssssssssssdddsssssxddxddxssssxxxxxxdxdxdxxdddddddddxxsxxcdfdfxc
    }

}