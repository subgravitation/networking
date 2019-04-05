#include <string>

namespace utils
{
	void assert(bool assertion, const std::string& good, const std::string& bad);
	void incoming_message(const std::string& message);
	void outgoing_message(const std::string& message);
}
