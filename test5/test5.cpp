#include "stdafx.h"
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
 
#undef RC_OPENCV_2_4_8
 
#ifdef _DEBUG
#ifdef RC_OPENCV_2_4_8
#pragma comment( lib, "cxcore248d.lib" )
#pragma comment( lib, "cv248d.lib" )
#pragma comment( lib, "highgui248d.lib" )      
#else
#pragma comment( lib, "opencv_core248d.lib" )
#pragma comment( lib, "opencv_highgui248d.lib" )
#pragma comment( lib, "opencv_imgproc248d.lib" )
#endif
#else
#ifdef RC_OPENCV_2_4_8
#pragma comment( lib, "cxcore248.lib" )
#pragma comment( lib, "cv248.lib" )
#pragma comment( lib, "highgui248.lib" )
#else
#pragma comment( lib, "opencv_core248.lib" )
#pragma comment( lib, "opencv_highgui248.lib" )
#pragma comment( lib, "opencv_imgproc248.lib" )
#endif
#endif
 
void main()
{
    /** 打开输入视频文件 */
    cv::VideoCapture vc;
    vc.open( "D:\\测试\\test5\\1.avi" );
     
    if ( vc.isOpened() )
    {
        /** 打开输出视频文件 */
        cv::VideoWriter vw;
        vw.open( "D:\\测试\\test5\\output.avi", // 输出视频文件名
                (int)vc.get( CV_CAP_PROP_FOURCC ), // 也可设为CV_FOURCC_PROMPT，在运行时选取
                (double)vc.get( CV_CAP_PROP_FPS ), // 视频帧率
                cv::Size( (int)vc.get( CV_CAP_PROP_FRAME_WIDTH ), (int)vc.get( CV_CAP_PROP_FRAME_HEIGHT ) ), // 视频大小
                true ); // 是否输出彩色视频
 
        /** 如果成功打开输出视频文件 */
        if ( vw.isOpened() )
        {
            while ( true )
            {
                /** 读取当前视频帧 */
                cv::Mat frame;
                vc >> frame;
 
                /** 若视频读取完毕，跳出循环 */
                if ( frame.empty() )
                {
                    break;
                }
 
                /** 将视频写入文件 */
                vw << frame;
            }
        }
    }
 
    /** 手动释放视频捕获资源 */
    vc.release();
}