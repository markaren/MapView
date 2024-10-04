#ifndef URLFETCHER_HPP
#define URLFETCHER_HPP

#include <curl/curl.h>

#include <string>
#include <vector>


inline static size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    auto stream = (std::vector<unsigned char> *) userdata;
    size_t count = size * nmemb;
    stream->insert(stream->end(), ptr, ptr + count);
    return count;
}

struct UrlFetcher {

    UrlFetcher() : curl(curl_easy_init()) {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &write_data);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "threepp/1.0 (Cross-Platform; C++)");
    }

    bool fetch(const std::string &url, std::vector<unsigned char> &data) {

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        CURLcode res = curl_easy_perform(curl);

        return res == CURLE_OK;
    }

    ~UrlFetcher() {
        curl_easy_cleanup(curl);
    }

private:
    CURL *curl;
};


#endif//URLFETCHER_HPP
