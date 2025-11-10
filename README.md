# Rational Numbers Calculator

A C++ implementation of a Rational Numbers class that performs arithmetic operations and comparisons on fractions with automatic simplification.

## About

This project implements a custom `Rationals` class that handles rational numbers (fractions) as first-class objects in C++. The class automatically simplifies fractions using the Greatest Common Divisor (GCD) algorithm and supports all standard arithmetic operations and comparisons.

Built as part of COP3014 coursework, this project demonstrates:
- Object-oriented programming principles in C++
- Operator overloading for intuitive syntax
- Encapsulation of complex mathematical operations
- Recursive algorithms (GCD calculation)
- Input validation and error handling

## Features

### Arithmetic Operations
- **Addition** - Add two rational numbers with automatic simplification
- **Subtraction** - Subtract rational numbers
- **Multiplication** - Multiply rational numbers
- **Division** - Divide rational numbers with zero-division protection
- **Unary Negation** - Negate rational numbers

### Comparison Operations
- Equality (`==`)
- Inequality (`!=`)
- Less than (`<`)
- Greater than (`>`)
- Less than or equal (`<=`)
- Greater than or equal (`>=`)

### Automatic Features
- **Automatic Simplification** - All fractions are automatically reduced to lowest terms
- **Smart Input** - Accepts both whole numbers and fractions (e.g., `5` or `3/4`)
- **Smart Output** - Displays whole numbers without denominators (e.g., `4` instead of `4/1`)
- **Sign Normalization** - Always displays negative sign on numerator (e.g., `-3/4` instead of `3/-4`)
- **Error Handling** - Prevents division by zero with clear error messages

## Tech Stack

- **C++** (C++11 or later)
- **Standard Library** (`iostream`)
- Custom namespace implementation (`YK`)

## 🤝 Contributing

Contributions are welcome! Here are some ways you can help improve this project:

### Enhancement Ideas

- 📊 Add mixed number support (e.g., 1 1/2)
- 🧮 Implement additional operations (power, root, absolute value)
- 🎨 Create a GUI calculator interface
- 📝 Add comprehensive unit tests
- 🔄 Implement conversion to/from decimal
- 📐 Add floating-point approximation method
- 🌐 Support for arbitrarily large numerators/denominators (BigInt)
- ⚡ Optimize operations for performance
- 📚 Add more example programs
- 🔍 Implement additional number theory functions (LCM, prime factorization)
