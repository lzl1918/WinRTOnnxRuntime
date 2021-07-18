#pragma once
#include "FloatTensor.g.h"

namespace winrt::WinRTOnnxRuntime::implementation
{
    struct FloatTensor : FloatTensorT<FloatTensor>
    {
        FloatTensor() = default;

        FloatTensor(array_view<int64_t const> dimensions, array_view<float const> data);

    private:
        array_view<int64_t const> dimensions;
        array_view<float const> data;
    };
}

namespace winrt::WinRTOnnxRuntime::factory_implementation
{
    struct FloatTensor : FloatTensorT<FloatTensor, implementation::FloatTensor>
    {
    };
}
