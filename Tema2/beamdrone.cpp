#include <bits/stdc++.h>
using namespace std;

const int DIM = 1005;

ifstream fin("beamdrone.in");
ofstream fout("beamdrone.out");

int n, m, xi, yi, xf, yf;
char a[DIM][DIM];
int dp[DIM][DIM][4];
// 0, 1, 2, 3 = N, E, S, W
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
deque< pair<int, pair<int, int> > > my_queue;

int main() {
    fin >> n >> m;
    fin >> xi >> yi >> xf >> yf;
    for (int i = 0; i < n; i++)
        fin >> a[i];

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int d = 0; d < 4; d++) {
        dp[xi][yi][d] = 0;
        my_queue.push_back({d, {xi, yi}});
    }

    while (!my_queue.empty()) {
        int dir = my_queue.front().first;
        int x = my_queue.front().second.first;
        int y = my_queue.front().second.second;
        my_queue.pop_front();
        // pastrez directia
        int x_next = x + dx[dir];
        int y_next = y + dy[dir];
        if (0 <= x_next && x_next < n && 0 <= y_next && y_next < m
             && a[x_next][y_next] ==
             '.' && dp[x_next][y_next][dir] > dp[x][y][dir]) {
            dp[x_next][y_next][dir] = dp[x][y][dir];
            my_queue.push_front({dir, {x_next, y_next}});
        }

        // ma intorc la 90 de grade la dreapta pe loc
        int d = (dir + 1) % 4;
        if (dp[x][y][d] > dp[x][y][dir] + 1) {
            dp[x][y][d] = dp[x][y][dir] + 1;
            my_queue.push_back({d, {x, y}});
        }

        // ma intorc la 90 de grade la stanga pe loc
        d = (dir - 1 + 4) % 4;
        if (dp[x][y][d] > dp[x][y][dir] + 1) {
            dp[x][y][d] = dp[x][y][dir] + 1;
            my_queue.push_back({d, {x, y}});
        }
    }

    int answer = 0x3f3f3f3f;
    for (int d = 0; d < 4; d++)
        answer = min(answer, dp[xf][yf][d]);
    fout << answer;
    return 0;
}
