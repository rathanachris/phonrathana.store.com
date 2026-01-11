#include "firebase/analytics.h"

using firebase::analytics::Parameter;

void LogSelectContentEvent(
    const char* id,
    const char* name,
    const char* favorite_food,
    const char* user_id) 
{
    // 1️⃣ បង្កើត parameter list
    const Parameter kSelectContentParameters[] = {
        Parameter(firebase::analytics::kParameterItemID, id),
        Parameter(firebase::analytics::kParameterItemName, name),
        Parameter(firebase::analytics::kUserPropertySignUpMethod, "Google"),
        Parameter("favorite_food", favorite_food),
        Parameter("user_id", user_id),
    };

    // 2️⃣ Log event
    firebase::analytics::LogEvent(
        firebase::analytics::kEventSelectContent,
        kSelectContentParameters,
        sizeof(kSelectContentParameters) / sizeof(kSelectContentParameters[0])
    );
}
