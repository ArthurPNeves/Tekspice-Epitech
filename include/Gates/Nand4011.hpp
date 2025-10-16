/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** Nand4011
*/

#pragma once
#include "AComponent.hpp"

namespace nts {
class Nand4011 : public AComponent {
    public: 
        Nand4011(std::size_t nbPin);
        ~Nand4011();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    private:
        Tristate computeNAND(std::size_t pin); 

};
}
