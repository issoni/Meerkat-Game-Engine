#pragma once

#if MK_DEBUG==2
	#define MK_ERROR(x) std::cout<<x<<std::endl;
	#define MK_LOG(x) std::cout<<x<<std::endl;
#elif MK_DEBUG==1
	#define MK_ERROR(x) std::cout<<x<<std::endl;
	#define MK_LOG(x) 
#else 
	#define MK_ERROR(x)
	#define MK_LOG(x)
#endif

#ifdef MEERKAT_MSCPP
	#ifdef MEERKAT_LIB
		#define MEERKAT_API __declspec(dllexport)
	#else 
		#define MEERKAT_API __declspec(dllimport)
	#endif
#else 
	#define MEERKAT_API
#endif

#define MEERKAT_APPLICATION_START(ClassName) \
int main()\
{\
	ClassName::Init();\
	ClassName::RunInterface();\
	return(0);\
}
