#pragma once
#include <string>

namespace JSONINTERFACES {
    using std::string;
    typedef const int type_t;
    enum TYPE {
        VALUE,
        JSONOBJ
    };
    
    struct strchangeable {
        virtual string str() = 0;
    };

    struct identifiable {
        virtual type_t Type() = 0;
    };
    
    struct IJsonData : identifiable, strchangeable {
    };
}

namespace MANAGERINTERFACES {
    struct IJsonPrintManager {
        virtual void print() = 0;
    };
    struct IJsonMaker {
        virtual void makefile() = 0;
    };
    struct IJsonConsoleLogger {
        virtual void log() = 0;
    };
    struct IJsonParser {
        virtual bool parse() = 0;
    };
}
using namespace JSONINTERFACES;
using namespace MANAGERINTERFACES;