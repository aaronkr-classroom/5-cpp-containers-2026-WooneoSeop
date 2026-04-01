#pragma once
// grade.h


#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <list>
#include <vector>
#include "Student_info.h"

using std::vector; // 추가
using std::list; 

double grade(double, double, const vector<double>&); // const?
double grade(double, double, double);
double grade(const Student_info&);

bool fgrade(const Student_info&);
vector<Student_info> extract_fails(vector<Student_info>&);
list<Student_info> extract_fails(list<Student_info>&);



#endif
