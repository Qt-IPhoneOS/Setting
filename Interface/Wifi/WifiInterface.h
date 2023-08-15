#ifndef WIFIINTERFACE_H
#define WIFIINTERFACE_H

#include <shared_mutex>
#include <AbstractInterface/AbstractInterface.h>
#include "Signal.h"

class WifiInterfacePrivate;
class WifiInterface final : public AbstractInterface {
    friend class WifiInterfacePrivate;
    friend class WifiAdapter;
protected:
    class MutexWrapper {
    public:
        MutexWrapper(std::shared_mutex& mutex):mMutex(mutex)
        {}

        MutexWrapper(const MutexWrapper& other):mMutex(other.mMutex)
        {}

        void lock()
        {
            mMutex.lock();
        }

        void unlock()
        {
            mMutex.unlock();
        }

        void lock_shared()
        {
            mMutex.lock_shared();
        }

        bool try_lock_shared()
        {
            return mMutex.try_lock_shared();
        }

        void unlock_shared()
        {
            mMutex.unlock_shared();
        }

    private:
        std::shared_mutex& mMutex;
    };
public:
    ~WifiInterface();

    static WifiInterface* instance();

    bool doConnect() override;
    bool doDisconnect() override;

protected:
    WifiInterface();
    WifiInterface(const WifiInterface& ) = delete;
    WifiInterface& operator=(const WifiInterface& ) = delete;

    WifiInterfacePrivate* mWifiPriv {nullptr};
};

class WifiAdapter {
    friend class WifiInterface;
    friend class WifiInterfacePrivate;
public:
protected:
    WifiAdapter(WifiInterface& interface);
    WifiAdapter(const WifiAdapter&) = delete;
    WifiAdapter& operator=(const WifiAdapter&) = delete;

    WifiInterface& mWifiIF;

    mutable WifiInterface::MutexWrapper mMutex;
};

#endif // WIFIINTERFACE_H
