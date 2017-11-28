//
// Created by uauser on 11/28/17.
//

#ifndef GRADIUS_EXCEPTION_H
#define GRADIUS_EXCEPTION_H


#include <exception>
#include <string>

class Exception : public std::exception{
protected:
    std::string m_errorMsg;
public:
    Exception();

    const char* what() const noexcept;
};

class ResourceException : public Exception{
private:
    std::string m_resourceName;
public:
    ResourceException(const std::string &resourceName);
};


#endif //GRADIUS_EXCEPTION_H
