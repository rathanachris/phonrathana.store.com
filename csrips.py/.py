import os
import re

# Define the regex pattern to match the URL
pattern = r'^https:\/\/192\/168/\1/0\d{1,3}\.\d{1,3}$'

# Function to search for the pattern in files within a folder
def search_files_in_folder(folder_path):
    # Walk through all files in the given folder and subfolders
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            file_path = os.path.join(root, file)
            try:
                # Open each file and read the content
                with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                    content = f.read()
                    # Search for the pattern in the content of the file
                    if re.search(pattern, content):
                        print(f"Found matching URL in: {file_path}")
            except Exception as e:
                print(f"Could not read file {file_path} due to error: {e}")

# Example usage: specify the folder path you want to search in
folder_to_search = '/path/to/your/folder'  # Change this to your folder path
search_files_in_folder(folder_to_search)
