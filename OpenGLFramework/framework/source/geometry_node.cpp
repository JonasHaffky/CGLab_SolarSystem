#include <GeometryNode.hpp>

GemetryNode::GeometryNode(){};
model::model GemetryNode::getGeometry(){
	return geometry_;
}
void GemetryNode::setGeometry(model::model const& model){
	geometry_ = model;
}