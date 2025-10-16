/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** Adder4008
*/

#pragma once
#include "AComponent.hpp"

namespace nts {
class Adder4008 : public AComponent{
    public:
        Adder4008();
        ~Adder4008();

        void addInputs();
        nts::Tristate calcSum(nts::Tristate A, nts::Tristate B, nts::Tristate C);
        nts::Tristate calcSum(nts::Tristate A, nts::Tristate B, int C);
        nts::Tristate calcCarry(nts::Tristate A, nts::Tristate B, nts::Tristate C);
        nts::Tristate calcCarry(nts::Tristate A, nts::Tristate B, int C);
        void setAllPins(nts::Tristate state);
        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
    private: 
        std::vector<int> _inPins;
        std::vector<int> _outPins;
};
}
