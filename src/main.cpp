#include <BA/Engine.hpp>
#include "Scenes/MenuScene.hpp"

using sp::MenuScene;

int main(int argc, char* argv[]) {
	ba::Engine engine("Whisper", {0, 0, 968, 605}, SDL_WINDOW_SHOWN);

	engine.setFPSLimit(60);
	engine.init();

	std::shared_ptr<MenuScene> menuScene = engine.createScene<MenuScene>();
	engine.addScene(menuScene);

	engine.run();

	engine.cleanUp();

	return 0;
}