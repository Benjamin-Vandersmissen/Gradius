//
// Created by uauser on 11/28/17.
//

#include "Exception.h"


ResourceException::ResourceException(const std::string &resourceName) : m_resourceName(resourceName) {
    m_errorMsg = "Resource \"" + m_resourceName + "\" Does not exists";
}

Exception::Exception() {}

const char *Exception::what() const noexcept {
    return m_errorMsg.c_str();
}
