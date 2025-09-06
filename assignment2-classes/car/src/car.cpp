/**
 * @brief Car class implementation details.
 */
#include "car.h"

namespace vehicle
{
    Car::Car(const char* brand,
             const char* model,
             const char* color,
             unsigned yearOfLaunch,
             TransmissionType transmissionType) noexcept
        : myBrand{brand}
        , myModel{model}
        , myColor{color}
        , myYearOfLaunch{yearOfLaunch}
        , myTransmissionType{transmissionType}
    {}

    const char* Car::brand() const noexcept { return myBrand; }
    const char* Car::model() const noexcept { return myModel; }
    const char* Car::color() const noexcept { return myColor; }
    unsigned Car::yearOfLaunch() const noexcept { return myYearOfLaunch; }
    TransmissionType Car::transmissionType() const noexcept { return myTransmissionType; }

    void Car::setColor(const char* color) noexcept { myColor = color; }
    void Car::setTransmissionType(TransmissionType transmissionType) noexcept { myTransmissionType = transmissionType; }

    void Car::print(std::ostream& os) const
    {
        os << "--------------------------------------------------------------------------------\n";
        os << "Brand: " << myBrand << "\n";
        os << "Model: " << myModel << "\n";
        os << "Color: " << myColor << "\n";
        os << "Year of launch: " << myYearOfLaunch << "\n";
        os << "Transmission type: " << transmissionAsText() << "\n";
        os << "--------------------------------------------------------------------------------\n";
    }

    const char* Car::transmissionAsText() const noexcept
    {
        return (myTransmissionType == TransmissionType::Manual) ? "Manual" : "Automatic";
    }
} // namespace vehicle
