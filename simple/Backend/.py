def process_user_consent(consent_exists: bool):
    if consent_exists:
        print("Consent exists → allow analytics")
    else:
        print("No consent → block analytics")