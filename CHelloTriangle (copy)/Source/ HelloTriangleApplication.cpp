#include "../Header/HelloTriangleApplication.h"
bool checkValidationLayerSupport()  {
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
    for(const char* layerName : validationLayers)   {
        bool layerFound = false;

        for(const auto& layerProperties : availableLayers)  {
            if(strcmp(layerName, layerProperties.layerName)== 0)    {
                layerFound = true;
                break;
            }
        }
        if(!layerFound) {
            return false;
        }
    }
    return true;
};
std::vector<const char*> getRequiredExtensions()    {
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    if (enableValidationLayers) {
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }
    return extensions;
}
VkResult CreateDebugUtilsMessangerEXT(VkInstance instance,
                                      const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator,
                                      VkDebugUtilsMessengerEXT* pDebugMessanger)   {
    auto funk =(PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (funk != nullptr)    {
        return funk(instance, pCreateInfo, pAllocator, pDebugMessanger);
    }    else   {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
void DestroyDebugUtilsMessangerEXT(VkInstance instance,
                                   VkDebugUtilsMessengerEXT debugMessenger,
                                   const VkAllocationCallbacks* pAllocator)    {
    auto funk =(PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "PFN_vkDestroyDebugUtilsMessengerEXT");
    if (funk != nullptr)    {
        funk(instance, debugMessenger, pAllocator);
    }
}
void run()  {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}