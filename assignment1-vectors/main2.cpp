#include <iostream>
#include <vector>
#include <type_traits>
#include <limits>
#include <cmath>   // för fabs i flyttalstester

namespace vector
{
/**
 * @brief Return the largest int in the vector, or 0 if the vector is empty.
 * @param[in] numbers Vector of integers to inspect.
 * @return Largest integer, or 0 if empty.
 */
int getLargestInt(const std::vector<int>& numbers)
{
    if (numbers.empty()) { return 0; }
    int largest = numbers[0];
    for (const auto& n : numbers)
    {
        if (n > largest) { largest = n; }
    }
    return largest;
}

/**
 * @brief Sort given vector in ascending order (in-place).
 * @tparam T Numeric element type (must be arithmetic).
 * @param[in,out] data Vector to sort.
 * 
 */
template <typename T>
void sort(std::vector<T>& data)
{
    static_assert(std::is_arithmetic<T>::value,
                  "Non-arithmetic type specified in vector::sort!");

    if (data.empty()) { return; }

    for (std::size_t i = 0; i + 1 < data.size(); ++i)
    {
        for (std::size_t j = i + 1; j < data.size(); ++j)
        {
            if (data[i] > data[j])
            {
                const T tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}

/**
 * @brief Get the second largest (next largest) *distinct* value in the vector.
 * @tparam T Numeric element type (must be arithmetic).
 * @param[in] numbers Vector with numbers.
 * @return Next largest distinct value; T{0} if <2 elements or no distinct second exists.
 */
template <typename T>
T getNextLargest(const std::vector<T>& numbers)
{
    static_assert(std::is_arithmetic<T>::value,
                  "Non-arithmetic type specified in vector::getNextLargest!");

    if (numbers.size() < 2U) { return T{0}; }

    T largest = numbers[0];
    T nextLargest = std::numeric_limits<T>::lowest();

    for (const auto& x : numbers)
    {
        if (x > largest)
        {
            nextLargest = largest;
            largest = x;
        }
        else if (x < largest && x > nextLargest)
        {
            nextLargest = x;
        }
    }

    if (nextLargest == std::numeric_limits<T>::lowest())
    {
        return T{0};
    }
    return nextLargest;
}

} // namespace vector

//Denna section är till stor del genererad av ai
// -----------------------------------------------------------------------------
// Hjälpfunktioner för test (endast stdlib)
template <typename T>
void printVec(const std::vector<T>& v, const char* label)
{
    std::cout << label << ": [ ";
    for (const auto& x : v) std::cout << x << " ";
    std::cout << "]\n";
}

template <typename T>
bool equalVec(const std::vector<T>& a, const std::vector<T>& b)
{
    if (a.size() != b.size()) return false;
    for (std::size_t i = 0; i < a.size(); ++i)
        if (a[i] != b[i]) return false;
    return true;
}

bool almostEqual(double a, double b, double eps = 1e-9)
{
    return std::fabs(a - b) <= eps;
}

template <typename T>
void expectEq(const T& got, const T& want, const char* name)
{
    if (got == want) std::cout << "[PASS] " << name << " -> " << got << "\n";
    else             std::cout << "[FAIL] " << name << " -> got " << got << ", want " << want << "\n";
}

void expectEqDouble(double got, double want, const char* name)
{
    if (almostEqual(got, want)) std::cout << "[PASS] " << name << " -> " << got << "\n";
    else                         std::cout << "[FAIL] " << name << " -> got " << got << ", want " << want << "\n";
}

template <typename T>
void expectVecEq(const std::vector<T>& got, const std::vector<T>& want, const char* name)
{
    if (equalVec(got, want))
    {
        std::cout << "[PASS] " << name << " -> ";
        printVec(got, "vec");
    }
    else
    {
        std::cout << "[FAIL] " << name << "\n";
        printVec(got,  " got");
        printVec(want, "want");
    }
}

// -----------------------------------------------------------------------------
// Demo + utökade tester
int main()
{
    std::cout << "==== Uppg. 5: getLargestInt + erase ====\n";
    {
        std::vector<int> numbers{1, 2, 5, 4, 8, 9, 0, -3};
        printVec(numbers, "Initial");
        const int largest = vector::getLargestInt(numbers);
        expectEq(largest, 9, "getLargestInt(base)");

        // Radera första förekomsten av största talet
        for (auto it = numbers.begin(); it != numbers.end(); ++it)
        {
            if (*it == largest) { numbers.erase(it); break; }
        }
        expectVecEq(numbers, std::vector<int>{1,2,5,4,8,0,-3}, "erase largest once");
    }

    // Kantfall för getLargestInt
    {
        std::vector<int> empty{};
        expectEq(vector::getLargestInt(empty), 0, "getLargestInt(empty)");
        std::vector<int> single{42};
        expectEq(vector::getLargestInt(single), 42, "getLargestInt(single)");
        std::vector<int> allNeg{-5,-9,-2,-11};
        expectEq(vector::getLargestInt(allNeg), -2, "getLargestInt(all negative)");
        std::vector<int> dupes{7,7,7};
        expectEq(vector::getLargestInt(dupes), 7, "getLargestInt(dupes)");
    }

    std::cout << "\n==== Uppg. 6: sort<T> (int/double) ====\n";
    {
        std::vector<int> a{3,1,4,1,5,9,2,6};
        vector::sort(a);
        expectVecEq(a, std::vector<int>{1,1,2,3,4,5,6,9}, "sort int");

        std::vector<int> already{1,2,3};
        vector::sort(already);
        expectVecEq(already, std::vector<int>{1,2,3}, "sort already sorted");

        std::vector<int> rev{5,4,3,2,1};
        vector::sort(rev);
        expectVecEq(rev, std::vector<int>{1,2,3,4,5}, "sort reverse");

        std::vector<int> neg{0,-3,4,-1,2};
        vector::sort(neg);
        expectVecEq(neg, std::vector<int>{-3,-1,0,2,4}, "sort negatives");
    }
    {
        std::vector<double> d{3.14, 2.71, -1.0, 0.0, 2.71};
        vector::sort(d);
        expectVecEq(d, std::vector<double>{-1.0, 0.0, 2.71, 2.71, 3.14}, "sort double dupes");
    }

    std::cout << "\n==== getNextLargest<T> (distinkt tvåa) ====\n";
    {
        const std::vector<double> numbers{3.4, 2.3, 4.7, 9.3, -2.4, -1.0};
        const double got = vector::getNextLargest(numbers);
        expectEqDouble(got, 4.7, "getNextLargest(example)");
    }
    // Kantfall för getNextLargest
    {
        const std::vector<int> empty{};
        expectEq(vector::getNextLargest(empty), 0, "getNextLargest(empty)");

        const std::vector<int> single{5};
        expectEq(vector::getNextLargest(single), 0, "getNextLargest(single)");

        const std::vector<int> allEqual{7,7,7};
        expectEq(vector::getNextLargest(allEqual), 0, "getNextLargest(all equal)");

        const std::vector<int> twoVals{10, 8};
        expectEq(vector::getNextLargest(twoVals), 8, "getNextLargest(two vals)");

        const std::vector<int> negatives{-10, -3, -7, -3, -20};
        expectEq(vector::getNextLargest(negatives), -7, "getNextLargest(negatives)");

        const std::vector<double> floats{1.0, 3.5, 3.5, 2.4};
        expectEqDouble(vector::getNextLargest(floats), 2.4, "getNextLargest(double dupes)");
    }

    // // Kompileringsfel-test (avkommentera för att verifiera constraints):
    // std::vector<std::string> s{"hej","då"};
    // vector::sort(s);                  // ska ge static_assert-fel
    // vector::getNextLargest(s);        // ska ge static_assert-fel

    std::cout << "\nAll tests done.\n";
    return 0;
}
