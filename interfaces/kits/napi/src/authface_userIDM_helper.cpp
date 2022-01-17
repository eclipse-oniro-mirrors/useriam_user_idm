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
#include <iremote_broker.h>
#include "useridentity_manager.h"
#include "hilog_wrapper.h"
#include "authface_userIDM_helper.h"

namespace OHOS {
namespace UserIAM {
namespace UserIDM {
napi_ref g_ctor;
/**
 * @brief Instance passed to context
 *
 * @param env
 * @param info
 * @return napi_value Instance
 */
napi_value UserIdentityManagerConstructor(napi_env env, napi_callback_info info)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    std::shared_ptr<UserIdentityManager> userIdentityManager;
    userIdentityManager.reset(new UserIdentityManager());
    napi_value thisVar = nullptr;
    size_t argc = 1;
    napi_value argv[1] = {nullptr};
    NAPI_CALL(env, napi_get_cb_info(env, info, &argc, argv, &thisVar, nullptr));
    NAPI_CALL(env, napi_wrap(
        env, thisVar, userIdentityManager.get(),
        [](napi_env env, void *data, void *hint) {
            UserIdentityManager *userIdentityManager = static_cast<UserIdentityManager *>(data);
            if (userIdentityManager != nullptr) {
                delete userIdentityManager;
            }
        },
        nullptr, nullptr));
    return thisVar;
}

/**
 * @brief start the OpenSession
 *
 * @param env
 * @param info
 * @return napi_value void
 */
napi_value OpenSession(napi_env env, napi_callback_info info)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_value thisVar = nullptr;
    size_t argcAsync = 0;
    napi_value argv[ARGS_MAX_COUNT] = {nullptr};
    NAPI_CALL(env, napi_get_cb_info(env, info, &argcAsync, argv, &thisVar, nullptr));
    UserIdentityManager *userIdentityManager = nullptr;
    NAPI_CALL(env, napi_unwrap(env, thisVar, (void **)&userIdentityManager));
    return userIdentityManager->NAPI_OpenSession(env, info);
}

/**
 * @brief AddCredential
 *
 * @param env
 * @param info
 * @return napi_value Verify that the certification capability is available
 */
napi_value AddCredential(napi_env env, napi_callback_info info)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_value thisVar = nullptr;
    size_t argcAsync = 0;
    napi_value argv[ARGS_MAX_COUNT] = {nullptr};
    NAPI_CALL(env, napi_get_cb_info(env, info, &argcAsync, argv, &thisVar, nullptr));
    UserIdentityManager *userIdentityManager = nullptr;
    NAPI_CALL(env, napi_unwrap(env, thisVar, (void **)&userIdentityManager));
    return userIdentityManager->NAPI_AddCredential(env, info);
}

/**
 * @brief Get the Property object
 *
 * @param env
 * @param info
 * @return napi_value It supports querying subclasses / remaining authentication times / freezing time
 */
napi_value UpdateCredential(napi_env env, napi_callback_info info)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_value thisVar = nullptr;
    size_t argcAsync = 0;
    napi_value argv[ARGS_MAX_COUNT] = {nullptr};
    NAPI_CALL(env, napi_get_cb_info(env, info, &argcAsync, argv, &thisVar, nullptr));
    UserIdentityManager *userIdentityManager = nullptr;
    NAPI_CALL(env, napi_unwrap(env, thisVar, (void **)&userIdentityManager)); 
    return userIdentityManager->NAPI_UpdateCredential(env, info);
}

/**
 * @brief Set the Property object
 *
 * @param env
 * @param info
 * @return napi_value Set properties: can be used to initialize algorithms
 */
napi_value CloseSession(napi_env env, napi_callback_info info)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_value thisVar = nullptr;
    size_t argcAsync = 0;
    napi_value argv[ARGS_MAX_COUNT] = {nullptr};
    NAPI_CALL(env, napi_get_cb_info(env, info, &argcAsync, argv, &thisVar, nullptr));
    UserIdentityManager *userIdentityManager = nullptr;
    NAPI_CALL(env, napi_unwrap(env, thisVar, (void **)&userIdentityManager));
    return userIdentityManager->NAPI_CloseSession(env, info);
}

/**
 * @brief user authentication
 *
 * @param env
 * @param info
 * @return napi_value Enter the challenge value, authentication method, trust level and callback, and return the result
 * and acquireinfo through the callback
 */
napi_value Cancel(napi_env env, napi_callback_info info)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_value thisVar = nullptr;
    size_t argcAsync = 0;
    napi_value argv[ARGS_MAX_COUNT] = {nullptr};
    NAPI_CALL(env, napi_get_cb_info(env, info, &argcAsync, argv, &thisVar, nullptr));
    UserIdentityManager *userIdentityManager = nullptr;
    NAPI_CALL(env, napi_unwrap(env, thisVar, (void **)&userIdentityManager));
    return userIdentityManager->NAPI_Cancel(env, info);
}

