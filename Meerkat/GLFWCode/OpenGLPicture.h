#pragma once


#include"PictureImplementation.h"

namespace mk {
	class OpenGLPicture : public PictureImplementation {
	public:
		virtual void Bind() override;
		virtual void GetHeight() override;
		virtual void GetWidth() override;
	};
}
