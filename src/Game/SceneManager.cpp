#include "SceneManager.hpp"


SceneManager& SceneManager::GetInstance()
{
	static SceneManager inst = SceneManager();
	return inst;
}

void SceneManager::InitScene(int d)
{
	currentScene = new Scene(d);
	ResetPlayerController();
}

Scene* SceneManager::GetCurrentScene() { return currentScene; }

void SceneManager::Update() 
{ 
	switch (DM.GetState())
	{
		case GameState::MAIN_MENU:
		{
			
			mainMenu->Update();
			
			if (IM.GetDirction() == DIR_UP)
			{
				DM.SetState(GameState::GAME);
				InitScene(1);
			}
		}break;
		case GameState::GAME:
		{
			playerController->Update();
			GetCurrentScene()->Update();
		}break;
		case GameState::GAME_OVER:
		{
			InitScene(0);
			DM.SetState(GameState::MAIN_MENU);
			ResetPlayerController();
		}break;
	}
}

void SceneManager::Draw() 
{ 
	switch (DM.GetState())
	{
		case GameState::MAIN_MENU:
		{
			R.RenderText("Pacote", SDL_Color{255, 100, 200, 50}, SDL_Rect{ 0,0,100,100 });
			mainMenu->Draw();
		}break;
		case GameState::GAME:
		{
			GetCurrentScene()->Draw();
		}break;
		case GameState::GAME_OVER:
		{

		}break;
	}

}

int SceneManager::GetDifficulty() { return GetCurrentScene()->GetDifficulty(); }

SceneManager::SceneManager() 
{
	mainMenu = new MainMenu();
	InitScene(0);
	ResetPlayerController();
}

void SceneManager::ResetPlayerController()
{
	playerController = new PlayerController(GetCurrentScene());
}
