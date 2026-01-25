import json
import os
from datetime import datetime


def load_json(file_path: str) -> dict:
    """
    Load JSON file and return dictionary
    """
    if not os.path.exists(file_path):
        raise FileNotFoundError(f"File not found: {file_path}")

    with open(file_path, "r", encoding="utf-8") as f:
        return json.load(f)


def save_json(file_path: str, data: dict) -> None:
    """
    Save dictionary to JSON file
    """
    os.makedirs(os.path.dirname(file_path), exist_ok=True)

    with open(file_path, "w", encoding="utf-8") as f:
        json.dump(data, f, indent=4, ensure_ascii=False)


def get_env(key: str, default=None):
    """
    Get environment variable safely
    """
    return os.getenv(key, default)


def log(message: str, level: str = "INFO") -> None:
    """
    Simple logger
    """
    time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    print(f"[{time}] [{level}] {message}")


def validate_keys(data: dict, required_keys: list) -> None:
    """
    Validate required keys in dictionary
    """
    missing = [k for k in required_keys if k not in data]
    if missing:
        raise KeyError(f"Missing keys: {missing}")
