#ifndef _CPPYPLOT_H_
#define _CPPYPLOT_H_

#include <string>
#include <fstream>


/*! в массив x вписать числа в диапазоне [start, stop).
 *
 */
void set_range(double *x, double start, double stop, int size_arr);
/*! в массив y вписать значени€ функции func(x).
 *
 */
void set_frange(double *y, double *x, int size_arr, double (*func)(double ) );


//! класс пишет python файл. ¬ызов этого файла происходит при вызове деконструктора этого класса
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

//! Ёкземпл€р класса CLS_PLOT.
extern CLS_PLOT plt;

#endif // _CPPYPLOT_H_
