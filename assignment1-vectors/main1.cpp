#include <iostream>
#include <vector>

/**
 * @brief Demonstration av iteration och vektoroperationer i C++.
 */
int main()
{
    // Skapar vektor med elementen {1, 2, 3}
    std::vector<int> v1{1, 2, 3};

    // -------------------------------------------------------------------------
    // Uppgift 1a) Iterera via index
    std::cout << "Iteration via index:\n";
    for (std::size_t i = 0; i < v1.size(); ++i)
    {
        std::cout << v1[i] << "\n";
    }

    // Uppgift 1b) Iterera via range-baserad for-loop
    std::cout << "\nIteration via range-based for loop:\n";
    for (const auto& value : v1)
    {
        std::cout << value << "\n";
    }

    // Uppgift 1c) Iterera via iterator
    std::cout << "\nIteration via iterator:\n";
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        std::cout << *it << "\n";
    }

    // -------------------------------------------------------------------------
    // Uppgift 2a) Kolla vektorns storlek
    std::cout << "\n2a) Storlek: " << v1.size() << "\n";

    // Uppgift 2b) Lägga till talet 4 längst bak i vektorn
    v1.push_back(4);
    std::cout << "2b) Efter push_back(4): ";
    for (auto val : v1) std::cout << val << " ";
    std::cout << "\n";

    // Uppgift 2c) Sätta vektorns storlek till 10
    v1.resize(10);
    std::cout << "2c) Efter resize(10), storlek = " << v1.size() << "\n";

    // Uppgift 2d) Tömma vektorn
    v1.clear();
    std::cout << "2d) Efter clear(), storlek = " << v1.size() << "\n";

    // Uppgift 2e) Kolla om vektorn är tom
    std::cout << "2e) Är vektorn tom? " << (v1.empty() ? "Ja" : "Nej") << "\n";

    // För f) och g) behöver vi återinitiera vektorn
    v1 = {10, 20, 30, 40};
    std::cout << "\nÅterinitierad v1: ";
    for (auto val : v1) std::cout << val << " ";
    std::cout << "\n";

    // Uppgift 2f) Ta bort det första elementet
    v1.erase(v1.begin());
    std::cout << "2f) Efter erase(begin()): ";
    for (auto val : v1) std::cout << val << " ";
    std::cout << "\n";

    // Uppgift 2g) Ta bort det sista elementet
    v1.pop_back();
    std::cout << "2g) Efter pop_back(): ";
    for (auto val : v1) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}

/*
 * Uppgift 3:
 * Om vi bara vill läsa innehållet i en vektor är det bäst att skicka den som
 * en konstant referens (const std::vector<int>&).
 *
 * Orsaker:
 * - Vi undviker att hela vektorn kopieras (vilket kan bli dyrt för stora vektorer).
 * - Vi kan ändå läsa alla element.
 * - Med const garanteras att funktionen inte kan ändra innehållet.
 *
 * Därför väljer vi pass-by-const-reference framför pass-by-value.
 */
