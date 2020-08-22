#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	BZ_PROFILE_FUNCTION();

	m_CheckerboardTexture = Blaze::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	BZ_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Blaze::Timestep ts)
{
	BZ_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		BZ_PROFILE_SCOPE("Renderer Prep");
		Blaze::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Blaze::RenderCommand::Clear();
	}

	{
		BZ_PROFILE_SCOPE("Renderer Draw");
		Blaze::Renderer2D::BeginScene(m_CameraController.GetCamera());
		// Blaze::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Blaze::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Blaze::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		// Blaze::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		Blaze::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	BZ_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Blaze::Event& e)
{
	m_CameraController.OnEvent(e);
}