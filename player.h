#pragma once
#include "game.h";
#include "surface.h"
#include "GameObject.h"

namespace Tmpl8
{
	class PlayerShip : public GameObject
	{
	public:
		void DrawLives(Surface* screen);
		void PlayerBorderCollision();
		void RotationManagement(Surface* screen);
		void DrawSprite(Surface* screen);
		void CheckCollision();

		/* Still have to initialize this function (for multiple classes as well) */
		// virtual void Reset();
		
		int m_score = 0;

		float m_rotation = 0;
		int m_frameForRotation = 360;
		bool m_rotatingToRight = false;
		bool m_rotatingToLeft = false;

		int m_position_x = 375;
		int m_position_y = 200;

		int m_speed = 0;
		bool m_movement = false; 

		bool m_hitByAsteroid = false;
		bool m_hitByEnemyShip = false;
		bool m_hitByEnemyBullet = false;

		int m_lives = 3;
		bool m_GameOver = false;
	};

};
