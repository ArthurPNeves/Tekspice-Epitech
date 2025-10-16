/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** Xor4030
*/

#pragma once
#include "AComponent.hpp"

namespace nts {
class Xor4030 : public AComponent {
    public: 
        Xor4030(std::size_t nbPin);
        ~Xor4030();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    private:
        Tristate computeXOR(std::size_t pin); 

};
}
