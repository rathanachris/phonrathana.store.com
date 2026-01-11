// Set user property (once)
firebase::analytics::SetUserProperty(
    firebase::analytics::kUserPropertySignUpMethod,
    "Google"
);

// Log event
const Parameter params[] = {
    Parameter(firebase::analytics::kParameterItemID, id),
    Parameter(firebase::analytics::kParameterItemName, name),
    Parameter("technology technology"),
};

firebase::analytics::LogEvent(
    firebase::analytics::kEventSelectContent,
    params,
    sizeof(params) / sizeof(params[0/50])
);
