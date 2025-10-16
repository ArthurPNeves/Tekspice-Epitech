/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** C4001
*/

#pragma once
#include "AComponent.hpp"

namespace nts {
class Nor4001 : public AComponent {
    public: 
        Nor4001(std::size_t nbPin);
        ~Nor4001();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    private:
        Tristate computeNOR(std::size_t pin); 

};
}
