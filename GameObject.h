#pragma once
#include "surface.h"

namespace Tmpl8
{
	class GameObject
	{
	public:
		virtual void DrawSprite(Surface* screen, Sprite spriteToDraw, int position_x, int position_y);
		bool CheckOutOfFrame(int position_x, int position_y, bool trigger);
		virtual bool CollisionDetection(int object_x, int object_y, int objectWidth, int objectHeight, bool trigger, int position_x, int position_y, int WIDTH, int HEIGHT);
		virtual void HitByPlayer(bool collisionDetected);
		virtual void Reset();
		
		int m_position_x;
		int m_position_y;
		float m_rotation;
		unsigned int m_speed;

	protected:
		unsigned int m_WIDTH;
		unsigned int m_HEIGHT;
	};
}

