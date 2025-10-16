/*
** EPITECH PROJECT, 2025
** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
** File description:
** Inverter4069
*/

#pragma once
#include "AComponent.hpp"

namespace nts {
class Inverter4069 : public AComponent {
    public: 
        Inverter4069(std::size_t nbPin);
        ~Inverter4069();
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
    private:
        Tristate computeNOT(std::size_t pin); 

};
}
