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

    const char* what() const noexcept override;
};

class ResourceException : public Exception{
private:
    int m_type;

    std::string m_resourceName;
public:
    ResourceException(int type, const std::string &resourceName, std::string extra = "");

    enum types{
        missingResource,
        unknownClass
    };
};

class LevelException : public Exception{
private:
    int m_type;

    std::string m_level;
public:
    enum types{
        missingEntry,
        missingFile
    };

    LevelException(int type, std::string level, std::string extra = "");
};


#endif //GRADIUS_EXCEPTION_H
