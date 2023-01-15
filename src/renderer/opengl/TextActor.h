#pragma once

#include "Actor.h"

#include "scene/actor/TextActor.h"
#include "Font.h"

namespace renderer {
namespace opengl {

class TextActor : public Actor {
public:
	TextActor( scene::actor::TextActor *actor, Font *gl_font );
	~TextActor();
	
	void Update( const string& text, const float x, const float y );
	void Draw( shader_program::OpenGLShaderProgram *shader_program );
	
protected:
	Font *m_gl_font = nullptr;
	
private:
	Font::font_context_t m_ctx;

};

} /* namespace opengl */
} /* namespace renderer */
