//
// Created by benji on 28.11.17.
//

#ifndef GRADIUS_SINGLETON_H
#define GRADIUS_SINGLETON_H

template <typename T>
class Singleton {
private:
    static T* m_instance;
protected:
    virtual ~Singleton(){
        delete m_instance;
    }
    explicit Singleton() = default;

public:
    static T* getInstance(){
        if(!m_instance){
            m_instance = new T;
        }
        return m_instance;
    }
};

template <typename T> T* Singleton<T>::m_instance = nullptr;


#endif //GRADIUS_SINGLETON_H
