////////////////////////////////////////////////////////////////////////////////
#pragma once
////////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstdint>

#include <memory>
#include <any>
#include <vector>
#include <map>
#include <stack>
#include <array>
#include <string>
#include "Parameter.h"

//types
typedef unsigned char  uchar;

//command

/*
class ICommandParameter
{
};
*/

class ICommandBase
{
public:
    //virtual void SetParameter(const std::shared_ptr<ICommandParameter>& param) = 0;
    virtual void SetParameter(std::shared_ptr<Parameters> param) = 0;
    virtual void Exec(int id) = 0;
/*
virtual std::shared_ptr<ICommandBase> get_Undo() = 0;
virtual std::shared_ptr<ICommandBase> get_Redo() = 0;
//use make_shared, then the virtual destructor is not necessary. (RAII)
*/
};

class CommandManager
{
public:
/*
...
*/
private:
    std::vector<std::shared_ptr<ICommandBase>> m_vecUndo;
    std::vector<std::shared_ptr<ICommandBase>> m_vecRedo;
};

//Notifications

template <class T>
class NotificationImpl
{
public:
    void Clear() throw()
    {
        m_array.clear();
    }
    void AddNotification(const std::shared_ptr<T>& p)
    {
        m_array.push_back(p);
    }
    void RemoveNotification(const std::shared_ptr<T>& p) throw()
    {
        auto iter(m_array.begin());
        for( ; iter != m_array.end(); ++ iter ) {
            if( (*iter).get() == p.get() ) {
                m_array.erase(iter);
                return ;
            }
        }
    }

protected:
    std::vector<std::shared_ptr<T>> m_array;
};

class IPropertyNotification
{
public:
    ~IPropertyNotification(){};
    virtual void OnPropertyChanged(const std::string& str) = 0;
    //virtual void OnPropertyChanged(unsigned int uPropertyID) = 0;
};

class ICommandNotification
{
public:
    ~ICommandNotification(){}
    virtual void OnCommandComplete(const std::string& str, bool bOK) = 0;
    //virtual void OnCommandComplete(unsigned int uCommandID, bool bOK) = 0;
};

template <class T>
class Proxy_PropertyNotification : public NotificationImpl<IPropertyNotification>
{
public:
    void AddPropertyNotification(const std::shared_ptr<IPropertyNotification>& p)
    {
        AddNotification(p);
    }
    void RemovePropertyNotification(const std::shared_ptr<IPropertyNotification>& p) throw()
    {
        RemoveNotification(p);
    }
    void Fire_OnPropertyChanged(const std::string& str)
    {
        auto iter(m_array.begin());
        for( ; iter != m_array.end(); ++ iter ) {
            (*iter)->OnPropertyChanged(str);
        }
    }
};

template <class T>
class Proxy_CommandNotification : public NotificationImpl<ICommandNotification>
{
public:
    void AddCommandNotification(const std::shared_ptr<ICommandNotification>& p)
    {
        AddNotification(p);
    }
    void RemoveCommandNotification(const std::shared_ptr<ICommandNotification>& p) throw()
    {
        RemoveNotification(p);
    }
    void Fire_OnCommandComplete(const std::string& str, bool bOK)
    {
        auto iter(m_array.begin());
        for( ; iter != m_array.end(); ++ iter ) {
            (*iter)->OnCommandComplete(str, bOK);
        }
    }
};
