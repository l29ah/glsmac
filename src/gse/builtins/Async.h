#pragma once

#include "gse/Bindings.h"

namespace gse {
namespace builtins {

class Async : public Bindings {
public:
	void AddToContext( context::Context* ctx ) override;
};

}
}
