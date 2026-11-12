// Copyright (c) Microsoft Corporation. All rights reserved.

#include <vcruntime_internal.h>

unsigned long long __processor_features_0_63 = 0;
unsigned long long __processor_features_64_127 = 0;

void __processor_features_init()
{
    __processor_features_0_63 = 0;
    __processor_features_64_127 = 0;

    for (DWORD i = 0; i < 64; ++i)
    {
        __processor_features_0_63 |= (IsProcessorFeaturePresent(i) ? 1ull : 0ull) << i;
        __processor_features_64_127 |= (IsProcessorFeaturePresent(i + 64) ? 1ull : 0ull) << i;
    }
}
