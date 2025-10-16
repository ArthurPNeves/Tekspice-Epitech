/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** Error
*/

#include <exception> 
#include <string> 

namespace nts {
class Error : public std::exception {
    protected: 
        std::string _message;
    public: 
        explicit Error(const std::string& message) : _message(message) {};
        const char* what() const noexcept override {
            return _message.c_str();
        }
};

class LexicalError : public Error {
    public: 
        explicit LexicalError(const std::string& message)
        : Error("lexical error: " + message) {}
};

class UnknownCommandError : public Error {
public:
    explicit UnknownCommandError(const std::string& command)
        : Error("Unknown command: " + command) {}
};

class UnknownTypeError : public Error {
    public: 
        explicit UnknownTypeError(const std::string& message)
        : Error("Unknown component type " + message) {}
};

class UnknownNameError : public Error {
    public: 
        explicit UnknownNameError(const std::string& message)
        : Error("Unknown component name " + message) {}
};

class DuplicateError : public Error {
    public: 
        explicit DuplicateError(const std::string& message)
        : Error("Duplicate component " + message) {}
};

class NoChipsetError : public Error {
    public: 
        NoChipsetError() : Error("No chipsets in the circuit") {}
};

class InvalidInputValue : public Error {
    public:
        explicit InvalidInputValue(const std::string& value) 
        : Error("Invalid input value " + value){}
};

class FileOpenError : public Error {
public:
    explicit FileOpenError(const std::string& filename)
        : Error("Could not open file: " + filename) {}
};

class InvalidPin : public Error {
public:
    explicit InvalidPin()
        : Error("Invalid pin requested") {}
};

class InvalidPinNb : public Error {
public:
    explicit InvalidPinNb()
        : Error("Invalid pin number") {}
};

class notANtsFile : public Error {
    public:
        explicit notANtsFile()
            : Error("Not a nts") {}
    };

}