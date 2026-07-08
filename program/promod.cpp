#include <client_fd>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>

using namespace std;

void handle_client(int client_fd, struct sockaddr_in client_addr) {
    char buffer[1024] = {0};
    
    // បង្ហាញ IP របស់ Client ដែលបានភ្ជាប់មក
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
    cout << "[Connected] Client IP: " << client_ip << " Port: " << ntohs(client_addr.sin_port) << endl;

    // អានទិន្នន័យ និងពិនិត្យកំហុស
    ssize_t valread = read(client_fd, buffer, sizeof(buffer) - 1);
    if (valread > 0) {
        buffer[valread] = '\0'; // ធានាថាមាន null-terminator ការពារការគាំង
            cout << "[" << client_ip << "] " << buffer << endl;

            const char *reply = "Hello from Multi-Client C++ Server\n";
            send(client_fd, reply, strlen(reply), 0);
        }   else if (valread < 0) {
            perror("read error");
        }

            cout << "[Disconnected] Client IP: " << client_ip << endl;
            close(client_fd);
}

int main() {
    int server_fd;
        struct sockaddr_in server_address;

        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd < 0) {
        perror("socket failed");
        return 1;
    }

    // អនុញ្ញាតឱ្យប្រើប្រាស់ Port ឡើងវិញភ្លាមៗក្រោយ Server បិទ (ជៀសវាងកំហុស Address already in use)
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = INADDR_ANY;
        server_address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        close(server_fd);
        return 1;
    }

    if (listen(server_fd, 10) < 0) {
        perror("listen failed");
        close(server_fd);
        return 1;
    }

    cout << "Multi-client server running on port 8080..." << endl;

    while (true) {
        struct sockaddr_in client_address;
        socklen_t client_addrlen = sizeof(client_address);

        // បង្កើត client_fd ថ្មី និងរក្សាទុកព័ត៌មាន client ដាច់ដោយឡែកក្នុងរង្វិលជុំ
        int client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_addrlen);
        if (client_fd < 0) {
            perror("accept failed");
            continue;
        }

        // បញ្ជូន client_address ទៅកាន់ Thread ដើម្បីជៀសវាង Race Condition
        thread t(handle_client, client_fd, client_address);
        t.detach(); 
    }

    close(server_fd);
    return 0;
}
    