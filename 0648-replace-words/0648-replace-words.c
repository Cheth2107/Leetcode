#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the Trie node structure
typedef struct TrieNode {
    struct TrieNode* children[26];
    bool isEndOfWord;
} TrieNode;

// Function to create a new Trie node
TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    newNode->isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a word into the Trie
void insert(TrieNode* root, char* word) {
    TrieNode* node = root;
    while (*word) {
        if (node->children[*word - 'a'] == NULL) {
            node->children[*word - 'a'] = createNode();
        }
        node = node->children[*word - 'a'];
        word++;
    }
    node->isEndOfWord = true;
}

// Function to find the shortest root in the Trie for a given word
char* findRoot(TrieNode* root, char* word) {
    TrieNode* node = root;
    char* prefix = word;
    while (*word) {
        if (node->children[*word - 'a'] == NULL) {
            return NULL;
        }
        node = node->children[*word - 'a'];
        word++;
        if (node->isEndOfWord) {
            // Temporarily null-terminate the root
            char* temp = word;
            *temp = '\0';
            return strdup(prefix);
        }
    }
    return NULL;
}

// Function to replace words in the sentence with their roots
char* replaceWords(char** dictionary, int dictionarySize, char* sentence) {
    // Step 1: Build the Trie
    TrieNode* root = createNode();
    for (int i = 0; i < dictionarySize; i++) {
        insert(root, dictionary[i]);
    }

    // Step 2: Process the sentence
    char* result = (char*)malloc(strlen(sentence) + 1);
    char* resultPtr = result;
    char* word = strtok(sentence, " ");
    
    while (word != NULL) {
        char* replacement = findRoot(root, word);
        if (replacement != NULL) {
            strcpy(resultPtr, replacement);
            resultPtr += strlen(replacement);
            free(replacement);
        } else {
            strcpy(resultPtr, word);
            resultPtr += strlen(word);
        }
        word = strtok(NULL, " ");
        if (word != NULL) {
            *resultPtr = ' ';
            resultPtr++;
        }
    }
    *resultPtr = '\0';
    
    return result;
}


