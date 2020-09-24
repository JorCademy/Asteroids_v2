#pragma once
#include "game.h";
#include "surface.h"
#include "asteroid.h"
#include "GameObject.h"

namespace Tmpl8
{
	class EnemyShip : public GameObject
	{
	public:
		EnemyShip(float speed);
		~EnemyShip();
		int GetStarting_X();
		int GetStarting_Y();
		void virtual DrawSprite(Surface* screen);
		void virtual Movement();
		bool virtual CollisionDetection(int player_x, int player_y, int playerWidth, int playerHeight);
		void virtual HitByPlayer();
		virtual void Reset();

		int m_speed;
		bool m_startMoving = false;
		bool m_collisionDetected = false;
		int m_position_x = GetStarting_X();
		int m_position_y = GetStarting_Y();

	private:
		enum m_optional_positions_x { LEFT = -40, RIGHT = 840 };
		enum m_optional_positions_y { UPPER_SIDE = 150, LOWER_SIDE = 350 };
		bool m_move = false;
		bool m_leftSide = false;
		bool m_upperSide = false;
		bool m_outOfFrame;
	};
}