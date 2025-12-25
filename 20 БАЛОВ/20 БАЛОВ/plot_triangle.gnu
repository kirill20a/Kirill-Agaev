set terminal wxt size 800,600
set title 'Minimal Perimeter Triangle'
set xlabel 'X coordinate'
set ylabel 'Y coordinate'
set grid
set key outside

# Настройки для точек
set style line 1 lc rgb 'blue' pt 7 ps 0.8  # Все точки
set style line 2 lc rgb 'red' pt 7 ps 1.5   # Точки треугольника

# Рисуем все точки
plot 'all_points.dat' using 2:3 with points ls 1 title 'All points', \
     'min_triangle.dat' using 2:3 with points ls 2 title 'Triangle vertices', \
     'min_triangle.dat' using 2:3 with lines lc rgb 'green' lw 2 title 'Triangle'

pause -1 "Press Enter to exit..."
