#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"
#include <iostream>
#include <string>

using namespace std;

class Koerper {
public:
  virtual Vektor punkt() = 0;
  virtual std::string name() {return k_name;}
 double k_masse; 
 string k_name;
  
};
#endif