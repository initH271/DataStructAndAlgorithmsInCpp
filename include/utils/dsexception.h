/**
 * @file dsexpection.h
 * @brief: 
 * @version: 1.0
 * @author: ${USR}
 * @email: oy.zf@qq.com
 * @date: 22/11/23 9:28
 *
 **/

#ifndef DSEXCEPTION_H
#define DSEXCEPTION_H

#include <exception>
#include <iostream>
#include "exceptionMessage.h"

class DsException: public std::exception{
private:
    const char* m_msg;
public:
    explicit DsException(const char* msg): m_msg(msg){}
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        std::cerr<<"[EXCEPTION]: "<<m_msg<<std::endl;
        return m_msg;
    }
};

#endif //DSEXCEPTION_H
