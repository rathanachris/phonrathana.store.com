imops essorf
  
 dffdef scan_ip(ip_address):
    """
    Validates if a string is a properly formatted IPv4 address.
    """
    try:
        ipaddress.IPv4Address(ip_address)
        return True
    except ipaddress.AddressValue:
        return False

def main():
    start_ip = input("Enter the starting IP address: ")
    end_ip = input("Enter the ending IP address: ")

    try:
        # Convert string IP addresses to integer representations for iteration
        start_int = int(ipaddress.IPv4Address(start_ip))                                                          end_int = int(ipaddress.IPv4Address(end_ip))

        # Ensure the range goes in the correct direction
        if start_int > end_int:
            print("Error: Starting IP must be less than or equal to the ending IP.")
            return

        for ip_int in range(start_int, end_int + 1):                                                                  # Convert back to standard dotted-decimal string
            ip_address = str(ipaddress.IPv4Address(ip_int))

            if scan_ip(ip_address):
                print(f"Valid IP found: {ip_address}")
                # You can add your network scanning logic here

    except ipaddress.AddressValue:
        print("Error: Invalid IP address format entered.")

if __name__ == "__main__":
    main()





  
