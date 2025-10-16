#pragma once
#include "IComponent.hpp"
#include "Circuit.hpp"
#include <fstream>
#include <sstream>

namespace nts 
{
    enum State
    {
        null,
        chipsets,
        links
    };

    class Parser
    {
    public:
        Parser();
        ~Parser();

        void openFile(const std::string &filepath);
        void NextLine();
        std::string parseLine();
        bool isNewSection();
        nts::State getParseState() const {return this->_parseState;};
        void buildCircuit(Circuit &circuit);

    protected:
    private:
        std::ifstream _stream;
        std::stringstream _line;
        int _argNumber = 0;
        nts::State _parseState = null;
    };
}