#ifndef __TILEEDITOR_ENTITY_H__
#define __TILEEDITOR_ENTITY_H__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Constants.h"
//#include "EntityManager.h"

class EntityManager;
class Component;

class Entity {
    public:
        std::string mName;
        LayerType mLayer;

        Entity(EntityManager& entityManager);
        Entity(EntityManager& entityManager, const std::string& name, LayerType layer);

        bool isActive() const;
        void update(float deltaTime);
        void render();
        void destroy();
        void print(unsigned int i);

//        template <typename T, typename... TArgs>
//        T& addComponent(TArgs&&... args) {
//            T* newComponent(new T(std::forward<TArgs>(args)...));
//
//            newComponent->mOwner = this;
//
//            mComponents.emplace_back(newComponent);
//            mComponentTypeMap[&typeid(*newComponent)] = newComponent;
//
//            newComponent->init();
//
//            return *newComponent;
//        }
//
//        template <typename T>
//        T* getComponent() {
//            return static_cast<T*>(mComponentTypeMap[&typeid(T)]);
//        }
//
//        template <typename T>
//        bool hasComponent() const {
//            return mComponentTypeMap.count(&typeid(T));
//        }

    private:
        EntityManager& mEntityManager;
        bool mActive;
//        std::vector<Component*> mComponents;
//        std::map<const std::type_info*, Component*> mComponentTypeMap;

        void listComponents();
};

#endif // __TILEEDITOR_ENTITY_H__
