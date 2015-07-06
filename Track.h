#ifndef _TRACK_CLASS
#define _TRACK_CLASS

#include "Point.h"

class Track {
private :
	Point* m_point;
	int m_totPoint;

public :
	explicit Track(int totPoint);
	~Track();
	int getTotPoint() const;
	Point* getPoint() const;
	void setTotPoint(int totPoint);
	double getLine(Point a, Point b);
	double getHeight(Point p1, Point p2, Point p3);
	double getAngle(Point p1, Point p2, Point p3);
};

#endif