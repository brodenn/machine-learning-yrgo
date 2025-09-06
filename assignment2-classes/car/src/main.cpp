/**
 * @brief Inlämningsuppgift 2 – VG (5a–c): vektor av Car*, massändra färg, skriv till fil.
 */
#include <iostream>
#include <vector>
#include <fstream>
#include "car.h"

using vehicle::Car;
using vehicle::TransmissionType;

int main()
{
    // 5a) Tre bilar + vektor av pekare (ingen kopiering av objekt)
    Car car1{"Volvo", "V70", "Black", 1995, TransmissionType::Manual};
    Car car2{"BMW", "Z3", "Blue", 2001, TransmissionType::Automatic};
    Car car3{"Skoda", "Octavia RS", "White", 2003, TransmissionType::Manual};

    std::vector<Car*> cars{&car1, &car2, &car3};

    // Skriv ut alla i originalfärger
    for (auto* c : cars) { c->print(); }

    // 5b) Ändra färg på alla till röd via iteration, skriv ut igen
    for (auto* c : cars) { c->setColor("Red"); }
    for (auto* c : cars) { c->print(); }

    // 5c) Skriv bilinformationen till fil cars.txt (utan att ändra Car)
    std::ofstream ofs{"cars.txt"};
    for (auto* c : cars) { c->print(ofs); }

    return 0;
}
