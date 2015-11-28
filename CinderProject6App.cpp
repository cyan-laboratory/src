

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Shader.h"
using namespace ci;
using namespace ci::app;

class BasicApp : public App {
public:
	void draw() override;
};

void BasicApp::draw()
{
	gl::clear();
	gl::enableDepthRead();
	gl::enableDepthWrite();
	CameraPersp cam;
	cam.lookAt(vec3(3, 3, 3), vec3(0));
	gl::setMatrices(cam);

	auto lambert = gl::ShaderDef().lambert();
	auto shader = gl::getStockShader(lambert);
	shader->bind();
	// draw sphere at the origin, radius 1
	gl::drawSphere(vec3(), 1.0f,22);
}

CINDER_APP(BasicApp, RendererGl)

