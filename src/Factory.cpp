#include "Factory.hpp"
#include "ClockComponent.hpp"
#include "FalseComponent.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "TrueComponent.hpp"
#include "Error.hpp"
#include "Adder4008.hpp"
#include "AndComponent.hpp"
#include "NotComponent.hpp"
#include "XorComponent.hpp"
#include "OrComponent.hpp"
#include "Adder4008.hpp"
#include "Nor4001.hpp"
#include "Nand4011.hpp"
#include "Xor4030.hpp"
#include "Inverter4069.hpp"
#include "Or4071.hpp"
#include "And4081.hpp"


// #include "FlipFlop4013.hpp"
#include "Johnson4017.hpp"
// #include "Counter4040.hpp"
// #include "ShiftRegister4094.hpp"
// #include "DataSelector4512.hpp"
// #include "Decoder4514.hpp"
// #include "RAM4801.hpp"
// #include "ROM2716.hpp"

namespace nts {
std::shared_ptr<nts::IComponent> Factory::createComponent(const std::string &type) {
    if (type == "input") return std::make_shared<InputComponent>();
    if (type == "output") return std::make_shared<OutputComponent>();
    if (type == "true") return std::make_shared<TrueComponent>();
    if (type == "false") return std::make_shared<FalseComponent>();
    if (type == "clock") return std::make_shared<ClockComponent>();
    if (type == "and") return std::make_shared<AndComponent>();
    if (type == "or") return std::make_shared<OrComponent>();
    if (type == "xor") return std::make_shared<XorComponent>();
    if (type == "not") return std::make_shared<NotComponent>();

    if (type == "4001") return std::make_shared<Nor4001>(14);
    if (type == "4011") return std::make_shared<Nand4011>(14);
    if (type == "4030") return std::make_shared<Xor4030>(14);
    if (type == "4071") return std::make_shared<Or4071>(14);
    if (type == "4081") return std::make_shared<And4081>(14);
    if (type == "4069") return std::make_shared<Inverter4069>(14);
    if (type == "4008") return std::make_shared<Adder4008>();
    // if (type == "4013") return std::make_shared<FlipFlop4013>();
    if (type == "4017") return std::make_shared<Component4017 >();
    // if (type == "4040") return std::make_shared<Counter4040>();
    // if (type == "4094") return std::make_shared<ShiftRegister4094>();
    // if (type == "4512") return std::make_shared<DataSelector4512>();
    // if (type == "4514") return std::make_shared<Decoder4514>();
    // if (type == "4801") return std::make_shared<RAM4801>();
    // if (type == "2716") return std::make_shared<ROM2716>("./rom.bin");
    throw UnknownTypeError(type);
}
}