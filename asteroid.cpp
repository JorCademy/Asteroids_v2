#include "precomp.h" // include this first in every .cpp file
#include "asteroid.h"
#include "game.h";
#include "surface.h"

namespace Tmpl8
{
	static Sprite asteroidSprite_small(new Surface("assets/small-asteroid-sheet.png"), 36);
	static Sprite asteroidSprite_medium(new Surface("assets/medium-asteroid-sheet.png"), 36);
	static Sprite asteroidSprite_big(new Surface("assets/big-asteroid-sheet.png"), 36);

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
		// Draw the player sprite
		if (m_size == 1)
		{
			m_asteroid_WIDTH = 14;
			m_asteroid_HEIGHT = 14;

			asteroidSprite_small.SetFrame(m_asteroidFrame);
			asteroidSprite_small.Draw(screen, m_position_x, m_position_y);
		}
		else if (m_size == 2)
		{
			m_asteroid_WIDTH = 28;
			m_asteroid_HEIGHT = 28;

			asteroidSprite_medium.SetFrame(m_asteroidFrame);
			asteroidSprite_medium.Draw(screen, m_position_x, m_position_y);
		}
		else if (m_size == 3)
		{
			m_asteroid_WIDTH = 40;
			m_asteroid_HEIGHT = 40;

			asteroidSprite_big.SetFrame(m_asteroidFrame);
			asteroidSprite_big.Draw(screen, m_position_x, m_position_y);
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
		else if (m_position_x < 400 && m_position_y > 250)
		{
			m_rotation = optional_angles_lowerleft[m_angle_index];
		}
		else if (m_position_x > 400 && m_position_y < 250)
		{
			m_rotation = optional_angles_upperright[m_angle_index];
		}
		else if (m_position_x > 400 && m_position_y > 250) 
		{
			m_rotation = optional_angles_lowerright[m_angle_index];
		}
	}

	void Asteroid::Movement()
	{
		m_position_x += sin(m_rotation * 100 * (PI / 180)) * m_speed * m_speed_offset;
		m_position_y -= cos(m_rotation * 100 * (PI / 180)) * m_speed * m_speed_offset;

		if (collisionDetected)
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

	// Temporary function for analyzing the asteroid's behaviour
	bool Asteroid::CheckOutOfFrame()
	{
		bool asteroidOutOfFrame;

		if (m_position_x < -50 || m_position_x > 850 || m_position_y < -50 || m_position_y > 550)
		{
			asteroidOutOfFrame = true;
		}
		else
		{
			asteroidOutOfFrame = false;
		}

		return asteroidOutOfFrame;
	}

	/*
	Referenced AABB from Stackoverflow: https://stackoverflow.com/questions/6083626/box-collision-code
	*/
	bool Asteroid::CollisionDetection(int player_x, int player_y, int playerWidth, int playerHeight)
	{
		collisionDetected = false;

		int asteroid_x_min = m_position_x;
		int asteroid_x_max = m_position_x + m_asteroid_WIDTH;
		int asteroid_y_min = m_position_y;
		int asteroid_y_max = m_position_y + m_asteroid_HEIGHT;

		int player_x_min = player_x;
		int player_x_max = player_x + playerWidth;
		int player_y_min = player_y;
		int player_y_max = player_y + playerHeight;

		if (!((asteroid_x_max < player_x_min || asteroid_x_min > player_x_max) || ((asteroid_y_max < player_y_min) || (asteroid_y_min > player_y_max))))
		{
			collisionDetected = true;
		} 

		return collisionDetected;
	}

	void Asteroid::HitByPlayer()
	{
		if (collisionDetected)
		{
			SettingRandomStartingPosition();
			/* Split (somehow) or move to a location outside of the player's view */
		}
	}

	Asteroid::~Asteroid()
	{}
}

