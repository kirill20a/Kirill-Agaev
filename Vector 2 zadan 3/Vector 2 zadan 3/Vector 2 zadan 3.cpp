#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Point {
    char color;
    int x, y;
};

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void solve(Point* reds, Point* blues, bool* used, double curr, double& best, int idx, int n) {
    if (idx == n) {
        if (curr < best) best = curr;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            double newCurr = curr + dist(reds[idx], blues[i]);
            if (newCurr < best) {
                solve(reds, blues, used, newCurr, best, idx + 1, n);
            }
            used[i] = false;
        }
    }
}

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cout << "Cannot open file\n";
        return 1;
    }

    int total;
    fin >> total;
    int n = total / 2;

    Point* reds = new Point[n];
    Point* blues = new Point[n];
    int rCount = 0, bCount = 0;

    for (int i = 0; i < total; i++) {
        char col;
        int x, y;
        fin >> col >> x >> y;
        if (col == 'r') {
            reds[rCount].color = col;
            reds[rCount].x = x;
            reds[rCount].y = y;
            rCount++;
        }
        else {
            blues[bCount].color = col;
            blues[bCount].x = x;
            blues[bCount].y = y;
            bCount++;
        }
    }
    fin.close();

    if (rCount != bCount) {
        cout << "Error: unequal number of red and blue points\n";
        delete[] reds;
        delete[] blues;
        return 1;
    }

    bool* used = new bool[n];
    for (int i = 0; i < n; i++) used[i] = false;

    double best = 1e20;
    solve(reds, blues, used, 0.0, best, 0, n);

    cout << best << endl;

    delete[] reds;
    delete[] blues;
    delete[] used;

    return 0;
}