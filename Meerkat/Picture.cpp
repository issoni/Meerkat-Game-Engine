#include "pch.h"
#include "Picture.h"
#include"GLFWCode/OpenGLPicture.h"

mk::Picture::Picture() {
#ifdef MEERKAT_MSCPP
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture };
#elif MEERKAT_APPLE
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture };
#elif MEERKAT_LINUX
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture };
#endif
}

void mk::Picture::Bind()
{
	mImplementation->Bind();
}

void mk::Picture::GetHeight()
{

}

void mk::Picture::GetWidth()
{
}

