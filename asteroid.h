#pragma once
#include "game.h";
#include "surface.h"
#include "GameObject.h"

namespace Tmpl8
{
	class Asteroid : public GameObject
	{
	public:
		Asteroid();
		Asteroid(int angle_index, int coordinate_index, float speed_offset, int player_x, int player_y, int player_width, int player_height, int asteroid_size);
		void SettingRandomStartingPosition();
		void virtual DrawSprite(Surface* screen);
		void RotationSprite();
		void CalculatingRotation();
		void virtual Movement();
		void virtual HitByPlayer();
		virtual bool CollisionDetection(int player_x, int player_y, int playerWidth, int playerHeight);
		~Asteroid();

		bool collisionDetected = false;
		int m_speed;
		int m_asteroid_WIDTH;
		int m_asteroid_HEIGHT;
		int m_position_x;
		int m_position_y;
		int m_size;

	private:
		int m_asteroidFrame = 0;
		int m_asteroidSpeed;
		float m_rotation;
		int m_angle_index;
		int m_coordinate_index;
		float m_speed_offset;
		int m_start_x;
		int m_start_y;
	};
}
