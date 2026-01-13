class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        
    
        for (auto &s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }

        
        for (int i = 0; i < 80; i++) { 
            double mid = (low + high) / 2.0;
            double below = 0.0, above = 0.0;

            for (auto &s : squares) {
                double y = s[1];
                double l = s[2];

                if (y + l <= mid) {
                    below += l * l;
                } 
                else if (y >= mid) {
                    above += l * l;
                } 
                else {
                    below += l * (mid - y);
                    above += l * (y + l - mid);
                }
            }

            if (below < above)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
