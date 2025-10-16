/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

namespace nts {
InputComponent::InputComponent() : AComponent(1), _state(nts::Undefined) {}

void InputComponent::setState(nts::Tristate state)
{
    _state = state;
}

nts::Tristate InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        return nts::Undefined;
    return _pins[0]; 
}

void InputComponent::simulate(std::size_t tick)
{
    (void)tick;
    _pins[0] = _state; 
}
}