#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(int N, vector<pair<int, int>> conf)
{
    int answer = 0;
    sort(conf.begin(), conf.end(), compare); // 끝나는 시간 기준 오름차순 정렬

    int endTime = 0;
    vector<pair<int, int>>::iterator iter;

    for (iter = conf.begin(); iter < conf.end(); iter++)
    {
        if ((*iter).first >= endTime)
        {
            answer++;
            endTime = (*iter).second;
        }
    }

    return answer;
}

int main()
{
    int N;
    int start, end;

    vector<pair<int, int>> conf;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &start, &end);
        conf.push_back(make_pair(start, end));
    }

    printf("%d", solution(N, conf));
    return 0;
}