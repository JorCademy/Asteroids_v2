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
	};
}

