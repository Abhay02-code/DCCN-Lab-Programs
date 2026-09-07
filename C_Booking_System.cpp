#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> group;

    for (int i = 0; i < n; i++) {
        int people, money;
        cin >> people >> money;

        group.push_back({people, money, i});
    }

    int m;
    cin >> m;

    vector<int> table(m);

    for (int i = 0; i < m; i++) {
        cin >> table[i];
    }

    // Money ke decreasing order mein
    sort(group.begin(), group.end(),
         [](auto a, auto b) {
             return get<1>(a) > get<1>(b);
         });

    // Table capacity increasing order mein
    sort(table.begin(), table.end());

    vector<bool> used(m, false);

    vector<pair<int, int>> answer;

    int total = 0;

    for (int i = 0; i < n; i++) {

        int people = get<0>(group[i]);
        int money = get<1>(group[i]);
        int index = get<2>(group[i]);

        for (int j = 0; j < m; j++) {

            if (!used[j] && table[j] >= people) {

                used[j] = true;

                total += money;

                // +1 because original indexing 1 se hai
                answer.push_back({index + 1, j + 1});

                break;
            }
        }
    }

    cout << answer.size() << " " << total << endl;

    for (auto p : answer) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}