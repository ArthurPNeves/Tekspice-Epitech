/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** OrComponent
*/

#include "OrComponent.hpp"
namespace nts {
OrComponent::OrComponent() : AComponent(3) {}

nts::Tristate OrComponent::compute(std::size_t pin)
{
    if (pin != 3)
        return nts::Undefined;
    
    nts::Tristate a = getLink(1);
    nts::Tristate b = getLink(2);
    
    if (a == nts::True || b == nts::True)
        return nts::True;
    if (a == nts::False && b == nts::False)
        return nts::False;
    return nts::Undefined;
}
}