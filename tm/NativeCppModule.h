#pragma once

#if __has_include(<React-Codegen/AppSpecsJSI.h>) // CocoaPod headers on Apple
#include <React-Codegen/AppSpecsJSI.h>
#elif __has_include("AppSpecsJSI.h") // CMake headers on Android
#include "AppSpecsJSI.h"
#endif
#include <memory>
#include <string>

namespace facebook::react {

#pragma mark - Structs
using ConstantsStruct =
    NativeCppModuleConstantsStruct<bool, int32_t, std::string>;

template <>
struct Bridging<ConstantsStruct>
    : NativeCppModuleConstantsStructBridging<ConstantsStruct> {};

class NativeCppModule : public NativeCppModuleCxxSpec<NativeCppModule> {
 public:
  NativeCppModule(std::shared_ptr<CallInvoker> jsInvoker);

  std::string reverseString(jsi::Runtime& rt, std::string input);

  ConstantsStruct getConstants(jsi::Runtime& rt);
};

} // namespace facebook::react