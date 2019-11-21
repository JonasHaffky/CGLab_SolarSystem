#ifndef CAMERA_NODE_HPP
#define CAMERA_NODE_HPP
#include <glm/glm.hpp>

class CameraNode : public Node {
	public:
		CameraNode(){};
		//why is the perspective a bool?
		bool getPerspective();
		//What is this for?
		bool getEnabled();
		void setEnabled(bool enable);
		glm::mat4 getProjectionMatrx();
		void setProjectionMatrix(glm::mat4 const& projection_matrix);

	private:
		bool isPerspective_;
		bool isEnabled_;
		glm::mat4 projectionMatrix_;
}