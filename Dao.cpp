#include <iostream>
#include "Dao.h"
#include "Player.h"
using namespace std;

Dao::Dao(double speed) : Player(speed) {
}

double Dao::getSpeed() const {
	return m_speed;
}

double Dao::getTimePerTrack() const {
	return m_time_per_track;
}

void Dao::setTimePerTrack(double timePerTrack) {
	m_time_per_track = timePerTrack;
}

double Dao::run(Track& track) {
	double totLine = 0.0;

	for (int i = 0; i < track.getTotPoint(); i++) {
		totLine += track.getLine(track.getPoint()[i], track.getPoint()[((i+1) == track.getTotPoint()? 0 : i+1)]);
		cout << "Line : " << track.getLine(track.getPoint()[i], track.getPoint()[((i+1) == track.getTotPoint()? 0 : i+1)]) << endl;
	}

	setTimePerTrack(totLine);

	return getTimePerTrack();
}