#ifndef GEOMETRY_NODE_HPP
#define GEOMETRY_NODE_HPP
#include <node.hpp>
#include <model.hpp>

class GeometryNode : Node {
	public:
		GeometryNode();
		model getGeometry();
		void setGeometry(model const& model);

	private:
		model geometry_;

};
#endif