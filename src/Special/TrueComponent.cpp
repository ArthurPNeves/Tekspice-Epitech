/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** TrueComponent
*/

#include "TrueComponent.hpp"

namespace nts {
TrueComponent::TrueComponent() : AComponent(1), _state(nts::True) {}

nts::Tristate TrueComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::Undefined;
    return _state;
}
}
