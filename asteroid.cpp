#include "precomp.h" // include this first in every .cpp file
#include "asteroid.h"
#include "game.h";
#include "surface.h"

namespace Tmpl8
{
	static Sprite s_asteroidSprite_small(new Surface("assets/small-asteroid-sheet.png"), 36);
	static Sprite s_asteroidSprite_medium(new Surface("assets/medium-asteroid-sheet.png"), 36);
	static Sprite s_asteroidSprite_big(new Surface("assets/big-asteroid-sheet.png"), 36);

	Asteroid::Asteroid()
	{}

	Asteroid::Asteroid(
		int angle_index, int coordinate_index, 
		float speed_offset, 
		int player_x, int player_y, 
		int player_width, int player_height, 
		int asteroid_size
	):
		m_angle_index(angle_index),
		m_size(asteroid_size),
		m_coordinate_index(coordinate_index),
		m_speed_offset(speed_offset)
	{
		SettingRandomStartingPosition();
		CalculatingRotation();
		Movement();
		CollisionDetection(player_x, player_y, 40, 40);
	};

	void Asteroid::SettingRandomStartingPosition()
	{
		int coordinates[13][2] = {
			{ 0, -200 },
			{ -100, 100 },
			{ -75, 400 },
			{ 0, 600 },
			{ 200, 800 },
			{ 600, 800 },
			{ 800, 600 },
			{ 1000, 500 },
			{ 1000, 100 },
			{ 1000, -100 },
			{ 750, -100 },
			{ 600, -200 },
			{ 200, -200 }
		};
		
		m_start_x = coordinates[m_coordinate_index][0];
		m_start_y = coordinates[m_coordinate_index][1];

		m_position_x = coordinates[m_coordinate_index][0];
		m_position_y = coordinates[m_coordinate_index][1];
	}

	void Asteroid::DrawSprite(Surface* screen)
	{	
		if (m_size == SMALL)
		{
			m_WIDTH = 24;
			m_HEIGHT = 24;

			s_asteroidSprite_small.SetFrame(m_asteroidFrame);
			s_asteroidSprite_small.Draw(screen, m_position_x, m_position_y);
		}
		else if (m_size == MEDIUM)
		{
			m_WIDTH = 39;
			m_HEIGHT = 39;

			s_asteroidSprite_medium.SetFrame(m_asteroidFrame);
			s_asteroidSprite_medium.Draw(screen, m_position_x, m_position_y);
		}
		else if (m_size == BIG)
		{
			m_WIDTH = 60;
			m_HEIGHT = 60;

			s_asteroidSprite_big.SetFrame(m_asteroidFrame);
			s_asteroidSprite_big.Draw(screen, m_position_x, m_position_y);
		}
	}

	void Asteroid::RotationSprite()
	{
		if (--m_asteroidFrame == -1)
		{
			m_asteroidFrame = 35;
		}
	}

	/* For using acos, referencing: https://www.cplusplus.com/reference/cmath/acos/ */
	void Asteroid::CalculatingRotation()
	{
		float optional_angles_upperleft[3] = { 30, 34, 37.5 };
		float optional_angles_upperright[3] = { 52.5, 56.5, 60 };
		float optional_angles_lowerleft[3] = { 7.5, 11, 15 };
		float optional_angles_lowerright[3] = { 75, 79, 82.5 };

		if (m_position_x < 400 && m_position_y < 250)
		{
			m_rotation = optional_angles_upperleft[m_angle_index];
		}
		
		if (m_position_x < 400 && m_position_y > 250)
		{
			m_rotation = optional_angles_lowerleft[m_angle_index];
		}
		
		if (m_position_x > 400 && m_position_y < 250)
		{
			m_rotation = optional_angles_upperright[m_angle_index];
		}
		
		if (m_position_x > 400 && m_position_y > 250) 
		{
			m_rotation = optional_angles_lowerright[m_angle_index];
		}
	}

	void Asteroid::Movement()
	{
		m_position_x += sin(m_rotation * 100 * (PI / 180)) * m_speed * m_speed_offset;
		m_position_y -= cos(m_rotation * 100 * (PI / 180)) * m_speed * m_speed_offset;

		if (m_collisionDetected)
		{
			SettingRandomStartingPosition();
		}

		if ((m_start_x < 400 && m_position_y < 250) && m_position_x > 850) // upperleft
		{
			SettingRandomStartingPosition();
		}
		else if ((m_start_x < 400 && m_position_y > 250) && m_position_x > 850) // lowerleft
		{
			SettingRandomStartingPosition();
		}
		else if ((m_start_x > 400 && m_position_y < 250) && m_position_x < -50) // upperright
		{
			SettingRandomStartingPosition();
		}
		else if ((m_start_x > 400 && m_position_y > 250) && m_position_x < -50) // lowerright
		{
			SettingRandomStartingPosition();
		}
	}

	/*
	Referenced AABB from Stackoverflow: https://stackoverflow.com/questions/6083626/box-collision-code
	*/
	void Asteroid::HitByPlayer()
	{
		if (m_collisionDetected)
		{
			SettingRandomStartingPosition();
			/* Split (somehow) or move to a location outside of the player's view */
		}
	}

	bool Asteroid::CollisionDetection(int player_x, int player_y, int playerWidth, int playerHeight)
	{
		m_collisionDetected = false;

		int asteroid_x_min = m_position_x;
		int asteroid_x_max = m_position_x + m_WIDTH;
		int asteroid_y_min = m_position_y;
		int asteroid_y_max = m_position_y + m_HEIGHT;

		int player_x_min = player_x;
		int player_x_max = player_x + playerWidth;
		int player_y_min = player_y;
		int player_y_max = player_y + playerHeight;

		if (!((asteroid_x_max < player_x_min || asteroid_x_min > player_x_max) || ((asteroid_y_max < player_y_min) || (asteroid_y_min > player_y_max))))
		{
			m_collisionDetected = true;
		}

		return m_collisionDetected;
	}

	void Asteroid::Reset()
	{
		m_position_x = m_start_x;
		m_position_y = m_start_y;
	}

	Asteroid::~Asteroid()
	{}
}

