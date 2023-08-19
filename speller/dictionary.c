// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Counter for tracking the number of words loaded
unsigned int wordCount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get the hash value for the given word
    unsigned int index = hash(word);

    // Traverse the linked list at the index in the hash table
    node *cursor = table[index];
    while (cursor != NULL)
    {
        // Compare the word with the current node's word
        if (strcmp(cursor->word, word) == 0)
        {
            // Word found in the dictionary
            return true;
        }

        // Move to the next node
        cursor = cursor->next;
    }

    // Word not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Custom hash function: simple lowercase ASCII-based hash
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    // Initialize hash table
    for (unsigned int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Buffer for storing each word read from the file
    char buffer[LENGTH + 1];

    // Read words from the dictionary file
    while (fscanf(file, "%s", buffer) != EOF)
    {
        // Create a new node for each word
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(file);
            return false;
        }

        // Copy the word into the new node
        strcpy(newNode->word, buffer);

        // Hash the word to determine the index
        unsigned int index = hash(newNode->word);

        // Insert the new node at the beginning of the linked list
        newNode->next = table[index];
        table[index] = newNode;

        // Increase word count
        wordCount++;
    }

    // Close the dictionary file
    fclose(file);

    // Dictionary successfully loaded
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Helper function to free the linked list nodes recursively
void freeNodes(node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    // Recursively free the rest of the list
    freeNodes(ptr->next);

    // Free the current node
    free(ptr);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Free the memory allocated for each node in the hash table
    for (unsigned int i = 0; i < N; i++)
    {
        freeNodes(table[i]);
    }

    // Reset the word count
    wordCount = 0;

    // Dictionary successfully unloaded
    return true;
}
