#include <stdio.h>
int binarySearch(int arr[], int n, int key){
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n; 
    scanf("%d", &n);
    int arr[n]; 
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    int key;
    scanf("%d", &key);
    int index = binarySearch(arr, n, key);
    if (index != -1) {
        printf("Element %d is located at index %d\n", key, index);
    } else {
        printf("Element is not found\n");
    }

    return 0;
}

