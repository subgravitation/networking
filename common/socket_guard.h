#ifndef SOCKET_GUARD
#define SOCKET_GUARD

struct socket_guard
{
    explicit socket_guard(int _descr);
    ~socket_guard();

    int descr;
};

#endif