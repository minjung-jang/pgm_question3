#ifndef _POINT_CLASS
#define _POINT_CLASS

#include <string>
using namespace std;

class Point {
private :
	int m_x;
	int m_y;

public :
	explicit Point();
	explicit Point(int x, int y);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	void setXY(int x, int y);
	bool setXY(string xy);
};

#endif