// class FlipFlop {
// public:
//     FlipFlop(std::size_t nbPin) : _q(nts::Undefined), _qbar(nts::Undefined) {}

//     void simulate(std::size_t tick) {
//         nts::Tristate reset = getInput(4);  // Assuming reset is on pin 4
//         nts::Tristate set = getInput(6);    // Assuming set is on pin 6
//         nts::Tristate clk = getInput(3);    // Assuming clock is on pin 3
//         nts::Tristate data = getInput(5);   // Assuming data (D) is on pin 5

//         if (reset == nts::True) {
//             _q = nts::False;
//             _qbar = nts::True;
//         } else if (set == nts::True) {
//             _q = nts::True;
//             _qbar = nts::False;
//         } else if (clk == nts::True) {
//             _q = data;
//             _qbar = (data == nts::True) ? nts::False : nts::True;
//         }
//     }

//     nts::Tristate compute(std::size_t pin) {
//         if (pin == 1) return _q;   // Q output
//         if (pin == 2) return _qbar; // Q̅ output
//         return nts::Undefined;
//     }

// private:
//     nts::Tristate _q;
//     nts::Tristate _qbar;

//     nts::Tristate getInput(std::size_t pin) {
//         // Your logic to fetch pin state from connections
//     }
// };
