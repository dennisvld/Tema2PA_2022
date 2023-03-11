#include <bits/stdc++.h>
using namespace std;

ifstream fin("fortificatii.in");
ofstream fout("fortificatii.out");

const int DIM = 1e5 + 5;
const long long INF = (1LL<<40);

int n, m, b;
long long dist[DIM], st, dr, mid, k;
bool in_imperiu[DIM];
vector<int> barbari;
vector< pair<int, long long> > edges[DIM];
priority_queue< pair<long long, int>, vector< pair<long long, int> >,
 greater< pair<long long, int> > > q;

bool check(long long time) {
    long long needed = 0;
    for (int j = 0 ; j < barbari.size(); j++) {
        int nod = barbari[j];
        for (int i = 0; i < edges[nod].size(); i++) {
            int vecin = edges[nod][i].first;
            long long cost = edges[nod][i].second;
            if (in_imperiu[vecin] == false)
                continue;
            if (dist[vecin] + cost < time)
                needed += time - (dist[vecin] + cost);
        }
    }
    return needed <= k;
}

int main() {
    fin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        in_imperiu[i] = true;
        dist[i] = INF;
    }

    fin >> b;
    for (int i = 1; i <= b; i++) {
        int x; fin >> x;
        barbari.push_back(x);
        in_imperiu[x] = false;
    }

    for (int i = 1; i <= m; i++) {
        int x, y;
        long long z;
        fin >> x >> y >> z;
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }

    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        long long dst = q.top().first;
        int nod = q.top().second;
        q.pop();
        if (dist[nod] != dst)
            continue;
        for (int i = 0; i < edges[nod].size(); i++) {
            int vecin = edges[nod][i].first;
            long long cost = edges[nod][i].second;
            if (!in_imperiu[vecin])
                continue;
            if ( dist[vecin] > dist[nod] + cost ) {
                dist[vecin] = dist[nod] + cost;
                q.push({dist[vecin], vecin});
            }
        }
    }

    st = 0;
    dr = INF;
    while (st <= dr) {
        mid = ((st + dr) >> 1);
        if (check(mid)) {
            st = mid + 1;
        } else {
            dr = mid - 1;
        }
    }
    fout << dr;
    return 0;
}
