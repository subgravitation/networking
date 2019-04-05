#include "socket_guard.h"

#include "assertion.h"

#include <string>

#include <unistd.h>
#include <string.h>

using namespace std;

socket_guard::socket_guard(int _descr)
    : descr(_descr)
{
    utils::assert(descr != -1, "socket created", "failed to create socket");
}

socket_guard::~socket_guard()
{
    auto close_result = close(descr);
    utils::assert(close_result != -1, "socket closed", string("something goes wrong with socket close: ") + strerror(errno));
}