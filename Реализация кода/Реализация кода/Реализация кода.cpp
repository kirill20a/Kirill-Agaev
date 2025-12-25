#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>


using namespace std;

struct point {
    int x, y, id;
};

inline bool cmp_x(const point& a1, const point& a2) {
    return a1.x < a2.x || (a1.x == a2.x && a1.y < a2.y);
}

inline bool cmp_y(const point& a1, const point& a2) {
    return a1.y < a2.y;
}

int N;
point* a;
point* temp;
point nearest_pair[2];
double mindist = DBL_MAX;

inline void upd_id(const point& a1, const point& a2) {
    double dist = sqrt((a1.x - a2.x) * (a1.x - a2.x) +
        (a1.y - a2.y) * (a1.y - a2.y) + 0.0);
    if (dist < mindist) {
        mindist = dist;
        nearest_pair[0] = a1;
        nearest_pair[1] = a2;
    }
}

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i <= r; ++i) {
            for (int j = i + 1; j <= r; ++j) {
                upd_id(a[i], a[j]);
            }
        }
        sort(a + l, a + r + 1, cmp_y);
        return;
    }

    int m = (l + r) >>1;
    int midx = a[m].x;

    rec(l, m);
    rec(m + 1, r);

    merge(a + l, a + m + 1, a + m + 1, a + r + 1, temp, cmp_y);
    copy(temp, temp + r - l + 1, a + l);

    int tsz = 0;
    for (int i = l; i <= r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && (a[i].y - temp[j].y) < mindist; --j) {
                upd_id(a[i], temp[j]);
            }
            temp[tsz++] = a[i];
        }
    }
}

time_t example1(int N, bool flag) {
    int xmin = 0;
    int xmax = 359;
    int ymin = -90;
    int ymax = 90;

    temp = new point[N];
    a = new point[N];

    for (int i = 0; i < N; i++) {
        a[i].x = xmin + rand() % (xmax - xmin + 1);
        a[i].y = ymin + rand() % (ymax - ymin + 1);
        a[i].id = i;
    }

    time_t start, end;
    start = clock();

    sort(a, a + N, cmp_x);
    rec(0, N - 1);

    end = clock();

    if (flag) {
        ofstream in("example.dat");
        in << "ID\tX\tY\n";
        ofstream rez("nearest_pair.dat");
        rez << "ID\tX\tY\n";

        for (int i = 0; i < N; i++) {
            in << a[i].id << "\t" << a[i].x << "\t" << a[i].y << "\n";
        }
        in.close();

        cout << "mindist = " << mindist << endl;
        for (int i = 0; i < 2; i++) {
            cout << "id" << i + 1 << " = " << nearest_pair[i].id
                << " x" << i + 1 << " = " << nearest_pair[i].x
                << " y" << i + 1 << " = " << nearest_pair[i].y << endl;
            rez << nearest_pair[i].id << "\t" << nearest_pair[i].x
                << "\t" << nearest_pair[i].y << "\n";
        }
        rez.close();
    }

    delete[] a;
    delete[] temp;

    return end - start;
}

int main() {
    srand(time_t(NULL));

    ofstream rez_time("time_algo.dat");

    int pow10 = 10;
    for (int raz = 2; raz <= 6; raz++) {
        cout << "raz = " << raz << '\t';
        pow10 *= 10;

        for (int i = 1; i < 10; i++) {
            cout << i << " ";
            N = i * pow10;
            time_t t = example1(N, false);
            rez_time << N << "\t" << t << "\n";
        }
        cout << "\n";
    }
    rez_time.close();

    return 0;
}