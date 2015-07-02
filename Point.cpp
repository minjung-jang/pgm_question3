#include <iostream>
#include <string>

#include "Point.h"
using namespace std;

Point::Point() {
}

Point::Point(int x = 0, int y = 0) : m_x(x), m_y(y) {
}

int Point::getX() const {
	return m_x;
}

int Point::getY() const {
	return m_y;
}

void Point::setX(int x) {
	m_x = x;
}

void Point::setY(int y) {
	m_y = y;
}

void Point::setXY(int x, int y) {
	m_x = x;
	m_y = y;
}

/*-----------------------------------------
	string : "정수,정수" 의 형태만 수용
  -----------------------------------------*/
bool Point::setXY(string xy) {
	string::size_type pos = xy.find(",");

	if (pos == string::npos) {
		return false;
	}

	string x = xy.substr(0, pos);
	string y = xy.substr(pos+1, string::npos);

	setXY(atoi(x.c_str()), atoi(y.c_str()));

	return true;
}
