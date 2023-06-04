#include<stdio.h>
void countingSort(int arr[], int size, int range) {
    int count[range + 1];
    int output[size];
    for (int i = 0; i <= range; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= range; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}
int main() {
    int arr[100], size, range = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if(arr[i]>range){
            range = arr[i];
        }
    }
    countingSort(arr, size, range);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
