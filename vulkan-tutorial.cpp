// vulkan-tutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VulkanApp.h"


int main()
{
	VulkanApp app;
	app.init_window();
	app.init_vulkan();
	app.render_loop();
	app.cleanup();
    return 0;
}

