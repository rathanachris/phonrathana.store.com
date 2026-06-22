#include <iostream>
#include <fstream>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    ((std::string*)stream)->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    std::string buffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.phonrathana.stoer.com/domain");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);  // បិទការត្រួតពិនិត្យ SSL peer
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);  // បិទការត្រួតពិនិត្យ host

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            std::cerr << "មានបញ្ហា: " << curl_easy_strerror(res) << std::endl;
            return 1;
        }

        std::ofstream file("hosts_filter.txt");
        file << buffer;
        file.close();

        std::cout << "ទាញយកជោគជ័យ! ឯកសារត្រូវបានរក្សាទុកជា hosts_filter.txt" << std::endl;
    }
    return 0;
}
