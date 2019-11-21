#include <node.hpp>
#include <glm/glm.hpp>
#include <iostream>


Node node::getParent(){
	return parent_;
}

void node::setParent(Node* parent){
	parent_ = parent;
}

std::vector<std::shared_ptr<Node>> const& node::getChildrenList(){
	return children_;
}

//What is this for? What should be returned?
Node const& node::getChildren(std::string name){

}

std::string const& node::getName(){
	return name_;
}

std::string const& node::getPath(){

}

int node::getDepth(){

}

glm::mat4 node::getLocalTransform() const{
	return localTransform_;
}

void node::setLocalTransform(glm::mat4 const% transform){
	transform_ = transform;
}

glm::mat4 node::getWorldTransform() const{
	return worldTransform_;
}

void node::setWorldTransform(glm::mat4 const% transform){
	transform_ = transform;
}

//adding more children? addChild?
void node::addChildren(std::shared_ptr<Node> const& node){
	//checking what exactly i do here
	auto new_child(std::make_shared<T>(node));
	return add_child(new_child);
}

//removing all children or one? why give back node?
std::shared_ptr<Node> node::removeChildren(std::string const& node){
	for(auto child(children_.begin()); child != children_.end(); ++child) {
		if (*child == node) {
			children_.erase(child);
			node->parent_ = nullptr;
			//not sure what to do next 
			break;
		}
	}
}

