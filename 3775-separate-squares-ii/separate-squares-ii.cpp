class Solution {
public:
    struct Event {
        double y, x1, x2;
        int type;
        bool operator<(const Event& o) const {
            return y < o.y;
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        for (auto &s : squares) {
            double x = s[0], y = s[1], l = s[2];
            events.push_back({y, x, x + l, +1});
            events.push_back({y + l, x, x + l, -1});
        }
        sort(events.begin(), events.end());

        vector<double> ys, lens, pref;
        multiset<pair<double,double>> active;

        double prevY = events[0].y;
        double area = 0.0;

        for (int i = 0; i < events.size();) {
            double curY = events[i].y;
            double dy = curY - prevY;

            if (dy > 0) {
                double len = unionLen(active);
                ys.push_back(prevY);
                lens.push_back(len);
                pref.push_back(area);
                area += dy * len;
            }

            while (i < events.size() && events[i].y == curY) {
                if (events[i].type == 1)
                    active.insert({events[i].x1, events[i].x2});
                else
                    active.erase(active.find({events[i].x1, events[i].x2}));
                i++;
            }
            prevY = curY;
        }

        double half = area / 2.0;

        for (int i = 0; i < ys.size(); i++) {
            if (lens[i] == 0) continue;
            double nextArea = pref[i] + lens[i] * (
                (i + 1 < ys.size() ? ys[i+1] : 1e18) - ys[i]
            );

            if (nextArea >= half) {
                double need = half - pref[i];
                return ys[i] + need / lens[i];
            }
        }

        return ys.back();
    }

private:
    double unionLen(multiset<pair<double,double>>& s) {
        if (s.empty()) return 0;
        auto it = s.begin();
        double l = it->first, r = it->second, len = 0;
        ++it;
        for (; it != s.end(); ++it) {
            if (it->first > r) {
                len += r - l;
                l = it->first;
                r = it->second;
            } else {
                r = max(r, it->second);
            }
        }
        return len + (r - l);
    }
};
