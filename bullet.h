#pragma once
#include "game.h";
#include "surface.h"
#include "GameObject.h"

namespace Tmpl8
{
	class Bullet : public GameObject
	{
	public:
		Bullet();
		Bullet(int object_x, int object_y, float objectRotation);
		~Bullet();
		void virtual DrawSprite(Surface* screen, char* fileName, int bulletPosition_x, int bulletPosition_y);
		void virtual SetEqualToObject(int object_x, int object_y, int objectRotation);
		void virtual ShootBullet(Surface* screen, int speed, int object_x, int object_y, int objectRotation, bool shootObjectBullet);
		void CheckCollision();

		bool m_hitByEnemyShip;
		bool m_hitByAsteroid;

	private:
		bool m_playerBulletOutOfFrame;
		int m_player_x;
		int m_player_y;
		int m_player_rotation;
	};
};