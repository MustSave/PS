#include <iostream>
#include <vector>
using namespace std;

int solution(int N, vector<int> price)
{
    int* DP = new int[N+1];

    for (int i = 1; i < N+1; i++)
    {
        if (i < price.size()+1)
            DP[i] = price[i-1];
        
        for (int j = 1; j <= i/2; j++)
        {
            DP[i] = max(DP[j] + DP[i-j], DP[i]);
        }
    }

    return DP[N];
}

int main()
{
    int N = 0;
    vector<int> price;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int p = 0;
        cin >> p; 
        price.push_back(p);
    }

    cout << solution(N, price);
}