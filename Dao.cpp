#include <iostream>
#include "Dao.h"
#include "Player.h"
using namespace std;

Dao::Dao(double speed) : Player(speed) {
}

double Dao::getSpeed() const {
	return m_speed;
}

double Dao::getDistPerTrack() const {
	return m_dist_per_track;
}

void Dao::setDistPerTrack(double distPerTrack) {
	m_dist_per_track = distPerTrack;
}

/*----------------------------------------------
	다오의 트랙 이동 경로 계산
------------------------------------------------*/
double Dao::run(Track& track) {
	double totLine = 0.0;

	for (int i = 0; i < track.getTotPoint(); i++) {
		totLine += track.getLine(track.getPoint()[i], track.getPoint()[((i+1) == track.getTotPoint()? 0 : i+1)]);
		cout << "Line : " << track.getLine(track.getPoint()[i], track.getPoint()[((i+1) == track.getTotPoint()? 0 : i+1)]) << endl;
	}

	setDistPerTrack(totLine);

	return getDistPerTrack();
}