#include "Track.h"
#include "Point.h"
#include <cmath>

Track::Track(int totPoint = 0) {
	m_totPoint = totPoint;

	if (m_totPoint != 0) {
		m_point = new Point[m_totPoint];
	}
}

Track::~Track() {
	if (m_totPoint != 0) {
		delete[] m_point;
	}
}

int Track::getTotPoint() const {
	return m_totPoint;
}

Point* Track::getPoint() const {
	return m_point;
}

void Track::setTotPoint(int totPoint) {
	m_totPoint = totPoint;

	if (m_totPoint != 0) {
		m_point = new Point[m_totPoint];
	}
}

/*-------------------------------------------------
	���� a, b ������ ���� ����
---------------------------------------------------*/
double Track::getLine(Point a, Point b) {
	return sqrt(pow(abs(a.getX()-b.getX()), 2) + pow(abs(a.getY()-b.getY()), 2));
}

/*-------------------------------------------------
	���� p1, p2, p3�� �̷�� �ﰢ���� ����
	- �� ������ ���� ���� �� ���� �� ���� �غ�
---------------------------------------------------*/
double Track::getHeight(Point p1, Point p2, Point p3) {
	double bottom_line;
	double left_line;
	double right_line;
	double height;

	/*--------------------------------------------
		p1 �� ���������� ����.
		���� �� ������ �غ����� ����
	----------------------------------------------*/
	if (getLine(p1, p2) > getLine(p1, p3)) {
		if (getLine(p1, p2) > getLine(p2, p3)) {
			bottom_line = getLine(p1, p2);
			left_line = getLine(p1, p3);
			right_line = getLine(p2, p3);
		} else {
			bottom_line = getLine(p2, p3);
			left_line = getLine(p1, p2);
			right_line = getLine(p1, p3);
		}
	} else {
		if (getLine(p1, p3) > getLine(p2, p3)) {
			bottom_line = getLine(p1, p3);
			left_line = getLine(p2, p3);
			right_line = getLine(p1, p2);
		} else {
			bottom_line = getLine(p2, p3);
			left_line = getLine(p1, p2);
			right_line = getLine(p1, p3);
		}
	}

	double x;

	x = (pow(right_line,2) - pow(left_line,2) + pow(bottom_line,2))/(2*bottom_line);
	height = sqrt(pow(right_line,2)-pow(x,2));

	return height;
}

/*-------------------------------------------------
	���� p1, p2, p3�� �̷�� �ﰢ�� �� p2 �� ����
	- �� ������ ���� ���� �� ���� �� ���� �غ�
---------------------------------------------------*/
double Track::getAngle(Point p1, Point p2, Point p3) {
	double height = getHeight(p1, p2, p3);
	double bottom, left, right;
	double angle;

	if (getLine(p1, p2) > getLine(p1, p3)) {
		if (getLine(p1, p2) > getLine(p2, p3)) {
			bottom = getLine(p1, p2);
			left = getLine(p1, p3);
			right = getLine(p2, p3);
			angle = asin(height/right) * 180 / 3.1415;
		} else {
			bottom = getLine(p2, p3);
			left = getLine(p1, p2);
			right = getLine(p1, p3);
			angle = asin(height/left) * 180 / 3.1415;
		}
	} else {
		if (getLine(p1, p3) > getLine(p2, p3)) {
			bottom = getLine(p1, p3);
			left = getLine(p2, p3);
			right = getLine(p1, p2);
			angle = 180 - ((asin(height/right) + asin(height/left)) * 180 / 3.1415);
		} else {
			bottom = getLine(p2, p3);
			left = getLine(p1, p2);
			right = getLine(p1, p3);
			angle = asin(height/left) * 180 / 3.1415;
		}
	}

	return angle;
}