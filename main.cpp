#include "tests/IntersectionLibraryTest.h"
#include "tests/RayTest.h"
#include "tests/SceneGraphTest.h"
#include "tests/SphereTest.h"

int main()
{
	IntersectionLibraryTest intersectionLibraryTest;
	RayTest rayTest;
	SceneGraphTest sceneGraphTest;
	SphereTest sphereTest;

	int result = 0;

	result += QTest::qExec(&intersectionLibraryTest);
	result += QTest::qExec(&rayTest);
	result += QTest::qExec(&sceneGraphTest);
	result += QTest::qExec(&sphereTest);

	return result != 0;
}
