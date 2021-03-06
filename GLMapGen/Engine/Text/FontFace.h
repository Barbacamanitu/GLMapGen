#pragma once
#include "GL\glew.h"
#include <map>
#include <glm/vec2.hpp> // glm::vec3
struct Character {
	GLuint     TextureID;  // ID handle of the glyph texture
	glm::ivec2 Size;       // Size of glyph
	glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
	GLuint     Advance;    // Offset to advance to next glyph
};



class FontFace {
public:
	std::map<GLchar, Character> Characters;
};