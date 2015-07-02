#ifndef _BAZZY_CLASS
#define _BAZZY_CLASS

#include "Player.h"

class Bazzy : public Player {
public :
	explicit Bazzy(double speed);
	virtual double getSpeed() const;
	virtual double getTimePerTrack() const;
	virtual void setTimePerTrack(double timePerTrack);
	virtual double run(Track& track);
};

#endif
