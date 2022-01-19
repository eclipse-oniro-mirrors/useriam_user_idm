/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <message_parcel.h>

#include "useridm_hilog_wrapper.h"
#include "useridm_callback_stub.h"

namespace OHOS {
namespace UserIAM {
namespace UserIDM {
UserIDMCallbackStub::UserIDMCallbackStub(const std::shared_ptr<IDMCallback>& impl)
{
    callback_ = impl;
}

int32_t UserIDMCallbackStub::OnRemoteRequest(uint32_t code, MessageParcel &data,
                                             MessageParcel &reply, MessageOption &option)
{
    USERIDM_HILOGI(MODULE_INNERKIT, "UserIDMCallbackStub::OnRemoteRequest, cmd = %d, flags= %d", code,
                   option.GetFlags());

    std::u16string descripter = UserIDMCallbackStub::GetDescriptor();
    std::u16string remoteDescripter = data.ReadInterfaceToken();
    if (descripter != remoteDescripter) {
        USERIDM_HILOGE(MODULE_INNERKIT, "UserIDMCallbackStub::OnRemoteRequest failed, descriptor is not matched!");
        return FAIL;
    }

    switch (code) {
        case static_cast<int32_t>(IIDMCallback::IDM_CALLBACK_ON_RESULT):
            return OnResultStub(data, reply);
        case static_cast<int32_t>(IIDMCallback::IDM_CALLBACK_ON_ACQUIRE_INFO):
            return OnAcquireInfoStub(data, reply);
        default:
            return IPCObjectStub::OnRemoteRequest(code, data, reply, option);
    }
}

int32_t UserIDMCallbackStub::OnResultStub(MessageParcel& data, MessageParcel& reply)
{
    USERIDM_HILOGI(MODULE_INNERKIT, "UserIDMCallbackStub OnResultStub enter ");

    RequestResult reqRet;

    int32_t result = data.ReadInt32();
    reqRet.credentialId = data.ReadUint64();

    this->OnResult(result, reqRet);

    return SUCCESS;
}

int32_t UserIDMCallbackStub::OnAcquireInfoStub(MessageParcel& data, MessageParcel& reply)
{
    USERIDM_HILOGI(MODULE_INNERKIT, "UserIDMCallbackStub OnAcquireInfoStub enter ");

    int32_t ret = SUCCESS;
    RequestResult reqRet;
    int32_t module = data.ReadInt32();
    int32_t acquire = data.ReadInt32();
    reqRet.credentialId = data.ReadUint64();

    OnAcquireInfo(module, acquire, reqRet);
    if (!reply.WriteInt32(ret)) {
        USERIDM_HILOGE(MODULE_INNERKIT, "failed to WriteInt32(ret)");
        ret = FAIL;
    }

    return ret;
}

void UserIDMCallbackStub::OnResult(int32_t result, RequestResult reqRet)
{
    USERIDM_HILOGE(MODULE_INNERKIT, "UserIDMCallbackStub  OnResult enter");

    if (callback_ == nullptr) {
        USERIDM_HILOGE(MODULE_INNERKIT, "callback_ is nullptr");
    } else {
        USERIDM_HILOGE(MODULE_INNERKIT, "befor Call Napi callback~");
        callback_->OnResult(result, reqRet);
        USERIDM_HILOGE(MODULE_INNERKIT, "after Call Napi callback~");
    }
}

void UserIDMCallbackStub::OnAcquireInfo(int32_t module, int32_t acquire, RequestResult reqRet)
{
    USERIDM_HILOGE(MODULE_INNERKIT, "UserIDMCallbackStub  OnAcquireInfo enter");

    if (callback_ == nullptr) {
        USERIDM_HILOGE(MODULE_INNERKIT, "callback_ is nullptr");
    } else {
        callback_->OnAcquireInfo(module, acquire, reqRet);
    }
}
}  // namespace UserIDM
}  // namespace UserIAM
}  // namespace OHOS
