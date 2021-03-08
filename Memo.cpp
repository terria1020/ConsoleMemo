#ifdef _WIN32
    #include "header\Memo.h"
#else
    #include "header/Memo.h"    
#endif

Memo::Memo(const string name)
	: name(name)
{
}

Memo::~Memo() {
}