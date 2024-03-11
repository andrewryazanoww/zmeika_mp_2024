//
// Created by sempai on 2/25/24.
//

#ifndef SIMPLE_TCP_CONNECTIONHANDLER_H
#define SIMPLE_TCP_CONNECTIONHANDLER_H
#pragma once

#include <thread>

class ConnectionHandler {
private:
    std::thread m_thread;
    int fd = -1;
    bool m_terminate = false;

    std::string readMessage() const;

    void sendMessage(const std::string &msg) const;

    void stop();

public:
    explicit ConnectionHandler(int fd);

    ~ConnectionHandler();

    void terminate();

    void threadFunc();
};

#endif //SIMPLE_TCP_CONNECTIONHANDLER_H
