/**
 * @file interface.h
 * @brief Linear regression interface.
 */
#pragma once

namespace ml::lin_reg
{
/**
 * @brief Interface for simple linear regression models.
 *
 * For VG: uses virtual, override, default, delete, noexcept and Doxygen as appropriate.
 */
class Interface
{
public:
    /// Virtual defaulted destructor to enable proper polymorphic destruction.
    virtual ~Interface() noexcept = default;

    /**
     * @brief Predict y given x.
     * @param[in] input Input value x.
     * @return Predicted value y.
     */
    virtual double predict(double input) const noexcept = 0;
};
} // namespace ml::lin_reg
