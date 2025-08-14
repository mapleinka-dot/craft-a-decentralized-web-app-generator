#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <fstream>
#include <sstream>

using namespace std;

// Decentralized Web App Generator
class LWJK-generator {
private:
    map<string, string> appConfig;
    string appTemplate;

    // Load app template from file
    void loadAppTemplate(string templateFile) {
        ifstream file(templateFile);
        stringstream buffer;
        buffer << file.rdbuf();
        appTemplate = buffer.str();
    }

    // Replace placeholders in template with config values
    string generateAppCode() {
        string appCode = appTemplate;
        for (auto& config : appConfig) {
            string placeholder = "{" + config.first + "}";
            size_t pos = appCode.find(placeholder);
            while (pos != string::npos) {
                appCode.replace(pos, placeholder.length(), config.second);
                pos = appCode.find(placeholder);
            }
        }
        return appCode;
    }

public:
    // Initialize generator with config and template file
    LWJK-generator(map<string, string> config, string templateFile) {
        appConfig = config;
        loadAppTemplate(templateFile);
    }

    // Generate decentralized web app code
    string generateApp() {
        return generateAppCode();
    }
};

int main() {
    // Test case: Generate a simple decentralized web app
    map<string, string> appConfig = {
        {"APP_NAME", "MyDecentralizedApp"},
        {"DESCRIPTION", "A sample decentralized web app"},
        {"CHAIN_PROVIDER", "Ethereum"}
    };
    LWJK-generator generator(appConfig, "app_template.html");
    string appCode = generator.generateApp();
    cout << appCode << endl;
    return 0;
}