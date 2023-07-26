//#include <workflow/HttpHeaderCursor.h>

// Created by yjs on 23-3-13.
//
#include <workflow/WFTaskFactory.h>
#include <workflow/HttpUtil.h>
#include <csignal>
#include <string>


using namespace protocol;
using namespace std;


void wget_callback(WFHttpTask *task)
{
    protocol::HttpRequest *req = task->get_req();
    protocol::HttpResponse *resp = task->get_resp();
    int state = task->get_state();
    int error = task->get_error();

    // handle error states

    std::string name;
    std::string value;
    // print request to stderr
    fprintf(stderr, "%s %s %s\r\n", req->get_method(), req->get_http_version(), req->get_request_uri());
    protocol::HttpHeaderCursor req_cursor(req);
    while (req_cursor.next(name, value))
        fprintf(stderr, "%s: %s\r\n", name.c_str(), value.c_str());
    fprintf(stderr, "\r\n");

    // print response header to stderr


    // print response body to stdin
    const void *body;
    size_t body_len;
    resp->get_parsed_body(&body, &body_len); // always success.
    fwrite(body, 1, body_len, stdout);
    fflush(stdout);
};

int main(){
    string url{"http://www.baidu.com"};
    const int REDIRECT_MAX=1;
    const int RETRY_MAX=1;


    WFHttpTask *task = WFTaskFactory::create_http_task(url, REDIRECT_MAX, RETRY_MAX, wget_callback);
    protocol::HttpRequest *req = task->get_req();
    req->add_header_pair("Accept", "*/*");
    req->add_header_pair("User-Agent", "Wget/1.14 (gnu-linux)");
    req->add_header_pair("Connection", "close");
    task->start();
    pause();

}





