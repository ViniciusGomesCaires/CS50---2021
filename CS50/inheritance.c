#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *parent = malloc(sizeof(person));

    if (parent == NULL)
    {
        printf("Falha na alocação de memoria!");
    }

    // Generation with parent data
    if (generations > 1)
    {
        // TODO: Recursively create blood type histories for parents
        parent->parents[0] = create_family(generations - 1);
        parent->parents[1] = create_family(generations - 1);


        // TODO: Randomly assign child alleles based on parents
        parent->alleles[0] = parent->parents[0]->alleles[rand() % 2];
        parent->alleles[1] = parent->parents[1]->alleles[rand() % 2];

    }

    // Generation without parent data
    else
    {
        // TODO: Set parent pointers to NULL
        parent->parents[0] = NULL;
        parent->parents[1] = NULL;

        // TODO: Randomly assign alleles
        parent->alleles[0] = random_allele();
        parent->alleles[1] = random_allele();
    }

    // TODO: Return newly created person
    return parent;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // Handle base case
    if (p == NULL)
    {
        free(p);
    }
    else
    {
        // Free parents
        free_family(p->parents[0]);
        free_family(p->parents[1]);

        // Free child
        free(p);
    }
}
