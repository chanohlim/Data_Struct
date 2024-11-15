#include <stdio.h>

int main() {

    int input = 10;
    int arr[10] = {7, 224, 33, 5,90, 22, 23, 6, 4, 5};

    int min = 0;
    int temp;

    printf("\n초기 배열: ");
    for(int i=0; i<input; i++){

        printf("%d ",arr[i]);

    }
    printf("\n\n");

    for(int i=0; i<input-1; i++){

        min = i;
        for(int j=i+1; j<input; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        printf("Sort %d: ",i+1);
        for(int j=0; j<input; j++)
            printf("%d ",arr[j]);
        printf("\n");

    }

}

