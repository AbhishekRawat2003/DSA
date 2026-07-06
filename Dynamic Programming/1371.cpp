#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     vector<int> pathsWithMaxScore(vector<string>& board) {
//         int n = board.size(), m = board[0].size();
//         const int MOD = 1e9 + 7;
//         vector<vector<long long>> score(n, vector<long long>(m, -1));
//         vector<vector<long long>> ways(n, vector<long long>(m, 0));

//         board[0][0] = '0'; // E
//         board[n - 1][m - 1] = '0'; // S
//         score[0][0] = 0;
//         ways[0][0] = 1;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (board[i][j] == 'X' || (i == 0 && j == 0)) continue;

//                 long long best = -1, cnt = 0;
//                 // candidates come from (i-1,j), (i,j-1), (i-1,j-1)
//                 int di[3] = {-1, 0, -1};
//                 int dj[3] = {0, -1, -1};
//                 for (int k = 0; k < 3; k++) {
//                     int pi = i + di[k], pj = j + dj[k];
//                     if (pi < 0 || pj < 0 || score[pi][pj] == -1) continue;
//                     if (score[pi][pj] > best) {
//                         best = score[pi][pj];
//                         cnt = ways[pi][pj];
//                     } else if (score[pi][pj] == best) {
//                         cnt = (cnt + ways[pi][pj]) % MOD;
//                     }
//                 }

//                 if (best == -1) continue; // unreachable
//                 score[i][j] = best + (board[i][j] - '0');
//                 ways[i][j] = cnt;
//             }
//         }

//         long long finalScore = score[n - 1][m - 1];
//         long long finalWays = ways[n - 1][m - 1];
//         if (finalScore == -1) return {-1, 0};
//         return {(int)finalScore, (int)finalWays};
//     }
// };
class Solution {
public:
  int n, m;
  const int MOD = 1e9 + 7;
  vector<vector<long long>> scoreMemo, waysMemo;
  vector<vector<bool>> visited;

  // returns {score, ways} for reaching (0,0) from (i,j)...
  // actually easier: solve from (i,j) meaning "best way to reach
  // board[n-1][m-1] FROM here going up-left" Simpler mental model: solve(i,j) =
  // best path score+ways starting at (i,j) and moving to (0,0)
  pair<long long, long long> solve(int i, int j, vector<string> &board) {
    // out of bounds -> invalid
    if (i < 0 || j < 0)
      return {-1, 0};

    // obstacle -> invalid
    if (board[i][j] == 'X')
      return {-1, 0};

    // reached start 'E' -> base case, valid path with score 0, 1 way
    if (board[i][j] == 'E')
      return {0, 1};

    if (visited[i][j])
      return {scoreMemo[i][j], waysMemo[i][j]};
    visited[i][j] = true;

    pair<long long, long long> up = solve(i - 1, j, board);
    pair<long long, long long> left = solve(i, j - 1, board);
    pair<long long, long long> diag = solve(i - 1, j - 1, board);

    long long best = -1, cnt = 0;
    pair<long long, long long> options[3] = {up, left, diag};

    for (auto &opt : options) {
      if (opt.first == -1)
        continue; // invalid path, skip
      if (opt.first > best) {
        best = opt.first;
        cnt = opt.second;
      } else if (opt.first == best) {
        cnt = (cnt + opt.second) % MOD;
      }
    }

    if (best == -1) {
      scoreMemo[i][j] = -1;
      waysMemo[i][j] = 0;
    } else {
      int cellVal = (board[i][j] == 'S') ? 0 : (board[i][j] - '0');
      scoreMemo[i][j] = best + cellVal;
      waysMemo[i][j] = cnt;
    }
    return {scoreMemo[i][j], waysMemo[i][j]};
  }

  vector<int> pathsWithMaxScore(vector<string> &board) {
    n = board.size();
    m = board[0].size();
    scoreMemo.assign(n, vector<long long>(m, -1));
    waysMemo.assign(n, vector<long long>(m, 0));
    visited.assign(n, vector<bool>(m, false));

    auto result = solve(n - 1, m - 1, board);
    if (result.first == -1)
      return {0, 0};
    return {(int)result.first, (int)result.second};
  }
};
int main() {
  vector<string> board{"E12", "1X1", "21S"};
  Solution s;
  vector<int> res = s.pathsWithMaxScore(board);
  for (auto val : res)
    cout << val << " ";
  return 0;
}