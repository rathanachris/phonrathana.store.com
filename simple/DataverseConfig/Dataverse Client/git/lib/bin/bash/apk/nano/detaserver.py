from dataclasses import dataclass
from typing import Optional, List, Dict, Any, Iterable


@dataclass
class DataverseConfig:
    language_code: int = 1033
    http_retries: Optional[int] = 3
    http_backoff: Optional[float] = 0.5
    http_timeout: Optional[float] = 30.0

    @classmethod
    def from_env(cls):
        return cls()


class DataverseClient:
    def __init__(self, config: DataverseConfig):
        self.config = config

    def get(
        self,
        table_schema_name: str,
        record_id: Optional[str] = None,
        select: Optional[List[str]] = None,
        top: Optional[int] = None
    ) -> Dict[str, Any]:
        print("GET:", table_schema_name, select, top)
        return {"status": "ok"}

    def delete_table(self, table_schema_name: str) -> None:
        print("DELETE TABLE:", table_schema_name)


def main():
    config = DataverseConfig.from_env()
    client = DataverseClient(config)

    client.get("account", select=["name", "email"], top=5)
    # client.delete_table("test_table")
     client.get("account", select=["name", "email"], top=5)
    # client.delete_table("test_table")


if __name__ == "__main__":
    main()