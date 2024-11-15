#include <stdio.h>
#include <time.h>
#include <ctype.h>
#define SWAP(a,b) {int tmp = a; a = b; b = tmp;}

int partition(int arr[], int low, int high){

    int pivot = arr[low];
    int i = low;
    int j = high + 1;

    while (i < j){
        do {
            i++;
        }while (arr[i] <= pivot);
        do{
            j--;
        }while (arr[j] > pivot);
        if (i<j){
            SWAP(arr[i],arr[j]);
        }
    }
    SWAP(arr[low],arr[j]);
    return j;

}

void quickSort(int arr[], int low, int high){

    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

}

int main() {

    // 변수 선언 및 초기화
    int data[2000010];
    int i = 0, j, k, num;
    float start,end,sort_time;

    // 1,000
    char * filename11 = "/Users/chanlim/Desktop/input/input_1,000.txt";
    FILE *fp1 = fopen(filename11,"r");

    if (fp1 == NULL){
        printf("Error: could not open file %s",filename11);
        return 1;
    }

    while (fscanf(fp1,"%d",&num) != EOF) {
        *(data + i) = num;
        i++;
    }

    fclose(fp1);


    // Quick Sort 정렬
    start = clock();
    quickSort(data,0,i - 1);
    end = clock();
    sort_time = (float)(end - start)/CLOCKS_PER_SEC;


    printf("\n1,000개 정렬에 소요된 시간: %f초",sort_time);

    // 5,000
    char * filename2 = "/Users/chanlim/Desktop/input/input_5,000.txt";
    FILE *fp2 = fopen(filename2,"r");

    if (fp2 == NULL){
        printf("Error: could not open file %s",filename2);
        return 1;
    }

    while (fscanf(fp2,"%d",&num) != EOF) {
        *(data + i) = num;
        i++;
    }

    fclose(fp2);


    // Quick Sort 정렬
    start = clock();
    quickSort(data,0,i - 1);
    end = clock();
    sort_time = (float)(end - start)/CLOCKS_PER_SEC;


    printf("\n5,000개 정렬에 소요된 시간: %f초",sort_time);

    // 10,000
    char * filename3 = "/Users/chanlim/Desktop/input/input_10,000.txt";
    FILE *fp3 = fopen(filename3,"r");

    if (fp3 == NULL){
        printf("Error: could not open file %s",filename3);
        return 1;
    }

    while (fscanf(fp3,"%d",&num) != EOF) {
        *(data + i) = num;
        i++;
    }

    fclose(fp3);


    // Quick Sort 정렬
    start = clock();
    quickSort(data,0,i - 1);
    end = clock();
    sort_time = (float)(end - start)/CLOCKS_PER_SEC;


    printf("\n10,000개 정렬에 소요된 시간: %f초",sort_time);

    // 50,000
    char * filename4 = "/Users/chanlim/Desktop/input/input_50,000.txt";
    FILE *fp4 = fopen(filename4,"r");

    if (fp4 == NULL){
        printf("Error: could not open file %s",filename4);
        return 1;
    }

    while (fscanf(fp4,"%d",&num) != EOF) {
        *(data + i) = num;
        i++;
    }

    fclose(fp4);


    // Quick Sort 정렬
    start = clock();
    quickSort(data,0,i - 1);
    end = clock();
    sort_time = (float)(end - start)/CLOCKS_PER_SEC;


    printf("\n50,000개 정렬에 소요된 시간: %f초",sort_time);

    // 100,000
    char * filename5 = "/Users/chanlim/Desktop/input/input_100,000.txt";
    FILE *fp5 = fopen(filename5,"r");

    if (fp5 == NULL){
        printf("Error: could not open file %s",filename5);
        return 1;
    }

    while (fscanf(fp5,"%d",&num) != EOF) {
        *(data + i) = num;
        i++;
    }

    fclose(fp5);


    // Quick Sort 정렬
    start = clock();
    quickSort(data,0,i - 1);
    end = clock();
    sort_time = (float)(end - start)/CLOCKS_PER_SEC;


    printf("\n100,000개 정렬에 소요된 시간: %f초",sort_time);

    // 500,000
    char * filename6 = "/Users/chanlim/Desktop/input/input_500,000.txt";
    FILE *fp6 = fopen(filename6,"r");

    if (fp6 == NULL){
        printf("Error: could not open file %s",filename6);
        return 1;
    }

    while (fscanf(fp6,"%d",&num) != EOF) {
        *(data + i) = num;
        i++;
    }

    fclose(fp6);


    // Quick Sort 정렬
    start = clock();
    quickSort(data,0,i - 1);
    end = clock();
    sort_time = (float)(end - start)/CLOCKS_PER_SEC;


    printf("\n500,000개 정렬에 소요된 시간: %f초",sort_time);

    // 1,000,000
    char * filename7 = "/Users/chanlim/Desktop/input/input_1,000,000.txt";
    FILE *fp7 = fopen(filename7,"r");

    if (fp7 == NULL){
        printf("Error: could not open file %s",filename7);
        return 1;
    }

    while (fscanf(fp7,"%d",&num) != EOF) {
        *(data + i) = num;
        i++;
    }

    fclose(fp7);


    // Quick Sort 정렬
    start = clock();
    quickSort(data,0,i - 1);
    end = clock();
    sort_time = (float)(end - start)/CLOCKS_PER_SEC;


    printf("\n1,000,000개 정렬에 소요된 시간: %f초\n",sort_time);
    return 0;
}
