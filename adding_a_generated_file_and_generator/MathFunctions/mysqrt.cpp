#include "MathFunctions.h"
#include "TutorialConfig.h"
#include <stdio.h>

#include "Table.h"

#include <math.h>

// a hack square root calculation using simple operations
double mysqrt(double x)
{
  if (x <= 0) {
    return 0;
  }

  double result;

  // if we have both log and exp then use them
  #if defined(HAVE_LOG) && defined(HAVE_EXP)

    result = exp(log(x) * 0.5);
    fprintf(stdout, "Computing sqrt of %g to be %g using log and exp\n", x, result);

  #else // else do it iteratively

    double delta;
    result = x;

    // use the table to help find an initial value
    if (x >= 1 && x < 10) {
      result = sqrtTable[static_cast<int>(x)];
      fprintf(stdout, "Grabbing initial value %g from table\n", result);
    }

    // do ten iterations
    int i;
    for (i = 0; i < 10; ++i) {
      if (result <= 0) {
        result = 0.1;
      }
      delta = x - (result * result);
      result = result + 0.5 * delta / result;
      fprintf(stdout, "Computing sqrt of %g to be %g\n", x, result);
    }

  #endif

  return result;
}