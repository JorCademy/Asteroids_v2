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

	Bullet::~Bullet() {}

	void Bullet::DrawSprite(Surface* screen, char* fileName, int bulletPosition_x, int bulletPosition_y)
	{
		static Sprite s_bullet(new Surface(fileName), 1);

		s_bullet.Draw(screen, bulletPosition_x, bulletPosition_y);
	}

	void Bullet::SetEqualToObject(int object_x, int object_y, int objectRotation)
	{
		m_position_x = object_x;
		m_position_y = object_y;
		m_rotation = objectRotation;
	}

	void Bullet::ShootBullet(Surface* screen, int speed, int object_x, int object_y, int objectRotation, bool shootObjectBullet)
	{
		if (shootObjectBullet == false)
		{
			m_position_x += sin(m_rotation * 10 * (PI / 180)) * speed;
			m_position_y -= cos(m_rotation * 10 * (PI / 180)) * speed;
		}
		else if (shootObjectBullet == true && this->CheckOutOfFrame(m_position_x, m_position_y, m_playerBulletOutOfFrame) == false)
		{
			m_position_x += sin(m_rotation * 10 * (PI / 180)) * speed;
			m_position_y -= cos(m_rotation * 10 * (PI / 180)) * speed;
		}
		else if (shootObjectBullet == true && this->CheckOutOfFrame(m_position_x, m_position_y, m_playerBulletOutOfFrame) == true)
		{
			this->SetEqualToObject(object_x, object_y, objectRotation);
			m_position_x += 0;
			m_position_y -= 0;
		}
	}

	void Bullet::CheckCollision()
	{
		if (m_hitByEnemyShip || m_hitByAsteroid)
		{
			this->SetEqualToObject(m_player_x, m_player_y, m_player_rotation);
		}

		m_hitByAsteroid = false;
		m_hitByEnemyShip = false;
	}
};