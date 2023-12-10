#pragma once

#include "Picture.h"

namespace mk {
	class PictureImplementation {
	public:
		virtual void Bind() = 0; 
		virtual void GetHeight() = 0;
		virtual void GetWidth() = 0;

		virtual ~PictureImplementation() {};
	};
}
