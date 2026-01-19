class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i-1][j-1]
                           + pref[i-1][j]
                           + pref[i][j-1]
                           - pref[i-1][j-1];
            }
        }

        
        auto isPossible = [&](int len) {
            for (int i = 0; i + len <= m; i++) {
                for (int j = 0; j + len <= n; j++) {
                    int sum = pref[i+len][j+len]
                            - pref[i][j+len]
                            - pref[i+len][j]
                            + pref[i][j];
                    if (sum <= threshold)
                        return true;
                }
            }
            return false;
        };

        
        int low = 0, high = min(m, n), ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
