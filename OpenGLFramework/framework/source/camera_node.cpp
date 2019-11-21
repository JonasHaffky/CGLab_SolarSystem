#include <CameraNode.hpp>

CameraNode::CameraNode(){};


bool CameraNode::getPerspective(){
	return isPerspective_;
}

bool CameraNode::getEnabled(){
	return isEnabled_;
}

void CameraNode::setEnabled(bool enable){
	isEnabled_ = enable;
}

glm::mat4 CameraNode::getProjectionMatrx(){
	return projectionMatrix_;
}

void CameraNode::setProjectionMatrix(glm::mat4 projectionMatrix) {
	projectionMatrix_ = projectionMatrix;
}