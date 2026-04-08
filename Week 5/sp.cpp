// sp.cpp
#include "sp.h"
#include <cctype>

using namespace std;

vector<string> sp(const string& s) {
    vector<string> ret;
    typedef string::size_type str_sz;

    str_sz i = 0;

    while (i != s.size()) {

        while (i != s.size() && isspace(s[i])) {
            ++i;
        }

        str_sz j = i;
        while (j != s.size() && !isspace(s[j])) {
            ++j;
        }

        if (i != j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }

    return ret;
}
