//
// Created by neha2 on 10-04-2022.
//
#include <bits/stdc++.h>

using namespace std;

std::pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b) {
    return std::make_pair(a.first + b.first, a.second + b.second);
};

class pantry {
    enum direction {
        start, dir1, dir2, dir3, dir4
    };
public:
    int ans, m, n;
    int final_ans;
    void dfs(pair<int, int> source, pair<int, int> target, vector<vector<bool>> &visited,
             vector<pair<direction, pair<int, int>>> &dirs, direction o_dir) {
        cout << source.first << " " << source.second << endl;
        if (source == target) {
            this->final_ans=ans;
            return;
        } else {
            visited[source.first][source.second] = true;

            for (auto d: dirs) {
                auto delta = source + d.second;
                direction dir = d.first;
                int dx = delta.first, dy = delta.second;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && !visited[dx][dy]) {
                    if (o_dir != dir) {
                        ans += 1;
                    }
                    dfs(delta, target, visited, dirs, dir);
                    if(this->final_ans!=-1)
                        return;
                    if (o_dir != dir)
                        ans -= 1;

                }
            }
            visited[source.first][source.second] = false;
        }
    }

    int move(pair<int, int> source, pair<int, int> target, int ans, int m, int n) {
        auto visited = vector<vector<bool>>(m, vector<bool>(n, false));
        this->m = m;
        this->n = n;
        this->ans = 0;
        this->final_ans=-1;
        vector<pair<direction, pair<int, int>>> dirs = {make_pair(direction::dir1, make_pair(-1, -1)),
                                                        make_pair(direction::dir2, make_pair(1, 1)),
                                                        make_pair(direction::dir3, make_pair(-1, 1)),
                                                        make_pair(direction::dir4, make_pair(1, -1))};
        dfs(source, target, visited, dirs, direction::start);
        return this->ans;
    }

    int solve0() {
        pair<int, int> source = make_pair(2, 0);
        pair<int, int> target = make_pair(2, 2);
        int ans = -1;
        int m = max(source.first , target.first) + 1;
        int n = max(source.second , target.second) + 1;
        ans = move(source, target, ans, m, n);
        cout << "one such move is =" << ans << endl;
    }
    int solveDp(){
        pair<int, int> source = make_pair(2, 0);
        pair<int, int> target = make_pair(2, 2);
        int ans = -1;
        int m = max(source.first , target.first) + 1;
        int n = max(source.second , target.second) + 1;

        cout << "min move is=" << ans << endl;
    }
};

int main() {
    pantry p;
    p.solve();
}