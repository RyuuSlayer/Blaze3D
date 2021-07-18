#pragma once

#include <filesystem>

namespace Blaze {

	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender();
	private:
		std::filesystem::path m_CurrentDirectory;
	};

}

class ContentBrowserPanel
{
};
