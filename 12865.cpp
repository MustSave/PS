#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;

    //scanf("%d %d", &N, &K);
    cin >> N >> K;

    int** arr;
    arr = new int* [N];
    for(int i = 0; i < N; i++){
        arr[i] = new int[2];
        cin >> arr[i][0] >> arr[i][1];
    }

    int** v2;
    v2 = new int* [K+1];
    for(int i = 0; i < K+1; i++){
        v2[i] = new int[N+1] {};
    }

    for (int i = 1; i < N+1; i++){
        for (int j = 0; j < K+1; j++){
            if (j-arr[i-1][0] >= 0) {
                v2[j][i] = max(v2[j][i-1], v2[j-arr[i-1][0]][i-1] + arr[i-1][1]);
            }
            else {
                v2[j][i] = v2[j][i-1];
            }
        }
    }

    printf("%d", v2[K][N]);

    return 0;
}