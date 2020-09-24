#include "precomp.h" // include this first in every .cpp file
#include "asteroid.h"
#include "game.h";
#include "surface.h"
#include "enemyship.h"

namespace Tmpl8
{
	static Sprite s_enemyShipSprite(new Surface("assets/enemy-ship.png"), 1);

	EnemyShip::EnemyShip(float speed) :
		m_speed(speed)
	{
		m_HEIGHT = 20;
		m_WIDTH = 40;
	}

	EnemyShip::~EnemyShip() { }

	int EnemyShip::GetStarting_X()
	{
		int startingPosition_x;

		if (!m_leftSide)
		{
			startingPosition_x = RIGHT;
		}
		else
		{
			startingPosition_x = LEFT;
		}

		return startingPosition_x;
	}

	int EnemyShip::GetStarting_Y()
	{
		int startingPosition_y;

		if (!m_upperSide)
		{
			startingPosition_y = LOWER_SIDE;
		}
		else
		{
			startingPosition_y = UPPER_SIDE;
		}

		return startingPosition_y;
	}
	   
	void EnemyShip::DrawSprite(Surface* screen) 
	{
		s_enemyShipSprite.Draw(screen, m_position_x, m_position_y);
	}

	void EnemyShip::Movement()
	{
		if (m_startMoving)
		{
			if (!CheckOutOfFrame(m_position_x, m_position_y, m_outOfFrame))
			{
				if (m_leftSide && m_upperSide && !CheckOutOfFrame(m_position_x, m_position_y, m_outOfFrame))
				{
					m_position_x += m_speed;

					if (m_position_x >= 200 && m_position_x <= 600)
					{
						m_position_y += m_speed;
					}
				}
				else if (!m_leftSide && !m_upperSide && !CheckOutOfFrame(m_position_x, m_position_y, m_outOfFrame))
				{
					m_position_x -= m_speed;

					if (m_position_x <= 600 && m_position_y >= 200)
					{
						m_position_y -= m_speed;
					}
				}
			}
			else if (CheckOutOfFrame(m_position_x, m_position_y, m_outOfFrame))
			{
				if (m_leftSide == true)
				{
					m_leftSide = false;
				}
				else
				{
					m_leftSide = true;
				}

				if (m_upperSide == true)
				{
					m_upperSide = false;
				}
				else
				{
					m_upperSide = true;
				}

				m_position_x = GetStarting_X();
				m_position_y = GetStarting_Y();

				m_startMoving = false;
			}
		}
	}

	bool EnemyShip::CollisionDetection(int object_x, int object_y, int objectWidth, int objectHeight)
	{
		m_collisionDetected = false;

		int enemyship_x_min = m_position_x;
		int enemyship_x_max = m_position_x + m_WIDTH;
		int enemyship_y_min = m_position_y + m_HEIGHT;
		int enemyship_y_max = m_position_y;

		int player_x_min = object_x;
		int player_x_max = object_x + objectWidth;
		int player_y_min = object_y;
		int player_y_max = object_y + objectHeight;

		if (!((enemyship_x_max < player_x_min || enemyship_x_min > player_x_max) || ((enemyship_y_max < player_y_min) || (enemyship_y_min > player_y_max))))
		{
			m_collisionDetected = true;
		}

		return m_collisionDetected;
	}

	void EnemyShip::HitByPlayer()
	{
		if (m_collisionDetected)
		{
			if (m_leftSide == true)
			{
				m_leftSide = false;
			}
			else
			{
				m_leftSide = true;
			}

			if (m_upperSide == true)
			{
				m_upperSide = false;
			}
			else
			{
				m_upperSide = true;
			}

			m_position_x = GetStarting_X();
			m_position_y = GetStarting_Y();

			m_startMoving = false;
		}
	}

	void EnemyShip::Reset()
	{
		m_leftSide = false;
		m_upperSide = false;

		m_position_x = RIGHT;
		m_position_y = LOWER_SIDE;

		m_startMoving = false;
	}
}