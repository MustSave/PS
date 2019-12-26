#include <stdio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define N 20

int n;
int max = 0;
bool lock[N][N];

void copy(int a[N][N], int b[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

void clear()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            lock[i][j] = false;
        }
    }
}

void move(int map[N][N], int direction)
{
    int a;
    if (direction == UP)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                a = 1;
                while (i - a >= 0) // 0이 아니거나 index를 벗어남
                {
                    if (map[i - a][j] == 0)
                    {
                        a++;
                    }
                    else
                        break;
                }
                
                if (i-a >= 0 && map[i - a][j] == map[i][j] && !lock[i - a][j])
                {
                    map[i - a][j] = map[i][j] * 2;
                    lock[i - a][j] = true;
                    map[i][j] = 0;
                }
                else
                {
                    map[i - a + 1][j] = map[i][j];
                    if (a != 1)
                        map[i][j] = 0;
                }
            }
        }
    }

    if (direction == DOWN)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = n-1; i >= 0; i--)
            {
                a = 1;
                while (i + a <= n-1) // 0이 아니거나 index를 벗어남
                {
                    if (map[i + a][j] == 0)
                    {
                        a++;
                    }
                    else
                        break;
                }

                if (i + a < n && map[i + a][j] == map[i][j] && !lock[i + a][j])
                {
                    map[i + a][j] = map[i][j] * 2;
                    lock[i + a][j] = true;
                    map[i][j] = 0;
                }
                else
                {
                    map[i + a - 1][j] = map[i][j];
                    if (a != 1)
                        map[i][j] = 0;
                }
            }
        }
    }

    if (direction == LEFT)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a = 1;
                while (j - a >= 0) // 0이 아니거나 index를 벗어남
                {
                    if (map[i][j-a] == 0)
                    {
                        a++;
                    }
                    else
                        break;
                }

                if (j-a >= 0 && map[i][j-a] == map[i][j] && !lock[i][j-a])
                {
                    map[i][j-a] = map[i][j] * 2;
                    lock[i][j-a] = true;
                    map[i][j] = 0;
                }
                else
                {
                    map[i][j-a+1] = map[i][j];
                    if (a != 1)
                        map[i][j] = 0;
                }
            }
        }
    }

    if (direction == RIGHT)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n-1; j >= 0; j--)
            {
                a = 1;
                while (j + a <= n-1) 
                {
                    if (map[i][j+a] == 0)
                    {
                        a++;
                    }
                    else
                        break;
                }

                if (j+a < n && map[i][j+a] == map[i][j] && !lock[i][j+a])
                {
                    map[i][j+a] = map[i][j] * 2;
                    lock[i][j+a] = true;
                    map[i][j] = 0;
                }
                else
                {
                    map[i][j+a-1] = map[i][j];
                    if (a != 1)
                        map[i][j] = 0;
                }
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            if (map[k][l] > max) max = map[k][l];
        }
    }

    clear();
}

void DFS(int map[N][N], int depth)
{
    if (depth > 5)
        return;

    int tmp[N][N];

    copy(tmp, map);
    move(tmp, UP);
    DFS(tmp, depth + 1);

    copy(tmp, map); 
    move(tmp, DOWN);
    DFS(tmp, depth + 1);

    copy(tmp, map);
    move(tmp, LEFT);
    DFS(tmp, depth + 1);

    copy(tmp, map);
    move(tmp, RIGHT);
    DFS(tmp, depth + 1);
}

int main()
{
    scanf("%d", &n);

    int map[N][N];
    for (int k = 0; k < N; k++)
    {
        for (int l = 0; l < N; l++)
        {
            map[k][l] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    DFS(map, 1);
    printf("%d", max);

}