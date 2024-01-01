#pragma once

#include "base/Base.h"

#include "Parser.h"

namespace gse {
namespace parser {

CLASS( ParserFactory, base::Base )

	Parser* GetParser( const std::string& filename, const std::string& source );

};

}
}
