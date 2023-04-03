
#pragma once

#include <AzCore/Component/Component.h>

#include <RemoteProject/RemoteProjectBus.h>

namespace RemoteProject
{
    class RemoteProjectSystemComponent
        : public AZ::Component
        , protected RemoteProjectRequestBus::Handler
    {
    public:
        AZ_COMPONENT(RemoteProjectSystemComponent, "{563C6E5C-1BE5-4DEB-BBE1-A4133E6A3918}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        RemoteProjectSystemComponent();
        ~RemoteProjectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // RemoteProjectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
