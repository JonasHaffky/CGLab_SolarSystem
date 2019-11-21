#ifndef CAMERA_NODE_HPP
#define CAMERA_NODE_HPP
#include <glm/glm.hpp>
#include <node.hpp>

class CameraNode : Node {
	public:
		CameraNode();
		~CameraNode();
		//why is the perspective a bool?
		bool getPerspective();
		//What is this for?
		bool getEnabled();
		void setEnabled(bool enable);
		glm::mat4 getProjectionMatrx();
		void setProjectionMatrix(glm::mat4 const& projectionMatrix);

	private:
		bool isPerspective_;
		bool isEnabled_;
		glm::mat4 projectionMatrix_;
};

#endif