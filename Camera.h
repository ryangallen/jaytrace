#ifndef CAMERA_H
#define CAMERA_H

#include <Eigen/Core>
#include <Eigen/Geometry>

using Eigen::Vector3d;
using Eigen::Affine3d;

class Angle;

class Camera
{
public:
	Camera();
	Camera(Vector3d eye, Vector3d look, Vector3d up);

	void setEye(Vector3d eye);
	void setLook(Vector3d look);
	void setUp(Vector3d up);

	/// Translate the eye and look points by offset delta in camera coordinates
	void slide(Vector3d delta);

	/** Rotate the camera around the look point
	 *
	 * @param angle	angle (in radians) to rotate
	 * @param axis	axis to rotate around (in camera coordinates)
	 */
	void rotateAroundLook(Angle angle, Vector3d axis);

	/// Return a transformation to convert world coordinates into camera coordinates
	Affine3d getTransform() const;

protected:
	/// Compute the camera coordinate axes from the eye, look, and up vectors
	void computeCameraCoordinates();

	/// The location of the camera in world coordinates
	Vector3d eye;

	/// A point along the view direction from the camera in world coordinates
	Vector3d look;

	/// A vector in world coordinates that determines the top of the viewplane
	Vector3d up;

	/// Camera coordinate axes
	Vector3d u;
	Vector3d v;
	Vector3d n;
};

#endif // CAMERA_H
