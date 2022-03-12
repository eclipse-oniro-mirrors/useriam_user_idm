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


#ifndef USERIDM_SERVICE_H
#define USERIDM_SERVICE_H

#include <map>
#include <iremote_stub.h>
#include <system_ability.h>
#include <system_ability_definition.h>
#include <string>

#include "useridm_stub.h"
#include "useridm_hilog_wrapper.h"
#include "useridm_controller.h"
#include "iuser_idm.h"

namespace OHOS {
namespace UserIAM {
namespace UserIDM {
class UserIDMService : public SystemAbility, public UserIDMStub {
public:
    DECLARE_SYSTEM_ABILITY(UserIDMService);
    explicit UserIDMService(int32_t systemAbilityId, bool runOnCreate = false);
    ~UserIDMService() override;
    void OnStart() override;
    void OnStop() override;
    uint64_t OpenSession() override;
    void CloseSession() override;
    int32_t GetAuthInfo(AuthType authType, const sptr<IGetInfoCallback>& callback) override;
    int32_t GetAuthInfo(int32_t userId, AuthType authType, const sptr<IGetInfoCallback>& callback) override;
    int32_t GetSecInfo(int32_t userId, const sptr<IGetSecInfoCallback>& callback) override;
    void AddCredential(AddCredInfo& credInfo, const sptr<IIDMCallback>& callback) override;
    void UpdateCredential(AddCredInfo& credInfo, const sptr<IIDMCallback>& callback) override;
    int32_t Cancel(uint64_t challenge) override;
    int32_t EnforceDelUser(int32_t userId, const sptr<IIDMCallback>& callback) override; // del user
    void DelUser(std::vector<uint8_t> authToken, const sptr<IIDMCallback>& callback) override; // del pin
    void DelCred(uint64_t credentialId, std::vector<uint8_t> authToken, const sptr<IIDMCallback>& callback) override;

private:
    int32_t GetCallingUserID(int32_t &userID);
    bool CheckPermission(const std::string &permission);
    // add controller point
    UserIDMController idmController_;
};
}  // namespace UserIDM
}  // namespace UserIAM
}  // namespace OHOS
#endif // USERIDM_SERVICE_H
