#include <iostream>
using namespace std;

void marge(int arr[], int l, int mid, int r) {
    int s1 = mid - l + 1;
    int s2 = r - mid;
    int *tempA = new int[s1];
    int *tempB = new int[s2];
    
    for (int i = 0; i < s1; i++) {
        tempA[i] = arr[l + i];
    }
    for (int i = 0; i < s2; i++) {
        tempB[i] = arr[mid + 1 + i];
    }

    int x = 0;
    int y = 0;
    int z = l; // Set z to the starting index l
    while (x < s1 && y < s2) {
        if (tempA[x] < tempB[y]) {
            arr[z] = tempA[x];
            x++;
        } else {
            arr[z] = tempB[y];
            y++;
        }
        z++;
    }
    while (x < s1) {
        arr[z] = tempA[x];
        x++;
        z++;
    }
    while (y < s2) {
        arr[z] = tempB[y];
        y++;
        z++;
    }

    delete[] tempA;
    delete[] tempB;
}

void marge_sort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        marge_sort(arr, l, mid);
        marge_sort(arr, mid + 1, r);
        marge(arr, l, mid, r);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    marge_sort(arr, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
    }
    return 0;
}
