#pragma once

#include <string>
#include <opencv2/core/core.hpp>
#include "base_app.h"
#include "../buffer_parser.h"

class panoramic_app : public base_app {
    public:
        static panoramic_app *Instance(void);
        static void ReleaseInstance(void);

        std::string Handle(Command &cmd);

        std::string Login(Command &cmd);

		//获取录像目录及信息
        std::string GetRecordInfo(Command &cmd);
		//获取目录录像信息，分页
		std::string GetRecordPage(Command &cmd);
		//删除录像文件
        std::string DeleteRecord(Command &cmd);

        // 获取车辆的类型或颜色
        std::string GetVehicleInformation(Command &cmd);
        // 选择车辆的类型或颜色
        std::string SelectVehicleInformation(Command &cmd);
        // 获取各增强功能状态
        std::string GetEnhancementStatus(Command &cmd);
        // 选择各增强功能状态
        std::string LaneDepartureWarning(Command &cmd);
        std::string AbnormalBehaviorDetection(Command &cmd);
        std::string HeightLimitMonitoring(Command &cmd);
        // 改变状态位
        std::string ChangeEnhancementStatus(Command &cmd);
        // 获取各个摄像头ID的状态
        std::string GetCameraStatus(Command &cmd);
        // 设置摄像头ID的状态
        std::string SetCameraStatus(Command &cmd);
        // 设置ROI时获取第一个操作的摄像头ID
        std::string SetROI(Command &cmd);
        // 获取图像的亮度和对比度
        std::string GetImageInformation(Command &cmd);
        // 调整图像的亮度或对比度或者对它们进行重置
        std::string AdjustImageInformation(Command &cmd);
        // 恢复出厂设置
        std::string FactoryReset(Command &cmd);
        // 设置日期时间
        std::string SetDateTime(Command &cmd);
        // 查看储存卡信息
        std::string GetSDcardInfo(Command &cmd);
        // 格式化存储卡
        std::string FormatSDcard(Command &cmd);
        //修改密码
        std::string ChangePassword(Command &cmd);
        // 查询本机信息
        std::string GetSystemInfo(Command &cmd);
        // 查询用户日志
        std::string GetLogInfo(Command &cmd);


    private:
        static panoramic_app *p_instance;
};

