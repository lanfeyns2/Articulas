#pragma once

namespace Articulas
{
	namespace Layers
	{
		class Layer
		{
		public:
			
			virtual inline void OnAdded() = 0;
			virtual inline void OnDestroyed() = 0;
			virtual inline void OnUpdate() = 0;
			virtual inline void OnEvent() = 0;

			bool enabled = true;
		};
	}
}