#include <geometry_node.hpp>

GeometryNode::GeometryNode(){}

GeometryNode::GeometryNode(std::shared_ptr<Node> const& parent, std::string const& name):
	Node(parent, name) {}


model GeometryNode::getGeometry(){
	return geometry_;
}

void GeometryNode::setGeometry(model const& model){
	geometry_ = model;
}