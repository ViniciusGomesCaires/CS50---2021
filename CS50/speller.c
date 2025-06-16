#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>
#include "dictionary.h"

#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word [LENGTH + 1];
    struct node next;
}
node;

// Number of buckets in hash table
int count_words = 0;

// Hash table
nodetable[N];

// Returns true if word is in dictionary, else false
bool check(const char word)
{
    int hash_value = hash(word);
    nodetemp = table[hash_value];

    while (temp != NULL){
        if (strcasecmp(word, temp->word) == 0){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int index;
    int current_letter = 65;
    for (int i = 0; i < N; i++){

        if (toupper(word[0]) == current_letter){
            index = i;
        }
        current_letter++;
    }
    return index;
}
// Loads dictionary into memory, returning true if successful, else false
bool load(const char dictionary)
{
    FILEdictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL){
        return false;
    }

    char str[LENGTH + 1];
    while(fscanf(dictionary_file, "%s", str) != EOF){

        node n = malloc(sizeof(node));
        if (n == NULL){
            return false;
        }

        strcpy(n->word, str);
        int hash_value = hash(str);

        if (table[hash_value] == NULL){
            n->next = NULL;

        } else {
            n->next = table[hash_value];
        }
        table[hash_value] = n;
        count_words++;
    }

    fclose(dictionary_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i=0; i < N; i++){

        nodecursor = table[i];
        while(cursor != NULL){

            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        if (cursor == NULL){
            return true;
        }
    }
    return false;
}