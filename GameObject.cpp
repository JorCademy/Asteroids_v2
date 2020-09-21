#include "precomp.h" // include this first in every .cpp file
#include "game.h";
#include "surface.h"
#include "GameObject.h"

namespace Tmpl8
{
	void GameObject::DrawSprite(Surface* screen, Sprite objectSprite, int position_x, int position_y)
	{
		objectSprite.Draw(screen, position_x, position_y);
	}

	bool GameObject::CheckOutOfFrame(int position_x, int position_y, bool trigger) 
	{
		if (position_x < -50 || position_x > 850 || position_y < -50 || position_y > 550)
		{
			trigger = true;
		}
		else
		{
			trigger = false;
		}

		return trigger;
	}

	bool GameObject::CollisionDetection(int object_x, int object_y, int objectWidth, int objectHeight, bool trigger, int position_x, int position_y, int WIDTH, int HEIGHT) 
	{
		trigger = false;
		
		int this_x_min = position_x;
		int this_x_max = position_x + WIDTH;
		int this_y_min = position_y;
		int this_y_max = position_y + HEIGHT;
		
		int object_x_min = object_x;
		int object_x_max = object_x + objectWidth;
		int object_y_min = object_y;
		int object_y_max = object_y + objectHeight;

		if (!((this_x_max < object_x_min || this_x_min > object_x_max) || ((this_y_max < object_y_min) || (this_y_min > object_y_max))))
		{
			trigger = true;
		}

		return trigger;
	}

	void GameObject::HitByPlayer(bool collisionDetected) {}

	void GameObject::Reset() {}
}