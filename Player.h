#ifndef _PLAYER_CLASS
#define _PLAYER_CLASS

#include "Track.h"

class Player {
protected :
	double m_speed;
	double m_time_per_track;
public :
	explicit Player();
	explicit Player(double speed);
	virtual double getSpeed() const = 0;
	virtual double getTimePerTrack() const = 0;
	virtual void setTimePerTrack(double timePerTrack) = 0;
	virtual double run(Track& track) = 0;
};

#endif