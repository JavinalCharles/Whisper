#include <Scenes/MenuScene.hpp>

namespace sp {

using ba::debug;

MenuScene::MenuScene() : ba::Scene() {
}

MenuScene::MenuScene(ba::Window* window, ba::ResourceManager* resourceManager, ba::SceneManager* sceneManager) :
	ba::Scene(window, resourceManager, sceneManager)
{
}

void MenuScene::handleEvents() {
	m_mouse.handleEvents();
	if (m_mouse.isButtonDown(ba::MouseButton::LEFT)) {
		const ba::Vector2i& MOUSE_POS = m_mouse.getCurrMousePos();
		if (m_startBtn->getDrawable()->getGlobalBounds().contains(MOUSE_POS)) {
			debug << "start button is clicked." << std::endl;
		}
		else if (m_creditsBtn->getDrawable()->getGlobalBounds().contains(MOUSE_POS)) {
			debug << "credits button is clicked." << std::endl;
		}
		else if (m_exitBtn->getDrawable()->getGlobalBounds().contains(MOUSE_POS)) {
			debug << "exit button is clicked." << std::endl;
			m_CONTEXT.window->close();
		}
		debug << "Mouse Coordinates: {" << MOUSE_POS.x << ", " << MOUSE_POS.y << "}." << std::endl;
	}

}

void MenuScene::onCreate() {

}

void MenuScene::onActivate() {
	auto title = this->createEntity();
	m_startBtn = this->createEntity();
	m_creditsBtn = this->createEntity();
	m_exitBtn = this->createEntity();

	title->setPosition({54.f, 32.f});
	m_startBtn->setPosition({64.f, 128.f});
	m_creditsBtn->setPosition({64.f, 192.f});
	m_exitBtn->setPosition({64.f, 256.f});

	m_fontID = m_CONTEXT.resources->loadFont("Caveat/static/Caveat-Bold.ttf", 28);

	auto titleText = title->addComponent<ba::Text>();
	titleText->loadFontFromFile("Playwrite_CU/static/PlaywriteCU-Regular.ttf", 32);
	titleText->setColor(ba::Color::White);
	titleText->setWrapLength(640);
	titleText->setText("Whispers in the Dark");



	auto startText = m_startBtn->addComponent<ba::Text>();
	startText->setFontID(m_fontID);
	startText->setColor(ba::Color::White);
	startText->setWrapLength(250);
	startText->setText("START NEW GAME");

	auto creditText = m_creditsBtn->addComponent<ba::Text>();
	creditText->setFontID(m_fontID);
	creditText->setColor(ba::Color::White);
	creditText->setWrapLength(250);
	creditText->setText("CREDITS");

	auto exitText = m_exitBtn->addComponent<ba::Text>();
	exitText->setFontID(m_fontID);
	exitText->setColor(ba::Color::White);
	exitText->setWrapLength(250);
	exitText->setText("EXIT GAME");

	m_entityManager.add(title);
	m_entityManager.add(m_startBtn);
	m_entityManager.add(m_creditsBtn);
	m_entityManager.add(m_exitBtn);
}

void MenuScene::update(float deltaTime) {
	m_entityManager.update(deltaTime);

	m_entityManager.postUpdate(deltaTime);
}

void MenuScene::draw(Window& window) {
	m_entityManager.draw(window);
	const ba::Vector2i& POS = m_mouse.getCurrMousePos();
	std::optional<ba::FloatRect> hoveredBtnRect = m_startBtn->getDrawable()->getGlobalBounds();
	if (!hoveredBtnRect.value().contains(POS)) {
		hoveredBtnRect.emplace(m_creditsBtn->getDrawable()->getGlobalBounds());
		if (!hoveredBtnRect.value().contains(POS)) {
			hoveredBtnRect.emplace(m_exitBtn->getDrawable()->getGlobalBounds());
			if (!hoveredBtnRect.value().contains(POS)) {
				hoveredBtnRect.reset();
			} 
		} 
	}

	if (hoveredBtnRect.has_value()) {
		const ba::IntRect& btnRect = static_cast<ba::IntRect>(hoveredBtnRect.value());
		window.drawLine({{btnRect.l, btnRect.t + btnRect.h}, {btnRect.l + btnRect.w, btnRect.t + btnRect.h}});
	}

}

} // namespace whisper