#include <string>
#include <curl/curl.h>

#include "../../include/client.hpp"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

/**
 * \brief GET request the provided url and return the response body as a string
 *
 * @param url the URL to GET request
 * @return The response body
 */
std::string Client::get (const std::string url) {
    CURL *curl = curl_easy_init();
    CURLcode res;
    std::string readBuffer;

    if(curl) {
        // We need to convert the string url to a char* here
        // see https://stackoverflow.com/a/39693179
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Error codes can be found at
        // https://curl.haxx.se/libcurl/c/libcurl-errors.html
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
