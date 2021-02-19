#ifndef MQTT_JSON_H_INCLUDED_
#define MQTT_JSON_H_INCLUDED_

#include "sqlite_helper.h"

typedef struct FRAMEINFO
{
    unsigned char head_info;
    unsigned char address_info[4];
    unsigned char frame_num;
    unsigned char frame_des;
    unsigned char frame_type;
    int64_t data_num;
    unsigned char cmd;
    unsigned char node_info[4];
    unsigned char* frame_data;
}frame_info;

typedef struct DEVICERESULT
{
    std::string nodeId;
    int statuscode;
}device_result;

typedef struct DEVICERESP
{
    std::string type;
    int result_num;
    std::vector<device_result> results;
}device_resp;


class mqtt_json
{
public:
    mqtt_json();
    ~mqtt_json();
    
    std::string get_jsonstr();
    void create_json_add_device();
    void create_json_updatestatus_device(int status);
    void create_json_updatestatus_ipc(int status);
    void create_json_data_upload(frame_info* Frame_info);
    void create_json_sysinfo_upload(float usercpu, float syscpu, float mem);
    void create_json_event_upload(frame_info* Frame_info);
    void parse_json_device_response(char* msg);
    device_resp* get_deviceresp();
private:
    std::string m_jsonstr;
    db_helper* m_dbhelper;
    device_resp* m_deviceresp;
    
};

#endif