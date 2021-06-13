#include "json.hpp"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
using namespace nlohmann;

void flatten(std::istream& is, std::ostream& os);

void runtestcases() {
    vector<pair<string, string>> tc_list({{"tc1.json",    "tc1_op.json"},
                            {"tc2.json",    "tc2_op.json"},
                            {"tc3.json",     "tc3_op.json"},
                            {"tc4.json",     "tc4_op.json"}});
    
    for(auto tc: tc_list) {
        string filename("./tests/" + tc.first);
        ifstream istream(filename); ostringstream os;
        flatten(istream, os);

        string resultfilename("./tests/" + tc.second);
        ifstream rstream(resultfilename); ostringstream ors; string str;
        while(getline(rstream, str))
            ors << str << endl;

        if(os.str() != ors.str()) {
            cout << "Testcase for file " << tc.first << " failed" << endl;
            cout << "Output from the script is --> " << os.str() << endl;
            cout << "Expected output is --> " << ors.str() << endl;
            break;
        } else {
            cout << "Testcase for input from file " << tc.first << " is successful" << endl;
        }
    }
}