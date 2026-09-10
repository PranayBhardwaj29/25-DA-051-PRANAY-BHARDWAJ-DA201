// Name: Pranay Bhardwaj
// Roll Number: 25/DA/051
// Write a program to solve Activity Selection problem using the Greedy approach

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity
{
    int start, finish;
};

bool compare(Activity a, Activity b)
{
    return a.finish < b.finish;
}

int main()
{
    int n;
    cin >> n;

    vector<Activity> activities(n);

    for (int i = 0; i < n; i++)
        cin >> activities[i].start >> activities[i].finish;

    sort(activities.begin(), activities.end(), compare);

    cout << "Selected activities:\n";

    int lastFinish = -1;

    for (int i = 0; i < n; i++)
    {
        if (activities[i].start >= lastFinish)
        {
            cout << "(" << activities[i].start << ", "
                 << activities[i].finish << ")\n";
            lastFinish = activities[i].finish;
        }
    }

    return 0;
}