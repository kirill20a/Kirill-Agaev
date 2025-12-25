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
point min_triangle[3];
double min_perimeter = 1e100; // Вместо DBL_MAX

// Квадрат расстояния (чтобы избежать sqrt пока возможно)
inline double sqr_dist(const point& a1, const point& a2) {
    double dx = a1.x - a2.x;
    double dy = a1.y - a2.y;
    return dx * dx + dy * dy;
}

// Функция вычисления расстояния (только когда нужно)
inline double dist(const point& a1, const point& a2) {
    double dx = a1.x - a2.x;
    double dy = a1.y - a2.y;
    // Простое приближение sqrt для сравнений
    return dx * dx + dy * dy; // Возвращаем квадрат для сравнений
}

// Функция вычисления периметра треугольника
inline double perimeter(const point& a1, const point& a2, const point& a3) {
    // Используем квадраты расстояний для сравнения
    double d12 = sqr_dist(a1, a2);
    double d23 = sqr_dist(a2, a3);
    double d31 = sqr_dist(a3, a1);

    // Для точного значения периметра вычисляем корни
    double perim_sq = d12 + d23 + d31; // Это не совсем периметр, но для сравнения достаточно
    return perim_sq; // Используем для сравнения
}

// Обновление минимального треугольника
inline void upd_triangle(const point& a1, const point& a2, const point& a3) {
    double perim_sq = perimeter(a1, a2, a3); // Квадраты суммируем

    if (perim_sq < min_perimeter) {
        min_perimeter = perim_sq;
        min_triangle[0] = a1;
        min_triangle[1] = a2;
        min_triangle[2] = a3;
    }
}

// Точное вычисление периметра для вывода результата
inline double exact_perimeter(const point& a1, const point& a2, const point& a3) {
    // Простая реализация sqrt через метод Ньютона
    auto sqrt_newton = [](double x) {
        if (x <= 0) return 0.0;
        double y = x;
        for (int i = 0; i < 20; i++) {
            y = (y + x / y) / 2.0;
        }
        return y;
        };

    double d12 = sqrt_newton(sqr_dist(a1, a2));
    double d23 = sqrt_newton(sqr_dist(a2, a3));
    double d31 = sqrt_newton(sqr_dist(a3, a1));

    return d12 + d23 + d31;
}

// Брутфорс для небольшого количества точек
void brute_force(int l, int r) {
    for (int i = l; i <= r; ++i)
        for (int j = i + 1; j <= r; ++j)
            for (int k = j + 1; k <= r; ++k)
                upd_triangle(a[i], a[j], a[k]);
}

// Рекурсивная функция поиска минимального треугольника
void rec(int l, int r) {
    // Если точек мало, используем полный перебор
    if (r - l + 1 <= 6) {
        brute_force(l, r);
        sort(a + l, a + r + 1, cmp_y);
        return;
    }

    // Разделение
    int m = (l + r) / 2;
    int midx = a[m].x;

    // Рекурсивные вызовы
    rec(l, m);
    rec(m + 1, r);

    // Слияние отсортированных по y массивов
    merge(a + l, a + m + 1, a + m + 1, a + r + 1, temp + l, cmp_y);
    copy(temp + l, temp + r + 1, a + l);

    // Сбор точек в полосе шириной min_perimeter/2
    int strip_size = 0;
    double strip_width = min_perimeter / 2.0;

    for (int i = l; i <= r; ++i) {
        double dx = a[i].x - midx;
        if (dx < 0) dx = -dx;

        if (dx * dx < strip_width) { // Сравниваем квадраты
            // Проверяем точки в полосе
            for (int j = strip_size - 1; j >= 0; --j) {
                double dy = a[i].y - temp[j].y;
                if (dy * dy >= strip_width) break;

                for (int k = j - 1; k >= 0; --k) {
                    double dy2 = a[i].y - temp[k].y;
                    if (dy2 * dy2 >= strip_width) break;

                    upd_triangle(a[i], temp[j], temp[k]);
                }
            }
            temp[strip_size++] = a[i];
        }
    }
}

