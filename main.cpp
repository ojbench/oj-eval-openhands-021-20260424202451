#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    
    // Sort by x-coordinate
    sort(points.begin(), points.end());
    
    long long count = 0;
    
    // For each point as left boundary
    for (int i = 0; i < n; i++) {
        int y1 = points[i].second;
        
        // Maintain multiset of y-coordinates for points between i and j
        multiset<int> middle_ys;
        
        // For each point as right boundary
        for (int j = i + 1; j < n; j++) {
            int y2 = points[j].second;
            
            // Check if this forms a valid rectangle (y2 > y1)
            if (y2 > y1) {
                // Check if any point in middle_ys has y in [y1, y2]
                auto it = middle_ys.lower_bound(y1);
                if (it == middle_ys.end() || *it > y2) {
                    // No point in range [y1, y2]
                    count++;
                }
            }
            
            // Add current point to middle set for next iterations
            middle_ys.insert(y2);
        }
    }
    
    cout << count << endl;
    
    return 0;
}
