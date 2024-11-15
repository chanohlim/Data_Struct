#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOOM_FILTER_SIZE 10
#define NUM_HASH_FUNCTIONS 3

typedef struct BloomFilter {
    bool *bitArray;
    int size;
} BloomFilter;

BloomFilter* initBloomFilter(int size) {
    BloomFilter *filter = (BloomFilter*)malloc(sizeof(BloomFilter));
    if (filter == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    filter->bitArray = (bool*)calloc(size, sizeof(bool));
    if (filter->bitArray == NULL) {
        printf("Memory allocation error\n");
        free(filter);
        exit(1);
    }

    filter->size = size;
    return filter;
}

void destroyBloomFilter(BloomFilter *filter) {
    free(filter->bitArray);
    free(filter);
}

int hash1(int key, int size) {
    return key % size;
}

int hash2(int key, int size) {
    return (key / size) % size;
}

int hash3(int key, int size) {
    return (key / size / size) % size;
}

void insertBloomFilter(BloomFilter *filter, int key) {
    int hashValues[NUM_HASH_FUNCTIONS] = {
            hash1(key, filter->size),
            hash2(key, filter->size),
            hash3(key, filter->size)
    };

    for (int i = 0; i < NUM_HASH_FUNCTIONS; i++) {
        filter->bitArray[hashValues[i]] = true;
    }
}

bool isMemberBloomFilter(BloomFilter *filter, int key) {
    int hashValues[NUM_HASH_FUNCTIONS] = {
            hash1(key, filter->size),
            hash2(key, filter->size),
            hash3(key, filter->size)
    };

    for (int i = 0; i < NUM_HASH_FUNCTIONS; i++) {
        if (!filter->bitArray[hashValues[i]]) {
            return false;
        }
    }
    return true;
}

int main() {
    BloomFilter *filter = initBloomFilter(BLOOM_FILTER_SIZE);

    int inputs[] = {15, 23, 37, 42, 56};
    int numInputs = sizeof(inputs) / sizeof(inputs[0]);

    for (int i = 0; i < numInputs; i++) {
        insertBloomFilter(filter, inputs[i]);
    }

    int testInputs[] = {15, 23, 78, 90, 56};
    int numTestInputs = sizeof(testInputs) / sizeof(testInputs[0]);

    for (int i = 0; i < numTestInputs; i++) {
        if (isMemberBloomFilter(filter, testInputs[i])) {
            printf("%d is probably in the filter.\n", testInputs[i]);
        } else {
            printf("%d is definitely not in the filter.\n", testInputs[i]);
        }
    }

    destroyBloomFilter(filter);
    return 0;
}
