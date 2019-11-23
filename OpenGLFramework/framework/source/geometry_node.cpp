#include <geometry_node.hpp>

GeometryNode::GeometryNode(){}

GeometryNode::GeometryNode(std::shared_ptr<Node> const& parent, std::string const& name):
	Node(parent, name) {}

GeometryNode::GeometryNode(std::shared_ptr<Node> const& parent, std::string const& name, int depth):
	Node(parent, name, depth) {}

model GeometryNode::getGeometry(){
	return geometry_;
}

void GeometryNode::setGeometry(model const& model){
	geometry_ = model;
}