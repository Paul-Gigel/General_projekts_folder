#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vk_layer.h>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <cstring>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"//VK_LAYER_LUNARG_standard_validation
};
//#define NDEBUG
#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif
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
}

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

VkResult CreateDebugUtilsMessangerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessanger)   {
    auto funk =(PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (funk != nullptr)    {
        return funk(instance, pCreateInfo, pAllocator, pDebugMessanger);
    }    else   {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}
void DestroyDebugUtilsMessangerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator)    {
    auto funk =(PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "PFN_vkDestroyDebugUtilsMessengerEXT");
    if (funk != nullptr)    {
        funk(instance, debugMessenger, pAllocator);
    }
}

class HelloTriangleApplication  {
public:
    void run()  {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }
private:
    GLFWwindow* window;
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    void initWindow()   {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    }
    void initVulkan()   {
        createInstance();
        setupDebugMessanger();
    }
    void setupDebugMessanger()  {
        if (!enableValidationLayers) return;
        VkDebugUtilsMessengerCreateInfoEXT createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        createInfo.pfnUserCallback = debugCallback;
        createInfo.pUserData = nullptr;
        if (CreateDebugUtilsMessangerEXT(instance, &createInfo, nullptr, &debugMessenger) != VK_SUCCESS)   {
            throw std::runtime_error("failed to set up debug messenger");
        }
    }
    void mainLoop() {
        while (!glfwWindowShouldClose(window))  {
           glfwPollEvents();
        }
    }
    void cleanup()  {
        if (enableValidationLayers) {
            DestroyDebugUtilsMessangerEXT(instance, debugMessenger, nullptr);
        }
        vkDestroyInstance(instance, nullptr);
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void createInstance()   {
        if (enableValidationLayers && !checkValidationLayerSupport())   {
            std::cout <<enableValidationLayers <<std::endl;
            throw std::runtime_error("validation layer requested, but not available");
        }

        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
/*--------------------------------------------------------------------------------------------------------------------*/
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
        createInfo.enabledLayerCount = 0;
/*????????????????????????????????????????????????????????????????????????????????????????????????????????????????????*/
        auto extension = getRequiredExtensions();
        createInfo.enabledExtensionCount = static_cast<uint32_t>(extension.size());
        createInfo.ppEnabledExtensionNames = extension.data();
/*--------------------------------------------------------------------------------------------------------------------*/
        if(vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
            throw std::runtime_error("failed to create instance");
        }
        if (enableValidationLayers) {
            createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
            createInfo.ppEnabledLayerNames = validationLayers.data();
        } else  {
            createInfo.enabledLayerCount = 0;
            std::cout<<"lol";
        }

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr,&extensionCount, nullptr);
        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr,&extensionCount, extensions.data());
        std::cout <<"available extensions:\n";

        auto array = glfwGetRequiredInstanceExtensions(&extensionCount);
        for (uint32_t count = 0; count<= 1;count++)   {
            std::cout <<*(array+count)<<std::endl;
        }
        for (const auto &extension : extensions)    {
            std::cout <<'\t' << extension.extensionName<<std::endl;
        }
    }
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData)    {
        std::cerr <<"validation layer: "<< pCallbackData->pMessage <<std::endl;
        return VK_FALSE;
    }
};
int main()  {
    HelloTriangleApplication app;
    try {
        app.run();
    } catch (const std::exception &e)   {
        std::cerr <<e.what()<<std::endl;
        return EXIT_FAILURE;
    }
    std::cout <<"es funktioniert\n";
    return EXIT_SUCCESS;
}
