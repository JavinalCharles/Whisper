#pragma once

#include <BA/Scenes/Scene.hpp>
#include <BA/Components/Text.hpp>
#include <BA/Systems/EntityManager.hpp>
#include <BA/Inputs/InputManager.hpp>
#include <BA/Inputs/MouseInput.hpp>
#include <BA/Tools/DebugHelper.hpp>

using ba::Entity;
using ba::IDtype;
using ba::Window;
using ba::Scene;

namespace sp {

class MenuScene : public ba::Scene {
public:
	MenuScene();

	MenuScene(ba::Window* window, ba::ResourceManager* resourceManager, ba::SceneManager* sceneManager);

	virtual void handleEvents() override;

	virtual void onCreate() override;
	virtual void onActivate() override;

	virtual void update(float deltaTime) override;
	virtual void draw(ba::Window& window) override;

private:
	void createMenuObjects();
private:
	ba::EntityManager m_entityManager;
	// ba::InputManager m_inputs;
	ba::MouseInput m_mouse{nullptr};

	std::shared_ptr<Entity> m_startBtn;
	std::shared_ptr<Entity> m_creditsBtn;
	std::shared_ptr<Entity> m_exitBtn;

	IDtype m_fontID;
	// IDtype m_titleFontID;
}; // class MenuScene

} // namespace sp