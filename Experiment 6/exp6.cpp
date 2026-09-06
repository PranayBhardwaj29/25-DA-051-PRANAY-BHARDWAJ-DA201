// Name: Pranay Bhardwaj
// Roll Number: 25/DA/051
// Write a program to solve the Fractional Knapsack problem using the Greedy approach.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;
    double ratio;
};

int main()
{
    int n;
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; i++)
    {
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    int capacity;
    cin >> capacity;

    sort(items.begin(), items.end(), [](const Item &a, const Item &b)
         { return a.ratio > b.ratio; });

    double maxValue = 0;

    for (int i = 0; i < n && capacity > 0; i++)
    {
        if (items[i].weight <= capacity)
        {
            maxValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            maxValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    cout << maxValue << endl;

    return 0;
}