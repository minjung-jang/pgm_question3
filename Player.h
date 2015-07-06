#ifndef _PLAYER_CLASS
#define _PLAYER_CLASS

#include "Track.h"

class Player {
protected :
	double m_speed;
	double m_dist_per_track;
public :
	explicit Player();
	explicit Player(double speed);
	virtual double getSpeed() const = 0;
	virtual double getDistPerTrack() const = 0;
	virtual void setDistPerTrack(double distPerTrack) = 0;
	virtual double run(Track& track) = 0;
};

#endif