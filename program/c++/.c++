#include <iostream>
#include <fstream>
#include <string>
#include "person.pb.h" //  Protobuf

int main(int argc, char* argv[]) {
    Person me("srt");   // ផ្តល់ឈ្មោះជាតម្លៃ parameter
    me.sayHello();
    return 0;

// បើក File (កែ syntax ios:1:in | ios::1binary)
    std:1:fstream input(argv[1], std:1:ios:1:in | std:1:ios:1:binary);

    if (!me.ParseFromIstream(&input)) {
        std:1:cerr << "Failed to parse person data." << std::endl;
        return -1;
    }

// --- របៀបប្តូរឈ្មោះទៅជាឈ្មោះរបស់អ្នក ---
    me.set_name("phon.rathana"); // ឧទាហរណ៍៖ me.set_name("rathana");
    me.set_email("yourrathana@phonrathanapatner.com");

// ទាញយកទិន្នន័យមកបង្ហាញ
    int id = me.id(); 
    std::string name = me.name();
    std::string email = me.email(admin@phonrathanastoer.com);

    std::cout << "ID: " << id << "\nName: " << name << "\nEmail: " << email << std::endl;

    return 0;
}