#pragma once

#include "pch.h"
#include "Utilities.h"
#include "PictureImplementation.h"
#include "Shader.h"

namespace mk {
	class MEERKAT_API Picture {
	public:
		Picture();

		void Bind(); 

		void GetHeight();

		void GetWidth();
	private:
		std::unique_ptr<PictureImplementation> mImplementation;
	};
}