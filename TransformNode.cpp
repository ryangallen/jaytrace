#include "TransformNode.h"

TransformNode::TransformNode(NodePointer parent): CompositeNode(parent)
{
	transform.setIdentity();
	if (parent) {
		transform = parent->getMatrixState();
	}
}

Transform3d TransformNode::getMatrixState()
{
	return transform;
}