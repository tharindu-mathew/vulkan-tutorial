#pragma once
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.hpp>

class VulkanApp
{
	VkInstance instance_;
public:
	void init_window();
	void create_instance();
	void init_vulkan();
	void render_loop();
	void cleanup();
	VulkanApp();
	~VulkanApp();
	GLFWwindow* window_;
};

