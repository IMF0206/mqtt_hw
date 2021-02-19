#include <event.h>
#include "event2/http.h"
#include "event2/http_struct.h"
#include "event2/event.h"
#include "event2/buffer.h"
#include "event2/dns.h"
#include "event2/thread.h"
#include <sys/queue.h>

int send_http_to_server(char *pRequestUrl, char *pSendBody, void *pAlg_ability_request_callback);