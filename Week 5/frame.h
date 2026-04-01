#pragma once
// frame.h

#ifndef GUARD_split_h
#define GUARD_split_h

#include <vector>
#include <string>

using std::vector;
using std::string;

string::size_type width(const vector <string>&);
vector<string> frame(const vector <string>&);


#endif
