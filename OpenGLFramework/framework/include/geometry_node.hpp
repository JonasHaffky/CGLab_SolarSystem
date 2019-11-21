#ifndef GEOMETRY_NODE_HPP
#define GEOMETRY_NODE_HPP

#include <OpenGLFramework/framework/include/model.hpp>

class GeometryNode : public Node {
	public:
		GeometryNode(){};
		model::model getGeometry();
		void setGeometry(model::model const& model);

	private:
		model::model geometry_;

}