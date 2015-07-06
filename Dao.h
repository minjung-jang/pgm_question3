#ifndef _DAO_CLASS
#define _DAO_CLASS

#include "Player.h"

class Dao : public Player {
public :
	explicit Dao(double speed);
	virtual double getSpeed() const;
	virtual double getDistPerTrack() const;
	virtual void setDistPerTrack(double distPerTrack);
	virtual double run(Track& track);
};

#endif