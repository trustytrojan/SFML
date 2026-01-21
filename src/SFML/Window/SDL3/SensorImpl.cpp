#include <SFML/Window/SDL3/SensorImpl.hpp>

namespace sf::priv
{
void SensorImpl::initialize()
{
}
void SensorImpl::cleanup()
{
}
bool SensorImpl::isAvailable(Sensor::Type)
{
    return false;
}
bool SensorImpl::open(Sensor::Type)
{
    return false;
}
void SensorImpl::close()
{
}
Vector3f SensorImpl::update()
{
    return {};
}
void SensorImpl::setEnabled(bool)
{
}
} // namespace sf::priv
