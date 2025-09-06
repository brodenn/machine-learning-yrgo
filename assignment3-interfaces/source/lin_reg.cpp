/**
 * @file lin_reg.cpp
 * @brief Implementation of the simple linear regression model.
 */
#include <algorithm>
#include "ml/lin_reg/lin_reg.h"

namespace ml::lin_reg
{
LinReg::LinReg(const std::vector<double>& trainInput,
               const std::vector<double>& trainOutput) noexcept
    : myTrainInput{trainInput}
    , myTrainOutput{trainOutput}
    , myTrainSetCount{std::min(trainInput.size(), trainOutput.size())}
    , myBias{0.5}
    , myWeight{0.5}
{
}

double LinReg::predict(double input) const noexcept
{
    // y = kx + m
    return (myWeight * input) + myBias;
}

bool LinReg::train(std::size_t epochCount, double learningRate) noexcept
{
    // Validation according to assignment: refuse invalid args or missing pairs.
    if (myTrainSetCount == 0U || epochCount == 0U || learningRate <= 0.0)
    {
        return false;
    }

    // Training is covered in later lectures; we just "pretend".
    // (void) to silence unused-var warnings in strict builds.
    (void)epochCount;
    (void)learningRate;
    return true;
}
} // namespace ml::lin_reg
