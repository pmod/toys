
#define _GNU_SOURCE
#include <fenv.h>

int foo(double d) {
  return 1/d;
}

int main() {
  feenableexcept(FE_INVALID   | 
                   FE_DIVBYZERO | 
                   FE_OVERFLOW  | 
                   FE_UNDERFLOW);

  return foo(0);
}

