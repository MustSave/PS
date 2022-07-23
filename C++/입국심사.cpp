#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> times) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pair<long long, int> t;
    vector<int>::iterator iter;

    double d=0;

    for (iter = times.begin(); iter < times.end(); iter++)
    {
        d += 1.0f / *iter;
    }

    long long eta = (long long)(n / d);

    for (iter = times.begin(); iter < times.end(); iter++)
    {
        long long i = eta / *iter;
        pq.push(make_pair(*iter * (i+1), *iter));
        n -= i;
    }

    while (n > 0)
    {
        t = pq.top();
        pq.pop();
        pq.push(make_pair(t.first + t.second, t.second));
        n--;
    }

    return t.first;
}

#include<iostream>
void main()
{
    cout << solution(6, vector<int>{7, 10});
}