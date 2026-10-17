
#include <stdio.h>

int binarySearch(int a[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (a[mid] == key)
        return mid;
    else if (key < a[mid])
        return binarySearch(a, low, mid - 1, key);
    else
        return binarySearch(a, mid + 1, high, key);
}

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int key = 30, n = 5;

    int result = binarySearch(a, 0, n - 1, key);

    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at index %d\n", result);

    return 0;
}

