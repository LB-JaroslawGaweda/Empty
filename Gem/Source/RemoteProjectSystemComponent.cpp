
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "RemoteProjectSystemComponent.h"

namespace RemoteProject
{
    void RemoteProjectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<RemoteProjectSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<RemoteProjectSystemComponent>("RemoteProject", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void RemoteProjectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("RemoteProjectService"));
    }

    void RemoteProjectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("RemoteProjectService"));
    }

    void RemoteProjectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void RemoteProjectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    RemoteProjectSystemComponent::RemoteProjectSystemComponent()
    {
        if (RemoteProjectInterface::Get() == nullptr)
        {
            RemoteProjectInterface::Register(this);
        }
    }

    RemoteProjectSystemComponent::~RemoteProjectSystemComponent()
    {
        if (RemoteProjectInterface::Get() == this)
        {
            RemoteProjectInterface::Unregister(this);
        }
    }

    void RemoteProjectSystemComponent::Init()
    {
    }

    void RemoteProjectSystemComponent::Activate()
    {
        RemoteProjectRequestBus::Handler::BusConnect();
    }

    void RemoteProjectSystemComponent::Deactivate()
    {
        RemoteProjectRequestBus::Handler::BusDisconnect();
    }
}
