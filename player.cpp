#include "precomp.h" // include this first in every .cpp file
#include "player.h"
#include <iostream>

namespace Tmpl8
{
	// Player sprite initialization
	static Sprite playerSprite(new Surface("assets/aagun.tga"), 36);
	static int frame = 0;

	/* Make the player Spawn to the opposite border when touching one */
	void PlayerShip::PlayerBorderCollision() {
		if (position_x <= 0) {
			position_x = 780;
		}
		else if (position_x >= 780) {
			position_x = 0;
		}
		else if (position_y <= 0) {
			position_y = 550;
		}
		else if (position_y >= 550) {
			position_y = 0;
		}
	}

	void PlayerShip::RotationManagement(Surface* screen)
	{
		std::cout << frameForRotation << std::endl;

		if (movement)
		{
			// Generating the new player coordinates
			// Note: I figured this mathematical solution out on my own
			rotation = 360 + (frameForRotation * 10);
			position_x = position_x + sin(rotation * (PI / 180)) * speed;
			position_y = position_y - cos(rotation * (PI / 180)) * speed;
		}
		else if (!movement)
		{
			// Stop movement
			position_x += 0;
			position_y += 0;
		}

		if (rotatingToRight) {
			// Rotating to the right
			if (--frame == -1)
			{
				frame = 35;
			}

			++frameForRotation* speed;
		}
		else if (rotatingToLeft)
		{
			// Rotating to the left
			if (++frame == 36)
			{
				frame = 0;
				plot_x += 1;
				plot_y -= 1;
			}

			--frameForRotation * speed;
		}
		else
		{
			// Stop rotation
			frame += 0;
			frameForRotation += 0;
		}
	}

	void PlayerShip::DrawSprite(Surface* screen)
	{
		// Draw the player sprite
		playerSprite.SetFrame(frame);
		playerSprite.Draw(screen, position_x, position_y);
	}

	void PlayerShip::ShootBullet(Surface* screen, int bulletSpeed)
	{
		static Sprite bullet(new Surface("assets/bullet.png"), 1);

		bullet.Draw(screen, bulletPosition_x, bulletPosition_y);

		bulletPosition_x = bulletPosition_x + sin(bulletRotation * (PI / 180)) * speed;
		bulletPosition_y = bulletPosition_y - cos(bulletRotation * (PI / 180)) * speed;
	}
};

