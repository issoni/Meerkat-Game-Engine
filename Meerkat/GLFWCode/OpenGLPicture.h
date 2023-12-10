#pragma once


#include"PictureImplementation.h"

namespace mk {
	class OpenGLPicture : public PictureImplementation {
	public:
		OpenGLPicture(const std::string& file); 
		OpenGLPicture(std::string&& file);
		~OpenGLPicture();
		virtual void Bind() override;
		virtual int GetHeight() const override;
		virtual int GetWidth() const override;

	private:
		unsigned int mTex; 
		int mWidth{ 0 };
		int mHeight{ 0 };
		// int nrChannels{ 0 };
	};
}
