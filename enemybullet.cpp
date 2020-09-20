#include "precomp.h" // include this first in every .cpp file
#include "player.h"
#include "bullet.h"
#include "game.h"
#include "enemybullet.h"

namespace Tmpl8
{
	void EnemyBullet::Rotation(int player_x, int player_y)
	{
		/*
		Still have implement the enemy ship shooting towards the player 
		*/
		int optional_angles[5] = { 250, 100, 80, 40, 300 };

		m_rotation = optional_angles[angle_iterator];
	}

	void EnemyBullet::SetEqualToObject(int player_x, int player_y)
	{
		m_position_x = player_x;
		m_position_y = player_y;
	}

	void EnemyBullet::ShootBullet(Surface* screen, int speed, int object_x, int object_y, bool enemyShip_moving)
	{
		if (enemyShip_moving)
		{
			this->Rotation(object_x, object_y);

			if (this->CheckOutOfFrame(m_position_x, m_position_y))
			{
				angle_iterator += 1;
			}

			// Shoot bullet in direction of the player
			if (enemyShip_moving == false)
			{
				m_position_x += sin(m_rotation * 100 * (PI / 180)) * speed;
				m_position_y -= cos(m_rotation * 100 * (PI / 180)) * speed;
			}
			else if (enemyShip_moving == true && this->CheckOutOfFrame(m_position_x, m_position_y) == false)
			{
				m_position_x += sin(m_rotation * 100 * (PI / 180)) * speed;
				m_position_y -= cos(m_rotation * 100 * (PI / 180)) * speed;
			}
			else if (enemyShip_moving == true && this->CheckOutOfFrame(m_position_x, m_position_y) == true)
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
}