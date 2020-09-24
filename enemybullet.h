#pragma once
#include "game.h";
#include "surface.h"
#include "bullet.h"

namespace Tmpl8
{
	class EnemyBullet : public Bullet
	{
	public:
		EnemyBullet();
		~EnemyBullet();
		void virtual ShootBullet(Surface* screen, int speed, int object_x, int object_y);
		void Rotation(int player_x, int player_y);
		void virtual SetEqualToObject(int object_x, int object_y);
		void CheckCollision(int enemyShip_x, int enemyShip_y);

		bool m_enemyShip_moving = false;
		bool m_hitByPlayer = false;

	private:
		bool m_enemyBulletOutOfFrame;
		int m_angle_iterator = 0;
	};
}