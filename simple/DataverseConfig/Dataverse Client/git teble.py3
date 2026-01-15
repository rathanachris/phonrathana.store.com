class DataverseClient:
    def __init__(self, config: DataverseConfig):
        self.config = config

    def get(
        self,
        table_schema_name: str,
        record_id: Optional[str] = None,
        select: Optional[List[str]] = None,
        filter: Optional[str] = None,
        orderby: Optional[List[str]] = None,
        top: Optional[int] = None,
        expand: Optional[List[str]] = None,
        page_size: Optional[int] = None
    ) -> Dict[str, Any] | Iterable[List[Dict[str, Any]]]:
        """
        Get records from Dataverse table
        """
        # NOTE: This is a logical example (pseudo API call)
        query = {
            "table": table_schema_name,
            "record_id": record_id,
            "select": select,
            "filter": filter,
            "orderby": orderby,
            "top": top,
            "expand": expand,
            "page_size": page_size
        }

        print("GET request:", query)
        return {"status": "success", "data": []}

    def delete_table(self, table_schema_name: str) -> None:
        """
        Delete a Dataverse table
        """
        print(f"Deleting table: {table_schema_name}")