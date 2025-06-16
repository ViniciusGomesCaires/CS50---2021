#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");

     for (int i = 0; i < strlen(word1); i++){
        if (isdigit(word1[i])){
            printf("Enter just words not numbers.\n");
            return 1;
        }
    }

    string word2 = get_string("Player 2: ");

    for (int i = 0; i < strlen(word2); i++){
        if (isdigit(word2[i])){
            printf("Enter just words not numbers.\n");
            return 1;
        }
    }

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2){
        printf("Player 1 Wins!");
    }
    else if (score1 < score2){
        printf("Player 2 Wins!");
    }
    else{
        printf("Tie!");
    }
    printf("\n");
    return 0;
}

int compute_score(string word)
{
    int count = 0;
    int index = 0;

    for (int i = 0; i < strlen(word); i++){
        if (isalpha(word[i])){
            if (isupper(word[i])){
                index = word[i] - 'A';
                count += POINTS[index];
            }
            if (islower(word[i])){
                index = word[i] - 'a';
                count += POINTS[index];
            }
        }
    }
    return count;
}