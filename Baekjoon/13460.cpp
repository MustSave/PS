#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

struct balls
{
    int red_x, red_y, blue_x, blue_y, depth, prev;
} ball;

int hole_x;
int hole_y;

int GARO;
int SERO;
char map[10][10];
bool visit[10][10][10][10] = {false};

int move(int direction, int red_x, int red_y, int blue_x, int blue_y)
{
    int x = direction == LEFT ? -1 : direction == RIGHT ? 1 : 0;
    int y = direction == UP ? -1 : direction == DOWN ? 1 : 0;
    bool s = false;

    switch (direction)
    {
    case UP:
        s = red_y > blue_y ? true : false;
        break;
    case DOWN:
        s = red_y > blue_y ? false : true;
        break;
    case LEFT:
        s = red_x > blue_x ? true : false;
        break;
    case RIGHT:
        s = red_x > blue_x ? false : true;
        break;
    }

    while (1)
    {
        red_x += x;
        red_y += y;
        if (map[red_y][red_x] == '#')
        {
            red_x -= x;
            red_y -= y;
            break;
        }
        else if (map[red_y][red_x] == 'O') break;
    }

    while (1)
    {
        blue_x += x;
        blue_y += y;
        if (map[blue_y][blue_x] == '#')
        {
            blue_x -= x;
            blue_y -= y;
            break;
        }
        else if (map[blue_y][blue_x] == 'O') break;
    }

    if (blue_x == hole_x && blue_y == hole_y) return 1;
    else if (red_x == hole_x && red_y == hole_y) return 2;
    else if (red_x == blue_x && red_y == blue_y)
    {
        if (s)
        {
            red_x -= x;
            red_y -= y;
        }
        else
        {
            blue_x -= x;
            blue_y -= y;
        }
    }

    ball.red_x = red_x;
    ball.red_y = red_y;
    ball.blue_x = blue_x;
    ball.blue_y = blue_y;
    return 0;
}

int main()
{
    int dir[4] = {1, 0, 3, 2};

    std ::queue<balls> Q;
    scanf("%d %d", &SERO, &GARO);

    char c[GARO + 1];
    for (int i = 0; i < SERO; i++)
    {
        fflush(stdin);
        scanf("%s", c);
        for (int j = 0; j < GARO; j++)
        {
            if (c[j] == 'R')
            {
                ball.red_x = j;
                ball.red_y = i;
                c[j] = '.';
            }
            if (c[j] == 'B')
            {
                ball.blue_x = j;
                ball.blue_y = i;
                c[j] = '.';
            }
            if (c[j] == 'O')
            {
                hole_x = j;
                hole_y = i;
            }
            map[i][j] = c[j];
        }
    }

    ball.depth = 0;
    Q.push(ball);

    int ret, rx, ry, bx, by, d;
    bool stop = false;
    while (!Q.empty())
    {
        ball = Q.front();Q.pop();
        if (ball.depth > 9 || stop) break;

        rx = ball.red_x; ry = ball.red_y; bx = ball.blue_x; by = ball.blue_y; d = ball.depth;
        if (visit[rx][ry][bx][by]) continue; // 이 코드 지울 시 메모리 사용 늘어남

        for (int i = 0; i < 4; i++)
        {
            if (dir[i] == i) continue;

            ret = move(i, rx, ry, bx, by);
            if (ret == 2)
            {
                printf("%d\n", d + 1);
                stop = true;
                break;
            }
            else if (ret == 0)
            {
                ball.depth = d + 1;
                ball.prev = i;
                Q.push(ball); 
            }

        }
        visit[rx][ry][bx][by] = true;
    }
    !stop ? printf("%d\n", -1) : true;
}