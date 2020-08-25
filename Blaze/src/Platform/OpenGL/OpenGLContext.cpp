#include "bzpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Blaze {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		BZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		BZ_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		BZ_CORE_INFO("OpenGL Info:");
		BZ_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		BZ_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		BZ_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		BZ_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		BZ_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}