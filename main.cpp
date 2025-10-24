#include "httplib.h"
#include <iostream>

int main() {
    httplib::Server svr;

    svr.Get("/hello", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Hello, World!", "text/plain");
    });

    std::cout << "Server running on port 8080..." << std::endl;
    svr.listen("0.0.0.0", 8080);
}
