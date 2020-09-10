#pragma once
#include "game.h";
#include "surface.h"

namespace Tmpl8
{
	class Bullet
	{
	public:
		void DrawSprite(Surface* screen);
		void ShootBullet(Surface* screen, int speed, float objectRotation);
		bool CheckOutOfFrame();

		int m_bulletPosition_x;
		int m_bulletPosition_y;
		float m_bulletRotation;
		bool m_shootPlayerBullet = false;
	};
};