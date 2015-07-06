#include <iostream>
#include "Player.h"
#include "Bazzy.h"

using namespace std;

Bazzy::Bazzy(double speed) : Player(speed) {
}

double Bazzy::getSpeed() const {
	return m_speed;
}

double Bazzy::getDistPerTrack() const {
	return m_dist_per_track;
}

void Bazzy::setDistPerTrack(double distPerTrack) {
	m_dist_per_track = distPerTrack;
}

/*----------------------------------------------
	배찌의 트랙 이동 경로 계산
------------------------------------------------*/
double Bazzy::run(Track& track) {
	double totLine = 0.0;
	Point p_pre(track.getPoint()[track.getTotPoint()-1].getX(), track.getPoint()[track.getTotPoint()-1].getY());
	Point p_cur(track.getPoint()[0].getX(), track.getPoint()[0].getY());

	if (track.getTotPoint() <= 3) {
		for (int i = 0; i < track.getTotPoint(); i++) {
			totLine += track.getLine(track.getPoint()[i], track.getPoint()[((i+1) == track.getTotPoint()? 0 : i+1)]);
		}
	} else {
		int i_pos = 0, cur_pos = 0, max_pos;
		double angle;		

		do {
			double max_angle = 0.0;
			Point p_move;

			i_pos = cur_pos + 1;
			while (true) {
				if (cur_pos == 0) {
					if (i_pos == track.getTotPoint()-1)
						break;
				}

				angle = track.getAngle(p_pre, p_cur, track.getPoint()[((i_pos) == track.getTotPoint()? 0 : i_pos)]);
				
				if (max_angle < angle) {
					max_angle = angle;	
					max_pos = ((i_pos) == track.getTotPoint()? 0 : i_pos);
					cout << "max_angle : " << max_angle << " i_pos : " << i_pos << " cur_pos : " << cur_pos << " max_pos : " << max_pos << endl;
					p_move.setXY(track.getPoint()[((i_pos) == track.getTotPoint()? 0 : i_pos)].getX(), track.getPoint()[((i_pos) == track.getTotPoint()? 0 : i_pos)].getY());
				}

				i_pos++;

				if (i_pos >= track.getTotPoint())
					break;

				cout << "angle : " << angle << " i_pos : " << i_pos << " cur_pos : " << cur_pos << " max_pos : " << max_pos << endl;
			}

			totLine += track.getLine(p_cur, p_move);

			cur_pos = max_pos;

			cout << "cur_pos [" << cur_pos << "] line's length [" << track.getLine(p_cur, p_move) << "] " << endl;
			
			p_pre = p_cur;
			p_cur = p_move;

			cout << "p_pre (x,y) : " << p_pre.getX() << "," << p_pre.getY() << endl;
			cout << "p_cur (x,y) : " << p_cur.getX() << "," << p_cur.getY() << endl;

		} while (cur_pos != 0);
	}

	setDistPerTrack(totLine);

	return getDistPerTrack();
}