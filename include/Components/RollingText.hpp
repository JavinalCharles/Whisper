#pragma once

#include <sstream>

#include <BA/Components/Text.hpp>

using ba::Entity;
using ba::IDtype;

namespace sp {

class RollingText : public ba::Text {
	friend class TextRollerSystem;
public:
	explicit RollingText(Entity* owner, IDtype drawLayer = 0);

	void setTextRenderSpeed(float charPerSecond);
	void insertToBuffer(const std::string& buffer);
	
private:
	std::stringstream m_buffer;
	float m_charPerSecond = 8.f;
	float m_deltaPerChar = 0.13333333f; // 60secs / 8 charspersecond

	float m_currentDelta = 0.f;
}; // class RollingText


} // namespace sp