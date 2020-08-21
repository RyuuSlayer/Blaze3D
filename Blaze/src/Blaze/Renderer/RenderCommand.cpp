#include "bzpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Blaze {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}