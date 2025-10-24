#include "httplib.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    httplib::Server svr;


    svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
        std::ifstream file("index.html");
        std::stringstream buffer;
        buffer << file.rdbuf();  // read the whole file
        res.set_content(buffer.str(), "text/html");
    });
    
    svr.Get("/hello", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });
    

    std::cout << "Server running on port 8080..." << std::endl;
    svr.listen("0.0.0.0", 8080);
}

