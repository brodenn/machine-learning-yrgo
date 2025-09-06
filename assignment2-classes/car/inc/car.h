/**
 * @brief Car class implementation.
 */
#pragma once

#include <iostream>

namespace vehicle
{
    /**
     * @brief Enumeration for transmission types.
     */
    enum class TransmissionType
    {
        Manual,    /**< Manual transmission. */
        Automatic  /**< Automatic transmission. */
    };

    /**
     * @brief Class representing a car with brand, model, color, year and transmission.
     */
    class Car
    {
    public:
        /**
         * @brief Construct a new Car.
         *
         * @param[in] brand Brand of the car.
         * @param[in] model Model of the car.
         * @param[in] color Color of the car.
         * @param[in] yearOfLaunch Year of launch.
         * @param[in] transmissionType Transmission type (default = Manual).
         */
        explicit Car(const char* brand,
                     const char* model,
                     const char* color,
                     unsigned yearOfLaunch,
                     TransmissionType transmissionType = TransmissionType::Manual) noexcept;

        /**
         * @brief Destroy the Car (default).
         */
        ~Car() noexcept = default;

        // Delete copy & move constructors/operators.
        Car() = delete;
        Car(const Car&) = delete;
        Car(Car&&) = delete;
        Car& operator=(const Car&) = delete;
        Car& operator=(Car&&) = delete;

        // Getters
        const char* brand() const noexcept;
        const char* model() const noexcept;
        const char* color() const noexcept;
        unsigned yearOfLaunch() const noexcept;
        TransmissionType transmissionType() const noexcept;

        // Setters
        void setColor(const char* color) noexcept;
        void setTransmissionType(TransmissionType transmissionType) noexcept;

        // Print info
        void print(std::ostream& os = std::cout) const;

    private:
        const char* myBrand;
        const char* myModel;
        const char* myColor;
        unsigned myYearOfLaunch;
        TransmissionType myTransmissionType;

        const char* transmissionAsText() const noexcept;
    };
} // namespace vehicle
