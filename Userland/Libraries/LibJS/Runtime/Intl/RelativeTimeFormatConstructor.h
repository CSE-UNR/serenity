/*
 * Copyright (c) 2022, Tim Flynn <trflynn89@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/NativeFunction.h>

namespace JS::Intl {

class RelativeTimeFormatConstructor final : public NativeFunction {
    JS_OBJECT(RelativeTimeFormatConstructor, NativeFunction);

public:
    virtual ThrowCompletionOr<void> initialize(Realm&) override;
    virtual ~RelativeTimeFormatConstructor() override = default;

    virtual ThrowCompletionOr<Value> call() override;
    virtual ThrowCompletionOr<NonnullGCPtr<Object>> construct(FunctionObject& new_target) override;

private:
    explicit RelativeTimeFormatConstructor(Realm&);

    virtual bool has_constructor() const override { return true; }

    JS_DECLARE_NATIVE_FUNCTION(supported_locales_of);
};

ThrowCompletionOr<RelativeTimeFormat*> initialize_relative_time_format(VM& vm, RelativeTimeFormat& relative_time_format, Value locales_value, Value options_value);

}
