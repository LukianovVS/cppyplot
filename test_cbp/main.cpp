#include "../src/cppyplot.h"

// ���������� �������������� ������� � ���������
#define _USE_MATH_DEFINES_
#include <cmath>



// �������� ������� f(x)

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
  const double a = -3;  // ����� ������� �������
  const double b =  3;  // ������ ������� �������
  const int N = 400;    // ���-�� ����� �� ������� [a, b)
  double x[N];          // ����� ����� �������� �������� ��������� �������
  double y[N];          // ����� ����� �������� �������� �������

  //  ������ ��� ��������� �������
  const int Np = 5;
  double xp[Np];
  double yp[Np];

  //! ������ 1. ������ �� ������� ������ 1 ������

  // ��������� ������ ��������� �� a �� b � ����� (b-a)/N. ��������� N �����
  set_range(x, a, b, N);
  // ����������� f(x) ��� Func_1
  set_frange(y, x, N, Func_1);

  // ������ �������
  plt.figure(1);          // ������� ���� 1
  plt.plot(x, y, N);      // ��������� ������
  plt.grid();             // �������� ����� �����


  //! ������ 2. ������ �� ������� ��������� ��������

  // ������ ������ ��� ������ �������
  set_frange(y, x, N, Func_2);
  plt.figure(2);
  plt.plot(x, y, N, "'b-'");              // "b" - blue; "-" �������� �����

  // ��� ��������� ������� - ��� ��������� ������ �������.
  // ��������� ����� ������
  set_frange(y, x, N, Func_3);
  plt.plot(x, y, N, "'r--'");             // "r" - red; "--" �������

  // ��������� ��� ���� ������
  for (int i = 0; i < N; i++)
    y[i] = -y[i];
  plt.plot(x, y, N, "'r--'");
  plt.grid();

  //! ������ 3. ������ �������� ������ + ���������� �������
  // ����������� �����
  set_frange(y, x, N, Func_1);
  // ����� (����� �������� ������)
  set_range(xp, a, b, Np);
  set_frange(yp, xp, Np, Func_1);


  plt.figure(3);
  plt.plot(x, y, N, "'k-', label = 'f(x)' ");       // 'k-' - ������ �����;  label - ������ ��� �����
  plt.plot(xp, yp, Np, "'r.', label = 'points'");   // 'r.' - ������� �����
  plt.legend();                                     // ���������� "�����" �����
  plt.grid();


  return 0;
}
