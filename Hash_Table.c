#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct HashTbl;
typedef struct HashTbl *HashTable;

struct HashTbl {
    int TableSize;
    ElementType *TheLists;
};

HashTable InitTable(int TableSize) {
    HashTable H;
    int i;

    H = malloc(sizeof(struct HashTbl));
    if (H == NULL) {
        printf("Out of space!!!\n");
        return NULL;
    }

    H->TableSize = TableSize;
    H->TheLists = malloc(sizeof(ElementType) * H->TableSize);
    if (H->TheLists == NULL) {
        printf("Out of space!!!\n");
        return NULL;
    }

    for (i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = -1;
    }

    return H;
}

int Hash(ElementType Key, int TableSize) {
    return Key % TableSize;
}

void Insert(ElementType Key, HashTable H) {
    int Pos = Hash(Key, H->TableSize);
    int initialPos = Pos;

    while (H->TheLists[Pos] != -1) {
        Pos++;
        if (Pos >= H->TableSize)
            Pos = 0;
        if (Pos == initialPos) {
            printf("Hash table is full!\n");
            return;
        }
    }

    H->TheLists[Pos] = Key;
}

int main() {
    HashTable H;
    ElementType value;
    int TableSize, input;
    printf("Enter the number of Total Hash Size(m): ");
    scanf("%d", &TableSize);
    printf("Enter the number of Hash to receive input: ");
    scanf("%d", &input);
    H = InitTable(TableSize);
    for (int i = 0; i < input; i++) {
        printf("Enter the Hash Value: ");
        scanf("%d", &value);
        Insert(value, H);
    }
    printf("\n\nFindHash\n");
    for (int i = 0; i < TableSize; i++) {
        if (H->TheLists[i] != -1) {
            printf("H->TheLists[%d] = %d\n", i, H->TheLists[i]);
        } else {
            printf("H->TheLists[%d] = NULL\n", i);
        }
    }
    free(H->TheLists);
    free(H);
    return 0;
}
