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
    /** ��������Ƶ�ļ� */
    cv::VideoCapture vc;
    vc.open( "D:\\����\\test5\\1.avi" );
     
    if ( vc.isOpened() )
    {
        /** �������Ƶ�ļ� */
        cv::VideoWriter vw;
        vw.open( "D:\\����\\test5\\output.avi", // �����Ƶ�ļ���
                (int)vc.get( CV_CAP_PROP_FOURCC ), // Ҳ����ΪCV_FOURCC_PROMPT��������ʱѡȡ
                (double)vc.get( CV_CAP_PROP_FPS ), // ��Ƶ֡��
                cv::Size( (int)vc.get( CV_CAP_PROP_FRAME_WIDTH ), (int)vc.get( CV_CAP_PROP_FRAME_HEIGHT ) ), // ��Ƶ��С
                true ); // �Ƿ������ɫ��Ƶ
 
        /** ����ɹ��������Ƶ�ļ� */
        if ( vw.isOpened() )
        {
            while ( true )
            {
                /** ��ȡ��ǰ��Ƶ֡ */
                cv::Mat frame;
                vc >> frame;
 
                /** ����Ƶ��ȡ��ϣ�����ѭ�� */
                if ( frame.empty() )
                {
                    break;
                }
 
                /** ����Ƶд���ļ� */
                vw << frame;
            }
        }
    }
 
    /** �ֶ��ͷ���Ƶ������Դ */
    vc.release();
}