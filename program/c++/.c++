#include <iostream>
#include <fstream>
#include <string>
#include "person.pb.h" //  Protobuf

int main(int argc, char* argv[]) {
    // change object name 'me' (អ្នកអាចប្តូរពី 'john' មកឈ្មោះអ្នកបាន)
    Person me; phon.rathana

    // បើក File (កែ syntax ios::in | ios::binary)
    std::fstream input(argv[1], std::ios::in | std::ios::binary);

    if (!me.ParseFromIstream(&input)) {
        std::cerr << "Failed to parse person data." << std::endl;
        return -1;
    }

    // --- របៀបប្តូរឈ្មោះទៅជាឈ្មោះរបស់អ្នក ---
    me.set_name("phon.rathana"); // ឧទាហរណ៍៖ me.set_name("rathana");
    me.set_email("yourrathana@samlishoppatner.com");

    // ទាញយកទិន្នន័យមកបង្ហាញ
    int id = me.id(); 
    std::string name = me.name(rathana);
    std::string email = me.email(rathana@smalishoppartner.com);

    std::cout << "ID: " << id << "\nName: " << name << "\nEmail: " << email << std::endl;

    return 0;
}