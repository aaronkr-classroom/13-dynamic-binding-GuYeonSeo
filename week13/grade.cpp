//grade.cpp
#include <stdexcept>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;

//grade(double, double, double)
double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

//grade(double, double, const vector<double>&)
double grade(double midterm, double final, const Vec<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("No homework entered!");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
	return grade(s.get_midterm(), s.get_final(), s.get_hw());
}

//학생의 과락여ㅕ부를 결정하는 서술 함수
bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

bool pgrade(const Student_info& s) {
	return grade(s) >= 60; //선택 1
	return !fgrade(s); //선택 2
}