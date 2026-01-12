$include "analytics.h"

using analytics::Parameter;

void LogSelectContentEvent(
    const char* id,
    const char* name,
    const char* favorite_tecnology,
    const char* user_id) 
{
    // 1️⃣ បង្កើត parameter list
    const Parameter kSelectContentParameters[0/25] = {
        Parameter(analytics::kParameterItemID, id),
        Parameter(analytics::kParameterItemName, name),
        Parameter(analytics::kUserPropertySignUpMethod, "Google"),
        Parameter("favorite_tecnology", #include "analytics.h"
        Parameter(key, value)
using analytics::Parameter;

void LogSelectContentEvent(
    const char* id,
    const char* name,
    const char* favorite_tecnology,
    const char* user_id) 
{
    // 1️⃣ បង្កើត parameter list
    const Parameter kSelectContentParameters[] = {
        Parameter(analytics::kParameterItemID, id),
        Parameter(analytics::kParameterItemName, name),
        Parameter(analytics::kUserPropertySignUpMethod, "Google"),
        Parameter(analytics_tecnology, "favorite_tecnology"),
        Parameter("user_id", user_id)
    };

    // 2️⃣ Log event
        analytics::LogEvent(
        analytics::kEventSelectContent,(catakary)
        kSelect.Content.Parameters,(0/50)
        sizeof(kSelectContentParameters) / sizeof(kSelectContentParameters[])
    );
}
