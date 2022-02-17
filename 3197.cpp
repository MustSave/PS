#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

typedef struct {
    int x;
    int y;
    int time = 0;
} Coord;

int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> ori[2];
int R, C;
char arr[1500][1501];

bool bounderycheck(int i, int j) {
    if (i+1 < R and (arr[i+1][j]  == '.' or arr[i+1][j] == 'L')){
        return true;}
    else if (i-1 >= 0 and (arr[i-1][j] == '.' or arr[i-1][j] == 'L')){
        return true;}
    else if (j+1 < C and (arr[i][j+1] == '.' or arr[i][j+1] == 'L')){
        return true;}
    else if (j-1 >= 0 and (arr[i][j-1] == '.' or arr[i][j-1] == 'L')){
        return true;}
    return false;
}

void melt(int i, int j, int t, queue<Coord> &q) {
    arr[i][j] = '.';
    int dx, dy;
    for (int a = 0; a < 4; a++) { // 얼음 좌표, 녹는시간 큐에 저장
        dx = direction[a][0];
        dy = direction[a][1];
        if (0 <= i+dx && i+dx < R && 0 <= j+dy && j+dy < C && arr[i+dx][j+dy] == 'X') {
           arr[i+dx][j+dy] = '1';
           q.push({i+dx, j+dy, t+1}); 
        }
    }
}

bool ismeet(queue<pair<int, int>> &m) {
    int x, y, dx, dy;
    char c;
    pair<int, int> tmp;
    queue <pair<int, int>> t;
    bool next = false;

    while (!m.empty()) { // bfs 탐색하며 
        next = false;
        tmp = m.front();
        m.pop();
        x = tmp.first;
        y = tmp.second;
        
        for (int a = 0; a < 4; a++) {
            dx = direction[a][0];
            dy = direction[a][1];

            if (0 <= x+dx && x+dx < R && 0 <= y+dy && y+dy < C) {
                c = arr[x+dx][y+dy];
                if (c == '1') { // 영역 경계임을 표시
                    next = true;
                }
                else if (c == '.') { // 영역 넓히기
                    if (x+dx == ori[1].first && y+dy == ori[1].second) {
                        return true;
                    }
                    arr[x+dx][y+dy] = 'O';
                    m.push(make_pair(x+dx, y+dy));
                }
            }
        }
        if (next) {t.push(tmp);} // 경계를 따로 저장하여 다음턴에 경계부터 탐색
    }

    while(!t.empty()) {
        m.push(t.front());
        t.pop();
    }

    return false;
}

int main(){
    int l = 0;
    scanf("%d %d", &R, &C);

    queue <Coord> q;
    queue <pair<int, int>> m;
    
    char* tmp = new char[C+1];
    
    for (int i = 0; i < R; i++) {
        scanf("%s", tmp);
        for (int j = 0; j < C; j++) {
            arr[i][j] = tmp[j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 'X' && bounderycheck(i, j)) { // 경계면 큐1에 저장
                q.push({i, j, 1});
                arr[i][j] = '1';
            }
            else if (arr[i][j] == 'L') {
                arr[i][j] = '.';
                ori[l++] = make_pair(i, j);
            }
        }
    }

    m.push(ori[0]);
    arr[ori[0].first][ori[0].second] = 'O';

    int time = 0;
    Coord pop;
    while (!q.empty()) {
        pop = q.front();
        
        if (pop.time == time) { // 1틱동안 얼음 녹이기
            q.pop();
            melt(pop.x, pop.y, time, q);
        }
        else { // 1틱 이후 만나는지 확인
            if (ismeet(m)) {break;}
            time++;
        }
    }

    printf("%d", time);
    return 0;
}