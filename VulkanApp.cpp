#include "stdafx.h"
#include "VulkanApp.h"
#include "GLFW/glfw3.h"



void VulkanApp::init_window() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	constexpr int WIDTH = 800;
	constexpr int HEIGHT = 600;
	window_ = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan Window", nullptr, nullptr);

}

void VulkanApp::create_instance() {

	VkApplicationInfo app_info = {};
	app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.pApplicationName = "Vulkan Tutorial";
	app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.apiVersion = VK_VERSION_1_0;
	app_info.pEngineName = "Tharindu Mathew Engine";

	VkInstanceCreateInfo create_info = {};
	create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	create_info.pApplicationInfo = &app_info;

	uint32_t glfw_extension_count = 0;
	const char** glfw_extensions;

	glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

	create_info.enabledExtensionCount = glfw_extension_count;
	create_info.ppEnabledExtensionNames = glfw_extensions;

	VkResult result = vkCreateInstance(&create_info, nullptr, &instance_);

	if (result != VK_SUCCESS) {
		throw std::runtime_error("Unable to create instance!");
	}
}

void VulkanApp::init_vulkan() {
	create_instance();
}

void VulkanApp::render_loop() {
	while (!glfwWindowShouldClose(window_)) {
		glfwPollEvents();
	}
}

void VulkanApp::cleanup() {
	glfwDestroyWindow(window_);
	glfwTerminate();
}

VulkanApp::VulkanApp()
{
}


VulkanApp::~VulkanApp()
{
}
