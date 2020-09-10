#pragma once
#include "game.h";
#include "surface.h"

namespace Tmpl8 {

	class PlayerShip
	{
	public:
		void PlayerBorderCollision();
		void RotationManagement(Surface* screen);
		void DrawSprite(Surface* screen);
		void ShootBullet(Surface* screen, int bulletSpeed);
		// bool CheckBulletOutOfFrame(int bulletPosition_x, int bulletPosition_y);

		// Player rotation
		float rotation = 0;
		int frameForRotation = 360;
		bool rotatingToRight = false;
		bool rotatingToLeft = false;

		// Random values for rotation
		int plot_x = position_x;
		int plot_y = position_y;

		// Starting Position player
		int position_x = 100;
		int position_y = 100;
		
		// Player movement
		int speed = 0;
		bool movement = false; // Letting the player move in the chosen direction

		// Player bullet
		bool shootPlayerBullet = false;
		int bulletPosition_x;
		int bulletPosition_y;
		int bulletSpeed;
		float bulletRotation;
	};

};
