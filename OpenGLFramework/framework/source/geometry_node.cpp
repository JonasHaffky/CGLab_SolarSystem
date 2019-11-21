#include <geometry_node.hpp>

GeometryNode::GeometryNode(){}
model GeometryNode::getGeometry(){
	return geometry_;
}

void GeometryNode::setGeometry(model const& model){
	geometry_ = model;
}