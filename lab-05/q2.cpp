#include <iostream>
using namespace std;

#define N 5

int maze[N][N] = {
    {1,0,1,1,1},
    {1,1,1,0,1},
    {0,0,1,1,1},
    {1,1,0,1,0},
    {1,1,1,1,1}
};

int sol[N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isSafe(int x, int y) {
    return (x>=0 && y>= 0 && x<N && y<N && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMazeUtil(int x, int y) {
    if (x==N-1 && y==N-1) {
        sol[x][y] = 1;
    return true;
}
if (isSafe(x, y)) {
    sol[x][y] = 1;
    for (int i=0; i<4; i++) {
        if(solveMazeUtil(x + dx[i], y + dy[i])) return true;
    }
    sol[x][y] = 0;
    return false;
}
return false;
}

void solveMaze() {
for (int i=0; i<N; i++)
    for (int j = 0; j < N; j++)
        sol[i][j] = 0;

if (solveMazeUtil(0, 0)) {
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++)
        cout << sol[i][j] << " ";
        cout << endl;
}
} else {
    cout << "No Solution" << endl;
}
}

int main() {
    solveMaze();
}
