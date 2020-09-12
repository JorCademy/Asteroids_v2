#pragma once
#include "game.h";
#include "surface.h"

namespace Tmpl8
{
	class Bullet
	{
	public:
		void DrawSprite(Surface* screen);
		void SetEqualToObject(int object_x, int object_y, int objectRotation);
		void ShootBullet(Surface* screen, int speed);
		bool CheckOutOfFrame();

		int m_bulletPosition_x;
		int m_bulletPosition_y;
		float m_bulletRotation;
	};
};