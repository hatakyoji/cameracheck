//---------------------------------------------------------
// 概要      : カメラのフレームレートの判別
// File Name : cameracheck.cpp
// Library   : OpenCV 2.0
//---------------------------------------------------------

#include <stdio.h>
#include <highgui.h>
#include <cv.h>

#pragma comment (lib,"cv200d.lib")
#pragma comment (lib,"cxcore200d.lib")
#pragma comment (lib,"highgui200d.lib")

#define WIDTH	720	//	キャプチャ画像の横幅
#define HEIGHT	480	//	キャプチャ画像の縦幅

uchar r[1000],g[1000],b[1000];

int main( int argc, char** argv ){ 
	int key;					//	キー入力用の変数
	CvCapture *capture;				//	カメラキャプチャ用の構造体
	IplImage *frameImage;				//	キャプチャ画像用IplImage
	char windowNameCapture[] = "Capture";			//キャプチャした画像を表示するウィンドウの名前
	int x, y;
	FILE *fp;
	int i,j,k,l;
	uchar b0,g0,r0,b1,g1,r1,b2,g2,r2,b3,g3,r3;

	//	カメラを初期化する
	if ( ( capture = cvCreateCameraCapture( 0 ) ) == NULL ) {
		//	カメラが見つからなかった場合
		printf( "カメラが見つかりません\n" );
		key = cvWaitKey( 10 );
	}

	cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_WIDTH, WIDTH);
	cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);


	//	ウィンドウを生成する
    cvNamedWindow( windowNameCapture, CV_WINDOW_AUTOSIZE );
	i = 0;
	j = 0;
	k = 0;

	//	メインループ
	while ( k<1000 ) {
		//	カメラからの入力画像フレームをframeImageに格納する
		printf("in");
		frameImage = cvQueryFrame( capture );
		printf("out");
      /* 画素値を直接操作する*/   
		x = 80;
		y = 60;

		b0 = frameImage ->imageData[frameImage ->widthStep * y + x * 3];        // B
		g0 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 1];    // G      
		r0 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 2];    // R

    	     frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		x = 81;
		y = 60;
		b1 = frameImage ->imageData[frameImage ->widthStep * y + x * 3];        // B
		g1 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 1];    // G      
		r1 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 2];    // R

        	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		x = 80;
		y = 61;

		b2 = frameImage ->imageData[frameImage ->widthStep * y + x * 3];        // B
		g2= frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 1];     // G      
		r2 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 2];    // R

       	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;


		x = 81;
		y = 61;
		b3 = frameImage ->imageData[frameImage ->widthStep * y + x * 3];        // B
		g3 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 1];    // G      
		r3 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 2];    // R

        	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
     	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		r[i]=(r0+r1+r2+r3)/4;
		g[j]=(g0+g1+g2+g3)/4;
		b[k]=(b0+b1+b2+b3)/4;

		i++;
		j++;
		k++;


		//	画像を表示する
		cvShowImage( windowNameCapture, frameImage );
	    cvWaitKey( 1 );

		key = cvWaitKey( 10 );
		if( key == 'q' ) 
			//	'q'キーが押されたらループを抜ける
			break;


	}	



	//	キャプチャを解放する
	cvReleaseCapture( &capture );
	//	ウィンドウを破棄する
	cvDestroyWindow(windowNameCapture);

	i=0;
	j=0;
	k=0;

	fp=fopen("cameracheck.csv","w");
	for(l=0;l< 1000;l++){
		fprintf(fp,"%d,%d,%d \n",r[i],g[j],b[k]);
		i++;
		j++;
		k++;
	}
	fclose(fp);

	return 0;
}

