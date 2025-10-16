/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** And4081
*/

#pragma once
#include "AComponent.hpp"

namespace nts {
class And4081 : public AComponent {
    public: 
        And4081(std::size_t nbPin);
        ~And4081();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    private:
        Tristate computeAND(std::size_t pin); 

};
}
