// arr 대신 vector 사용해보기
// int * int가 int값을 초과하지 않는지
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    //bool* eratos = new bool[n+1];
    vector<bool> eratos(n+1, true);

    //for (int i = 2; i <= n; i++)
    //{
    //    eratos[i] = true;
    //}

    //for (int i = 2; i * i <= n; i++)
    int i;
    for (i = 2; i * i <= n; i++)
    {
        if (eratos[i])
        {
            answer++;
            
            for (int j = i * i; j <= n; j += i)
            {
                eratos[j] = false;
            }
        }
    }
    
    // for (int i = 2; i <= n; i++)
    // {
    //     if (eratos[i])
    //     {
    //         answer++;
    //     }
    // }
    for (; i <= n; i++)
    {
        if(eratos[i])
            answer++;
    }

    return answer;
}