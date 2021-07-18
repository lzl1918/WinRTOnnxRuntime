#pragma once
#include "OnnxRuntime.g.h"
#include <onnxruntime_c_api.h>

namespace winrt::WinRTOnnxRuntime::implementation
{
    struct OnnxRuntime : OnnxRuntimeT<OnnxRuntime>
    {
        OnnxRuntime();
        OnnxRuntime(const OrtApi* ortApi);

        winrt::WinRTOnnxRuntime::OnnxSession LoadSession(hstring const& model);
        void Close();

        static winrt::WinRTOnnxRuntime::OnnxRuntime Create();

    private:
        const OrtApi* ortApi;
        OrtEnv* ortEnv;
    };
}
namespace winrt::WinRTOnnxRuntime::factory_implementation
{
    struct OnnxRuntime : OnnxRuntimeT<OnnxRuntime, implementation::OnnxRuntime>
    {
    };
}