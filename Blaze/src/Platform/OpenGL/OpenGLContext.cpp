#include "bzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Blaze {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		BZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		BZ_CORE_INFO("OpenGL Info:");
		BZ_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		BZ_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		BZ_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}