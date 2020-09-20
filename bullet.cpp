#include "precomp.h" // include this first in every .cpp file
#include "player.h"
#include "bullet.h"
#include "game.h"

namespace Tmpl8
{
	Bullet::Bullet()
	{}

	Bullet::Bullet(int object_x, int object_y, float objectRotation):
		m_player_x(object_x),
		m_player_y(object_y),
		m_player_rotation(objectRotation)
	{}

	void Bullet::DrawSprite(Surface* screen, char* fileName, int bulletPosition_x, int bulletPosition_y)
	{
		static Sprite bullet(new Surface(fileName), 1);

		bullet.Draw(screen, bulletPosition_x, bulletPosition_y);
	}

	void Bullet::SetEqualToObject(int object_x, int object_y, int objectRotation)
	{
		m_bulletPosition_x = object_x;
		m_bulletPosition_y = object_y;
		m_bulletRotation = objectRotation;
	}

	void Bullet::ShootBullet(Surface* screen, int speed, int object_x, int object_y, int objectRotation, bool shootObjectBullet)
	{
		if (shootObjectBullet == false)
		{
			m_bulletPosition_x += sin(m_bulletRotation * 10 * (PI / 180)) * speed;
			m_bulletPosition_y -= cos(m_bulletRotation * 10 * (PI / 180)) * speed;
		}
		else if (shootObjectBullet == true && this->CheckOutOfFrame(m_bulletPosition_x, m_bulletPosition_y) == false)
		{
			m_bulletPosition_x += sin(m_bulletRotation * 10 * (PI / 180)) * speed;
			m_bulletPosition_y -= cos(m_bulletRotation * 10 * (PI / 180)) * speed;
		}
		else if (shootObjectBullet == true && this->CheckOutOfFrame(m_bulletPosition_x, m_bulletPosition_y) == true)
		{
			this->SetEqualToObject(object_x, object_y, objectRotation);
			m_bulletPosition_x += 0;
			m_bulletPosition_y -= 0;
		}
	}

	bool Bullet::CheckOutOfFrame(int bulletPosition_x, int bulletPosition_y)
	{
		bool bulletOutOfFrame;

		if (bulletPosition_x < 0 || bulletPosition_x > 850 || bulletPosition_y < 0 || bulletPosition_y > 550)
		{
			bulletOutOfFrame = true;
		}
		else
		{
			bulletOutOfFrame = false;
		}

		return bulletOutOfFrame;
	}

	void Bullet::CheckCollision()
	{
		if (m_hitByEnemyShip || m_hitByAsteroid)
		{
			m_bulletPosition_x = m_player_x;
			m_bulletPosition_y = m_player_y;
			m_bulletRotation = m_player_rotation;
		}

		m_hitByAsteroid = false;
		m_hitByEnemyShip = false;
	}
};