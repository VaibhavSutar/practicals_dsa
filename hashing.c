#include <stdio.h>

#define SIZE 10

// Function to perform hashing using the divisive method
int hash(int key) {
    return key % SIZE;
}

// Function to insert a key into the hash table using linear probing
void insert(int hashTable[], int key) {
    int index = hash(key);

    // If the initial index is occupied, find the next available slot using linear probing
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    // Insert the key at the determined index
    hashTable[index] = key;
}

// Function to search for a key in the hash table using linear probing
int search(int hashTable[], int key) {
    int index = hash(key);

    // Search for the key using linear probing until an empty slot or the key is found
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index; // Key found
        }
        index = (index + 1) % SIZE;
    }

    return -1; // Key not found
}

// Function to display the hash table
void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t", hashTable[i]);
    }
    printf("\n");
}

int main() {
    int hashTable[SIZE];

    // Initialize the hash table with -1 to indicate empty slots
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    // Number of elements to be inserted
    int n;

    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);

    printf("Enter the elements to be inserted:\n");
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insert(hashTable, key);
    }

    // Display the final hash table
    display(hashTable);

    // Search for a key in the hash table
    int searchKey;
    printf("Enter the key to search: ");
    scanf("%d", &searchKey);

    int result = search(hashTable, searchKey);
    if (result != -1) {
        printf("Key %d found at index %d.\n", searchKey, result);
    } else {
        printf("Key %d not found in the hash table.\n", searchKey);
    }

    return 0;
}
