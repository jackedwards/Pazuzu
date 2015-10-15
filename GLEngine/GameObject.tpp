template <class T>
void GameObject::AddComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "ERROR: T must extend Component.\n");

    if (!HasComponent<T>())
    {
	    std::shared_ptr<T> component = std::make_shared<T>();
        component->mp_gameObject = this;
        component->Start();
	    m_components.insert(std::pair<std::type_index, std::shared_ptr<Component> >(typeid(T), std::move(component)));
    }
}

template <class T>
void GameObject::RemoveComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "ERROR: T must extend Component.\n");

    if (HasComponent<T>())
    {
        std::shared_ptr<T> component = GetComponent<T>();
        m_components.erase(typeid(T));
    }
}

template <class T>
bool GameObject::HasComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "ERROR: T must extend Component.\n");

    if (m_components.count(typeid(T)) > 0)
        return true;
    
    return false;
}

template <class T>
std::shared_ptr<T> GameObject::GetComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "ERROR: T must extend Component.\n");
    
    if (HasComponent<T>())
        return std::static_pointer_cast<T>(m_components[typeid(T)]);
    else
    	return nullptr;
}
