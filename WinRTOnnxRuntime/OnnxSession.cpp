#include "pch.h"
#include "OnnxSession.h"
#include "OnnxSession.g.cpp"

namespace winrt::WinRTOnnxRuntime::implementation
{
	OnnxSession::OnnxSession() : OnnxSession::OnnxSession(nullptr, nullptr, nullptr)
	{
	}

	OnnxSession::OnnxSession(const OrtApi* ortApi, OrtSessionOptions* ortSessionOptions, OrtSession* ortSession)
		: ortApi(ortApi), ortSessionOptions(ortSessionOptions), ortSession(ortSession)
	{
	}

	void OnnxSession::Close()
    {
		if (ortApi != nullptr)
		{
			ortApi->ReleaseSessionOptions(ortSessionOptions);
			ortSessionOptions = nullptr;
			ortApi->ReleaseSession(ortSession);
			ortSession = nullptr;
			ortApi = nullptr;
		}
    }
}
