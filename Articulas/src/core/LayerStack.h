#pragma once

#include <vector>
#include "Layers/Layer.h"

namespace Articulas
{
	namespace Layerstack
	{
		void PushLayer(Articulas::Layers::Layer* layer);
		void PopLayer(uint16_t index);
		void RenderStack();
		void EnableLayer(uint16_t index);
		void DisableLayer(uint16_t index);

		extern std::vector<Articulas::Layers::Layer*> layers;
	}
}
