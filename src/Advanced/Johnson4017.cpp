/*
** EPITECH PROJECT, 2025
** OOP
** File description:
** Component4017
*/

#include "Johnson4017.hpp"
#include <vector>
#include "Error.hpp"
#include <algorithm>

namespace nts
{

    Component4017::Component4017() : AComponent(15), _currentState(-1) {
        _inPins = std::vector<int> {13, 14, 15};
        _outPins = std::vector<int> {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12};
        updatePins();
    }

    Component4017::~Component4017() {}

    void Component4017::reset()
    {
        _currentState = 0;
        _pins[3] = nts::True;  
        _pins[2] = nts::False;  
        _pins[4] = nts::False;  
        _pins[7] = nts::False;  
        _pins[10] = nts::False; 
        _pins[1] = nts::False;  
        _pins[5] = nts::False;  
        _pins[6] = nts::False;  
        _pins[9] = nts::False;  
        _pins[11] = nts::False; 
        _pins[12] = nts::True;  
    }

    void Component4017::updatePins()
    {
        _pins[3] = _currentState == 0 ? nts::True : nts::False;
        _pins[2] = _currentState == 1 ? nts::True : nts::False;
        _pins[4] = _currentState == 2 ? nts::True : nts::False;
        _pins[7] = _currentState == 3 ? nts::True : nts::False;
        _pins[10] = _currentState == 4 ? nts::True : nts::False;
        _pins[1] = _currentState == 5 ? nts::True : nts::False;
        _pins[5] = _currentState == 6 ? nts::True : nts::False;
        _pins[6] = _currentState == 7 ? nts::True : nts::False;
        _pins[9] = _currentState == 8 ? nts::True : nts::False;
        _pins[11] = _currentState == 9 ? nts::True : nts::False;
        _pins[12] = _currentState >= 5 && _currentState <= 9 ? nts::False : nts::True;
    }

    void Component4017::simulate(std::size_t tick)
    {
        (void)tick;

        nts::Tristate newPin15 = _links[15].first->compute(_links[15].second);
        nts::Tristate newPin14 = _links[14].first->compute(_links[14].second);
        nts::Tristate newPin13 = _links[13].first->compute(_links[13].second);

        if (newPin15 == nts::True)
        {
            reset();
            _pins[13] = newPin13;
            _pins[14] = newPin14;
            return;
        }
        if (_currentState == (size_t)-1)
        {
            _pins[13] = newPin13;
            _pins[14] = newPin14;
            return;
        }

        if (_pins[14] == nts::False && newPin14 == nts::True && (_pins[13] == nts::False || _pins[13] == nts::Undefined))
        {
            _currentState += _currentState < 9 ? 1 : -9;
        }
        else if (_pins[13] == nts::True && newPin13 == nts::False && _pins[14] == nts::True)
        {

            _currentState += _currentState < 9 ? 1 : -9;
        }
        _pins[13] = newPin13;
        _pins[14] = newPin14;
        updatePins();
    }

    nts::Tristate Component4017::compute(std::size_t pin)
    {

        if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end())
        {
            if (_links[pin].first != nullptr)
            {
                _pins[pin] = _links[pin].first->compute(_links[pin].second);
            }
            return _pins[pin];
        }
        else if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end())
        {
            if (!_isUpdated)
            {
                _isUpdated = True;
                simulate(0);
            }
            return _pins[pin];
        }
        else
        {
            throw InvalidPin();
        }
    }

}