#include <stdbool.h>
#include <stdlib.h>

// Define a hash map node structure
struct HashMapNode {
    int key;
    int value;
    struct HashMapNode* next;
};

// Function to create a new hash map node
struct HashMapNode* createNode(int key, int value) {
    struct HashMapNode* newNode = (struct HashMapNode*)malloc(sizeof(struct HashMapNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Hash function
unsigned int hash(int key, int size) {
    return abs(key) % size;
}

// Function to insert into the hash map
void insert(struct HashMapNode** hashMap, int size, int key, int value) {
    unsigned int index = hash(key, size);
    struct HashMapNode* newNode = createNode(key, value);
    newNode->next = hashMap[index];
    hashMap[index] = newNode;
}

// Function to find a value in the hash map
bool find(struct HashMapNode** hashMap, int size, int key, int* value) {
    unsigned int index = hash(key, size);
    struct HashMapNode* current = hashMap[index];
    while (current) {
        if (current->key == key) {
            *value = current->value;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool checkSubarraySum(int* nums, int numsSize, int k) {
    if (numsSize < 2) return false;

    // Allocate hash map
    int hashMapSize = 1000; // You can adjust the size based on needs
    struct HashMapNode** hashMap = (struct HashMapNode**)calloc(hashMapSize, sizeof(struct HashMapNode*));

    // Initial conditions
    int prefixSum = 0;
    insert(hashMap, hashMapSize, 0, -1); // Handle the case where the subarray starts from the beginning

    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        int remainder = k == 0 ? prefixSum : prefixSum % k;

        int previousIndex;
        if (find(hashMap, hashMapSize, remainder, &previousIndex)) {
            if (i - previousIndex > 1) { // Ensure the subarray length is at least 2
                free(hashMap);
                return true;
            }
        } else {
            insert(hashMap, hashMapSize, remainder, i);
        }
    }

    free(hashMap);
    return false;
}
