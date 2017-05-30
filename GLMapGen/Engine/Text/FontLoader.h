#pragma once
#include <string>
#include <ft2build.h>
#include "FontFace.h"
#include <glm/mat4x4.hpp>
#include "../GLHelper/ShaderProgram.h"
#include <memory>

#include FT_FREETYPE_H  
class FontLoader
{
public:
	FontLoader();
	~FontLoader();
	bool Load(std::string filename,std::string name);
	void drawText(std::string name, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
private:
	FT_Library ft;
	std::map<std::string, FontFace> loadedFonts;
	glm::mat4 projection;
	GLuint VAO,VBO;
	std::unique_ptr<ShaderProgram> prog;
};

