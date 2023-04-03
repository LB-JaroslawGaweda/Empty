
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace RemoteProject
{
    class RemoteProjectRequests
    {
    public:
        AZ_RTTI(RemoteProjectRequests, "{36CDEAF2-950F-4CE5-931A-905E2B5C5D76}");
        virtual ~RemoteProjectRequests() = default;
        // Put your public methods here
    };

    class RemoteProjectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using RemoteProjectRequestBus = AZ::EBus<RemoteProjectRequests, RemoteProjectBusTraits>;
    using RemoteProjectInterface = AZ::Interface<RemoteProjectRequests>;

} // namespace RemoteProject
