#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "Dao.h"
#include "Bazzy.h"
#include "Track.h"

using namespace std;

void main(int argc, char *argv[]) {
	
	if (argc < 2) {
		cout << "execute : Program.exe file.txt" << endl;
		exit(-1);
	}

	ifstream in;
	in.open(argv[1]);

	string data;

	getline(in, data);
	Dao dao(atof(data.c_str()));

	getline(in, data);
	Bazzy bazzy(atof(data.c_str()));

	cout << "Dao's speed : " << dao.getSpeed() << endl;
	cout << "Bazzy's speed : " << bazzy.getSpeed() << endl;

	getline(in, data);
	Track track(atoi(data.c_str()));

	cout << "The Number of Track's point : " << track.getTotPoint() << endl;

	for (int i = 0; i < track.getTotPoint(); i++) {
		getline(in, data);

		if (track.getPoint()[i].setXY(data)) {
			cout << track.getPoint()[i].getX() << ", " << track.getPoint()[i].getY() << endl;
		}
	}

	cout << "== DAO ==" << endl;
	double dao_dist = dao.run(track);
	cout << "DAO DISTANCE : " << dao_dist << endl;
	cout << "== BAZZY ==" << endl;
	double bazzy_dist = bazzy.run(track);
	cout << "BAZZY DISTANCE : " << bazzy_dist << endl;

	double x_catch;
	
	x_catch = bazzy.getSpeed() * (60 * dao.getSpeed()) / ((bazzy.getSpeed() * dao_dist) - (dao.getSpeed() * bazzy_dist));

	cout << "몇 바퀴째에 BAZZY는 DAO를 따라잡을 수 있을까? " << ceil(x_catch) << "바퀴" << endl;

}
