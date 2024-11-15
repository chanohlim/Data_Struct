#include <stdio.h>

void insertionSort(int arr[], int n) {

    int i, key, j;
    for (i = 1; i < n; i++) {
        printf("Sort %d: ", i);
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;

        for (j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

int main() {

    int input = 8;
    int arr[8] = {34, 57, 33, 2 ,5555, 358, 994,3};

    printf("정렬 전: ");
    for (int i = 0; i < input; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
    insertionSort(arr, input);

    printf("\n정렬 후: ");
    for (int i = 0; i < input; i++)
        printf("%d ", arr[i]);

}
