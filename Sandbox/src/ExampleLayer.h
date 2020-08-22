#pragma once

#include "Blaze.h"

class ExampleLayer : public Blaze::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Blaze::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Blaze::Event& e) override;
private:
	Blaze::ShaderLibrary m_ShaderLibrary;
	Blaze::Ref<Blaze::Shader> m_Shader;
	Blaze::Ref<Blaze::VertexArray> m_VertexArray;

	Blaze::Ref<Blaze::Shader> m_FlatColorShader;
	Blaze::Ref<Blaze::VertexArray> m_SquareVA;

	Blaze::Ref<Blaze::Texture2D> m_Texture, m_ChernoLogoTexture;

	Blaze::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
