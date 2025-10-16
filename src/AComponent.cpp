/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include <memory>
#include <iostream>

namespace nts {

AComponent::AComponent(std::size_t pinCount) : _pins(pinCount, nts::Undefined) {}

AComponent::~AComponent() {}


void AComponent::setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin)
{

    
    if (pin > _pins.size()) {
        throw std::out_of_range("Not enough pins allocated");
    }

    _links[pin] = {other, otherPin};

}

nts::Tristate AComponent::getLink(std::size_t pin) const
{
    auto it = _links.find(pin);
    if (it != _links.end()) {

        std::shared_ptr<nts::IComponent> linkedComponent = it->second.first;
        std::size_t linkedPin = it->second.second;
        if (linkedComponent != nullptr) {
            return linkedComponent->compute(linkedPin);
        }
    }

    return nts::Undefined;
}

void AComponent::simulate(std::size_t tick)
{
    (void) tick;
}
}