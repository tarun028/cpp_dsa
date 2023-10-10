#include<iostream>
using namespace std;

int mountain(int arr[], int size) {
    int s = 0;
    int e = size - 1;
    int mid = (s + e) / 2;

    while (s <= e) {
        if (arr[mid] < arr[mid + 1]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = (s + e) / 2;  // Remove the declaration of int mid inside the loop
    }
    return s;
}

int main() {
    int mount[5] = {3, 4, 5, 1};
    cout << "Big " << mountain(mount, 5);
    return 0;
}
