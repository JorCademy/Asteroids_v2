#pragma once
#include "game.h";
#include "surface.h"
#include "asteroid.h"

namespace Tmpl8
{
	/*
	When implementing the EnemyShip class using inheritance, I noticed 
	that all of the objects within Asteroids contain certain properties, 
	like movement, collision detection and boundary checking. I think it 
	would be a great idea to create an Entity class, which contains all 
	those properties (member functions), which the other classes can inherit.s
	*/
	class EnemyShip : public Asteroid
	{
	public:
		int GetStarting_X();
		int GetStarting_Y();
		void virtual DrawSprite(Surface* screen);
		void virtual Movement();
		bool virtual CheckOutOfFrame();
		bool virtual CollisionDetection(int player_x, int player_y, int playerWidth, int playerHeight);
		void virtual HitByPlayer();

		int m_speed;
		bool startMoving = false;
		bool collisionDetected = false;
		int m_position_x = GetStarting_X();
		int m_position_y = GetStarting_Y();

	private:
		const int m_HEIGHT = 20;
		const int m_WIDTH = 40;
	};
}