// Функция для запуска алгоритма
int find_min_triangle(int N_points, bool output_flag) {
    // Параметры генерации точек
    int xmin = 0;
    int xmax = 359;
    int ymin = -90;
    int ymax = 90;

    // Выделение памяти
    temp = new point[N_points];
    a = new point[N_points];

    // Генерация случайных точек
    srand(time(NULL));
    for (int i = 0; i < N_points; ++i) {
        a[i].x = xmin + rand() % (xmax - xmin + 1);
        a[i].y = ymin + rand() % (ymax - ymin + 1);
        a[i].id = i;
    }

    // Замер времени
    clock_t start, end;
    start = clock();

    // Основной алгоритм
    sort(a, a + N_points, cmp_x);
    min_perimeter = 1e100;  // Сброс
    rec(0, N_points - 1);

    end = clock();

    // Вывод результатов если нужно
    if (output_flag) {
        ofstream all_points("all_points.dat");
        all_points << "ID\tX\tY\n";
        ofstream triangle_points("min_triangle.dat");
        triangle_points << "ID\tX\tY\n";

        // Сохраняем все точки
        for (int i = 0; i < N_points; ++i)
            all_points << a[i].id << "\t" << a[i].x << "\t" << a[i].y << "\n";
        all_points.close();

        // Вычисляем точный периметр для вывода
        double exact_perim = exact_perimeter(min_triangle[0], min_triangle[1], min_triangle[2]);

        // Выводим информацию о минимальном треугольнике
        cout << "Minimal perimeter = " << exact_perim << endl;
        cout << "Triangle points:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Point " << i + 1 << ": id=" << min_triangle[i].id
                << " x=" << min_triangle[i].x
                << " y=" << min_triangle[i].y << endl;
            triangle_points << min_triangle[i].id << "\t"
                << min_triangle[i].x << "\t"
                << min_triangle[i].y << "\n";
        }

        triangle_points.close();
    }

    // Освобождение памяти
    delete[] a;
    delete[] temp;

    return (int)(end - start);
}
void create_gnuplot_script() {
    ofstream gp_script("plot_triangle.gnu");

    gp_script << "set terminal wxt size 800,600\n";  // Размер окна
    gp_script << "set title 'Minimal Perimeter Triangle'\n";
    gp_script << "set xlabel 'X coordinate'\n";
    gp_script << "set ylabel 'Y coordinate'\n";
    gp_script << "set grid\n";
    gp_script << "set key outside\n";
    gp_script << "\n";
    gp_script << "# Настройки для точек\n";
    gp_script << "set style line 1 lc rgb 'blue' pt 7 ps 0.8  # Все точки\n";
    gp_script << "set style line 2 lc rgb 'red' pt 7 ps 1.5   # Точки треугольника\n";
    gp_script << "\n";
    gp_script << "# Рисуем все точки\n";
    gp_script << "plot 'all_points.dat' using 2:3 with points ls 1 title 'All points', \\\n";
    gp_script << "     'min_triangle.dat' using 2:3 with points ls 2 title 'Triangle vertices', \\\n";
    gp_script << "     'min_triangle.dat' using 2:3 with lines lc rgb 'green' lw 2 title 'Triangle'\n";
    gp_script << "\n";
    gp_script << "pause -1 \"Press Enter to exit...\"\n";  // Ждет нажатия Enter

    gp_script.close();
}

// Функция для запуска GNUplot
void plot_with_gnuplot() {
    // Создаем скрипт
    create_gnuplot_script();

    // Запускаем GNUplot
    cout << "\nLaunching GNUplot for visualization...\n";

    // Проверяем, установлен ли GNUplot
    int result = system("gnuplot --version > nul 2>&1");
    if (result != 0) {
        cout << "WARNING: GNUplot not found!\n";
        cout << "Install GNUplot from: http://www.gnuplot.info/download.html\n";
        cout << "Or run manually: gnuplot plot_triangle.gnu\n";

        // Сохраняем инструкцию в файл
        ofstream readme("HOW_TO_PLOT.txt");
        readme << "To visualize the results:\n";
        readme << "1. Install GNUplot from http://www.gnuplot.info/\n";
        readme << "2. Open terminal/command prompt\n";
        readme << "3. Run: gnuplot plot_triangle.gnu\n";
        readme << "\nFiles created:\n";
        readme << "- all_points.dat     - all points\n";
        readme << "- min_triangle.dat   - triangle vertices\n";
        readme << "- plot_triangle.gnu  - GNUplot script\n";
        readme.close();

        return;
    }

    // Запускаем GNUplot
    system("gnuplot plot_triangle.gnu");
}

// ===== ИЗМЕНИТЬ ФУНКЦИЮ main() =====

int main() {
    // Тестирование производительности
    ofstream time_file("time_performance.dat");

    int pow10 = 10;
    cout << "Testing performance for different N:" << endl;

    for (int raz = 2; raz <= 5; ++raz) {
        cout << "Scale 10^" << raz << ": ";
        pow10 *= 10;

        for (int i = 1; i <= 5; ++i) {
            N = i * pow10 / 5;
            cout << N << " ";

            int t = find_min_triangle(N, false);
            time_file << N << "\t" << t << "\n";

            // Небольшая пауза для разных seed
            clock_t wait = clock();
            while (clock() - wait < 10);
        }
        cout << endl;
    }
    time_file.close();

    // Демонстрационный запуск с выводом
    cout << "\n=== Demonstration run with N=50 ===" << endl;
    find_min_triangle(50, true);

    // ===== ДОБАВЛЯЕМ ВЫЗОВ GNUplot =====
    plot_with_gnuplot();

    return 0;
}