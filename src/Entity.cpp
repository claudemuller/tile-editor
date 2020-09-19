#include "Entity.h"

//#include "Components/TransformComponent.h"

Entity::Entity(EntityManager& entityManager): mEntityManager(entityManager) {
    mActive = true;
}

Entity::Entity(EntityManager& entityManager, const std::string& name, LayerType layer): mEntityManager(entityManager), name(name), layer(layer) {
    mActive = true;
}

bool Entity::isActive() const {
    return mActive;
}

void Entity::update(float deltaTime) {
//    for (auto& component : mComponents) {
//        component->update(deltaTime);
//    }
}

void Entity::render() {
//    for (auto& component : mComponents) {
//        component->render();
//    }
}

void Entity::destroy() {
    mActive = false;
}

void Entity::print(unsigned int i) {
    std::cout << "Entity [" << i << "] Name: " << mName << std::endl;
    listComponents();
}

void Entity::listComponents() {
//    for (auto& componentType : mComponentTypeMap) {
//        std::cout << "\tComponent<" << componentType.first->name() << ">" << std::endl;
//    }
}
