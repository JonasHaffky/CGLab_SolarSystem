#include <scene_graph.hpp>


SceneGraph* SceneGraph::getInstance() {
	if (!scene_graph_instance_) {
		scene_graph_instance_ = new SceneGraph;
	}
	return scene_graph_instance_;
}

SceneGraph::SceneGraph(): 
	name_{"default name"},
	root_{} {}

SceneGraph::~SceneGraph(){}

std::string const& SceneGraph::getName() {
	return name_;
}

std::shared_ptr<Node> const& SceneGraph::getRoot() {
	return root_;
}

void SceneGraph::setName(std::string const& name){
	name_ = name;
}

void SceneGraph::setRoot(std::shared_ptr<Node> const& root){
	root_ = root;
}

void SceneGraph::printGraph(){

	std::shared_ptr<Node> root = getRoot();
	int depth = root->getDepth();

	graphPrinter(root, depth);

}

void graphPrinter(std::shared_ptr<Node> const& node, int depth) {
	//creating emptyspace, depending on depth
	for (int index = 0; index < depth; ++index) {
		std::cout<<" ";

	}
	std::cout<<node->getName()<<std::endl;
	auto childrenlist = node->getChildrenList();
	for (auto const& child : childrenlist) {
		graphPrinter(child, child->getDepth());
	}

}