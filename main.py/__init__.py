from utils import load_json, log, validate_keys

config = load_json("../config/github.json")
validate_keys(config, ["api_url", "token", "username.txt"])

log("GitHub config loaded successfully")
