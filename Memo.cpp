#ifdef _WIN32
    #include "header\Memo.h"
#elif __linux__
    #include "header/Memo.h"
#endif



Memo::Memo(const string name)
	: name(name)
{
}

Memo::~Memo() {
}