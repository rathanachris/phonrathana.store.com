import requests

url = "https://www.phonrathana.stoer.com/domain"
output_file = "hosts_filter.txt"

try:
    response = requests.get(url, verify=False)  # បិទការត្រួតពិនិត្យ SSL
    response.raise_for_status()  # ពិនិត្យបើមាន error (ដូចជា 503)
    
    with open(output_file, "w") as file:
        file.write(response.text)
    
    print(f"ទាញយកជោគជ័យ! ឯកសារត្រូវបានរក្សាទុកជា {output_file}")
except requests.exceptions.RequestException as e:
    print(f"មានបញ្ហា: {e}")library
