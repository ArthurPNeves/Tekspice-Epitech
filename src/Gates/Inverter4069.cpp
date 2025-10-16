/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** Inverter4069
*/

#include "Inverter4069.hpp"
#include "Error.hpp"
namespace nts {

nts::Inverter4069::Inverter4069(std::size_t nbPin) : AComponent(nbPin)
{
    if (nbPin != 14) 
        throw InvalidPinNb();
}

nts::Inverter4069::~Inverter4069()
{
}

void nts::Inverter4069::simulate(std::size_t tick)
{
    (void)tick;
}

Tristate nts::Inverter4069::compute(std::size_t pin)
{
    if (pin < 1 || pin > 14)
        throw InvalidPin();

    if (pin == 2 || pin == 4 ||  pin == 6 || pin == 8 || pin == 10 || pin == 12)
        return computeNOT(pin);

    return Tristate::Undefined;
}

Tristate nts::Inverter4069::computeNOT(std::size_t pin)
{
    std::size_t pinA;

    switch (pin) {
    case 2:
        pinA = 1; 
        break;
    case 4:
        pinA = 3;
        break;
    case 6:
        pinA = 5;
        break;
    case 8:
        pinA = 9;
        break;
    case 10:
        pinA = 11;
        break;
    case 12:
        pinA = 13;
        break;
    default:
        throw InvalidPin();
    }


    Tristate A = _links[pinA].first->compute(_links[pinA].second);

    if (A == Tristate::Undefined)
        return Tristate::Undefined;

    if (A == Tristate::True)
        return Tristate::False;

    return Tristate::True;
}
}