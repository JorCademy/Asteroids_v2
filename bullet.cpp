#include "precomp.h" // include this first in every .cpp file
#include "player.h"
#include "bullet.h"
#include "game.h"
#include <iostream>

namespace Tmpl8
{
	void Bullet::DrawSprite(Surface* screen)
	{
		static Sprite bullet(new Surface("assets/bullet.png"), 1);

		bullet.Draw(screen, m_bulletPosition_x, m_bulletPosition_y);
	}

	void Bullet::ShootBullet(Surface* screen, int speed, float objectRotation)
	{
		static Sprite bullet(new Surface("assets/bullet.png"), 1);

		bullet.Draw(screen, m_bulletPosition_x, m_bulletPosition_y);

		m_bulletPosition_x = m_bulletPosition_x + sin(m_bulletRotation * (PI / 180)) * speed;
		m_bulletPosition_y = m_bulletPosition_y - cos(m_bulletRotation * (PI / 180)) * speed;
	}

	bool Bullet::CheckOutOfFrame()
	{
		bool bulletOutOfFrame;

		if (m_bulletPosition_x < 0 || m_bulletPosition_x > 850 || m_bulletPosition_y < 0 || m_bulletPosition_y > 550) 
		{
			bulletOutOfFrame = true;
		}
		else
		{
			bulletOutOfFrame = false;
		}

		return bulletOutOfFrame;
	}
};