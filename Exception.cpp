//
// Created by uauser on 11/28/17.
//

#include "Exception.h"


ResourceException::ResourceException(int type, const std::string &resourceName, std::string extra)
        : m_resourceName(resourceName) {
    switch(type){
        case types::missingResource: {
            m_errorMsg = "Resource \"" + m_resourceName + "\" Does not exists";
            break;
        }
        case types::unknownClass: {
            m_errorMsg = "Unknown type in Resource \"" + m_resourceName + "\": \"" + extra + "\"";
            break;
        }
        default: {
            m_errorMsg = "Something went wrong";
        }
    }
}

Exception::Exception() {}

const char *Exception::what() const noexcept {
    return m_errorMsg.c_str();
}

LevelException::LevelException(int type, std::string level, std::string extra) {

    switch(type){
        case types::missingEntry:{
            m_errorMsg = "Missing entry \"" + extra + "\" in level \"" + level + "\"";
            break;
        }
        case types::missingFile:{
            m_errorMsg = "Level file not found: \"" + level +"\"";
            break;
        }

        default:{
            m_errorMsg = "Something went wrong";
        }
    }
}
