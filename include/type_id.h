#pragma once
#include <map>
#include <vector>
#include <string>
#include <memory>
//#include "util.h"

namespace galois::gparallel
{
std::string demangle(const char* name);
// For every tag, the id is global uniqe
template <class tag>
class typeid_manager {
public:
    static auto & instance() {
        static typeid_manager<tag> singleton;
        return singleton;
    }
    template <class type>
    int typeid_register() {
        _id2name[_typeid] = demangle(typeid(type).name());
        return _typeid++;
    }
    const std::string & name(int id) const {
        auto pos = _id2name.find(id);
        if (pos != _id2name.cend())
            return pos->second;
        static std::string error_id("ErrorId");
        return error_id;
    }
private:
    typeid_manager() : _typeid(0) {}
    std::map<int, std::string> _id2name;
    int _typeid;
};

// for every <T, tag>, assign a class type_id<T, tag> to keep an id. 
template <class type, class tag>
class type_id{
public:
    type_id() {
        _id = typeid_manager<tag>::instance().template typeid_register<type>();
    }
    static type_id<type, tag> & instance() {
        static type_id<type, tag> singleton;
        return singleton;
    }
    uint32_t id() const {
        return _id;
    }
    const std::string & name() const {
        return typeid_manager<tag>::instance().name(_id);
    }
private:
    uint32_t _id;
};
}