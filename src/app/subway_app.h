#pragma once

#include <string>
#include <jsoncpp/json/json.h>
#include "base_app.h"
#include "../buffer_parser.h"

#define SUBWAY_COPY_ROOT_NAME "subway"
#define SUBWAY_MEDIA_NVIDIA_ROOT_HEAD "media\/nvidia\/"
#define SUBWAY_MEDIA_CIDI_ROOT_HEAD "media\/cidi\/"
#define COPY_FILE_SIGN "/tmp/copying_file"
// Copy FORMAT_USR_FLAG from 'ips/monitor/recorder/diskManager.h'
#define FORMAT_USR_FLAG "/tmp/usrdisk"

#define SUBWAY_IPS_FW_FILENAME "ips_update/ips_fw.zip"
#define SUBWAY_IPS_MAP_FILENAME "ips_update/ips_map.zip"
#define SUBWAY_IPS_MODEL_FILENAME "ips_update/ips_model.zip"
#define SUBWAY_IPS_PARAMS_FILENAME "ips_update/ips_params.zip"
#define SUBWAY_IPS_TELE_FW_FILENAME "ips_update/tele_fw.zip"
#define SUBWAY_IPS_HAP_FW_FILENAME "ips_update/hap_fw.zip"

enum {
  CLIENT_ADMIN,
  CLIENT_CIDI,
  CLIENT_UNKNOWN
};

typedef struct {
  int type;
  time_t start_ts; // in seconds
  std::vector<std::string> ex_from;
  std::vector<std::string> ex_to;
  std::vector<std::string> ix_from;
  std::vector<std::string> ix_to;
  int state;
  long total_size;
  int percent; // x%
} CopyTask;

typedef struct {
  std::string name;
  std::string type;
} DateListItem;

struct VersionInfo {
  std::string dev_name;
  std::string sys_ver;
  std::string sw_ver;
  std::string mcu_ver;
  std::string sys_model;
  std::string hw_model;
};


class subway_app : public base_app {
  public:
    static subway_app *Instance(void);
    static void ReleaseInstance(void);

    std::string Handle(Command &cmd);

  private:
    subway_app(void);

    int IdentifyClient(Command &cmd);

    int PickHandle(Command &cmd, Json::Value &map, std::string &out_msg);

    int Login(Command &cmd, Json::Value &map, std::string &out_msg);

    int Register(Command &cmd, Json::Value &map, std::string &out_msg);

    int ResetPassword(Command &cmd, Json::Value &map, std::string &out_msg);

    int Logout(Command &cmd, Json::Value &map, std::string &out_msg);

    int QueryStatus(Command &cmd, Json::Value &map, std::string &out_msg);

    int GetSensorState(Command &cmd, Json::Value &map, std::string &out_msg);

    int GetInternalInfo(Command &cmd, Json::Value &map, std::string &out_msg);

    int GetExternalInfo(Command &cmd, Json::Value &map, std::string &out_msg);

    int GetRecordDateList(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int GetLogDateList(Command &cmd, Json::Value &map, std::string &out_msg);

    int GetDateList(Command &cmd, int type, Json::Value &map,
        std::string &out_msg);

    void RecordLog(int type, std::string &root_path, long &size,
        long &free_size, std::vector<DateListItem> &vec, int flag);

    int ShowRecordDateList(Command &cmd, Json::Value & map, std::string &out_msg);
    int ShowRecordDateListWithoutJPG(Command &cmd, Json::Value & map, std::string &out_msg);

    int ShowLogDateList(Command &cmd, Json::Value & map, std::string &out_msg);

    int ShowDateList(Command &cmd, int type, Json::Value &map,
        std::string &out_msg, bool include_jpg);

    bool ListDate(int type, std::string &root_path, long &size,
        long &free_size, std::vector<std::pair<std::string, std::string>>& vec, int flag, std::string &date_value);

    int RecordDateCopy(Command &cmd, Json::Value &map, std::string &out_msg);

    int RecordTimeCopy(Command &cmd, Json::Value &map, std::string &out_msg);

    int LogDateCopy(Command &cmd, Json::Value &map, std::string &out_msg);

    int DateCopy(Command &cmd, int type, Json::Value &map,
        std::string &out_msg);

    void* CopyHandler(void *param);
    Command copy_command;
    bool is_copying = false;

    int RealCopy(int type, int client_type, int &rc, std::string &usb_path, 
                long &usb_free, std::vector<std::string> &name_list);
    
    void AppendRecordCopyFromPath(std::string xx, bool is_internal,
        std::vector<std::string> &name_list, bool is_video);

    void AppendCopyFromPath(std::string xx, bool yy,
        std::vector<std::string> &name_list);

    void AppendCopyToPath(std::string xx, bool yy, std::string &usb_path);

    bool AppendCopyToPath_COMMON(std::string xx, bool yy,
        std::string &usb_path, std::string media_root);

    void ExecuteCopyCommand(std::string xx, std::string yy);

    int QueryCopyProgress(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int QueryRealProgress(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int QueryLogCopyProgress(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int GetVersionInfo(Command &cmd, Json::Value &map, std::string &out_msg);
    struct VersionInfo verInfo;

    int DownloadCalibrationParams(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int FirmwareImportAndUpgrade(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int FirmwareVersionQuery(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int FirmwareVersionRollback(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int SystemReboot(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int QueryUpgradeProgress(Command &cmd, Json::Value &map,
        std::string &out_msg);
    bool is_upgrading;

    int FormatExternalHdd(Command &cmd, Json::Value &map,
        std::string &out_msg);

    bool is_formating = false;
    int QueryFormatProgress(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int MapImport(Command &cmd, Json::Value &map, std::string &out_msg);

    int MapQueryCopyProgress(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int ModelImport(Command &cmd, Json::Value &map, std::string &out_msg);


    int CalibrationStart(Command &cmd, Json::Value &map, std::string &out_msg);

    int CalibrationStatus(Command &cmd, Json::Value &map,
        std::string &out_msg);

    int TeleUpgradeStart(Command &cmd, Json::Value &map, std::string &out_msg);
    bool tele_upgrading;

    int TeleUpgradeStatus(Command &cmd, Json::Value &map, std::string &out_msg);

    int HapUpgradeStart(Command &cmd, Json::Value &map, std::string &out_msg);
    bool hap_upgrading;

    int HapUpgradeStatus(Command &cmd, Json::Value &map, std::string &out_msg);

    CopyTask copy_task;
    static subway_app *p_instance;
};

