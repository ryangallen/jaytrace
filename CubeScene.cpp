#include "CubeScene.h"

#include "MaterialNode.h"
#include "TranslationNode.h"
#include "RotationNode.h"
#include "ScalingNode.h"
#include "Cube.h"
#include "Sphere.h"

CubeScene::CubeScene()
{
	setupCamera();
	setupObjects();
	setupLights();
}

void CubeScene::setupCamera()
{
	Vector3d eye(3, 3, 10);
	Vector3d look(0, 0, 0);
	Vector3d up(0, 1, 0);
	camera = Camera(eye, look, up);
}

void CubeScene::setupObjects()
{
	NodePointer rootNode(new TransformNode(getCamera().getTransform()));

	MaterialNodePointer material(new MaterialNode(rootNode));
	Color white(1, 1, 1);
	material->setAmbient(Color(0.5, 0, 0));
	material->setDiffuse(white * .5);
	material->setSpecular(Color(0.5, 0, 1.0));
	material->setShininess(20);

	RayObjectPointer cube(new Cube(material));
	addObject(cube);

	NodePointer translation(new TranslationNode(-2.5, 0, 0, material));
	RayObjectPointer cube2(new Cube(translation));
	addObject(cube2);
}

void CubeScene::setupLights()
{
	Color white(1, 1, 1);

	LightPointer l1(new Light(Vector3d(-3, 12, -15), 0));
	l1->setAmbient(white * .2);
	l1->setDiffuse(white);
	l1->setSpecular(white);
	addLight(l1);
}
