#include <string>
#include <vector>
#include <queue>

using namespace std;
#pragma region Priority Queue
// long long solution(int n, vector<int> times) {
//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
//     pair<long long, int> t;
//     vector<int>::iterator iter;

// #pragma region Timeout해결을 위한 부분
//     double workSpeed = 0;
//     for (iter = times.begin(); iter < times.end(); iter++)
//     {
//         workSpeed += 1.0f / *iter;
//     }

//     long long eta = (long long)(n / workSpeed);

//     for (iter = times.begin(); iter < times.end(); iter++)
//     {
//         long long i = eta / *iter;
//         pq.push(make_pair(*iter * (i+1), *iter));
//         n -= i;
//     }
// #pragma endregion

//     while (n > 0)
//     {
//         t = pq.top();
//         pq.pop();
//         pq.push(make_pair(t.first + t.second, t.second));
//         n--;
//     }

//     return t.first;
// }
#pragma endregion

#pragma region Binary Search // 대충은 알겠는데 확실하게는 모르겠다...
long long solution(int n, vector<int> times)
{
    long long left = 0, mid = 0, right = 1e9 * n, answer = right;

    double workSpeed = 0;
    int lazy = 0;
    for (int i = 0; i < times.size(); i++)
    {
        workSpeed += (double)1.0 / times[i];
        if (times[i] > lazy)
            lazy = times[i];
    }

    left = n / workSpeed - lazy;
    right = answer = left + lazy + lazy;

    while (left <= right)
    {
        mid = (left + right) >> 1;

        long long tmp = 0;
        for (auto x : times) // double이 아니라 long으로 하는 이유???
            tmp += mid / x;

        if (tmp >= n)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

#pragma endregion

#include<iostream>
void main()
{
    cout << solution(6, vector<int>{7, 10});
}