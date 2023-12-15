#pragma once

#include "pch.h"
#include "Utilities.h"
#include "PictureImplementation.h"
#include "Shader.h"

namespace mk {
	class MEERKAT_API Picture {
	public:
		Picture(const std::string& file);
		Picture(std::string&& file);

		void Bind(); 
		int GetHeight() const;
		int GetWidth() const;

	private:
		std::unique_ptr<PictureImplementation> mImplementation;
	};
}