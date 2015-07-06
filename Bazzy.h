#ifndef _BAZZY_CLASS
#define _BAZZY_CLASS

#include "Player.h"

class Bazzy : public Player {
public :
	explicit Bazzy(double speed);
	virtual double getSpeed() const;
	virtual double getDistPerTrack() const;
	virtual void setDistPerTrack(double distPerTrack);
	virtual double run(Track& track);
};

#endif
