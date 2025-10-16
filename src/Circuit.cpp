/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "ClockComponent.hpp"

#include "Error.hpp"

namespace nts {

Circuit::Circuit() : _tickCount(0) {}

Circuit::~Circuit() {}

std::shared_ptr<IComponent> Circuit::getComponent(const std::string &name) const
{
    auto aux = this->_components.find(name);
    if (aux != this->_components.end()) {
        return aux->second;
    }
    return nullptr; 
}

void Circuit::addComponent(const std::string& name, const std::string &type) {
    if (_components.find(name) != _components.end()) {
        throw DuplicateError(name);
    }

    std::shared_ptr<nts::IComponent> aux = factory.createComponent(type);
    if (!aux) {
        throw UnknownTypeError(type);
    }
    Circuit::addComponent(name, std::move(aux));

}


void Circuit::addComponent(const std::string& name, std::shared_ptr<nts::IComponent> component) {
    if (!component) {
        throw UnknownNameError(name);
    }

    if (std::dynamic_pointer_cast<InputComponent>(component) || std::dynamic_pointer_cast<ClockComponent>(component)) {
        _inpComponents.push_back(name);
    } else if (std::dynamic_pointer_cast<OutputComponent>(component)) {
        _outComponents.push_back(name);
    }

    _components.emplace(name, component);
}


void Circuit::simulate(std::size_t tick)
{
    (void)tick;

    for (const auto& name : _inpComponents) {
        auto comp = _components.find(name);
        if (comp != _components.end()) {
            comp->second->simulate(tick);
        }
    }

    _tickCount++;
}

void Circuit::display() const {
    if (_components.empty()) {
        throw NoChipsetError();
    }
    std::cout << "tick: " << _tickCount << std::endl;
    std::cout << "input(s):" << std::endl;
    for (const auto& name : _inpComponents) {
        auto comp = _components.find(name);
        if (comp != _components.end()) {
            nts::Tristate res = comp->second->compute(1);
            char st = (res == nts::Undefined) ? 'U' : (res == nts::False) ? '0' : '1';
            std::cout << "  " << name << ": " << st << std::endl;
        }
    }

    std::cout << "output(s):" << std::endl;

    for (const auto& name : _outComponents) {
        auto comp = _components.find(name); 
        if (comp != _components.end()) {
            nts::Tristate res = comp->second->compute(1);
            char st = (res == nts::Undefined) ? 'U' : (res == nts::False) ? '0' : '1';
            std::cout << "  " << name << ": " << st << std::endl;
        }
    }
}

void Circuit::linkComponents(const std::string& name, int pin, const std::string& otherName, int otherPin){
    auto comp = _components.find(name);
    auto otherComp = _components.find(otherName);
    if (comp == _components.end()) {
        throw UnknownNameError(name);
    }
    if (otherComp == _components.end()) {
        throw UnknownNameError(otherName);
    }

    otherComp->second->setLink(otherPin,  comp->second, pin);
    comp->second->setLink(pin,  otherComp->second, otherPin);

}

}