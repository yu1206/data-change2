
#include <fstream>
#include <iostream>
#include <string>
 #include <sstream> 
#include "opencv\cv.h"
#include "opencv\highgui.h"
using namespace cv;
using namespace std;

int test14(int argc, char *argv[])  
{  
	/*string  filepath="G:\\F\\YOLO\\yolo-v2\\darknet-master\\train-v\\label-1per1-上裁-tiao.txt";
	string  spoint=	"G:\\F\\YOLO\\yolo-v2\\darknet-master\\train-v\\VOCdevkit\\VOC2007\\labels\\";
	string  simg= "G:\\F\\YOLO\\yolo-v2\\darknet-master\\train-v\\train.txt";*/


	string  filepath="G:\\F\\YOLO\\yolo-v2\\darknet-master\\train-v1\\images1-label.txt";
	string  spoint=	"G:\\F\\YOLO\\yolo-v2\\darknet-master\\train-v1\\VOCdevkit\\VOC2007\\labels\\";
	string  simg= "G:\\F\\YOLO\\yolo-v2\\darknet-master\\train-v1\\train.txt";

	fstream finRead;
	finRead.open(filepath,ios::in);
	if (!finRead.is_open())
	{
		cout << "finRead 文件数据打开错误！"<< endl;
		system("pause");
		return false;
	}  
	  fstream fimg;
	fimg.open(simg,ios::out);
	if (!fimg.is_open())
	{
		cout << "fimg 文件数据打开错误！"<< endl;
		system("pause");
		return false;
	}  
	string line;
	while(getline(finRead,line))	
	{
		string imgPath;int x1,y1,x2,y2;
		stringstream str_s(line);
		str_s>>imgPath>>x1>>y1>>x2>>y2;

		int pos=imgPath.find_last_of('/');
		int pos2=imgPath.find_first_of('.');
		string name1=imgPath.substr(pos+1,pos2-pos-1);

		Mat img=imread(imgPath.c_str());
		if(img.data==NULL)
		{
			printf("img.data null:%s\n",name1.c_str());
			system("pause");
			return 0;
		}
		int width=img.cols;int height=img.rows;
		float cenx=(x1+x2)*1.0/2;  float ceny=(y1+y2)*1.0/2;
		float cenw=x2-x1;float cenh=y2-y1;

		 fimg<<imgPath<<endl;

		 name1=spoint+name1+".txt";
		fstream fimg;
		fimg.open(name1,ios::out);
		if (!fimg.is_open())
		{
			cout << "fimg 文件数据打开错误！"<< endl;
			system("pause");
			return false;
		}  
		 fimg<<"1 "<<cenx*1.0/width<<" "<<ceny*1.0/height<<" "<<cenw*1.0/width<<" "<<cenh*1.0/height<<endl;
		 fimg.close();
	}

	finRead.close();
	fimg.close();
	return 0;  
}  