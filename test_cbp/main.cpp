#include "../src/cppyplot.h"

// подключаем математические функции и константы
#define _USE_MATH_DEFINES_
#include <cmath>



// тестовые функции f(x)

// (x - 1)^2 - 1;
double Func_1(double x)
{
  return pow( (x - 1), 2) - 1;
}

// exp(-|x|) * cos(2 * pi *x)
double Func_2(double x)
{
  return exp(-fabs(x) ) * cos(2 * M_PI *x) ;
}

// exp(-|x|)
double Func_3(double x)
{
  return exp(-fabs(x) );
}


int main()
{
  const double a = -3;  // левая граница графика
  const double b =  3;  // правая граница графика
  const int N = 400;    // кол-во точек на отрезке [a, b)
  double x[N];          // здесь будут хранится значения агрумента функции
  double y[N];          // здесь будут хранится значения функции

  //  данные для точечного графика
  const int Np = 5;
  double xp[Np];
  double yp[Np];

  //! Пример 1. Строим на рисунке только 1 график

  // заполняем массив агрумента от a до b с шагом (b-a)/N. Заполняем N точек
  set_range(x, a, b, N);
  // Расчитываем f(x) для Func_1
  set_frange(y, x, N, Func_1);

  // строим графики
  plt.figure(1);          // открыть окно 1
  plt.plot(x, y, N);      // построить график
  plt.grid();             // показать линии сетки


  //! Пример 2. Строим на рисунке несколько графиков

  // строим график для другой функции
  set_frange(y, x, N, Func_2);
  plt.figure(2);
  plt.plot(x, y, N, "'b-'");              // "b" - blue; "-" сплошная линия

  // два следующих графика - это огибающая первой функции.
  // добовляем новый график
  set_frange(y, x, N, Func_3);
  plt.plot(x, y, N, "'r--'");             // "r" - red; "--" пунктир

  // добовляем ещё один график
  for (int i = 0; i < N; i++)
    y[i] = -y[i];
  plt.plot(x, y, N, "'r--'");
  plt.grid();

  //! Пример 3. Строим точечный график + используем легенду
  // Непрерывная линия
  set_frange(y, x, N, Func_1);
  // точки (будут нанесены сверху)
  set_range(xp, a, b, Np);
  set_frange(yp, xp, Np, Func_1);


  plt.figure(3);
  plt.plot(x, y, N, "'k-', label = 'f(x)' ");       // 'k-' - черная линия;  label - задает имя линии
  plt.plot(xp, yp, Np, "'r.', label = 'points'");   // 'r.' - красные точки
  plt.legend();                                     // отобразить "имена" линий
  plt.grid();


  return 0;
}
