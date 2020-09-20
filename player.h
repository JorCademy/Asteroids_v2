#pragma once
#include "game.h";
#include "surface.h"

namespace Tmpl8
{
	class PlayerShip
	{
	public:
		void DrawLives(Surface* screen);
		void PlayerBorderCollision();
		void RotationManagement(Surface* screen);
		void DrawSprite(Surface* screen);
		void CheckCollision();
		// bool CheckBulletOutOfFrame(int bulletPosition_x, int bulletPosition_y);

		// Player rotation
		float m_rotation = 0;
		int m_frameForRotation = 360;
		bool m_rotatingToRight = false;
		bool m_rotatingToLeft = false;

		// Starting Position player
		int m_position_x = 375;
		int m_position_y = 200;

		// Player movement
		int m_speed = 0;
		bool m_movement = false; // Letting the player move in the chosen direction

		// Hit by objects trigger variable
		bool m_hitByAsteroid = false;
		bool m_hitByEnemyShip = false;

		int m_lives = 3;
		bool m_GameOver = false;
	};

};
