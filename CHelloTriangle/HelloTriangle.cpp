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
            if(!layerFound) {
                return false;
            }
        }
    }
    return true;
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
    void initWindow()   {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    }
    void initVulkan()   {
        createInstance();
    }
    void mainLoop() {
        while (!glfwWindowShouldClose(window))  {
           glfwPollEvents();
        }
    }
    void cleanup()  {
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

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
        createInfo.enabledLayerCount = 0;

        if(vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
            throw std::runtime_error("failed to create instance");
        };

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr,&extensionCount, nullptr);
        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr,&extensionCount, extensions.data());
        std::cout <<"available extensions:\n";

        auto array = glfwGetRequiredInstanceExtensions(&extensionCount);
        for (uint32_t count = 0; count<= extensionCount;count++)   {
            std::cout <<*(array+count)<<std::endl;
        }
        for (const auto &extension : extensions)    {
            std::cout <<'\t' << extension.extensionName<<std::endl;
        }
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
