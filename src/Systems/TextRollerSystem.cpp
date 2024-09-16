#include <Systems/TextRollerSystem.hpp>
#include <BA/Systems/EntityManager.hpp>
#include <BA/Entities/Entity.hpp>

namespace sp {

using namespace ba;

TextRollerSystem::TextRollerSystem(EntityManager* entities) :
	ComponentSystem(entities)
{

}

void TextRollerSystem::update(float deltaTime) {
	for (const IDtype& ID: this->getIDs()) {
		const std::shared_ptr<Entity> entity = this->getEntity(ID);
		const std::shared_ptr<RollingText> rt = entity->getComponent<RollingText>();

		if (rt->m_buffer.peek() == EOF) {
			continue;
		}

		rt->m_currentDelta += deltaTime;
		if (rt->m_currentDelta >= rt->m_deltaPerChar) {
			char c;
			rt->m_buffer >> c;
			rt->appendText(c);

			rt->m_currentDelta -= rt->m_deltaPerChar; 
		}
	}
}


void TextRollerSystem::add(std::shared_ptr<Entity>& entity) {
	auto rollingText = entity->getComponent<RollingText>();

	if (rollingText != nullptr) {
		addID(entity->ID);
	}
}

} // namespace whisper