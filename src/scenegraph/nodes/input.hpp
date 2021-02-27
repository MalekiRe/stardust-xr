#pragma once

#include "../../nodetypes/node.hpp"
#include "../../nodetypes/input/inputhandler.hpp"
#include "../../nodetypes/input/inputmethod.hpp"
#include "../../util/threadsafelist.hpp"

namespace StardustXRServer {

class InputInterface : public Node {
public:
	InputInterface();
	~InputInterface();
	void handleMessengerDeletion(uint sessionID);

	std::vector<uint8_t> registerInputHandler(uint sessionID, flexbuffers::Reference data, bool returnValue);
	void processInput();

	ThreadSafeList<InputMethod *> inputMethods;
	ThreadSafeList<InputHandler *> inputHandlers;

private:
	std::vector<uint8_t> CreateInputData(flatbuffers::FlatBufferBuilder &fbb, InputMethod *inputMethod, InputHandler *inputHandler);
	flatbuffers::FlatBufferBuilder fbb;
};

} // namespace StardustXRServer
