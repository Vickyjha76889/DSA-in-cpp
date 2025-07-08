
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

// const string DIR = "DLRU";
// const int dx[4] = {1, 0, 0, -1};
// const int dy[4] = {0, -1, 1, 0};

// // ✅ Fixed isvalid:
// // - takes visited by const reference, not copy
// // - accepts 'n' for boundary checks
// // - uses correct bounds (>=0 && <n) :contentReference[oaicite:1]{index=1}
// bool isvalid(int x, int y,
//              const vector<vector<int>>& m,
//              const vector<vector<int>>& visited,
//              int n) {
//     return x >= 0 && x < n &&
//            y >= 0 && y < n &&
//            m[x][y] == 1 &&
//            visited[x][y] == 0;
// }

// void solve(const vector<vector<int>>& m,
//            int n,
//            int x, int y,
//            string& path,                  // ❗ pass path by reference, NOT by value
//            vector<vector<int>>& visited,
//            vector<string>& ans) {

//     if (x == n - 1 && y == n - 1) {
//         ans.push_back(path);
//         return;
//     }

//     visited[x][y] = 1; // ✅ mark visited

//     for (int i = 0; i < 4; ++i) {
//         int nx = x + dx[i], ny = y + dy[i];
//         if (isvalid(nx, ny, m, visited, n)) {
//             path.push_back(DIR[i]);
//             solve(m, n, nx, ny, path, visited, ans);
//             path.pop_back(); // ✅ backtrack path
//         }
//     }

//     visited[x][y] = 0; // ✅ unmark visited for backtracking
// }

// vector<string> findPath(vector<vector<int>>& m, int n) {
//     vector<string> ans;
//     vector<vector<int>> visited(n, vector<int>(n, 0));
//     string path;  // ❗ declare path before using

//     // ✅ ensure both start and end are open :contentReference[oaicite:2]{index=2}
//     if (m[0][0] == 1 && m[n-1][n-1] == 1) {
//         solve(m, n, 0, 0, path, visited, ans); // ✅ single call
//     }

//     sort(ans.begin(), ans.end());
//     return ans;
// }

// int main() {
//     vector<vector<int>> m = {
//         {1,0,0,0},
//         {1,1,0,0},
//         {1,1,0,0},
//         {0,1,1,1}
//     };
//     int n = 4;

//     vector<string> sna = findPath(m, n);

//     if (sna.empty()) {
//         cout << -1;
//     } else {
//         for (const string& a : sna)
//             cout << a << " ";
//     }
//     cout << "\n";
//     return 0;
// }
