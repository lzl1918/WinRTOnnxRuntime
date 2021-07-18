#include "pch.h"
#include "FloatTensor.h"
#include "FloatTensor.g.cpp"


namespace winrt::WinRTOnnxRuntime::implementation
{
    FloatTensor::FloatTensor(array_view<int64_t const> dimensions, array_view<float const> data) : dimensions(dimensions), data(data)
    {
    }
}
