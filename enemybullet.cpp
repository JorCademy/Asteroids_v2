#include "precomp.h" // include this first in every .cpp file
#include "player.h"
#include "bullet.h"
#include "game.h"
#include "enemybullet.h"

namespace Tmpl8
{
	EnemyBullet::EnemyBullet() {}

	EnemyBullet::~EnemyBullet() {}

	void EnemyBullet::Rotation(int player_x, int player_y)
	{
		/*
		Still have implement the enemy ship shooting towards the player 
		*/
		int optional_angles[5] = { 250, 100, 80, 40, 300 };

		m_rotation = optional_angles[m_angle_iterator];
	}

	void EnemyBullet::SetEqualToObject(int player_x, int player_y)
	{
		m_position_x = player_x;
		m_position_y = player_y;
	}

	void EnemyBullet::ShootBullet(Surface* screen, int speed, int object_x, int object_y)
	{
		if (m_enemyShip_moving)
		{
			this->Rotation(object_x, object_y);

			if (this->CheckOutOfFrame(m_position_x, m_position_y, m_enemyBulletOutOfFrame))
			{
				m_angle_iterator += 1;
			}

			// Shoot bullet in direction of the player
			if (m_enemyShip_moving == false)
			{
				m_position_x += sin(m_rotation * 100 * (PI / 180)) * speed;
				m_position_y -= cos(m_rotation * 100 * (PI / 180)) * speed;
			}
			else if (m_enemyShip_moving == true && this->CheckOutOfFrame(m_position_x, m_position_y, m_enemyBulletOutOfFrame) == false)
			{
				m_position_x += sin(m_rotation * 100 * (PI / 180)) * speed;
				m_position_y -= cos(m_rotation * 100 * (PI / 180)) * speed;
			}
			else if (m_enemyShip_moving == true && this->CheckOutOfFrame(m_position_x, m_position_y, m_enemyBulletOutOfFrame) == true)
			{
				this->SetEqualToObject(object_x, object_y);
				m_position_x += 0;
				m_position_y -= 0;
			}
		}
		else
		{
			this->SetEqualToObject(object_x, object_y);
		}
	}

	void EnemyBullet::CheckCollision(int enemyShip_x, int enemyShip_y)
	{
		if (m_hitByPlayer)
		{
			m_position_x = enemyShip_x;
			m_position_y = enemyShip_y;
		}

		m_hitByPlayer = false;
	}
}