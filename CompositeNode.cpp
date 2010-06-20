#include "CompositeNode.h"

#include <QDebug>

CompositeNode::~CompositeNode()
{
	qDebug()<<"Deleting CompositeNode "<<this;
}

void CompositeNode::addChild(NodePointer child)
{
	children.push_back(child);
}