#ifndef CHELLOTRIANGLE_COPY_HELLOTRIANGLEAPPLICATION_H
#define CHELLOTRIANGLE_COPY_HELLOTRIANGLEAPPLICATION_H
/*--------------------------------------------------------------------------------------------------------------------*/
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vk_layer.h>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <cstring>
/*--------------------------------------------------------------------------------------------------------------------*/
//#define NDEBUG
#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif
const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
};
bool checkValidationLayerSupport();
std::vector<const char*> getRequiredExtensions();
VkResult CreateDebugUtilsMessangerEXT(VkInstance instance,
                                      const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkDebugUtilsMessengerEXT* pDebugMessanger);
void DestroyDebugUtilsMessangerEXT(VkInstance instance,
                                   VkDebugUtilsMessengerEXT debugMessenger,
                                   const VkAllocationCallbacks* pAllocator);
/*--------------------------------------------------------------------------------------------------------------------*/
const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;
/*--------------------------------------------------------------------------------------------------------------------*/
class HelloTriangleApplication  {
private:
    GLFWwindow* window;
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
public:
    void run();
private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
private:
    void createInstance();
private:
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void setupDebugMessanger();
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                        VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                        void* pUserData);
};
#endif //CHELLOTRIANGLE_COPY_HELLOTRIANGLEAPPLICATION_H
