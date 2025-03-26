#include <apch.h>
#include "LayerStack.h"

namespace Articulas
{
	namespace Layerstack
	{
		
		std::vector<Articulas::Layers::Layer*> layers;

		void PushLayer(Articulas::Layers::Layer* layer)
		{
			layers.emplace_back(layer);
			auto& newLayer = layers.back();
			newLayer->OnAdded();
		}
		void PopLayer(uint16_t index)
		{
			layers.erase(layers.begin() + index);
		}
		void RenderStack()
		{
			for (auto& layer : layers)
			{
				if (layer->enabled)
				{
					layer->OnUpdate();
				}
			}
		}
		void EnableLayer(uint16_t index)
		{
			layers[index]->enabled = true;
		}
		void DisableLayer(uint16_t index)
		{
			layers[index]->enabled = false;
		}
	}
}