#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    
    int unknownNums = 0;
    int matchNums = 0;

    for (int i = 0; i < lottos_len; i++)
    {
        if (lottos[i] == 0)
        {
            unknownNums++;
            continue;
        }

        for (int j = 0; j < win_nums_len; j++)
        {
            if (win_nums[j] == lottos[i])
            {
                matchNums++;
                break;
            }
        }
    }

    answer[1] = matchNums >= 2 ? 7 - matchNums : 6;
    answer[0] = unknownNums == 6 ? 1 : answer[1] - unknownNums;

    return answer;
}