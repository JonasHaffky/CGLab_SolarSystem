#ifndef GEOMETRY_NODE_HPP
#define GEOMETRY_NODE_HPP
#include <node.hpp>
#include <model.hpp>

class GeometryNode : public Node {
	public:
		GeometryNode();
		GeometryNode(std::shared_ptr<Node> const& parent, std::string const& name);
		GeometryNode(std::shared_ptr<Node> const& parent, std::string const& name, int depth);
		model getGeometry();
		void setGeometry(model const& model);

	private:
		model geometry_;

};
#endif