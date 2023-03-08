#include <stdio.h>
#include <vector>
using namespace std;

int solution(int N, vector<pair<int, int>> matrix)
{
    int** DP = new int*[N];
    for (int i = 0; i < N; i++)
    {
        DP[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            DP[i][j] = 0;
        }
    }

    for (int length = 2; length <= N; length++)
    {
        for (int i = 0; i < N-length+1; i++)
        {
            DP[i][i+length-1] = DP[i][i+length-2] + matrix[i].first * matrix[i+length-1].first * matrix[i+length-1].second;
            for (int j = 0; j < length-1; j++)
            {
                DP[i][i+length-1] = min(DP[i][i+j] + DP[i+j+1][i+length-1] + matrix[i].first * matrix[i+j].second * matrix[i+length-1].second, DP[i][i+length-1]);
            }
            //printf("DP[%d][%d] : %d\n", i, i+length-1, DP[i][i+length-1]);
        }
    }

    return DP[0][N-1];
}

int main()
{
    int N;
    int r, c;
    vector<pair<int, int>> matrix;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &r, &c);
        matrix.push_back(make_pair(r, c));
    }

    printf("%d", solution(N, matrix));
}