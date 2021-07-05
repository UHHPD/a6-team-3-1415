#include "Vollzylinder.hh"

#include <cmath>
#include <cstdlib>

Vollzylinder::Vollzylinder(double nr, double nl) {
  r_ = nr;
  l_ = nl;
  k_name = "Vollzylinder";
  k_masse = 1;
}

Vektor Vollzylinder::punkt() {
  double R = r_;
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double z = l_ * (rand() / (double)RAND_MAX - 0.5);
  double r = R*sqrt(rand()/(double)RAND_MAX); 

  double x = r*cos(phi);
  double y = r*sin(phi);
  return Vektor(x, y, z);
};
