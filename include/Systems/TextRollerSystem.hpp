#pragma once

#include <BA/Systems/ComponentSystem.hpp>
#include <Components/RollingText.hpp>

namespace sp {
class TextRollerSystem : public ba::ComponentSystem {
public:
	explicit TextRollerSystem(ba::EntityManager* entityManager);

	virtual void update(float deltaTime) override;

	virtual void add(std::shared_ptr<ba::Entity>& entity);

private:
}; // class TextRollerSystem

} // namespace whisper