#ifndef NODE_HPP
#define NODE_HPP
#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <memory>

class Node {
public:
	Node();
	Node(std::shared_ptr<Node> const& parent, std::string const& name, std::string const& path, int depth);
	virtual ~Node() = default;

	std::shared_ptr<Node> getParent();
	void setParent(std::shared_ptr<Node> const& parent);
	std::vector<std::shared_ptr<Node>> const& getChildrenList();
	//get a specific child entered by a name
	std::shared_ptr<Node> const& getChild(std::string name);

	std::string getName() const;
	std::string getPath() const;
	int getDepth() const;
	glm::mat4 getLocalTransform() const;
	void setLocalTransform(glm::mat4 const& transform);
	glm::mat4 getWorldTransform();
	void setWorldTransform(glm::mat4 const& transform);
	//adding one child
	void addChild(std::shared_ptr<Node> const& node);
	//removing one child
	std::shared_ptr<Node> removeChild(std::string const& node);


private:
	std::shared_ptr<Node> parent_;
	std::vector<std::shared_ptr<Node>> children_;
	std::string name_;
	std::string path_;
	int depth_;
	glm::mat4 localTransform_;
	glm::mat4 worldTransform_{glm::mat4(1.0f)};

};

#endif