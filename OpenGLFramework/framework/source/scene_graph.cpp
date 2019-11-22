#include <scene_graph.hpp>

/**
SceneGraph* SceneGraph::getInstance(std::string name, std::shared_ptr<Node> root) {
	if (!scene_graph_instance_) {
		scene_graph_instance_ = new SceneGraph(name, root);
	}
	return scene_graph_instance_;
}
**/

SceneGraph::SceneGraph(std::string name, std::shared_ptr<Node> root): 
	name_{name},
	root_{root} {}

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
	std::cout<<root->getName()<< " has kids: "<< root->getChildrenList().size() <<std::endl;
	graphPrinter(root, depth);
}

void SceneGraph::graphPrinter(std::shared_ptr<Node> const& node, int depth) {
	//creating emptyspace, depending on depth
	for (int index = 0; index < depth; ++index) {
		std::cout<<" ";
	}

	std::cout<<node->getName()<<std::endl;
	for (auto const& child : node->getChildrenList()) {
		graphPrinter(child, depth+1);
	}

}