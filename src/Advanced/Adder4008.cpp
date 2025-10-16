/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** Adder4008
*/

#include "Adder4008.hpp"
#include "Error.hpp"
#include <algorithm>


namespace nts {
Adder4008::Adder4008() : AComponent(16)
{
    _inPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 9, 15};
    _outPins = std::vector<int> {10, 11, 12, 13, 14};
}

Adder4008::~Adder4008()
{
}

void Adder4008::setAllPins(nts::Tristate state)
{
    for (auto pin : _outPins) {
        _pins[pin] = state;
    }
}

void Adder4008::simulate(std::size_t tick)
{
    (void)tick;
    if (_links[9].first != nullptr) {
        if (_links[9].first->compute(_links[9].second) == nts::Undefined) {
            setAllPins(nts::Undefined);
            return;
        }
    }
    addInputs();
}

nts::Tristate Adder4008::compute(std::size_t pin)
{

    if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        simulate(0);
        return _pins[pin];
    } else if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].first != nullptr) {
            _pins[pin] = _links[pin].first->compute(_links[pin].second);
            return _pins[pin];
        }
    } else {
        throw InvalidPin();
    }
    return nts::Undefined;
}
void Adder4008::addInputs()
{
    std::vector<int> inputPins = {84, 7, 6, 9, 5, 4, 84, 3, 2, 84, 1, 15, 84};
    std::vector<int> outputPins = {10, 11, 12, 13};

    for (int bit = 0; bit < 4; bit++) {
        int aPin = inputPins[bit * 3 + 1];
        int bPin = inputPins[bit * 3 + 2];
        int carryInPin = (bit == 0) ? inputPins[bit * 3 + 3] : inputPins[(bit - 1) * 3 + 3];

        if (_links[aPin].first != nullptr && _links[bPin].first != nullptr &&
            (bit != 0 || _links[carryInPin].first != nullptr)) {

            nts::Tristate A = _links[aPin].first->compute(_links[aPin].second);
            nts::Tristate B = _links[bPin].first->compute(_links[bPin].second);
            nts::Tristate carryIn = (bit == 0) ? _links[carryInPin].first->compute(_links[carryInPin].second) : 
            static_cast<nts::Tristate>(carryInPin);

            if (A == nts::Undefined || B == nts::Undefined || (bit == 0 && carryIn == nts::Undefined)) {
                _pins[outputPins[bit]] = nts::Undefined;
                if (bit == 3) _pins[14] = nts::Undefined;
                else inputPins[(bit + 1) * 3 + 3] = 84;
            } else {
                _pins[outputPins[bit]] = calcSum(A, B, carryIn);
                if (bit == 3) {
                    _pins[14] = calcCarry(A, B, carryIn);
                } else {
                    inputPins[(bit + 1) * 3 + 3] = calcCarry(A, B, carryIn);
                }
            }
        }
    }
}

nts::Tristate Adder4008::calcSum(nts::Tristate A, nts::Tristate B, nts::Tristate C)
{
    if (A == nts::Undefined || B == nts::Undefined || C == nts::Undefined)
        return nts::Undefined;
    std::vector<nts::Tristate> truthMap =
        {nts::False, nts::True, nts::True, nts::False, nts::True, nts::False, nts::False, nts::True};
    int selector = 0 + (A == nts::True ? 1 : 0)
        + (B == nts::True ? 2 : 0)
        + (C == nts::True ? 4 : 0);
    return truthMap[selector]; 
}

nts::Tristate Adder4008::calcSum(nts::Tristate A, nts::Tristate B, int C)
{
    switch (C) {
        case 0: return calcSum(A, B, nts::False);
        case 1: return calcSum(A, B, nts::True);
        case 84: return nts::Undefined;
        default: throw InvalidPin();
    }
    return nts::Undefined;
}

nts::Tristate Adder4008::calcCarry(nts::Tristate A, nts::Tristate B, nts::Tristate C)
{
    if (A == nts::Undefined || B == nts::Undefined || C == nts::Undefined)
        return nts::Undefined;
    std::vector<nts::Tristate> truthMap =
        {nts::False, nts::False, nts::False, nts::True, nts::False, nts::True, nts::True, nts::True};
    int selector = 0 + (A == nts::True ? 1 : 0)
        + (B == nts::True ? 2 : 0)
        + (C == nts::True ? 4 : 0);
    return truthMap[selector];
}

nts::Tristate Adder4008::calcCarry(nts::Tristate A, nts::Tristate B, int C)
{
    switch (C) {
        case 0: return calcCarry(A, B, nts::False);
        case 1: return calcCarry(A, B, nts::True);
        case 84: return nts::Undefined;
        default: throw InvalidPin();
    }
    return nts::Undefined;
}

}
