#include <iostream>
#include <curl/curl.h>
#include "utils.hpp"

using std::cout;
using std::endl;

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
   return size * nmemb;
}

int main(int argc, char** argv){
    if (argc < 2){
        cout << "No argument passed!" << endl;
        return -2;
    }
    CURL *curl_handle = curl_easy_init();
    if (!curl_handle) return -1;
    CURLcode resp;
    curl_easy_setopt(curl_handle, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

    resp = curl_easy_perform(curl_handle);
    if (resp == CURLE_OK){
        cout << "OK!" << endl;
    }
    curl_easy_cleanup(curl_handle);
    return 0;
}
