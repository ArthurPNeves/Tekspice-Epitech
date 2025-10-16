/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** And4081
*/

#include "And4081.hpp"
#include "Error.hpp"
namespace nts {

nts::And4081::And4081(std::size_t nbPin) : AComponent(nbPin)
{
    if (nbPin != 14) 
        throw InvalidPinNb();
}

nts::And4081::~And4081()
{
}

void nts::And4081::simulate(std::size_t tick)
{
    (void)tick;
}

Tristate nts::And4081::compute(std::size_t pin)
{
    if (pin < 1 || pin > 14)
        throw InvalidPin();

    if (pin == 3 || pin == 4 || pin == 10 || pin == 11)
        return computeAND(pin);

    return Tristate::Undefined;
}

Tristate nts::And4081::computeAND(std::size_t pin)
{
    std::size_t pinA, pinB;

    switch (pin) {
    case 3:
        pinA = 1; 
        pinB = 2;
        break;
    case 4:
        pinA = 5;
        pinB = 6;
        break;
    case 10:
        pinA = 8;
        pinB = 9;
        break;
    case 11:
        pinA = 12;
        pinB = 13;
        break;
    default:
        throw InvalidPin();
    }


    Tristate A = _links[pinA].first->compute(_links[pinA].second);
    Tristate B = _links[pinB].first->compute(_links[pinB].second);

    if  (A == Tristate::False || B == Tristate::False)
        return Tristate::False;
    else if(A == Tristate::Undefined || B == Tristate::Undefined)
        return Tristate::Undefined;
    else
        return Tristate::True;
}
}