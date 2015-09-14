#pragma once

#include "GlContext.h"

class GlContextANGLE : public IGlContext
{
public:
	GlContextANGLE(uint32_t width, uint32_t height, uint32_t samples);
	~GlContextANGLE();
private:

	uint32_t GetSurfaceWidth() const override;
	uint32_t GetSurfaceHeight() const override;

	void SwapBuffers() override;
	std::vector<uint8_t> GetRaster() override;
	void SetRaster(const std::vector<uint8_t>& raster, uint32_t width, uint32_t height) override;

	void CreateMultisampledFBO(uint32_t width, uint32_t height, uint32_t samples);
	void CreateTextureFBO(uint32_t width, uint32_t height, GLuint& fbo, GLuint& texture);
	void Blit(GLuint fboFrom, GLuint fboTo);

	struct GLData
	{
		GLData() : display(EGL_NO_DISPLAY), context(EGL_NO_CONTEXT), surface(EGL_NO_SURFACE),
			renderBuffer(0), renderBufferDepth(0), fbo(0), renderTexture(0), textureFBO(0) {}
		~GLData();

		EGLDisplay display;
		EGLContext context;
		EGLSurface surface;

		GLuint renderBuffer;
		GLuint renderBufferDepth;
		GLuint fbo;

		GLuint renderTexture;
		GLuint textureFBO;
	};

	GLData gl_;
	std::vector<uint8_t> tempPixelBuffer_;
	uint32_t width_;
	uint32_t height_;

	std::unique_ptr<RasterSetter> rasterSetter_;
};