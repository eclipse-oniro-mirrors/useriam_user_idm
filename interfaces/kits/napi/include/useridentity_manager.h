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

#ifndef USERIDENTITY_MANAGER_H
#define USERIDENTITY_MANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include <securec.h>
#include "useridm_client.h"
#include "useridm_callback.h"
#include "napi/native_api.h"
#include "napi/native_node_api.h"

namespace OHOS {
namespace UserIAM {
namespace UserIDM {
#define ZERO_PARAMETER 0
#define ONE_PARAMETER 1
#define TWO_PARAMETER 2
#define THREE_PARAMETER 3
#define ARGS_MAX_COUNT 10
#define RESULT 0
const std::string PROPERTY_KEY_NAME = "credType";
const std::string PROPERTY_KEY_ID = "credSubType";
const std::string PROPERTY_KEY_EVENT = "token";
const std::string FUNC_ONRESULT = "OnResult";
const std::string FUNC_ONACQUIREINFO = "OnAcquireInfo";

typedef struct AsyncOpenSession {
    napi_env env;
    napi_async_work asyncWork;
    napi_deferred deferred;
    napi_value promise;
    napi_ref callback;
    uint64_t OpenSession;
} AsyncOpenSession;
typedef struct AsyncGetAuthInfo {
    napi_env env;
    uint64_t openSession;
    napi_async_work asyncWork;
    napi_ref callback;
    AuthType authType;
    napi_deferred deferred;
    napi_value promise;
} AsyncGetAuthInfo;
typedef struct CallbackInfo {
    napi_env env;
    napi_ref onResult;
    napi_ref onAcquireInfo;
} CallbackInfo;
typedef struct AsyncCallbackContext {
    napi_env env;
    CallbackInfo callbackInfo;
    napi_async_work asyncWork;
    AuthType authType;
    AuthSubType authSubType;
    std::vector<uint8_t> credentialId;
    std::vector<uint8_t> token;
    napi_value IdmCallOnResult;
    napi_value IdmCallonAcquireInfo;
} AsyncCallbackContext;
typedef struct SyncCancelContext {
    napi_env env;
    std::vector<uint8_t> challenge;
} SyncCancelContext;
class UserIdentityManager {
public:
    UserIdentityManager() ;
    ~UserIdentityManager() ;
    napi_value NAPI_OpenSession(napi_env env, napi_callback_info info);
    napi_value NAPI_AddCredential(napi_env env, napi_callback_info info);
    napi_value NAPI_UpdateCredential(napi_env env, napi_callback_info info);
    napi_value NAPI_CloseSession(napi_env env, napi_callback_info info);
    napi_value NAPI_Cancel(napi_env env, napi_callback_info info);
    napi_value NAPI_DelUser(napi_env env, napi_callback_info info);
    napi_value NAPI_DelCred(napi_env env, napi_callback_info info);
    napi_value NAPI_GetAuthInfo(napi_env env, napi_callback_info info);
private:
    napi_value OpenSessionWrap(napi_env env, napi_callback_info info, AsyncOpenSession *asyncInfo);
    napi_value OpenSessionCallback(napi_env env, napi_value *args, size_t argcAsync, AsyncOpenSession *asyncInfo);
    napi_value OpenSessionPromise(napi_env env, napi_value *args, size_t argcAsync, AsyncOpenSession *asyncInfo);

    napi_value GetAuthInfoWrap(napi_env env, napi_callback_info info, AsyncGetAuthInfo *asyncInfo);
    napi_value GetAuthInfoCallback(napi_env env, napi_value *args, size_t argcAsync, AsyncGetAuthInfo *asyncInfo);
    napi_value GetAuthInfoPromise(napi_env env, napi_value *args, size_t argcAsync, AsyncGetAuthInfo *asyncInfo);

    static void AddCredentialExecute(napi_env env, void *data);
    static void AddCredentialComplete(napi_env env, napi_status status, void *data);
    static void UpdateCredentialExecute(napi_env env, void *data);
    static void UpdateCredentialComplete(napi_env env, napi_status status, void *data);
    static void DelUserExecute(napi_env env, void *data);
    static void DelUserComplete(napi_env env, napi_status status, void *data);
    static void DelCredExecute(napi_env env, void *data);
    static void DelCredComplete(napi_env env, napi_status status, void *data);
};
AsyncGetAuthInfo *GCreateAsyncInfo(napi_env env);
AsyncOpenSession *OCreateAsyncInfo(napi_env env);
napi_value OpenSessionRet(napi_env env, AsyncOpenSession* asyncOpenSession);
} // namespace UserIDM
} // namespace UserIAM
} // namespace ohos

#endif // AUTHFACE_USERIDM_NAPI_H