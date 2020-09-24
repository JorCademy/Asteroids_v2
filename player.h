#pragma once
#include "game.h";
#include "surface.h"
#include "GameObject.h"

namespace Tmpl8
{
	class PlayerShip : public GameObject
	{
	public:
		PlayerShip(float deltaTime);
		~PlayerShip();
		void DrawLives(Surface* screen);
		void PlayerBorderCollision();
		void RotationManagement(Surface* screen);
		void DrawSprite(Surface* screen);
		void CheckCollision();
		virtual void Reset();
		
		int m_score = 0;
		const int m_START_X = 375;
		const int m_START_Y = 200;
		bool m_movement = false;
		bool m_hitByAsteroid = false;
		bool m_hitByEnemyShip = false;
		bool m_hitByEnemyBullet = false;
		int m_lives = 3;
		bool m_GameOver = false;
		bool m_rotatingToRight = false;
		bool m_rotatingToLeft = false;
		int m_frameForRotation = 360;
		float m_speed;

	private:
		int m_frame = 0;
	};

};
