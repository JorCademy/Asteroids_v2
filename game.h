#pragma once

namespace Tmpl8 {

	class Game
	{
	public:
		void SetTarget(Surface* surface) { screen = surface; }
		void Init();
		void Shutdown();
		void Tick(float deltaTime);
		void MouseUp(int button) { /* implement if you want to detect mouse button presses */ }
		void MouseDown(int button) { /* implement if you want to detect mouse button presses */ }
		void MouseMove(int x, int y) { /* implement if you want to detect mouse movement */ }
		void KeyUp(int key);
		void KeyDown(int key);
		void PlayGame(Surface* screen, float deltaTime);
		void DisplayScore(Surface* screen);
		void DrawAsteroids();
		void TimerManagement();
		void CollisionCheck();
		void StartMenu();
		void GameOver(Surface* screen);
		void Reset();

	private:
		SDL_Event event;
		Surface* screen;
		Font* asteroidsFont = new Font("assets/asteroids-font.png", "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890:!");
		bool m_GameOver = false;
		bool m_StartMenu = true;
		bool m_shootPlayerBullet = false;
		bool m_shootEnemyBullet = false;
		int m_timer = 0;
	};

}; // namespace Tmpl8