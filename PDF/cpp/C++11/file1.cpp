#include <iostream>

// Example of a literal type class
class LiteralType {
public:
    constexpr LiteralType(int value) : data(value) {}

    // A constexpr constructor
    constexpr LiteralType() : data(0) {}

    // A non-constexpr function
    int getValue() const {
        return data;
    }

private:
    int data;
};

int main() {
    // Initializing a constexpr variable with a literal value
    constexpr int constantValue = 42;

    // Initializing a constexpr variable using a constexpr constructor
    constexpr LiteralType obj1(10);

    // Initializing a constexpr variable using a default constexpr constructor
    constexpr LiteralType obj2;

    // Outputs
    std::cout << "Constant Value: " << constantValue << std::endl;
    std::cout << "Object 1 Value: " << obj1.getValue() << std::endl;
    std::cout << "Object 2 Value: " << obj2.getValue() << std::endl;

    return 0;
}

