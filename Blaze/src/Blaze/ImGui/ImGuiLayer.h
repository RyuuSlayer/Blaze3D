#pragma once

#include "Blaze/Core/Layer.h"

#include "Blaze/Events/ApplicationEvent.h"
#include "Blaze/Events/KeyEvent.h"
#include "Blaze/Events/MouseEvent.h"

namespace Blaze {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}