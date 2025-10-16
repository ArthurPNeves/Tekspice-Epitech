// /*
// ** EPITECH PROJECT, 2025
// ** B-OOP-400-PAR-4-1-tekspice-lynn.hakim
// ** File description:
// ** FlipFlop4013
// */

// #include "FlipFlop4013.hpp"
// #include "Error.hpp"

// namespace nts {

// FlipFlop4013::FlipFlop4013(std::size_t nbPin) : AComponent(nbPin), _flipFlopComponents{FlipFlop(7), FlipFlop(7)} {}

// FlipFlop4013::~FlipFlop4013()
// {
// };

// void FlipFlop4013::simulate(std::size_t tick)
// {
//     for (auto &ff : _flipFlopComponents) {
//         ff.simulate(tick);
//     }
// }

// nts::Tristate FlipFlop4013::compute(std::size_t pin)
// {
//     if (pin >= _pins.size()) {
//         throw InvalidPin();
//     }

//     if (pin >= 1 && pin <= 6) {
//         return _flipFlopComponents[0].compute(pin);
//     } else if (pin >= 8 && pin <= 13) {
//         return _flipFlopComponents[1].compute(pin - 7);
//     }
//     return nts::Undefined;
// }

// }
