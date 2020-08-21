#pragma once

#include "Blaze/Layer.h"

#include "Blaze/Events/ApplicationEvent.h"
#include "Blaze/Events/KeyEvent.h"
#include "Blaze/Events/MouseEvent.h"

namespace Blaze {

	class BLAZE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}