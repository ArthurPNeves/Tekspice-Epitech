/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** Or4071
*/

#pragma once
#include "AComponent.hpp"

namespace nts {
class Or4071 : public AComponent {
    public: 
        Or4071(std::size_t nbPin);
        ~Or4071();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    private:
        Tristate computeOR(std::size_t pin); 

};
}
