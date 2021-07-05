#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

double traegheit(Koerper* k, Vektor a, Vektor u){
  std::cout << "berechne fuer " << k->name() << std::endl;
  const int N = 10000;     // Anzahl Integrationspunkte
  double J = 0;
  double m = k->k_masse / N; //Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = k->punkt();
    Vektor c = x - a;
    Vektor d = c.kreuz(u);
    // Abstand Punkt x und Gerade a + t*u
    // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = d.betrag()/u.betrag(); //|n|/|u|
    // std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J += m * r * r;
  }
  std::cout << "Traegheitsmoment: " << J << std::endl;
}

int main() {
  
  const double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;
  
  std::unique_ptr<Zylindermantel> zm(new Zylindermantel(ZM_R, ZM_L));
  std::cout << zm->name() << std::endl;
  
  traegheit(zm.get(), a, u);
  
  /*double J = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = zm->punkt();
    Vektor c = x - a;
    Vektor d = c.kreuz(u);
    // Abstand Punkt x und Gerade a + t*u
    // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = d.betrag()/u.betrag(); //|n|/|u|
    // std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;
  */
  std::unique_ptr<Vollzylinder> vz(new Vollzylinder(ZM_R, ZM_L));
  std::cout << vz->name() << std::endl;

  traegheit(vz.get(), a, u);

  /*
  J = 0;
  for (int i = 0; i < N; ++i) {
    Vektor x = vz->punkt();
    Vektor c = x - a;
    Vektor d = c.kreuz(u);
    // Abstand Punkt x und Gerade a + t*u
    // Vektor n = ...;//Normalenvektor x-a kreuz u
    double r = d.betrag()/u.betrag(); //|n|/|u|
    // std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;
  */          
  return 0;
}
