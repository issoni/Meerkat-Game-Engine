#pragma once

#include "Utilities.h"

namespace mk {
	class MEERKAT_API KeyPressed {
	public: 
		KeyPressed(int kCode);

		int GetKeyCode() const; 
	private: 
		int mKeyCode; 
	};

	class MEERKAT_API KeyReleased {
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class MEERKAT_API WindowClosed {

	};
}
