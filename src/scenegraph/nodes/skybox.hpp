#pragma once

#include "../../nodetypes/node.hpp"

namespace StardustXRServer {

class SkyboxInterface : public Node {
public:
	SkyboxInterface();
	virtual ~SkyboxInterface() {}

	void update();

private:
	bool skytexEnabled = true;
};

} // namespace StardustXRServer
