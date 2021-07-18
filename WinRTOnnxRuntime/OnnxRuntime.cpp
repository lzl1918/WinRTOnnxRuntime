#include "pch.h"
#include "OnnxRuntime.h"
#include "OnnxRuntime.g.cpp"
#include "OnnxSession.h"

namespace winrt::WinRTOnnxRuntime::implementation
{
    OnnxRuntime::OnnxRuntime() : OnnxRuntime::OnnxRuntime(nullptr)
    {
    }

    OnnxRuntime::OnnxRuntime(const OrtApi* ortApi) : ortApi(ortApi)
    {
        if (ortApi == nullptr)
        {
            ortEnv = nullptr;
        }
        else
        {
            OrtEnv* ortEnv = nullptr;
            ortApi->CreateEnv(ORT_LOGGING_LEVEL_WARNING, "WinRTOnnxRuntime", &ortEnv);
            this->ortEnv = ortEnv;
        }
    }

    winrt::WinRTOnnxRuntime::OnnxRuntime OnnxRuntime::Create()
    {
        const OrtApiBase* ortApiBase = OrtGetApiBase();
        const OrtApi* ortApi = ortApiBase->GetApi(ORT_API_VERSION - 1);
        return winrt::make<winrt::WinRTOnnxRuntime::implementation::OnnxRuntime>(ortApi);
    }

    winrt::WinRTOnnxRuntime::OnnxSession OnnxRuntime::LoadSession(hstring const& model)
    {
        OrtSessionOptions* ortSessionOptions = nullptr;
        ortApi->CreateSessionOptions(&ortSessionOptions);

        std::wstring_view wstrModel(model);
        OrtSession* ortSession = nullptr;
        ortApi->CreateSession(ortEnv, wstrModel.data(), ortSessionOptions, &ortSession);

        return winrt::make<winrt::WinRTOnnxRuntime::implementation::OnnxSession>(ortApi, ortSessionOptions, ortSession);
    }

    void OnnxRuntime::Close()
    {
        if (ortApi != nullptr)
        {
            ortApi->ReleaseEnv(ortEnv);
            ortEnv = nullptr;
            ortApi = nullptr;
        }
    }
}

