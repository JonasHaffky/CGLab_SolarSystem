#ifndef NODE_HPP
#define NODE_HPP
#include <glm/glm.hpp>
#include <iostream>

class Node {
public:
	Node(std::string const& name = " ");
	virtual ~Node() = default;

	Node getParent();
	void setParent(Node* parent);
	std::vector<std::shared_ptr<Node>> const& getChildrenList();
	//What is this for?? getChild?
	Node const& getChildren(std::string name);

	std::string const& getName();
	std::string const& getPath();
	int getDepth();
	glm::mat4 getLocalTransform() const;
	void setLocalTransform(glm::mat4 const% transform);
	glm::mat4 getWorldTransform() const;
	void setWorldTransform(glm::mat4 const% transform);
	//adding more children? addChild?
	void addChildren(std::shared_ptr<Node> const& node);
	//removing all children or one? why give back node?
	std::shared_ptr<Node> removeChildren(std::string const& node);


protected:
	Node parent_;
	std::vector<std::shared_ptr<Node>> children_;
	std::string name_;
	std::string path_;
	int depth_;
	glm::mat4 localTransform_;
	glm::mat4 worldTransform_;
}