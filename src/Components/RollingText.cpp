#include <Components/RollingText.hpp>
#include <BA/Entities/Entity.hpp>

namespace sp {

using namespace ba;

RollingText::RollingText(Entity* owner, IDtype drawLayer) :
	ba::Text(owner, drawLayer)
{

}

void RollingText::setTextRenderSpeed(float charPerSecond) {
	m_charPerSecond = charPerSecond;
	m_deltaPerChar = 60.f / m_charPerSecond;
}

void RollingText::insertToBuffer(const std::string& str) {
	m_buffer << str;
}


} // namespace whisper