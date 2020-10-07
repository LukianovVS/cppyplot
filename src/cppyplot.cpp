#include "cppyplot.h"
#include <windows.h>
#include <stdio.h>

using namespace std;

CLS_PLOT plt;

// имя временного файла
#define FNAME_TMP_PY "cppyplot_tmp.py"


void set_range(double *x, double start, double stop, int size_arr)
{
  double step = (stop - start) / static_cast<double>(size_arr);
  for (int i = 0; i < size_arr; i++)
    x[i] = start + step * i;
}

void set_frange(double *y, double *x, int size_arr, double (*func)(double ) )
{
  for (int i = 0; i < size_arr; i++)
    y[i] = func(x[i]);
}


static int cls_counter = 0;


CLS_PLOT::CLS_PLOT()
{
  this->fid.open(FNAME_TMP_PY);
  cls_counter++;

  fid << "import matplotlib.pyplot as plt" << endl;
  fid << "import numpy as np\n" << endl;
}


CLS_PLOT::~CLS_PLOT()
{
  // дописываем файл
  fid << "plt.show()\n" << endl;
  fid.close();

  // замускаем python скрипт
  char str[123];
  sprintf(str, "python %s", FNAME_TMP_PY);
  system(str);
  // удаляем временный файл
  sprintf(str, "echo Y | ERASE %s", FNAME_TMP_PY);
  system(str);
}




void CLS_PLOT::plot(double x[], double y[], int size_arr, std::string str)
{
  if (size_arr < 1)
    return;

  fid << "x = np.array( [" << x[0];
  for (int i = 1; i < size_arr; i++)
  {
    fid << ", " << x[i];
  }
  fid << "])\n";

  fid << "y = np.array( [" << y[0];
  for (int i = 1; i < size_arr; i++)
  {
    fid << ", " << y[i];
  }
  fid << "])\n";

  fid << "plt.plot(x,y";

  if (str.length() > 0)
  {
    fid << ", " << str;
  }
  fid << ")\n";

  fid << "del x, y\n";

}

