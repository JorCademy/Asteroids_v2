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
		void Start(Surface* screen, float deltaTime);
		void DisplayScore(Surface* screen);
		void DrawAsteroids();
		void TimerManagement();
		void CollisionCheck();
		void GameOver(Surface* screen, float deltaTime);
		void Reset(Surface* screen);

	private:
		SDL_Event event;
		Surface* screen;
		bool m_GameOver = false;
	};

}; // namespace Tmpl8