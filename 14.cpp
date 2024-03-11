#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

// Activity structure representing start time, finish time, and index
struct Activity {
    int start, finish, index;
};

// Function to compare activities based on their finish time
bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

// Activity selection function using greedy method
void activitySelection(const vector<Activity>& activities) {
    cout << "Selected Activities:\n";

    // Sort activities based on finish time
    vector<Activity> sortedActivities = activities;
    sort(sortedActivities.begin(), sortedActivities.end(), compareActivities);

    // Select the first activity
    cout << "(" << sortedActivities[0].start << ", " << sortedActivities[0].finish << ") ";

    // Initialize the index of the last selected activity
    int lastSelected = 0;

    // Iterate through the remaining activities
    for (int i = 1; i < sortedActivities.size(); ++i) {
        // If the current activity's start time is greater than or equal to the finish time
        // of the last selected activity, then select it
        if (sortedActivities[i].start >= sortedActivities[lastSelected].finish) {
            cout << "(" << sortedActivities[i].start << ", " << sortedActivities[i].finish << ") ";
            lastSelected = i;
        }
    }

    cout << "\n";
}

// Function to measure execution time for a given input size
double measureTime(int n) {
    vector<Activity> activities;
    for (int i = 0; i < n; ++i) {
        Activity activity;
        activity.start = rand() % 100;
        activity.finish = activity.start + rand() % 50;
        activity.index = i + 1;
        activities.push_back(activity);
    }

    clock_t start, end;
    start = clock();

    activitySelection(activities);

    end = clock();

    return double(end - start) / CLOCKS_PER_SEC;
}

int main() {
    // Input sizes
    vector<int> inputSizes = {10, 20, 30, 40, 50};

    // Measure execution time for each input size
    cout << "Execution times for different input sizes:\n";
    for (int size : inputSizes) {
        double executionTime = measureTime(size);
        cout << "Input size " << size << ": " << executionTime << " seconds\n";
    }

    return 0;
}