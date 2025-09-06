/**
 * @file lin_reg.h
 * @brief Final linear regression class implementing the Interface.
 */
#pragma once

#include <cstddef>
#include <vector>
#include "ml/lin_reg/interface.h"

namespace ml::lin_reg
{
/**
 * @brief Simple (untrained) linear regression model y = kx + m.
 *
 * The class is non-copyable and non-movable (delete) as per assignment.
 */
class LinReg final : public Interface
{
public:
    /**
     * @brief Construct the model with training data (by reference).
     * @param[in] trainInput  Read-only vector of x values.
     * @param[in] trainOutput Read-only vector of y values.
     */
    explicit LinReg(const std::vector<double>& trainInput,
                    const std::vector<double>& trainOutput) noexcept;

    /// Virtual destructor override.
    ~LinReg() noexcept override = default;

    /// Predict y given x using current parameters (k, m).
    double predict(double input) const noexcept override;

    /**
     * @brief (Placeholder) Train the model.
     * @param[in] epochCount  Number of epochs (> 0).
     * @param[in] learningRate Learning rate (> 0.0). Default 0.01.
     * @return true if training was (pretend) performed, false otherwise.
     */
    bool train(std::size_t epochCount, double learningRate = 0.01) noexcept;

    // Disallow default, copy and move to follow the assignment strictly.
    LinReg()                                  = delete;
    LinReg(const LinReg&)                     = delete;
    LinReg(LinReg&&)                          = delete;
    LinReg& operator=(const LinReg&)          = delete;
    LinReg& operator=(LinReg&&)               = delete;

private:
    /// References to training data (not owned).
    const std::vector<double>& myTrainInput;
    const std::vector<double>& myTrainOutput;

    /// Number of complete (x,y) pairs available.
    const std::size_t myTrainSetCount;

    /// Parameters: y = kx + m
    double myBias;   ///< m
    double myWeight; ///< k
};
} // namespace ml::lin_reg
