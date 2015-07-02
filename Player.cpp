#include "Player.h"
#include "Track.h"

Player::Player() {
}

Player::Player(double speed) {
	m_speed = speed;
	m_time_per_track = 0.0;
}