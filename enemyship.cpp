#include "precomp.h" // include this first in every .cpp file
#include "asteroid.h"
#include "game.h";
#include "surface.h"
#include "enemyship.h"

namespace Tmpl8
{
	static Sprite enemyShipSprite(new Surface("assets/enemy-ship.png"), 1);

	bool move = false;
	bool leftSide = false;
	bool upperSide = false;
 
	enum optional_positions_x { LEFT = -40, RIGHT = 840 };
	enum optional_positions_y { UPPER_SIDE = 150, LOWER_SIDE = 350 };

	int EnemyShip::GetStarting_X()
	{
		int startingPosition_x;

		if (!leftSide)
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

		if (!upperSide)
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
		enemyShipSprite.Draw(screen, m_position_x, m_position_y);
	}

	/*
	Maybe it's  smart to divide some parts of this function in multiple 
	member functions, to make the code cleaner, easier to read.
	Also, it might be smart to make the positioning of the enemy, using the 
	variables leftSide and upperSide, more random. IE by using the score of the player
	in combination with modulus ( if ((score_player % 10) == 0) )
	*/

	void EnemyShip::Movement()
	{
		if (startMoving)
		{
			if (!CheckOutOfFrame())
			{
				if (leftSide && upperSide && !CheckOutOfFrame())
				{
					m_position_x += m_speed;

					if (m_position_x >= 200 && m_position_x <= 600)
					{
						m_position_y += m_speed;
					}
				}
				else if (!leftSide && !upperSide && !CheckOutOfFrame())
				{
					m_position_x -= m_speed;

					if (m_position_x <= 600 && m_position_y >= 200)
					{
						m_position_y -= m_speed;
					}
				}
			}
			else if (CheckOutOfFrame())
			{
				if (leftSide == true)
				{
					leftSide = false;
				}
				else
				{
					leftSide = true;
				}

				if (upperSide == true)
				{
					upperSide = false;
				}
				else
				{
					upperSide = true;
				}

				m_position_x = GetStarting_X();
				m_position_y = GetStarting_Y();

				startMoving = false;
			}
		}
	}

	bool EnemyShip::CheckOutOfFrame()
	{
		bool shipOutOfFrame;

		if (m_position_x < -50 || m_position_x > 850 || m_position_y < -50 || m_position_y > 550)
		{
			shipOutOfFrame = true;
		}
		else
		{
			shipOutOfFrame = false;
		}

		return shipOutOfFrame;
	}

	bool EnemyShip::CollisionDetection(int object_x, int object_y, int objectWidth, int objectHeight)
	{
		collisionDetected = false;

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
			collisionDetected = true;
		}

		return collisionDetected;
	}

	void EnemyShip::HitByPlayer()
	{
		if (collisionDetected)
		{
			if (leftSide == true)
			{
				leftSide = false;
			}
			else
			{
				leftSide = true;
			}

			if (upperSide == true)
			{
				upperSide = false;
			}
			else
			{
				upperSide = true;
			}

			m_position_x = GetStarting_X();
			m_position_y = GetStarting_Y();

			startMoving = false;
		}
	}
}