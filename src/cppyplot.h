#ifndef _CPPYPLOT_H_
#define _CPPYPLOT_H_

#include <string>
#include <fstream>


/*! � ������ x ������� ����� � ��������� [start, stop).
 *
 */
void set_range(double *x, double start, double stop, int size_arr);
/*! � ������ y ������� �������� ������� func(x).
 *
 */
void set_frange(double *y, double *x, int size_arr, double (*func)(double ) );


//! ����� ����� python ����. ����� ����� ����� ���������� ��� ������ �������������� ����� ������
class CLS_PLOT
{
private:
  std::ofstream fid;

public:
  CLS_PLOT();
  ~CLS_PLOT();


  void plot(double x[], double y[], int size_arr, std::string str = "");

  inline void figure(int i) { fid << "plt.figure(" << i << ")\n"; }

  inline void legend() { fid << "plt.legend()\n"; }

  inline void grid()   { fid << "plt.grid()\n";   }

};

//! ��������� ������ CLS_PLOT.
extern CLS_PLOT plt;

#endif // _CPPYPLOT_H_
