#pragma once

#include <string>
#include <GL/glew.h>

#include "base/Base.h"

#include "types/Font.h"
#include "types/Color.h"

#include "shader_program/FontOpenGLShaderProgram.h"

using namespace std;

namespace renderer {
namespace opengl {

MAJOR_CLASS( Font, base::Base )

	Font( types::Font *font, shader_program::FontOpenGLShaderProgram *shader_program );
	~Font();

	typedef struct {
		GLfloat x;
		GLfloat y;
		GLfloat tx;
		GLfloat ty;
	} vertex_t;
	typedef struct {
		vertex_t v1;
		vertex_t v2;
		vertex_t v3;
		vertex_t v4;
	} vertex_box_t;

	class font_context_t {
	public:
		GLuint m_vbos[128];
		size_t m_boxes_count[128];
		string m_text = "";
		float m_x = 0;
		float m_y = 0;
		font_context_t() {
			memset( m_vbos, 0, sizeof( m_vbos ) );
			for ( int sym = 32; sym < 128; sym++ ) {
				glGenBuffers( 1, &(m_vbos[sym]));
			}
			memset( m_boxes_count, 0, sizeof( m_boxes_count ) );
		}
		~font_context_t() {
			for ( int sym = 32; sym < 128; sym++ ) {
				glDeleteBuffers( 1, &(m_vbos[sym]));
			}
		}
	};
	
	void Render( const font_context_t* ctx, float z_index, types::Color color );
	void Update( font_context_t* ctx, const string& text, const float x, const float y );
	
protected:
	types::Font *m_font = nullptr;
	shader_program::FontOpenGLShaderProgram *m_shader_program = nullptr;

	// ascii only for now
	
	float m_tx[128];
	float m_ty[128];
	
	GLuint m_texture;
};

} /* namespace opengl */
} /* namespace renderer */
