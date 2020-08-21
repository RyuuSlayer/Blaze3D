#pragma once

#include "Blaze/Core/Core.h"

#include "Blaze/Core/Window.h"
#include "Blaze/Core/LayerStack.h"
#include "Blaze/Events/Event.h"
#include "Blaze/Events/ApplicationEvent.h"

#include "Blaze/Core/Timestep.h"

#include "Blaze/ImGui/ImGuiLayer.h"

namespace Blaze {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}