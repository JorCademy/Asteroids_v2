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
		virtual void Reset();
		~Asteroid();

		bool m_collisionDetected = false;
		int m_size;
		enum m_sizes { SMALL = 1, MEDIUM = 2, BIG = 3 };

	private:
		int m_asteroidFrame = 0;
		int m_asteroidSpeed;
		int m_angle_index;
		int m_coordinate_index;
		float m_speed_offset;
		int m_start_x;
		int m_start_y;
	};
}
