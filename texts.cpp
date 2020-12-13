#include "header/Misc.h"

#include <vector>
#include <string>

using namespace std;

vector<string> menu = {
	REPSTR(30, '-'),
	"< Console Memo >",
	"this program use to record memo.",
	REPSTR(30, '-'),
	"1 : Add Memo",
	"2 : Add memo-tag",
	"3 : remove Memo",
	"4 : remove memo-tag",
	"5 : show All Memos",
	"6 : set Theme",
	REPSTR(30, '-')
};

vector<string> themeMenu = {
    "< Theme Settings >",
    "1 : Base Theme",
    "2 : Theme 2",
    "3 : Theme 3",
    "4 : Custom Theme",
    REPSTR(30, '-')
};