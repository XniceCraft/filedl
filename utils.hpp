#if __cplusplus > 201703L
#include <filesystem>
#else
#include <sys/stat.h>
#endif

#include <string>

inline bool isFileExists(const std::string &path){
    #if __cplusplus > 201703L
    return std::filesystem::exists(path.c_str());
    #else
    struct stat buffer;
    return stat(path.c_str(), &buffer) == 0;
    #endif
}
