#include "json.hpp"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

/*
Read json file from stdin, flatten the json and write to stdout
*/

using namespace std;
using namespace nlohmann;

extern void runtestcases();

void flatten(const string& prefix, json& j, json& json_out) {
    switch(j.type())
    {
        case detail::value_t::object:
        {
            for (auto& e : *j.m_value.object) {
                string nprefix(prefix);
                if(!prefix.empty())
                    nprefix.append(".");
                nprefix.append(e.first);
                flatten(nprefix, e.second, json_out);
            }
        }
        case detail::value_t::array: //array not supported
        break;
        default:
        {
            json_out[prefix] = j;
            break;
        }
    }
}

bool flatten(std::istream& is, std::ostream& os) {
    if(!is || !os)
        return false;

    json json_obj = json::parse(is);
    json flat_json;
    try {
        flatten("", json_obj, flat_json);
        os << std::setw(4) << flat_json << endl;
    }
    catch(exception e) {
        os << "Exception while flattening json -> " << e.what() << endl;
        return false;
    }
    catch(...) {
        os << "Unknown error while flattening json " << endl;
        return false;
    }

    return true;
}


int main(int argc, char* argv[]) {
    if(argc > 1 && string(argv[1]) == "-t") {
        runtestcases();
    } else {
        flatten(cin, cout);
    }
}