/**
 * @brief user authentication
 *
 * @param env
 * @param info
 * @return napi_value Pass in the user ID, challenge value, authentication method, trust level and callback, and return
 * the result acquireinfo through the callback
 */
napi_value DelUser(napi_env env, napi_callback_info info)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_value thisVar = nullptr;
    size_t argcAsync = 0;
    napi_value argv[ARGS_MAX_COUNT] = {nullptr};
    NAPI_CALL(env, napi_get_cb_info(env, info, &argcAsync, argv, &thisVar, nullptr));
    UserIdentityManager *userIdentityManager = nullptr;
    NAPI_CALL(env, napi_unwrap(env, thisVar, (void **)&userIdentityManager));
    return userIdentityManager->NAPI_DelUser(env, info);
}

/**
 * @brief Cancel authentication
 *
 * @param env
 * @param info
 * @return napi_value success or fail
 */
napi_value DelCred(napi_env env, napi_callback_info info)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_value thisVar = nullptr;
    size_t argcAsync = 0;
    napi_value argv[ARGS_MAX_COUNT] = {nullptr};
    NAPI_CALL(env, napi_get_cb_info(env, info, &argcAsync, argv, &thisVar, nullptr));
    UserIdentityManager *userIdentityManager = nullptr;
    NAPI_CALL(env, napi_unwrap(env, thisVar, (void **)&userIdentityManager));
    return userIdentityManager->NAPI_DelCred(env, info);
}

napi_value GetAuthInfo(napi_env env, napi_callback_info info)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_value thisVar = nullptr;
    size_t argcAsync = 0;
    napi_value argv[ARGS_MAX_COUNT] = {nullptr};
    NAPI_CALL(env, napi_get_cb_info(env, info, &argcAsync, argv, &thisVar, nullptr));
    UserIdentityManager *userIdentityManager = nullptr;
    NAPI_CALL(env, napi_unwrap(env, thisVar, (void **)&userIdentityManager));
    return userIdentityManager->NAPI_GetAuthInfo(env, info);
}

/**
 * @brief Napi initialization
 *
 * @param env
 * @param exports
 */
void AuthFaceInit(napi_env env, napi_value exports)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_status status;
    napi_property_descriptor exportFuncs[] = {
        DECLARE_NAPI_FUNCTION("constructor", OHOS::UserIAM::UserIDM::Constructor),
    };
    status = napi_define_properties(env, exports, sizeof(exportFuncs) / sizeof(*exportFuncs), exportFuncs);
    if (status != napi_ok) {
        HILOG_ERROR("napi_define_properties faild");
    }
}

napi_value Constructor(napi_env env, napi_callback_info info)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_value thisVar;
    napi_value UserIdentityManager;
    NAPI_CALL(env, napi_get_cb_info(env, info, nullptr, nullptr, &thisVar, nullptr));
    NAPI_CALL(env, napi_new_instance(env, GetCtor(env), 0, nullptr, &UserIdentityManager));
    return UserIdentityManager;
}

napi_value GetCtor(napi_env env)
{
    HILOG_INFO("authFace : %{public}s, start.", __func__);
    napi_value cons;
    if (g_ctor != nullptr) {
        NAPI_CALL(env, napi_get_reference_value(env, g_ctor, &cons));
        return cons;
    }
    napi_property_descriptor clzDes[] = {
        DECLARE_NAPI_FUNCTION("openSession", OpenSession),
        DECLARE_NAPI_FUNCTION("addCredential", AddCredential),
        DECLARE_NAPI_FUNCTION("updateCredential", UpdateCredential),
        DECLARE_NAPI_FUNCTION("closeSession", CloseSession),
        DECLARE_NAPI_FUNCTION("cancel", Cancel),
        DECLARE_NAPI_FUNCTION("delUser", DelUser),
        DECLARE_NAPI_FUNCTION("delCred", DelCred),
        DECLARE_NAPI_FUNCTION("getAuthInfo", GetAuthInfo),
    };
    
    NAPI_CALL(env, napi_define_class(env, "UserIdentityManager", NAPI_AUTO_LENGTH, UserIdentityManagerConstructor,
              nullptr, sizeof(clzDes) / sizeof(napi_property_descriptor), clzDes, &cons));
        NAPI_CALL(env, napi_create_reference(env, cons, 1, &g_ctor));
    return cons;
}
} // namespace UserIDM
} // namespace UserIAM
} // namespace OHOS