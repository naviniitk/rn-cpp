#include "NativeCppModule.h"

namespace facebook::react {

NativeCppModule::NativeCppModule(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeCppModuleCxxSpec(std::move(jsInvoker)) {}

std::string NativeCppModule::reverseString(jsi::Runtime& rt, std::string input) {
  return std::string(input.rbegin(), input.rend());
}

} // namespace facebook::react
