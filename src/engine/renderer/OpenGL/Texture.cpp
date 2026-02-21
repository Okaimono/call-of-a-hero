#include "Texture.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
	type = texType;

	int widthImg, heightImg, numColCh;
	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 4);

	glGenTextures(1, &ID);
	glActiveTexture(slot);
	glBindTexture(texType, ID);

	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);
	glGenerateMipmap(texType);

	stbi_image_free(bytes);

	glBindTexture(texType, 0);
}

void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit)
{
	GLuint texUni = glGetUniformLocation(shader.getID(), uniform);
	shader.Activate();
	glUniform1i(texUni, unit);
}

void Texture::Bind()
{
	glBindTexture(type, ID);
}

void Texture::Unbind()
{
	glBindTexture(type, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}

void Texture::CompileErrors()
{
	if (ID == 0) {
		std::cout << "ERROR: Texture failed to generate" << std::endl;
		return;
	}

	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		std::cout << "ERROR: OpenGL error code: " << error << std::endl;
	}

	glBindTexture(type, ID);
	GLint width, height;
	glGetTexLevelParameteriv(type, 0, GL_TEXTURE_WIDTH, &width);
	glGetTexLevelParameteriv(type, 0, GL_TEXTURE_HEIGHT, &height);
	
	if (width == 0 || height == 0) {
		std::cout << "ERROR: Texture has invalid dimensions" << std::endl;
	} else {
		std::cout << "Texture loaded successfully: " << width << "x" << height << std::endl;
	}
	
	glBindTexture(type, 0);
}