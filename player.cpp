#include "precomp.h" // include this first in every .cpp file
#include "player.h"
#include "bullet.h"

namespace Tmpl8
{
	PlayerShip::PlayerShip(float speed) :
		m_speed(speed)
	{}

	PlayerShip::~PlayerShip() {}

	void PlayerShip::DrawLives(Surface* screen)
	{
		static Sprite s_referencedPlayerSprite(new Surface("assets/player-ship-sheet.png"), 36);

		int sprite_x = 20;
		int sprite_y = 50;

		for (int i = 0; i < m_lives; i++)
		{
			s_referencedPlayerSprite.Draw(screen, sprite_x, sprite_y);
			sprite_x += 30;
		}

		if (m_lives <= 0)
		{
			m_GameOver = true;
		}
	}

	void PlayerShip::CheckCollision()
	{
		if (m_hitByAsteroid || m_hitByEnemyShip)
		{
			m_lives -= 1;

			m_position_x = 375; 
			m_position_y = 200;
		}

		m_hitByAsteroid = false;
		m_hitByEnemyShip = false;
	}

	void PlayerShip::PlayerBorderCollision() 
	{
		if (m_position_x <= 0) 
		{
			m_position_x = 780;
		}
		else if (m_position_x >= 780) 
		{
			m_position_x = 0;
		}
		else if (m_position_y <= 0) 
		{
			m_position_y = 550;
		}
		else if (m_position_y >= 550) 
		{
			m_position_y = 0;
		}
	}

	void PlayerShip::RotationManagement(Surface* screen)
	{
		if (m_movement)
		{
			// Note: I figured this mathematical solution out on my own
			m_rotation = 360 + (m_frameForRotation * 10);
			m_position_x += sin(m_rotation * (PI / 180)) * m_speed;
			m_position_y -= cos(m_rotation * (PI / 180)) * m_speed;
		}
		else if (!m_movement)
		{
			m_position_x += 0;
			m_position_y += 0;
		}

		if (m_rotatingToRight) 
		{
			if (--m_frame == -1)
			{
				m_frame = 35;
			}

			++m_frameForRotation* m_speed;
		}
		else if (m_rotatingToLeft)
		{
			if (++m_frame == 36)
			{
				m_frame = 0;
			}

			--m_frameForRotation* m_speed;
		}
		else
		{
			m_frame += 0;
			m_frameForRotation += 0;
		}
	}

	void PlayerShip::DrawSprite(Surface* screen)
	{
		static Sprite s_playerSprite(new Surface("assets/player-ship-sheet.png"), 36);

		s_playerSprite.SetFrame(m_frame);

		s_playerSprite.Draw(screen, m_position_x, m_position_y);
	}

	void PlayerShip::Reset()
	{
		m_position_x = m_START_X;
		m_position_y = m_START_Y;

		m_lives = 3;
	}
};