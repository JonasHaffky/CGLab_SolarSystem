#include <node.hpp>
#include <glm/glm.hpp>
#include <iostream>


Node::Node() : 
	parent_{},
	children_{},
	name_{},
	depth_{},
	path_{},
	localTransform_{},
	worldTransform_{},
	position_ {} {}

Node::Node(std::shared_ptr<Node> parent, std::string const& name) : 
	parent_{parent},
	children_{},
	name_{name},
	depth_{0},
	path_{},
	localTransform_{1.0f},
	worldTransform_{1.0f},
	position_{} {
		if (parent != nullptr) {
			parent->addChild(std::make_shared<Node>(*this));
			depth_ += 1;
			path_ = path_+"/"+name;
			}
		else {
			path_ = "/";
			depth_ = 0;
		}

	}

Node::Node(std::shared_ptr<Node> parent, std::string const& name, int depth) : 
	parent_{parent},
	children_{},
	name_{name},
	depth_{depth},
	path_{},
	localTransform_{1.0f},
	worldTransform_{1.0f},
	position_{} {
		if (parent != nullptr) {
			parent->addChild(std::make_shared<Node>(*this));
			path_ = path_+"/"+name;
			}
		else {
			path_ = "/";

		}

	}


std::shared_ptr<Node> Node::getParent(){
	return parent_;
}

void Node::setParent(std::shared_ptr<Node> const& parent){
	parent_ = parent;
}

std::vector<std::shared_ptr<Node>> const& Node::getChildrenList(){
	return children_;
}

//What is this for? What should be returned?
std::shared_ptr<Node> const& Node::getChild(std::string name){
	for (auto const& child : getChildrenList()) {
		if (child->getName() == name){
			return child;
		}
	}
	return nullptr;
}

std::string Node::getName() const{
	return name_;
}

std::string Node::getPath() const{
	return path_;
}

int Node::getDepth() const{
	return depth_;
}

glm::mat4 Node::getLocalTransform() const{
	return localTransform_;
}

void Node::setLocalTransform(glm::mat4 const& transform){
	localTransform_ = transform;
}

glm::mat4 Node::getWorldTransform(){
	return worldTransform_;
}

void Node::setWorldTransform(glm::mat4 const& transform){
	worldTransform_ = transform;
}

//adding more children? addChild?
void Node::addChild(std::shared_ptr<Node> const& node){
	children_.push_back(node);
}

//removing all children or one? why give back node?
std::shared_ptr<Node> Node::removeChild(std::string const& name){
	int i = 0;
	for (auto const& child : getChildrenList()) {
		if (child->getName() == name){
			return child;
			children_.erase(children_.begin()+i);
		}
		++i;
	}
	return nullptr;
}

//removing all children or one? why give back node?
bool Node::hasChild(std::string const& name){
	for (auto const& child : getChildrenList()) {
		if (child->getName() == name){
			return true;
		}
	}
	return false;
}

void Node::setPosition(glm::fvec3 const& position){
	position_ = position;
}


glm::fvec3 Node::getPosition() const{
	return position_;

}
