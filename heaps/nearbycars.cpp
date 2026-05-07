#include <bits/stdc++.h>
using namespace std;

class Cars
{
public:
    int distance;
    int index;

    Cars(int distance, int index)
    {
        this->distance = distance;
        this->index = index;
    }

    bool operator<(const Cars &c) const
    {
        return this->distance > c.distance;
    }
};

void nearbycars(vector<pair<int, int>> &v, int k)
{
    priority_queue<Cars> pq;
    for (int i = 0; i < v.size(); i++)
    {
        int distance = v[i].first * v[i].first + v[i].second * v[i].second;
        pq.push(Cars(distance, i));
    }
    for (int i = 0; i < k; i++)
    {
        Cars car = pq.top();
        pq.pop();
        cout << v[car.index].first << " " << v[car.index].second << endl;
    }
}

int main()
{
    vector<pair<int, int>> v;

    v.push_back(make_pair(3, -3));
    v.push_back(make_pair(2, -2));
    v.push_back(make_pair(1, -1));
    int k = 2;
    nearbycars(v, k);
    return 0;
}