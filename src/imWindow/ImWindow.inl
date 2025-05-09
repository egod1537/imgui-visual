#pragma once

template<typename T>
T* ImWindow::AddComponent() {
    static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");

    auto newComponent = std::make_unique<T>();
    T* raw = newComponent.get();
    components.push_back(std::move(newComponent));
    return raw;
}

template<typename T>
T* ImWindow::GetComponent() {

}