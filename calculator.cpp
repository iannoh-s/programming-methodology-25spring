#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    // TODO
    if (a == std::numeric_limits<int>::max()) {
        throw std::overflow_error("Add Overflow");
    }
    else if (a == std::numeric_limits<int>::min()) {
        throw std::overflow_error("Add Underflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if (a == std::numeric_limits<int>::max()) {
        throw std::overflow_error("Subtract Overflow");
    }
    else if (a == std::numeric_limits<int>::min()) {
        throw std::overflow_error("Subtract Underflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if (a == 0) {
        return 0;
    }
    else if (abs(b) > std::numeric_limits<int>::max() / abs(a)) {
        if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
            throw std::overflow_error("Multiply Overflow");
        }
        else {
            throw std::overflow_error("Multiply Underflow");
        }
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    // TODO
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    else if (a == std::numeric_limits<int>::max()) {
        if (b == 1) {
            throw std::overflow_error("Divide Overflow");
        }
        else if (b == -1) {
            throw std::overflow_error("Divide Underflow");
        }
    }
    else if (a == std::numeric_limits<int>::min()) {
        if (b == 1) {
            throw std::overflow_error("Divide Underflow");
        }
        else if (b == -1) {
            throw std::overflow_error("Divide Overflow");
        }
    }
    return a / b;
}