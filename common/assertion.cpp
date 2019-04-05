#include "assertion.h"

#include <iostream>
#include <exception>

using namespace std;

namespace utils
{
    void assert(bool assertion, const string& good, const string& bad)
    {
        if (assertion)
        {
            if (!good.empty())
                cout << "- " << good << endl;
        }
        else
            throw runtime_error(bad);
    }

    void incoming_message(const string& message)
    {
        cout << "\t<<< " << message << endl; 
    }

    void outgoing_message(const string& message)
    {
        cout << "\t>>> " << message << endl; 
    }
}