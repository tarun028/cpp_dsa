#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaximumPoints(vector<int>& markers) {
    // Sort the markers in descending order
    sort(markers.rbegin(), markers.rend());

    // Initialize variables
    int jamesPoints = 0;
    int bobPoints = 0;

    // Iterate over the markers
    for (int i = 0; i < markers.size(); i++) {
        // Alternate between James and Bob
        if (i % 2 == 0) {
            jamesPoints += markers[i];
        } else {
            bobPoints += markers[i];
        }
    }

    return jamesPoints;
}

int main() {
    int R;
    cin >> R;

    vector<int> markers(R);

    // Read the marker values
    for (int i = 0; i < R; i++) {
        cin >> markers[i];
    }

    // Call the function to find the maximum points
    int maxPoints = findMaximumPoints(markers);

    // Print the maximum number of points
    cout << maxPoints << endl;

    return 0;
}