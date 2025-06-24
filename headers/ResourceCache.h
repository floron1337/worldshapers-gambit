//
// Created by floron on 6/25/25.
//

#ifndef RESOURCECACHE_H
#define RESOURCECACHE_H
#include <string>
#include <memory>
#include <map>

template<typename T>
class ResourceCache {
   std::map<std::string, std::unique_ptr<T>> resources;
public:
   T& add(const std::string& filename) {
      auto it = resources.find(filename);
      if (it != resources.end()) {
         return *(it->second);
      }
      auto resource = std::make_unique<T>();
      if (!resource->loadFromFile(filename)) {
         throw std::runtime_error("Failed to load resource: " + filename);
      }
      T& ref = *resource;
      resources[filename] = std::move(resource);
      return ref;
   }

   T& get(const std::string& filename) {
      auto it = resources.find(filename);
      if (it == resources.end()) {
         throw std::runtime_error("Resource not found: " + filename);
      }
      return *(it->second);
   }
};



#endif //RESOURCECACHE_H
