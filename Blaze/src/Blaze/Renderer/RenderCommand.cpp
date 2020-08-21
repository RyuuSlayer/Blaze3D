#include "bzpch.h"
#include "Blaze/Renderer/RenderCommand.h"

namespace Blaze {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}