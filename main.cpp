#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    // Sort by x-coordinate
    vector<int> idx_by_x(n);
    for (int i = 0; i < n; i++) idx_by_x[i] = i;
    sort(idx_by_x.begin(), idx_by_x.end(), [&](int a, int b) {
        return points[a].first < points[b].first;
    });
    
    long long count = 0;
    
    // Try all pairs of points as potential bottom-left and top-right corners
    for (int i = 0; i < n; i++) {
        long long x1 = points[i].first, y1 = points[i].second;
        
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            long long x2 = points[j].first, y2 = points[j].second;
            
            // Check if they can form a valid rectangle (bottom-left to top-right)
            if (x1 >= x2 || y1 >= y2) continue;
            
            // Find range of points with x in [x1, x2] using binary search
            int left = lower_bound(idx_by_x.begin(), idx_by_x.end(), x1,
                [&](int idx, long long val) { return points[idx].first < val; }) - idx_by_x.begin();
            int right = upper_bound(idx_by_x.begin(), idx_by_x.end(), x2,
                [&](long long val, int idx) { return val < points[idx].first; }) - idx_by_x.begin();
            
            // Check if any other point is inside or on the boundary
            bool valid = true;
            for (int pos = left; pos < right; pos++) {
                int k = idx_by_x[pos];
                if (k == i || k == j) continue;
                
                long long yk = points[k].second;
                
                // Check if point k is inside or on the boundary of the rectangle
                if (yk >= y1 && yk <= y2) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
