#ifndef SCENEGRAPH_HPP
#define SCENEGRAPH_HPP

#include <iostream>
#include "node.hpp"
#include <memory>

class SceneGraph {
public:
	static SceneGraph* getInstance();

	std::string const& getName();
	std::shared_ptr<Node> const& getRoot();
	void printGraph();

private:
	SceneGraph();
	~SceneGraph();
	void setName(std::string const& name);
	void setRoot(std::shared_ptr<Node> const& root);
	void graphPrinter(std::shared_ptr<Node> const& node, int depth);

	static SceneGraph* scene_graph_instance_;
	std::shared_ptr<Node> root_;
	std::string name_;
};

#endif