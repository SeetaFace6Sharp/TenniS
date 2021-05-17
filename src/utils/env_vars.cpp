#include <utils/env_vars.h>

namespace ts {
    std::string getEnvironmentVariable(const std::string& envName) {
#if TS_PLATFORM_OS_WINDOWS
        #include <Windows.h>
        char buffer[MAX_PATH];
        DWORD code = GetEnvironmentVariable(envName.c_str(), buffer, MAX_PATH);
        return code == 0 ? std::string("") : std::string(buffer)
#elif TS_PLATFORM_OS_LINUX || TS_PLATFORM_OS_ANDROID
        char* buffer = nullptr;
        buffer = std::getenv(envName.c_str());
        return buffer == nullptr ? std::string("") : std::string(buffer);
#endif
    }

}