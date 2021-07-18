#pragma once
#include "OnnxSession.g.h"
#include <onnxruntime_c_api.h>

namespace winrt::WinRTOnnxRuntime::implementation
{
    struct OnnxSession : OnnxSessionT<OnnxSession>
    {
        OnnxSession();
        OnnxSession(const OrtApi* ortApi, OrtSessionOptions* ortSessionOptions, OrtSession* ortSession);

        void Close();

    private:
        const OrtApi* ortApi;
        OrtSessionOptions* ortSessionOptions;
        OrtSession* ortSession;
    };
}
