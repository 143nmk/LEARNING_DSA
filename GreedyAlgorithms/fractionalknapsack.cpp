/* Cpp code for fractional knapsack problem */

#include <bits/stdc++.h>
using namespace std;

int fractionalKnapsack(vector<int> &profits, vector<int> &weights, int W)
{
    vector<pair<int, int>> P_by_W(weights.size(), make_pair(0, 0));
    for (int i = 0; i < weights.size(); i++)
    {
        P_by_W[i] = make_pair((profits[i] / weights[i]), i);
    }
    sort(P_by_W.begin(), P_by_W.end(), greater<pair<int, int>>());
    for (auto p : P_by_W)
    {
        cout << p.first << " " << p.second << endl;
    }
    int total_profit = 0;

    for (int i = 0; i < weights.size(); i++)
    {
        int index = P_by_W[i].second;

        if (weights[index] <= W)
        {
            total_profit += (profits[index]);
            W = W - weights[index];
        }
        else
        {
            total_profit += (P_by_W[i].first * W);
            W = 0;
            break;
        }
    }
    return total_profit;
}

int main()
{
    vector<int> weights = {10, 20, 30};
    vector<int> profits = {60, 100, 120};
    int W = 50;
    cout << fractionalKnapsack(profits, weights, W) << endl;
}