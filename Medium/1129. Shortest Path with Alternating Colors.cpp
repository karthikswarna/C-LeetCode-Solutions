typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
typedef pair<pii, pii> ppiipii;

class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges,
                                       vector<vector<int>>& blue_edges) {
    map<int, vector<int>> re, be;

    for (auto i : red_edges) {
      re[i[0]].push_back(i[1]);
    }

    for (auto i : blue_edges) {
      be[i[0]].push_back(i[1]);
    }

    list<ppiii> tasks;

    // 0 red, 1 blue
    // ppiii(pii(location, step), color)
    tasks.push_back(ppiii(pii(0, 0), 0));
    tasks.push_back(ppiii(pii(0, 0), 1));

    map<int, pii> dp;

    while (!tasks.empty()) {
      auto cur = tasks.front();
      tasks.pop_front();

      if (dp.find(cur.first.first) == dp.end()) {
        dp[cur.first.first] = pii(INT_MAX, INT_MAX);
      }

      if (cur.second == 0) {
        if (dp[cur.first.first].first < cur.first.second) {
          continue;
        }

        dp[cur.first.first].first
            = min(dp[cur.first.first].first, cur.first.second);

        // next blue
        for (auto i : be[cur.first.first]) {
          tasks.push_back(ppiii(pii(i, cur.first.second + 1), 1));
        }
      } else {
        if (dp[cur.first.first].second < cur.first.second) {
          continue;
        }

        dp[cur.first.first].second
            = min(dp[cur.first.first].second, cur.first.second);

        // next red
        for (auto i : re[cur.first.first]) {
          tasks.push_back(ppiii(pii(i, cur.first.second + 1), 0));
        }
      }
    }

    vector<int> res(n, -1);

    for (auto i : dp) {
      res[i.first] = min(i.second.first, i.second.second);
    }

    return res;
  }
};