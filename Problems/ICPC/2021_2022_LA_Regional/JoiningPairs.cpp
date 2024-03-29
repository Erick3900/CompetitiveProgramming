// 2021_2022_LA_Regional
// JoiningPairs
//
// Date: Wednesday October 18, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

// #include <bits/stdc++.h>

// #define _DEBUG
// #ifdef _DEBUG
// #    define deb(x) std::clog << #x << " = " << x << std::endl;
// #    define deb2(x, y) std::clog << #x << " = " << x << "\t|\t" << #y << " = " << y << std::endl;
// #    define debug(x) { x };
// #else
// #    define deb(x)
// #    define deb2(x, y)
// #    define debug(x)
// #endif

// int main(int argc, char *argv[]) {
//     std::ios_base::sync_with_stdio(false),
//         std::cin.tie(nullptr),
//         std::cout.tie(nullptr);

//     int w, h;
//     int x1, y1, x2, y2;

//     bool on_v = false;
//     bool on_h = false;

//     std::cin >> w >> h;

//     int n;

//     std::cin >> n;

//     for (int i = 0; i < n; ++i) {
//         std::cin >> x1 >> y1 >> x2 >> y2;

//         if ((y1 == 0 and y2 == h) or (y1 == h and y2 == 0)) {
//             on_v = true;
//         }
//         else if ((x1 == 0 and x2 == w) or (x1 == w and x2 == 0)) {
//             on_h = true;
//         }
//     }

//     if (on_v and on_h) {
//         std::cout << "N\n";
//     }
//     else {
//         std::cout << "Y\n";
//     }

// }


#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

struct Segment {
    Point left, right;
};

struct Event {
    int x, y;
    bool isLeft;
    int index;

    Event(int x, int y, bool l, int i)
        : x(x)
        , y(y)
        , isLeft(l)
        , index(i) { }

    bool operator<(const Event &e) const {
        if (y == e.y)
            return x < e.x;
        return y < e.y;
    }
};

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;    // collinear

    return (val > 0) ? 1 : 2;    // clock or counterclock wise
}

bool doIntersect(Segment s1, Segment s2) {
    Point p1 = s1.left, q1 = s1.right, p2 = s2.left, q2 = s2.right;

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false;    // Doesn't fall in any of the above cases
}

set<Event>::iterator pred(set<Event> &s, set<Event>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}

set<Event>::iterator succ(set<Event> &s, set<Event>::iterator it) {
    return it == s.end() ? ++it : s.begin();
}

int isIntersect(std::vector<Segment> &arr, int n) {
    unordered_map<string, int> mp;    // to note the pair for which intersection is checked already
    //
    vector<Event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(Event(arr[i].left.x, arr[i].left.y, true, i));
        e.push_back(Event(arr[i].right.x, arr[i].right.y, false, i));
    }

    sort(e.begin(), e.end(), [](Event &e1, Event &e2) { return e1.x < e2.x; });

    set<Event> s;

    for (int i = 0; i < 2 * n; i++) {
        Event curr = e[i];
        int index = curr.index;

        if (curr.isLeft) {
            auto next = s.lower_bound(curr);
            auto prev = pred(s, next);

            if (next != s.end() && doIntersect(arr[next->index], arr[index])) {
                string s = to_string(next->index + 1) + " " + to_string(index + 1);
                if (mp.count(s) == 0) {
                    mp[s]++;
                    return true;
                }    // if not already checked we can increase count in map
            }
            if (prev != s.end() && doIntersect(arr[prev->index], arr[index])) {
                string s = to_string(prev->index + 1) + " " + to_string(index + 1);
                if (mp.count(s) == 0) {
                    mp[s]++;
                    return true;
                }    // if not already checked we can increase count in map
            }

            if (prev != s.end() && next != s.end() && next->index == prev->index)
            {
                return true;
            }

            s.insert(curr);
        }
        else {
            auto it = s.find(Event(arr[index].left.x, arr[index].left.y, true, index));
            auto next = succ(s, it);
            auto prev = pred(s, it);

            if (next != s.end() && prev != s.end()) {
                string s1 = to_string(next->index + 1) + " " + to_string(prev->index + 1);
                string s2 = to_string(prev->index + 1) + " " + to_string(next->index + 1);
                if (mp.count(s1) == 0 && mp.count(s2) == 0 && doIntersect(arr[prev->index], arr[next->index]))
                {
                    return true;
                }
                mp[s1]++;
            }

            s.erase(it);
        }
    }

    return false;
}

int main() {

    int w, h, n, x1, x2, y1, y2;

    std::cin >> w >> h >> n;

    auto is_on_side = [&](int x, int y) {
        return (x == 0 or x == w or y == 0 or y == h);
    };

    std::vector<Segment> segments;
    segments.reserve(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> x1 >> y1 >> x2 >> y2;

        if (is_on_side(x1, y1) and is_on_side(x2, y2)) {
            segments.push_back({
                {x1, y1},
                {x2, y2}
            });
        }
    }

    if (isIntersect(segments, segments.size())) {
        std::cout << "N\n";
    }
    else {
        std::cout << "Y\n";
    }

    return 0;
}
