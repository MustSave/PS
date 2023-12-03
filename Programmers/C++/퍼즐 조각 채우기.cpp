#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

class Puzzle {
    int r;
    int c;
    vector<pair<int,int>> coords;

public:
    Puzzle(int r, int c, vector<pair<int,int>>& coords) {
        this -> r = r;
        this -> c = c;
        this -> coords = coords;
    }

    bool operator==(const Puzzle& puzzle) const {
        if (this->r != puzzle.r || this->c != puzzle.c || this->coords.size() != puzzle.coords.size()) return false;
        for (int i = 0; i < this->coords.size(); i++) {
            if (this->coords[i].first != puzzle.coords[i].first || this->coords[i].second != puzzle.coords[i].second)
                return false;
        }
        return true;
    }

    int getCoordSize() {
        return this->coords.size();
    }

    Puzzle rotateRight() {
        vector<pair<int,int>> rotatedCoords;
        for (const auto& coord: this->coords) {
            rotatedCoords.push_back({coord.second, this->r - 1 - coord.first});
        }
        sort(rotatedCoords.begin(), rotatedCoords.end());
        return Puzzle(this->c, this->r, rotatedCoords);
    }
};

unordered_map<int, vector<Puzzle>> s;

Puzzle bfs(vector<vector<int>>& game_board, int x, int y, int target) {
    int maxX = 0, minX = 100, maxY = 0, minY = 100;
    vector<pair<int,int>> coords;
    queue<pair<int,int>> Q({{x, y}});
    
    while(!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        
        if (game_board[x][y] == target) continue;
        game_board[x][y] = target;
        coords.push_back({x, y});
        maxX = max(maxX, x); minX = min(minX, x);
        maxY = max(maxY, y); minY = min(minY, y);
        
        for (const auto& [dx, dy]: dir) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= game_board.size() || ny >= game_board[0].size() || game_board[nx][ny] == target) continue;
            Q.push({nx, ny});
        }
    }
    
    for (auto& coord: coords) {
        coord.first -= minX;
        coord.second -= minY;
    }
    sort(coords.begin(), coords.end());
    return Puzzle(maxX-minX+1, maxY-minY+1, coords);
}

vector<Puzzle> getAllPossibleRotatedPuzzle(Puzzle& puzzle) {
    vector<Puzzle> puzzles;
    puzzles.push_back(puzzle);
    for (int i = 0; i < 3; i++) {
        puzzle = puzzle.rotateRight();
        puzzles.push_back(puzzle);
    }
    return puzzles;
}

bool existMatchPuzzle(vector<Puzzle>& puzzles, Puzzle& targetPuzzle) {
    for (auto& puzzle: puzzles) {
        if (puzzle == targetPuzzle) {
            return true;
        }
    }
    return false;
}

int resolvePuzzle(Puzzle& puzzle) {
    for (auto it = s.begin(); it != s.end(); it++) {
        if (existMatchPuzzle(it->second, puzzle)) {
            s.erase(it);
            return puzzle.getCoordSize();
        }
    }
    return 0;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int key = 0;
    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board[0].size(); j++) {
            if (game_board[i][j] == 1) continue;
            auto puzzle = bfs(game_board, i, j, 1);
            auto puzzles = getAllPossibleRotatedPuzzle(puzzle);
            s.insert({key++, puzzles});
        }
    }
    
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[0].size(); j++) {
            if (table[i][j] == 0) continue;
            auto puzzle = bfs(table, i, j, 0);
            answer += resolvePuzzle(puzzle);
        }
    }
    return answer;
}