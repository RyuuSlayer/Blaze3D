#pragma once

#include "Blaze.h"

class Sandbox2D : public Blaze::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Blaze::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Blaze::Event& e) override;
private:
	Blaze::OrthographicCameraController m_CameraController;

	// Temp
	Blaze::Ref<Blaze::VertexArray> m_SquareVA;
	Blaze::Ref<Blaze::Shader> m_FlatColorShader;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};