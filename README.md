# 🔌 Tekspice - Logic Circuit Simulator

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C++-20-blue.svg)](https://en.cppreference.com/w/cpp/20)
[![License](https://img.shields.io/badge/License-Epitech-red.svg)](https://www.epitech.eu/)

A robust and extensible logic circuit simulator built with modern C++20, demonstrating advanced Object-Oriented Programming principles and generic design patterns.

## 📋 Table of Contents

- [Overview](#-overview)
- [Object-Oriented Design](#-object-oriented-design)
- [Generic Architecture](#-generic-architecture)
- [Features](#-features)
- [Project Structure](#-project-structure)
- [Building](#-building)
- [Usage](#-usage)
- [Component Library](#-component-library)
- [Design Patterns](#-design-patterns)

## 🎯 Overview

Tekspice is a digital logic circuit simulator that allows users to design, simulate, and test complex electronic circuits. The project emphasizes **clean architecture**, **reusability**, and **extensibility** through careful application of OOP principles.

## 🏗️ Object-Oriented Design

This project showcases excellent OOP practices:

### 1. **Interface-Based Design** 
The `IComponent` interface defines the contract for all components in the system:
```cpp
class IComponent {
    virtual void simulate(std::size_t tick) = 0;
    virtual nts::Tristate compute(std::size_t pin) = 0;
    virtual void setLink(std::size_t pin, std::shared_ptr<IComponent> other, 
                         std::size_t otherPin) = 0;
};
```
This ensures **polymorphism** and allows any component to interact with any other component without knowing its concrete type.

### 2. **Abstract Base Class Pattern**
The `AComponent` abstract class provides common functionality for all components:
- Manages pin connections through an internal mapping structure
- Implements shared behavior (link management, state tracking)
- Forces derived classes to implement specific logic via pure virtual methods
- Reduces code duplication across 20+ component types

### 3. **Encapsulation**
- Private/protected members ensure data integrity
- Public interfaces expose only necessary functionality
- Components hide their internal state management

### 4. **Inheritance Hierarchy**
```
IComponent (interface)
    └── AComponent (abstract base)
        ├── Elementary Components (AND, OR, NOT, XOR)
        ├── Special Components (Input, Output, Clock, True, False)
        ├── Gate Components (4081, 4011, 4069, 4071, 4001, 4030)
        └── Advanced Components (Adder4008, Counter4040, FlipFlop4013, Johnson4017)
```

### 5. **Single Responsibility Principle**
Each class has a well-defined purpose:
- `Parser`: Handles .nts file parsing
- `Circuit`: Manages component lifecycle and simulation
- `Factory`: Creates components (Factory Pattern)
- `miniShell`: Handles user interaction

## 🔧 Generic Architecture

The project demonstrates generic programming and flexibility:

### 1. **Component-Agnostic System**
The circuit simulator doesn't need to know about specific component types. It works with the `IComponent` interface, making it trivial to add new components without modifying core logic.

### 2. **Factory Pattern for Extensibility**
```cpp
class Factory {
    static std::shared_ptr<IComponent> createComponent(const std::string &type);
};
```
New components can be added by:
1. Creating a class that inherits from `AComponent`
2. Implementing the required virtual methods
3. Adding the component to the Factory's creation logic

**No changes needed in:**
- Circuit management code
- Parser logic
- Shell interface
- Other components

### 3. **Generic Pin Management**
Components use a flexible pin system that works for:
- Simple gates (2 inputs, 1 output)
- Complex ICs (14-16 pins)
- Special components (single pin for clock/input/output)

### 4. **Tristate Logic**
Custom `Tristate` enum allows representing:
- `True` (1)
- `False` (0)
- `Undefined` (-1)

This generic approach handles unknown states during computation, making the simulator more realistic.

### 5. **Smart Pointer Usage**
`std::shared_ptr<IComponent>` enables:
- Automatic memory management
- Safe sharing of components across connections
- Prevention of memory leaks
- No manual `new`/`delete` required

### 6. **Template-Ready Design**
The architecture is designed to easily support:
- Different simulation modes
- Various timing models
- Custom logic levels
- Future extensions without breaking existing code

## ✨ Features

- ✅ Parse and validate circuit description files (.nts format)
- ✅ Simulate logic circuits tick-by-tick
- ✅ Support for elementary gates (AND, OR, NOT, XOR)
- ✅ Support for integrated circuits (4000 series)
- ✅ Advanced components (Adders, Counters, Flip-Flops)
- ✅ Interactive shell for circuit control
- ✅ Display component states in real-time
- ✅ Tristate logic support (True, False, Undefined)

## 📁 Project Structure

```
tekspice/
├── include/
│   ├── IComponent.hpp          # Base interface
│   ├── AComponent.hpp          # Abstract base class
│   ├── Factory.hpp             # Component factory
│   ├── Parser.hpp              # Circuit file parser
│   ├── Circuit.hpp             # Circuit manager
│   ├── miniShell.hpp           # Interactive shell
│   ├── Elementary/             # Basic logic gates
│   ├── Gates/                  # IC gate components (4000 series)
│   ├── Special/                # Special components (I/O, Clock)
│   └── Advanced/               # Complex components (Adders, Counters)
├── src/                        # Implementation files
├── Makefile                    # Build configuration
└── README.md                   # This file
```

## 🔨 Building

### Prerequisites
- C++ compiler with C++20 support (GCC 10+ or Clang 10+)
- Make

### Compilation
```bash
make
```

### Clean build
```bash
make re
```

### Debug build
```bash
make debug
```

## 🚀 Usage

### Basic Usage
```bash
./nanotekspice circuit_file.nts
```

### Circuit File Format (.nts)
```
.chipsets:
input a
input b
output s
and gate

.links:
a:1 gate:1
b:1 gate:2
gate:3 s:1
```

### Interactive Commands
Once the simulator is running:
- `display` - Show current state of all outputs
- `simulate` - Run one simulation tick
- `loop` - Continuously simulate
- `dump` - Display all component states
- `<input>=<value>` - Set input value (e.g., `a=1`)
- `exit` - Quit the simulator

## 🧩 Component Library

### Elementary Components
- **AND**: Logical AND gate
- **OR**: Logical OR gate
- **NOT**: Logical inverter
- **XOR**: Exclusive OR gate

### Special Components
- **Input**: User-controllable input
- **Output**: Observable output
- **Clock**: Oscillating signal
- **True/False**: Constant values

### Gate ICs (4000 Series)
- **4081**: Quad 2-input AND gate
- **4071**: Quad 2-input OR gate
- **4011**: Quad 2-input NAND gate
- **4001**: Quad 2-input NOR gate
- **4030**: Quad 2-input XOR gate
- **4069**: Hex inverter

### Advanced Components
- **4008**: 4-bit full adder
- **4013**: Dual D flip-flop
- **4017**: Decade counter/divider
- **4040**: 12-stage binary counter

## 🎨 Design Patterns

### Factory Pattern
Creates components dynamically based on type strings, decoupling component creation from usage.

### Strategy Pattern
Different components implement different computation strategies through the `compute()` method.

### Template Method Pattern
`AComponent` defines the skeleton of component behavior, letting subclasses override specific steps.

### Observer Pattern
Components observe their linked components to compute their own states.

## 🔬 Why This Design is Generic and Extensible

1. **Open/Closed Principle**: Open for extension (add new components), closed for modification (no changes to core code)

2. **Dependency Inversion**: High-level modules (Circuit, Parser) depend on abstractions (IComponent), not concrete implementations

3. **Liskov Substitution**: Any `IComponent` can be substituted for another without breaking the program

4. **Interface Segregation**: Clean, minimal interfaces that don't force unnecessary dependencies

5. **Scalability**: From 5 components to 500+ components without architectural changes

## 🎓 Learning Outcomes

This project demonstrates:
- ✅ Advanced C++ features (smart pointers, pure virtual functions, modern STL)
- ✅ SOLID principles in practice
- ✅ Design patterns for real-world problems
- ✅ Code organization and modularity
- ✅ Generic programming techniques
- ✅ Object-oriented architecture at scale

## 📝 License

This project is part of the EPITECH curriculum.

## 👥 Authors

Arthur Patrocínio Neves

---

**Note**: This simulator demonstrates that well-designed OOP code is not just about using classes—it's about creating flexible, maintainable, and extensible systems that can grow without becoming brittle.
