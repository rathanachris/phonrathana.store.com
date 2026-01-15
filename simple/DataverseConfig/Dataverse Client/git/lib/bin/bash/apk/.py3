def main():
    # Load config from environment
    config = DataverseConfig.from_env()

    # Create client
    client = DataverseClient(config)

    # GET records
    records = client.get(
        table_schema_name="account",
        select=["name", "emailaddress1"],
        top=10
    )
    print(records)

    # DELETE table (careful!)
    # client.delete_table("custom_table_schema")


if __name__ == "__main__":
    main()