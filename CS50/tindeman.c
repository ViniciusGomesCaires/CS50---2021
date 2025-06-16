#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool vote(int rank, string name, int ranks[])
{
    int compare;

    for (int i = 0; i < candidate_count; i++)
    {
        compare = strcmp(name, candidates[i]);
        if (compare == 0)
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
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
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
                pair_count++;
            }
        }
    }
    return;
}

void sort_pairs(void)
{

    for (int i = 0; i < pair_count; i++)
    {
        if (preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner] < preferences[pairs[i + 1].winner][pairs[i + 1].loser] - preferences[pairs[i + 1].loser][pairs[i + 1].winner])
        {
            pairs[pair_count].winner =  pairs[i + 1].winner;
            pairs[pair_count].loser =  pairs[i + 1].loser;
            pairs[i + 1].winner =  pairs[i].winner;
            pairs[i + 1].loser =  pairs[i].loser;
            pairs[i].winner =  pairs[pair_count].winner;
            pairs[i].loser =  pairs[pair_count].loser;
            i = 0;
        }
    }
    return;
}

bool cycle(int candidate_end, int candidate_start)
{

    if (candidate_end == candidate_start)
    {
        return true;
    }

    for (int candidate = 0; candidate < candidate_count; candidate++)
    {
        if (locked[candidate_end][candidate])
        {
            if (cycle(candidate, candidate_start))
            {
                return true;
            }
        }
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i  < candidate_count; i++)
    {
        for (int j = 0; j  < candidate_count; j++)
        {
            if (locked[j][i])
            {
                j = candidate_count;
            }
            else if (j == candidate_count - 1)
            {
                printf("%s\n", candidates[i]);
            }
        }
    }
    return;
}