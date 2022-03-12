/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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

#ifndef USERIDM_CALLBACK_H
#define USERIDM_CALLBACK_H

#include "useridm_info.h"

namespace OHOS {
namespace UserIAM {
namespace UserIDM {
class GetInfoCallback {
public:
    /**
     * @brief
     * @param info.
     * @return void.
     */
    virtual void OnGetInfo(std::vector<CredentialInfo>& info) = 0;
};

class GetSecInfoCallback {
public:
    /**
     * @brief
     * @param info .
     * @return void.
     */
    virtual void OnGetSecInfo(SecInfo &info) = 0;
};

class IDMCallback {
public:
    /**
     * @brief
     * @param result .
     * @param strcut reqRet .
     * @return void.
     */
    virtual void OnResult(int32_t result, RequestResult reqRet) = 0;

    /**
     * @brief
     * @param module .
     * @param acquire .
     * @param reqRet .
     * @return void.
     */
    virtual void OnAcquireInfo(int32_t module, int32_t acquire, RequestResult reqRet) = 0;
};
}  // namespace UserIDM
}  // namespace UserIAM
}  // namespace OHOS

#endif // USERIDM_CALLBACK_H