#include "pch.h"
#include "Picture.h"
#include"GLFWCode/OpenGLPicture.h"

mk::Picture::Picture(const std::string& file) {
#ifdef MEERKAT_MSCPP
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(file)};
#elif MEERKAT_APPLE
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(file)};
#elif MEERKAT_LINUX
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(file)};
#endif
}


mk::Picture::Picture(std::string&& file)
{
#ifdef MEERKAT_MSCPP
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(file)) };
#elif MEERKAT_APPLE
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(file)) };
#elif MEERKAT_LINUX
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(std::move(file)) };
#endif
}


void mk::Picture::Bind()
{
	mImplementation->Bind();
}

int mk::Picture::GetHeight() const
{
	return mImplementation->GetHeight(); 
}

int mk::Picture::GetWidth() const
{
	return mImplementation->GetWidth();
}

