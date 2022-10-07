#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count - i - 1; j++)
        {
            preferences[ranks[i]][ranks[candidate_count - j - 1]] ++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count ++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
// sort_pairs did not correctly sort pairs
void sort_pairs(void)
{
    for (int j = 0; true; j++)
    {
        int switch_count = 0;
        for (int i = 0; i < pair_count - 1; i ++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[i + 1].winner][pairs[i + 1].loser])
            {
                int pair_winner = pairs[i].winner;
                int pair_loser = pairs[i].loser;
                pairs[i].winner = pairs[i + 1].winner;
                pairs[i].loser = pairs[i + 1].loser;
                pairs[i + 1].winner = pair_winner;
                pairs[i + 1].loser = pair_loser;

                switch_count ++;
            }
            printf("%i%i\n%i%i\n%i%i\n", pairs[0].winner, pairs[0].loser, pairs[1].winner, pairs[1].loser, pairs[2].winner, pairs[2].loser);
        }

        if (switch_count == 0)
        {
            return;
        }
    }
}

bool checkcycle(int pair_winner, int pair_loser);

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!checkcycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
        else
        {
            return;
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    bool dominated;
    for (int i = 0; i < candidate_count; i++)
    {
        dominated = false;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                dominated = true;
                break;
            }
        }
        if (dominated == false)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}

// checks if there is a cycle
// lock pair did not correctly skip pair if it created a cycle
bool checkcycle(int pair_winner, int pair_loser)
{
    bool domination[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        domination[i] = false;
    }

    domination[pair_loser] = true;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (j == pair_loser)
            {
                break;
            }
            else if (locked[i][j] == true)
            {
                domination[j] = true;
                break;
            }
        }
    }

    int domination_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (domination[i] == true)
        {
            domination_count ++;
        }
    }

    if (domination_count == candidate_count)
    {
        return true;
    }
    else
    {
        return false;
    }
}