#pragma once
#include "game.h";
#include "surface.h"
#include "bullet.h"

namespace Tmpl8
{
	class EnemyBullet : public Bullet
	{
	public:
		void virtual ShootBullet(Surface* screen, int speed, int object_x, int object_y, bool shootBullet);
		void Rotation(int player_x, int player_y);
		void virtual SetEqualToObject(int object_x, int object_y);

		int m_position_x;
		int m_position_y;
		bool enemyShip_moving = false;

	private:
		int angle_iterator = 0;
		float a;
		float o;
		float s;
		float angle;
		int m_rotation;
	};
}