/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** XorComponent
*/

#include "XorComponent.hpp"

namespace nts {

XorComponent::XorComponent() : AComponent(3) {}

nts::Tristate XorComponent::compute(std::size_t pin)
{
    if (pin != 3)
        return nts::Undefined;

    nts::Tristate a = getLink(1);
    nts::Tristate b = getLink(2);
    
    if (a == nts::Undefined || b == nts::Undefined)
        return nts::Undefined;
    if (a == b)
        return nts::False;
    else
        return nts::True;
}
}