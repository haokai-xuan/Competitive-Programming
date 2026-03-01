#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Groove {
    int x1, x2, y;
    bool operator<(const Groove& other) const {
        return y < other.y;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> pos(n + 1); // x pos of hunter i
    vector<int> posInv(n + 1); // hunter at pos i
    vector<Groove> grooves;

    for (int i = 1; i <= n; i++) {
        pos[i] = i;
        posInv[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Groove g;
        g.x1 = x1;
        g.x2 = x2;
        g.y = y1;
        grooves.push_back(g);
    }
    sort(grooves.begin(), grooves.end());

    for (int i = 0; i < m; i++) {
        int x1 = grooves[i].x1;
        int x2 = grooves[i].x2;
        int h1 = posInv[x1];
        int h2 = posInv[x2];
        
        pos[h1] = x2;
        pos[h2] = x1;
        posInv[x1] = h2;
        posInv[x2] = h1;
    }

    for (int i = 1; i <= n; i++)
        cout << pos[i] << '\n';

    return 0;
}