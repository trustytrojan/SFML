#include <SFML/Window/VulkanImpl.hpp>

#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>

namespace sf::priv::VulkanImpl
{
bool isAvailable(bool)
{
    return true;
}
VulkanFunctionPointer getFunction(const char*)
{
    return reinterpret_cast<VulkanFunctionPointer>(SDL_Vulkan_GetVkGetInstanceProcAddr());
}
const std::vector<const char*>& getGraphicsRequiredInstanceExtensions()
{
    static std::vector<const char*> extensions;
    if (extensions.empty())
    {
        uint32_t           count         = 0;
        const char* const* sdlExtensions = SDL_Vulkan_GetInstanceExtensions(&count);
        for (uint32_t i = 0; i < count; ++i)
            extensions.push_back(sdlExtensions[i]);
    }
    return extensions;
}
bool createVulkanSurface(const VkInstance& instance, WindowHandle windowHandle, VkSurfaceKHR& surface, const VkAllocationCallbacks*)
{
    return SDL_Vulkan_CreateSurface(windowHandle, instance, nullptr, &surface);
}
} // namespace sf::priv::VulkanImpl
