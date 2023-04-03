
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "RemoteProjectSystemComponent.h"

namespace RemoteProject
{
    class RemoteProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(RemoteProjectModule, "{A3B6170C-3E8D-4764-91D1-960FA245CDE5}", AZ::Module);
        AZ_CLASS_ALLOCATOR(RemoteProjectModule, AZ::SystemAllocator, 0);

        RemoteProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                RemoteProjectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<RemoteProjectSystemComponent>(),
            };
        }
    };
}// namespace RemoteProject

AZ_DECLARE_MODULE_CLASS(Gem_RemoteProject, RemoteProject::RemoteProjectModule)
