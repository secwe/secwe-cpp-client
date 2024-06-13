#include "secwe_client.h"

int main() {
    secwe_client secweb
    (
            "__USERNAME__",
            "__API_KEY__"
    );

    auto result =
            secweb.Get("google.com");

    //std::cout << "Domain: " << result.first << ", Prediction: " << result.second << std::endl;
    return 0;
}
