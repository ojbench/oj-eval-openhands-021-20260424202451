#include <iostream>
#include <vector>
#include <algorithm>
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
    for (int i = 0; i < n - 1; i++) {
        int y1 = points[i].second;
        
        // For each point as right boundary
        for (int j = i + 1; j < n; j++) {
            int y2 = points[j].second;
            
            // Only consider if y2 > y1
            if (y2 <= y1) continue;
            
            // Check if any point between i and j (in x-order) has y in [y1, y2]
            bool valid = true;
            for (int k = i + 1; k < j; k++) {
                int yk = points[k].second;
                if (yk >= y1 && yk <= y2) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
