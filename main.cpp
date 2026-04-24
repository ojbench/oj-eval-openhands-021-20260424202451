#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    int count = 0;
    
    // Try all pairs of points as potential bottom-left and top-right corners
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            long long x1 = points[i].x, y1 = points[i].y;
            long long x2 = points[j].x, y2 = points[j].y;
            
            // Check if they can form a valid rectangle (bottom-left to top-right)
            if (x1 >= x2 || y1 >= y2) continue;
            
            // Check if any other point is inside or on the boundary
            bool valid = true;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                
                long long xk = points[k].x, yk = points[k].y;
                
                // Check if point k is inside or on the boundary of the rectangle
                if (xk >= x1 && xk <= x2 && yk >= y1 && yk <= y2) {
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
